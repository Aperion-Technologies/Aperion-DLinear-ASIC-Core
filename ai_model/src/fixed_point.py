# ai_model/src/fixed_point.py
"""
Fixed-point arithmetic utilities for bit-accurate hardware matching.

CRITICAL: These functions define the exact quantization scheme used in Chisel.
Any change here MUST be reflected in hardware/src/main/scala/*.scala
"""

import numpy as np
from typing import Union
from .config import FRAC_BITS as DEFAULT_FRAC_BITS

# Re-export for convenience
FRAC_BITS = DEFAULT_FRAC_BITS

# Int8 range for weights
WEIGHT_MIN = -128
WEIGHT_MAX = 127

# Int16 range for accumulators
ACC_MIN = -32768
ACC_MAX = 32767


def float_to_fixed(
    value: Union[float, np.ndarray],
    bits: int = 8,
    frac_bits: int = DEFAULT_FRAC_BITS
) -> Union[int, np.ndarray]:
    """
    Convert floating-point to fixed-point integer.

    Format: Q(bits-frac_bits-1).(frac_bits) signed
    Example: Q1.7 for 8-bit with frac_bits=7

    Args:
        value: Float or array of floats to convert
        bits: Total bit width (8 or 16)
        frac_bits: Number of fractional bits

    Returns:
        Fixed-point integer(s) in range [-2^(bits-1), 2^(bits-1)-1]
    """
    scale = 2 ** frac_bits
    scaled = np.round(np.asarray(value) * scale)

    # Determine dtype based on bits
    dtype = np.int8 if bits == 8 else np.int16

    # Saturate to valid range
    min_val = -(2 ** (bits - 1))
    max_val = (2 ** (bits - 1)) - 1
    clipped = np.clip(scaled, min_val, max_val)

    result = clipped.astype(dtype)

    # Return scalar if input was scalar
    if np.isscalar(value):
        return int(result)
    return result


def fixed_to_float(
    value: Union[int, np.ndarray],
    frac_bits: int = DEFAULT_FRAC_BITS
) -> Union[float, np.ndarray]:
    """
    Convert fixed-point integer back to floating-point.

    Args:
        value: Fixed-point integer(s)
        frac_bits: Number of fractional bits used in encoding

    Returns:
        Floating-point value(s)
    """
    scale = 2 ** frac_bits
    result = np.asarray(value, dtype=np.float32) / scale

    if np.isscalar(value):
        return float(result)
    return result


def saturate(value: Union[int, np.ndarray], bits: int = 8) -> Union[int, np.ndarray]:
    """
    Saturating arithmetic: clamp to valid range instead of wrapping.

    This matches hardware SaturatingAdder behavior.

    Args:
        value: Integer(s) to saturate
        bits: Bit width (8 or 16)

    Returns:
        Saturated integer(s)
    """
    min_val = -(2 ** (bits - 1))
    max_val = (2 ** (bits - 1)) - 1

    result = np.clip(value, min_val, max_val)

    if np.isscalar(value):
        return int(result)
    return result


def mac_fixed(
    inputs: np.ndarray,
    weights: np.ndarray,
    acc_bits: int = 16
) -> int:
    """
    Multiply-Accumulate in fixed-point matching hardware behavior.

    Hardware computes: sum(input[i] * weight[i]) with saturation

    Args:
        inputs: Int8 input activations
        weights: Int8 weights
        acc_bits: Accumulator bit width

    Returns:
        Saturated accumulator result (Int16)
    """
    # Widen to int32 for multiplication to avoid overflow
    products = inputs.astype(np.int32) * weights.astype(np.int32)
    acc = np.sum(products)
    return saturate(acc, bits=acc_bits)
