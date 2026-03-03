# ai_model/src/data_generator.py
"""
Synthetic market data generator for DLinear training.
Generates price series with trend + seasonal + noise components.
"""

import numpy as np
import pandas as pd
from pathlib import Path


def generate_synthetic_ticks(
    n_ticks: int = 100_000,
    base_price: float = 50000.0,
    trend_strength: float = 0.0001,
    seasonal_period: int = 64,
    seasonal_amplitude: float = 50.0,
    noise_std: float = 10.0,
    seed: int = 42
) -> np.ndarray:
    """
    Generate synthetic BTC/USD-like price ticks.

    Components:
    - Trend: random walk with drift
    - Seasonal: sinusoidal pattern (period = WINDOW_SIZE for hardware alignment)
    - Noise: Gaussian noise

    Args:
        n_ticks: Number of price ticks to generate
        base_price: Starting price
        trend_strength: Drift per tick
        seasonal_period: Period of seasonal component (should match MA_WINDOW)
        seasonal_amplitude: Amplitude of seasonal oscillation
        noise_std: Standard deviation of noise
        seed: Random seed for reproducibility

    Returns:
        np.ndarray: Array of shape (n_ticks,) with prices
    """
    np.random.seed(seed)

    # Trend component: random walk with drift
    trend = np.cumsum(np.random.randn(n_ticks) * trend_strength)

    # Seasonal component: sinusoidal
    t = np.arange(n_ticks)
    seasonal = seasonal_amplitude * np.sin(2 * np.pi * t / seasonal_period)

    # Noise component
    noise = np.random.randn(n_ticks) * noise_std

    # Combine
    prices = base_price + trend + seasonal + noise

    return prices.astype(np.float32)


def save_dataset(prices: np.ndarray, output_dir: Path) -> None:
    """Save prices to CSV for inspection and Parquet for training."""
    output_dir = Path(output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)

    df = pd.DataFrame({'price': prices})
    df.to_csv(output_dir / 'ticks.csv', index=False)
    df.to_parquet(output_dir / 'ticks.parquet', index=False)
    print(f"Saved {len(prices)} ticks to {output_dir}")


if __name__ == "__main__":
    from .config import WINDOW_SIZE

    prices = generate_synthetic_ticks(
        n_ticks=100_000,
        seasonal_period=WINDOW_SIZE
    )
    save_dataset(prices, Path(__file__).parent.parent / 'data')
