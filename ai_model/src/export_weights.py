# ai_model/src/export_weights.py
"""
Export quantized weights to .hex format for ASIC loading.

Hex Format:
- One value per line
- Two hex digits per Int8 value (00-FF)
- Two's complement for negative values
- Verilog $readmemh compatible

Usage:
    python -m src.export_weights --model outputs/dlinear_quantized.pt --output outputs/
"""

import argparse
from pathlib import Path
import numpy as np
import torch

from .model import QuantDLinear
from .config import WINDOW_SIZE, WEIGHT_BITS, ACTIVATION_BITS


def int8_array_to_hex(arr: np.ndarray) -> list[str]:
    """
    Convert int8 array to list of 2-digit hex strings.

    Uses two's complement for negative values (matching Verilog $readmemh).

    Args:
        arr: Numpy array of int8 values

    Returns:
        List of hex strings (e.g., ['00', '7F', 'FF', '80'])
    """
    # Ensure int8
    arr = arr.astype(np.int8)

    # View as unsigned for proper hex conversion
    unsigned = arr.view(np.uint8)

    return [f'{val:02X}' for val in unsigned.flatten()]


def hex_to_int8_array(hex_lines: list[str]) -> np.ndarray:
    """
    Parse hex strings back to int8 array.

    Args:
        hex_lines: List of hex strings

    Returns:
        Numpy array of int8 values
    """
    unsigned = np.array([int(h, 16) for h in hex_lines], dtype=np.uint8)
    return unsigned.view(np.int8)


def export_weights_to_hex(weights: np.ndarray, output_path: Path) -> None:
    """
    Write weights to hex file.

    Args:
        weights: Int8 weight array
        output_path: Path to output .hex file
    """
    hex_lines = int8_array_to_hex(weights)

    output_path = Path(output_path)
    output_path.parent.mkdir(parents=True, exist_ok=True)

    with open(output_path, 'w') as f:
        for line in hex_lines:
            f.write(line + '\n')

    print(f"Exported {len(hex_lines)} weights to {output_path}")


def export_model_weights(model_path: Path, output_dir: Path) -> dict:
    """
    Export all weights from trained model to hex files.

    Creates:
        - trend_w.hex: Trend head weights (64 values)
        - seas_w.hex: Seasonal head weights (64 values)
        - scales.txt: Quantization scales for debugging

    Args:
        model_path: Path to saved .pt model
        output_dir: Directory for output files

    Returns:
        Dict with exported paths and metadata
    """
    output_dir = Path(output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)

    # Load model
    model = QuantDLinear(
        window_size=WINDOW_SIZE,
        weight_bits=WEIGHT_BITS,
        act_bits=ACTIVATION_BITS
    )
    model.load_state_dict(torch.load(model_path, weights_only=True))
    model.eval()

    # Extract quantized weights
    weights = model.get_quantized_weights()

    # Export trend weights
    trend_path = output_dir / 'trend_w.hex'
    export_weights_to_hex(weights['trend_w'].flatten(), trend_path)

    # Export seasonal weights
    seas_path = output_dir / 'seas_w.hex'
    export_weights_to_hex(weights['seas_w'].flatten(), seas_path)

    # Save scales for reference
    scales_path = output_dir / 'scales.txt'
    with open(scales_path, 'w') as f:
        f.write(f"trend_scale: {weights['trend_scale']}\n")
        f.write(f"seas_scale: {weights['seas_scale']}\n")

    print(f"Scales saved to {scales_path}")

    return {
        'trend_w': trend_path,
        'seas_w': seas_path,
        'scales': scales_path,
        'trend_shape': weights['trend_w'].shape,
        'seas_shape': weights['seas_w'].shape
    }


def main():
    parser = argparse.ArgumentParser(description='Export model weights to hex')
    parser.add_argument('--model', type=Path, required=True, help='Path to .pt model')
    parser.add_argument('--output', type=Path, default=Path('outputs'), help='Output directory')
    args = parser.parse_args()

    result = export_model_weights(args.model, args.output)
    print(f"\nExported files:")
    print(f"  Trend weights: {result['trend_w']} (shape: {result['trend_shape']})")
    print(f"  Seasonal weights: {result['seas_w']} (shape: {result['seas_shape']})")


if __name__ == '__main__':
    main()
