# ai_model/src/golden_reference.py
"""
Generate golden reference vectors for hardware verification.

Creates bit-exact input/output pairs that hardware simulation must match.

Output files:
- input_N.hex: Input window (64 Int8 values)
- output_N.hex: Expected output (1 Int16 value)
- trend_N.hex: Intermediate trend values
- seasonal_N.hex: Intermediate seasonal values

Usage:
    python -m src.golden_reference --model outputs/dlinear_quantized.pt --data data/ticks.parquet --output outputs/golden/
"""

import argparse
from dataclasses import dataclass
from pathlib import Path
import numpy as np
import torch

from .model import QuantDLinear
from .dataset import PriceDataset
from .fixed_point import float_to_fixed, FRAC_BITS
from .export_weights import int8_array_to_hex, export_weights_to_hex
from .config import (
    WINDOW_SIZE, WEIGHT_BITS, ACTIVATION_BITS,
    GOLDEN_VECTORS_COUNT, ACCUMULATOR_BITS
)


@dataclass
class GoldenVector:
    """A single golden reference test vector."""
    input_window: np.ndarray   # Int8[WINDOW_SIZE]
    expected_output: np.int32  # Int32 (holds up to Int24 accumulator precision)
    trend: np.ndarray          # Int8[WINDOW_SIZE] - intermediate
    seasonal: np.ndarray       # Int8[WINDOW_SIZE] - intermediate


def generate_golden_vectors(
    model: QuantDLinear,
    dataset: PriceDataset,
    n_vectors: int = GOLDEN_VECTORS_COUNT,
    prefill_value: int = 0
) -> list[GoldenVector]:
    """
    Generate golden reference vectors from model and data.

    CRITICAL: This uses hw_simulation to compute the EXACT output
    that the RTL hardware will produce, ensuring bit-exact match.

    The simulation matches the test flow:
    1. Pipeline is prefilled with prefill_value (test: fill_pipeline(dut, fill_value=0))
    2. Input window is fed to hardware
    3. Output is captured after window is processed

    Args:
        model: Trained QuantDLinear model
        dataset: Price dataset
        n_vectors: Number of vectors to generate
        prefill_value: Value used to prefill pipeline (must match test)

    Returns:
        List of GoldenVector instances
    """
    from .hw_simulation import simulate_hardware_output

    model.eval()
    vectors = []

    # Extract Brevitas int8 weights (these are loaded into hardware)
    weights = model.get_quantized_weights()
    trend_weights = weights['trend_w'].flatten()
    seas_weights = weights['seas_w'].flatten()

    print(f"Using Brevitas weights - trend shape: {trend_weights.shape}, seas shape: {seas_weights.shape}")
    print(f"Weight ranges - trend: [{trend_weights.min()}, {trend_weights.max()}], "
          f"seas: [{seas_weights.min()}, {seas_weights.max()}]")
    print(f"Prefill value: {prefill_value} (must match test fill_pipeline)")

    # Sample evenly spaced indices
    indices = np.linspace(0, len(dataset) - 1, n_vectors, dtype=int)

    for idx in indices:
        x, _ = dataset[idx]
        input_float = x.numpy().flatten()

        # Simulate hardware computation exactly
        # CRITICAL: prefill_value must match test setup
        output_hw, trend_hw, seasonal_hw = simulate_hardware_output(
            input_float,
            trend_weights,
            seas_weights,
            prefill_value=prefill_value
        )

        # Also get input in int8 format for storage
        input_q = float_to_fixed(input_float, bits=8, frac_bits=FRAC_BITS)

        vectors.append(GoldenVector(
            input_window=input_q.astype(np.int8),
            expected_output=np.int32(output_hw),
            trend=trend_hw,
            seasonal=seasonal_hw
        ))

    return vectors


