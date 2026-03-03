#!/usr/bin/env python3
"""
ai_model/src/prepare_market_data.py
Convert market tick CSV to quantized HEX format for ASIC simulation.

CRITICAL: Quantization parameters MUST match Brevitas training config.

Input: CSV with price column (trades.csv or lob.csv)
Output:
  - market_input.hex: Quantized input windows (64 ticks per line)
  - expected_output.hex: Forward-looking target prices (for MSE calculation)

Per stage_4.md: "The SCALE in the script must match training in Brevitas."
"""

import argparse
from pathlib import Path
import numpy as np
import pandas as pd

from .config import WINDOW_SIZE, ACTIVATION_BITS, FRAC_BITS, PREDICTION_HORIZON


def normalize_prices(prices: np.ndarray) -> tuple[np.ndarray, float, float]:
    """
    Normalize prices to [-1, 1] range for quantization.

    For HFT, we use price DIFFERENCES (returns) rather than absolute prices.
    This ensures the model sees relative movements that fit in Int8 range.

    Args:
        prices: Raw price array

    Returns:
        Tuple of (normalized_prices, scale, offset)
    """
    # Calculate price differences (first-order differencing)
    diffs = np.diff(prices)

    # Pad to keep same length (first value is 0)
    diffs = np.concatenate([[0], diffs])

    # Normalize to fit in Int8 range (-128 to 127)
    # Use robust normalization (clip outliers at 3 sigma)
    std = np.std(diffs)
    mean = np.mean(diffs)

    # Clip at 3 sigma
    clipped = np.clip(diffs, mean - 3*std, mean + 3*std)

    # Scale to [-1, 1] range (will be quantized to Int8 later)
    if std > 0:
        normalized = clipped / (3 * std)
    else:
        normalized = clipped

    return normalized, 3 * std, mean


def quantize_to_int8(data: np.ndarray, frac_bits: int = FRAC_BITS) -> np.ndarray:
    """
    Quantize normalized [-1, 1] data to Int8 using Q1.7 format.

    Q1.7 format: 1 sign bit + 7 fractional bits
    Range: [-1.0, 0.9921875] with precision 0.0078125

    Args:
        data: Normalized data in [-1, 1] range
        frac_bits: Number of fractional bits (default 7 for Q1.7)

    Returns:
        Int8 quantized array
    """
    scale = 2 ** frac_bits  # 128 for Q1.7

    # Quantize: multiply by scale and round
    quantized = np.round(data * scale)

    # Clip to Int8 range
    q_min = -128
    q_max = 127
    clipped = np.clip(quantized, q_min, q_max)

    return clipped.astype(np.int8)


def int8_to_hex_line(window: np.ndarray) -> str:
    """
    Convert Int8 array to HEX string line.

    Uses two's complement for negative values (matching Verilog $readmemh).

    Args:
        window: Int8 array of WINDOW_SIZE values

    Returns:
        HEX string (2 chars per byte, no separators)
    """
    # View as unsigned for proper hex conversion
    unsigned = window.astype(np.int8).view(np.uint8)
    return ''.join(f'{b:02X}' for b in unsigned)


def load_trades_csv(csv_path: Path, max_rows: int = None) -> np.ndarray:
    """
    Load prices from trades.csv format.

    Expected columns: local_timestamp, side, price, amount

    Args:
        csv_path: Path to trades.csv
        max_rows: Maximum rows to load (None for all)

    Returns:
        Array of prices
    """
    # Read with limited rows if specified
    df = pd.read_csv(csv_path, nrows=max_rows, usecols=['price'])
    return df['price'].values


def load_lob_csv(csv_path: Path, max_rows: int = None) -> np.ndarray:
    """
    Load mid-prices from lob.csv format.

    Uses best bid/ask to calculate mid-price.

    Args:
        csv_path: Path to lob.csv
        max_rows: Maximum rows to load (None for all)

    Returns:
        Array of mid-prices
    """
    df = pd.read_csv(csv_path, nrows=max_rows,
                     usecols=['asks[0].price', 'bids[0].price'])
    mid_price = (df['asks[0].price'] + df['bids[0].price']) / 2
    return mid_price.values


