#!/usr/bin/env python3
"""
ai_model/src/prepare_market_data_v2.py
FIXED: Prepare market data matching the TRAINING format.

Key fixes:
1. Use normalized PRICES (not differences) - matches training
2. Use z-score normalization (mean=0, std=1) - matches PriceDataset
3. Proper alignment of predictions with actual price moves

The model was trained on:
- Input: 64 consecutive normalized PRICES
- Output: Next normalized PRICE

So backtesting must:
- Feed: 64 consecutive normalized prices
- Interpret output: Predicted next price level
- Calculate P&L: Based on predicted vs actual price direction
"""

import argparse
from pathlib import Path
import numpy as np
import pandas as pd

from .config import WINDOW_SIZE, ACTIVATION_BITS, FRAC_BITS, PREDICTION_HORIZON


def load_prices(csv_path: Path, price_col: str = 'price', max_rows: int = None) -> np.ndarray:
    """Load prices from CSV file."""
    df = pd.read_csv(csv_path, nrows=max_rows, usecols=[price_col])
    return df[price_col].values.astype(np.float64)


def normalize_prices_zscore(prices: np.ndarray) -> tuple[np.ndarray, float, float]:
    """
    Z-score normalization matching PriceDataset.

    This is EXACTLY how training data is normalized:
        normalized = (prices - mean) / std

    Args:
        prices: Raw price array

    Returns:
        Tuple of (normalized_prices, mean, std)
    """
    mean = np.mean(prices)
    std = np.std(prices)

    if std > 0:
        normalized = (prices - mean) / std
    else:
        normalized = prices - mean

    return normalized, mean, std


def quantize_to_int8(data: np.ndarray, frac_bits: int = FRAC_BITS) -> np.ndarray:
    """
    Quantize normalized data to Int8 using Q1.7 format.

    For z-score normalized data (typically in [-3, 3] range):
    - Clip to [-1, 1] (loses some outliers but fits Q1.7)
    - Or scale down by factor of 4 to fit most values

    We use clipping to [-1, 0.99] to match Q1.7 range.
    """
    # Clip to Q1.7 representable range
    clipped = np.clip(data, -1.0, 127/128)  # Q1.7 range

    # Scale by 2^frac_bits
    scale = 2 ** frac_bits  # 128 for Q1.7
    quantized = np.round(clipped * scale)

    # Clip to Int8 range
    quantized = np.clip(quantized, -128, 127)

    return quantized.astype(np.int8)


def int8_to_hex_line(window: np.ndarray) -> str:
    """Convert Int8 array to HEX string."""
    unsigned = window.astype(np.int8).view(np.uint8)
    return ''.join(f'{b:02X}' for b in unsigned)