def save_golden_vectors(vectors: list[GoldenVector], output_dir: Path) -> None:
    """
    Save golden vectors to hex files.

    Creates files:
        input_000.hex, input_001.hex, ...
        output_000.hex, output_001.hex, ...
        trend_000.hex, seasonal_000.hex, ...

    Args:
        vectors: List of GoldenVector instances
        output_dir: Output directory
    """
    output_dir = Path(output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)

    for i, vec in enumerate(vectors):
        # Input window
        input_path = output_dir / f'input_{i:03d}.hex'
        export_weights_to_hex(vec.input_window, input_path)

        # Expected output (Int32 as four hex bytes, little-endian)
        # Supports up to Int24 accumulator values
        output_path = output_dir / f'output_{i:03d}.hex'
        out_bytes = vec.expected_output.view(np.uint32).tobytes()
        with open(output_path, 'w') as f:
            f.write(f'{out_bytes[0]:02X}\n')  # Byte 0 (LSB)
            f.write(f'{out_bytes[1]:02X}\n')  # Byte 1
            f.write(f'{out_bytes[2]:02X}\n')  # Byte 2
            f.write(f'{out_bytes[3]:02X}\n')  # Byte 3 (MSB)

        # Trend and seasonal intermediates
        trend_path = output_dir / f'trend_{i:03d}.hex'
        export_weights_to_hex(vec.trend, trend_path)

        seas_path = output_dir / f'seasonal_{i:03d}.hex'
        export_weights_to_hex(vec.seasonal, seas_path)

    print(f"Saved {len(vectors)} golden vectors to {output_dir}")


def load_golden_vectors(input_dir: Path) -> list[GoldenVector]:
    """
    Load golden vectors from hex files.

    Args:
        input_dir: Directory containing hex files

    Returns:
        List of GoldenVector instances
    """
    from .export_weights import hex_to_int8_array

    input_dir = Path(input_dir)
    vectors = []

    i = 0
    while True:
        input_path = input_dir / f'input_{i:03d}.hex'
        if not input_path.exists():
            break

        # Load input
        with open(input_path, 'r') as f:
            input_hex = [line.strip() for line in f if line.strip()]
        input_window = hex_to_int8_array(input_hex)

        # Load output (Int32 as four hex bytes, little-endian)
        output_path = input_dir / f'output_{i:03d}.hex'
        with open(output_path, 'r') as f:
            out_hex = [line.strip() for line in f if line.strip()]
        # Pad to 4 bytes if old 2-byte format
        while len(out_hex) < 4:
            out_hex.append('00')
        out_bytes = bytes([int(h, 16) for h in out_hex])
        expected_output = np.frombuffer(out_bytes, dtype=np.int32)[0]

        # Load trend
        trend_path = input_dir / f'trend_{i:03d}.hex'
        with open(trend_path, 'r') as f:
            trend_hex = [line.strip() for line in f if line.strip()]
        trend = hex_to_int8_array(trend_hex)

        # Load seasonal
        seas_path = input_dir / f'seasonal_{i:03d}.hex'
        with open(seas_path, 'r') as f:
            seas_hex = [line.strip() for line in f if line.strip()]
        seasonal = hex_to_int8_array(seas_hex)

        vectors.append(GoldenVector(
            input_window=input_window,
            expected_output=expected_output,
            trend=trend,
            seasonal=seasonal
        ))

        i += 1

    return vectors


def main():
    parser = argparse.ArgumentParser(description='Generate golden reference vectors')
    parser.add_argument('--model', type=Path, required=True, help='Path to .pt model')
    parser.add_argument('--data', type=Path, required=True, help='Path to data parquet')
    parser.add_argument('--output', type=Path, default=Path('outputs/golden'))
    parser.add_argument('--n', type=int, default=GOLDEN_VECTORS_COUNT, help='Number of vectors')
    args = parser.parse_args()

    # Load model
    model = QuantDLinear(
        window_size=WINDOW_SIZE,
        weight_bits=WEIGHT_BITS,
        act_bits=ACTIVATION_BITS
    )
    model.load_state_dict(torch.load(args.model, weights_only=True))

    # Load dataset
    dataset = PriceDataset(args.data)

    # Generate vectors
    vectors = generate_golden_vectors(model, dataset, n_vectors=args.n)

    # Save
    save_golden_vectors(vectors, args.output)

    print(f"\nGenerated {len(vectors)} golden vectors")
    print(f"Input shape: {vectors[0].input_window.shape}")
    print(f"Output example: {vectors[0].expected_output}")


if __name__ == '__main__':
    main()