def prepare_market_hex(csv_path: Path, output_dir: Path,
                       window_size: int = WINDOW_SIZE,
                       prediction_horizon: int = PREDICTION_HORIZON,
                       max_rows: int = None,
                       csv_type: str = 'trades') -> dict:
    """
    Convert market CSV to HEX files for ASIC simulation.

    Creates:
        - market_input.hex: One line per prediction (WINDOW_SIZE * 2 hex chars)
        - expected_output.hex: Forward price for each window
        - quant_params.txt: Quantization parameters for dequantization

    Args:
        csv_path: Path to input CSV
        output_dir: Directory for output files
        window_size: Input window size (must match Chisel WINDOW_SIZE)
        prediction_horizon: Ticks ahead to predict
        max_rows: Maximum rows to process (None for all)
        csv_type: 'trades' or 'lob'

    Returns:
        Dict with paths and statistics
    """
    output_dir = Path(output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)

    # Load data based on CSV type
    if csv_type == 'lob':
        prices = load_lob_csv(csv_path, max_rows)
    else:
        prices = load_trades_csv(csv_path, max_rows)

    print(f"Loaded {len(prices)} prices from {csv_path}")
    print(f"Price range: {prices.min():.6f} - {prices.max():.6f}")

    # Normalize prices
    normalized, scale, offset = normalize_prices(prices)
    print(f"Normalization: scale={scale:.6f}, offset={offset:.6f}")

    # Quantize to Int8
    quantized = quantize_to_int8(normalized)
    print(f"Quantized range: [{quantized.min()}, {quantized.max()}]")

    # Generate sliding windows
    num_windows = len(prices) - window_size - prediction_horizon
    print(f"Generating {num_windows} windows (size={window_size}, horizon={prediction_horizon})")

    input_hex_lines = []
    target_hex_lines = []

    for i in range(num_windows):
        # Input window: quantized price differences
        window = quantized[i : i + window_size]
        input_hex_lines.append(int8_to_hex_line(window))

        # Target: future price difference (quantized)
        future_idx = i + window_size + prediction_horizon - 1
        target_value = quantized[future_idx]
        target_hex_lines.append(f'{int(target_value) & 0xFF:02X}')

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

    # Write quantization parameters (for dequantization in analysis)
    params_path = output_dir / 'quant_params.txt'
    with open(params_path, 'w') as f:
        f.write(f"# Quantization parameters for market data\n")
        f.write(f"scale: {scale}\n")
        f.write(f"offset: {offset}\n")
        f.write(f"frac_bits: {FRAC_BITS}\n")
        f.write(f"window_size: {window_size}\n")
        f.write(f"prediction_horizon: {prediction_horizon}\n")
        f.write(f"num_windows: {num_windows}\n")
        f.write(f"source_file: {csv_path.name}\n")
    print(f"Wrote parameters to {params_path}")

    return {
        'input_hex': input_path,
        'output_hex': output_path,
        'params': params_path,
        'num_windows': num_windows,
        'scale': scale,
        'offset': offset,
    }


def main():
    parser = argparse.ArgumentParser(
        description='Prepare market data for ASIC simulation'
    )
    parser.add_argument(
        '--csv', type=Path,
        default=Path('trades.csv'),
        help='Input CSV (trades.csv or lob.csv)'
    )
    parser.add_argument(
        '--output', type=Path,
        default=Path('ai_model/outputs'),
        help='Output directory for HEX files'
    )
    parser.add_argument(
        '--window', type=int, default=WINDOW_SIZE,
        help=f'Window size (default: {WINDOW_SIZE})'
    )
    parser.add_argument(
        '--max-rows', type=int, default=100000,
        help='Maximum rows to process (default: 100000)'
    )
    parser.add_argument(
        '--type', choices=['trades', 'lob'], default='trades',
        help='CSV type (trades or lob)'
    )
    args = parser.parse_args()

    result = prepare_market_hex(
        args.csv, args.output, args.window,
        max_rows=args.max_rows, csv_type=args.type
    )

    print(f"\nMarket data preparation complete!")
    print(f"Input HEX: {result['input_hex']}")
    print(f"Target HEX: {result['output_hex']}")
    print(f"Windows generated: {result['num_windows']}")


if __name__ == '__main__':
    main()