def prepare_market_hex_v2(csv_path: Path, output_dir: Path,
                          window_size: int = WINDOW_SIZE,
                          prediction_horizon: int = PREDICTION_HORIZON,
                          max_rows: int = None,
                          price_col: str = 'price',
                          rescale_factor: float = 0.25) -> dict:
    """
    Convert market CSV to HEX files matching TRAINING format.

    CRITICAL DIFFERENCES from v1:
    1. Uses PRICES (not differences)
    2. Uses z-score normalization (not 3-sigma clipping)
    3. Rescales to fit in Q1.7 range

    Args:
        csv_path: Path to input CSV
        output_dir: Directory for output files
        window_size: Input window size
        prediction_horizon: Ticks ahead to predict
        max_rows: Maximum rows to process
        price_col: Name of price column in CSV
        rescale_factor: Factor to rescale z-scores to fit Q1.7 (default 0.25 maps [-4,4] to [-1,1])

    Returns:
        Dict with paths and statistics
    """
    output_dir = Path(output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)

    # Load prices
    prices = load_prices(csv_path, price_col, max_rows)
    print(f"Loaded {len(prices)} prices from {csv_path}")
    print(f"Price range: {prices.min():.6f} - {prices.max():.6f}")

    # Z-score normalize (matching training)
    normalized, mean, std = normalize_prices_zscore(prices)
    print(f"Z-score normalization: mean={mean:.6f}, std={std:.6f}")
    print(f"Normalized range: [{normalized.min():.4f}, {normalized.max():.4f}]")

    # Rescale to fit Q1.7 range better
    # Z-scores are typically in [-3, 3], we need [-1, 1]
    rescaled = normalized * rescale_factor
    print(f"Rescaled by {rescale_factor}: [{rescaled.min():.4f}, {rescaled.max():.4f}]")

    # Quantize to Int8
    quantized = quantize_to_int8(rescaled)
    print(f"Quantized range: [{quantized.min()}, {quantized.max()}]")

    # Count clipped values
    n_clipped = np.sum(np.abs(rescaled) > 1.0)
    print(f"Values clipped to Q1.7 range: {n_clipped} ({100*n_clipped/len(rescaled):.2f}%)")

    # Generate sliding windows
    num_windows = len(prices) - window_size - prediction_horizon
    print(f"Generating {num_windows} windows")

    input_hex_lines = []
    target_values = []  # Store as float for accurate comparison
    target_hex_lines = []

    for i in range(num_windows):
        # Input window: quantized normalized prices
        window = quantized[i : i + window_size]
        input_hex_lines.append(int8_to_hex_line(window))

        # Target: next price (quantized)
        target_idx = i + window_size + prediction_horizon - 1
        target_q = quantized[target_idx]
        target_hex_lines.append(f'{int(target_q) & 0xFF:02X}')

        # Also store actual price for P&L calculation
        target_values.append(prices[target_idx])

    # Write market_input.hex
    input_path = output_dir / 'market_input.hex'
    with open(input_path, 'w') as f:
        for line in input_hex_lines:
            f.write(line + '\n')
    print(f"Wrote {len(input_hex_lines)} windows to {input_path}")

    # Write expected_output.hex
    output_path = output_dir / 'expected_output.hex'
    with open(output_path, 'w') as f:
        for line in target_hex_lines:
            f.write(line + '\n')
    print(f"Wrote {len(target_hex_lines)} targets to {output_path}")

    # Write actual prices for P&L calculation
    prices_path = output_dir / 'target_prices.csv'
    np.savetxt(prices_path, target_values, fmt='%.8f')
    print(f"Wrote {len(target_values)} target prices to {prices_path}")

    # Write quantization parameters
    params_path = output_dir / 'quant_params.txt'
    with open(params_path, 'w') as f:
        f.write(f"# Quantization parameters for market data (v2 - z-score)\n")
        f.write(f"normalization: zscore\n")
        f.write(f"mean: {mean}\n")
        f.write(f"std: {std}\n")
        f.write(f"rescale_factor: {rescale_factor}\n")
        f.write(f"frac_bits: {FRAC_BITS}\n")
        f.write(f"window_size: {window_size}\n")
        f.write(f"prediction_horizon: {prediction_horizon}\n")
        f.write(f"num_windows: {num_windows}\n")
        f.write(f"source_file: {csv_path.name}\n")
        f.write(f"clipped_pct: {100*n_clipped/len(rescaled):.2f}\n")
    print(f"Wrote parameters to {params_path}")

    return {
        'input_hex': input_path,
        'output_hex': output_path,
        'prices_path': prices_path,
        'params': params_path,
        'num_windows': num_windows,
        'mean': mean,
        'std': std,
    }


def main():
    parser = argparse.ArgumentParser(
        description='Prepare market data for ASIC simulation (v2 - matches training)'
    )
    parser.add_argument('--csv', type=Path, required=True, help='Input CSV with price column')
    parser.add_argument('--output', type=Path, default=Path('ai_model/outputs'))
    parser.add_argument('--window', type=int, default=WINDOW_SIZE)
    parser.add_argument('--max-rows', type=int, default=None)
    parser.add_argument('--price-col', default='price')
    parser.add_argument('--rescale', type=float, default=0.25,
                        help='Rescale factor for z-scores (default 0.25)')
    args = parser.parse_args()

    result = prepare_market_hex_v2(
        args.csv, args.output, args.window,
        max_rows=args.max_rows,
        price_col=args.price_col,
        rescale_factor=args.rescale
    )

    print(f"\nMarket data preparation complete (v2 - z-score)!")
    print(f"Input HEX: {result['input_hex']}")
    print(f"Target HEX: {result['output_hex']}")
    print(f"Target prices: {result['prices_path']}")
    print(f"Windows generated: {result['num_windows']}")


if __name__ == '__main__':
    main()
