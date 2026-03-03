#!/usr/bin/env python3
"""
ai_model/src/create_training_dataset.py
Create comprehensive training dataset for DLinear model.

Requirements:
- Multiple market regimes (trending, ranging, volatile)
- Proper normalization (z-score, matching backtest format)
- Train/val/test splits with no data leakage
"""

import argparse
from pathlib import Path
import numpy as np
import pandas as pd
from typing import Tuple


def generate_synthetic_regime_data(
    num_ticks: int = 100000,
    regime_length: int = 1000,
    base_price: float = 100.0,
    seed: int = 42
) -> pd.DataFrame:
    """
    Generate synthetic price data with multiple market regimes.

    Regimes:
    - Trending up (momentum)
    - Trending down
    - Mean-reverting (ranging)
    - High volatility
    - Low volatility
    """
    np.random.seed(seed)

    prices = [base_price]
    current_price = base_price

    num_regimes = num_ticks // regime_length

    for regime_idx in range(num_regimes):
        regime_type = regime_idx % 5

        if regime_type == 0:  # Trending up
            drift = 0.0005
            vol = 0.001
        elif regime_type == 1:  # Trending down
            drift = -0.0005
            vol = 0.001
        elif regime_type == 2:  # Mean-reverting
            drift = 0
            vol = 0.002
        elif regime_type == 3:  # High volatility
            drift = 0
            vol = 0.005
        else:  # Low volatility
            drift = 0
            vol = 0.0005

        for _ in range(regime_length):
            # Mean reversion for ranging regime
            if regime_type == 2:
                reversion = -0.01 * (current_price - base_price) / base_price
                ret = drift + reversion + np.random.normal(0, vol)
            else:
                ret = drift + np.random.normal(0, vol)

            current_price *= (1 + ret)
            prices.append(current_price)

    # Pad to exact length
    while len(prices) < num_ticks:
        prices.append(prices[-1] * (1 + np.random.normal(0, 0.001)))

    timestamps = pd.date_range(start='2024-01-01', periods=len(prices), freq='ms')

    return pd.DataFrame({
        'timestamp': timestamps[:num_ticks],
        'price': prices[:num_ticks]
    })


def normalize_for_training(
    prices: np.ndarray,
    rescale_factor: float = 0.25
) -> Tuple[np.ndarray, float, float]:
    """
    Normalize prices using z-score normalization.

    CRITICAL: Must match prepare_market_data_v2.py normalization.

    Args:
        prices: Raw price array
        rescale_factor: Scale factor to fit in Q1.7 range

    Returns:
        normalized: Normalized prices in [-1, 1] range
        mean: Mean for denormalization
        std: Std for denormalization
    """
    mean = np.mean(prices)
    std = np.std(prices)

    # Z-score normalization
    zscore = (prices - mean) / std

    # Rescale to fit in Q1.7 range [-1, 1]
    normalized = zscore * rescale_factor

    # Clip outliers
    normalized = np.clip(normalized, -1.0, 1.0)

    return normalized, mean, std


def create_windows(
    normalized: np.ndarray,
    window_size: int = 64,
    horizon: int = 1
) -> Tuple[np.ndarray, np.ndarray]:
    """
    Create sliding windows for training.

    Args:
        normalized: Normalized price array
        window_size: Input window size (must match WINDOW_SIZE)
        horizon: Prediction horizon

    Returns:
        X: Input windows (N, window_size)
        y: Target values (N,)
    """
    n_samples = len(normalized) - window_size - horizon + 1

    X = np.zeros((n_samples, window_size))
    y = np.zeros(n_samples)

    for i in range(n_samples):
        X[i] = normalized[i:i + window_size]
        y[i] = normalized[i + window_size + horizon - 1]

    return X, y


def split_train_val_test(
    X: np.ndarray,
    y: np.ndarray,
    train_ratio: float = 0.7,
    val_ratio: float = 0.15
) -> dict:
    """
    Split data chronologically (no shuffling to prevent data leakage).
    """
    n = len(X)
    train_end = int(n * train_ratio)
    val_end = int(n * (train_ratio + val_ratio))

    return {
        'X_train': X[:train_end],
        'y_train': y[:train_end],
        'X_val': X[train_end:val_end],
        'y_val': y[train_end:val_end],
        'X_test': X[val_end:],
        'y_test': y[val_end:]
    }


def main():
    parser = argparse.ArgumentParser(description='Create training dataset')
    parser.add_argument('--ticks', type=int, default=500000, help='Number of ticks')
    parser.add_argument('--window', type=int, default=64, help='Window size')
    parser.add_argument('--output', type=Path, default=Path('ai_model/data'))
    parser.add_argument('--rescale', type=float, default=0.25, help='Rescale factor')
    parser.add_argument('--seed', type=int, default=42, help='Random seed')
    args = parser.parse_args()

    args.output.mkdir(parents=True, exist_ok=True)

    print(f"Generating {args.ticks} synthetic ticks with multiple regimes...")
    df = generate_synthetic_regime_data(args.ticks, seed=args.seed)

    # Save raw prices
    df.to_csv(args.output / 'training_ticks.csv', index=False)
    print(f"Saved raw prices to {args.output / 'training_ticks.csv'}")

    # Normalize
    prices = df['price'].values
    normalized, mean, std = normalize_for_training(prices, args.rescale)

    print(f"Normalization: mean={mean:.4f}, std={std:.4f}")
    print(f"Normalized range: [{normalized.min():.4f}, {normalized.max():.4f}]")

    # Create windows
    X, y = create_windows(normalized, args.window)
    print(f"Created {len(X)} windows")

    # Split
    splits = split_train_val_test(X, y)

    print(f"Train: {len(splits['X_train'])}, Val: {len(splits['X_val'])}, Test: {len(splits['X_test'])}")

    # Save as parquet (for training) - save the normalized prices directly
    # The dataset.py will create windows from this
    train_df = pd.DataFrame({
        'price': normalized
    })
    train_df.to_parquet(args.output / 'ticks.parquet', index=False)

    # Save normalization params
    with open(args.output / 'norm_params.txt', 'w') as f:
        f.write(f"mean: {mean}\n")
        f.write(f"std: {std}\n")
        f.write(f"rescale_factor: {args.rescale}\n")
        f.write(f"window_size: {args.window}\n")
        f.write(f"num_samples: {len(X)}\n")

    print(f"\nDataset created successfully!")
    print(f"Next: python -m ai_model.src.train --data {args.output / 'ticks.parquet'}")


if __name__ == '__main__':
    main()
