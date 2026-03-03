# ai_model/tests/test_fixed_point.py
"""Tests for fixed-point conversion utilities."""

import pytest
import numpy as np
from src.fixed_point import (
    float_to_fixed,
    fixed_to_float,
    saturate,
    FRAC_BITS,
    WEIGHT_MIN,
    WEIGHT_MAX
)


class TestFixedPoint:
    """Test fixed-point conversion roundtrip and saturation."""

    def test_roundtrip_zero(self):
        """Zero should convert perfectly."""
        fixed = float_to_fixed(0.0, bits=8, frac_bits=FRAC_BITS)
        back = fixed_to_float(fixed, frac_bits=FRAC_BITS)
        assert back == 0.0

    def test_roundtrip_positive(self):
        """Positive values should roundtrip within quantization error."""
        original = 0.5
        fixed = float_to_fixed(original, bits=8, frac_bits=FRAC_BITS)
        back = fixed_to_float(fixed, frac_bits=FRAC_BITS)
        assert abs(back - original) < (1.0 / (2 ** FRAC_BITS))

    def test_roundtrip_negative(self):
        """Negative values should roundtrip within quantization error."""
        original = -0.5
        fixed = float_to_fixed(original, bits=8, frac_bits=FRAC_BITS)
        back = fixed_to_float(fixed, frac_bits=FRAC_BITS)
        assert abs(back - original) < (1.0 / (2 ** FRAC_BITS))

    def test_saturation_overflow(self):
        """Values above max should saturate to max."""
        result = saturate(200, bits=8)  # 8-bit signed max is 127
        assert result == 127

    def test_saturation_underflow(self):
        """Values below min should saturate to min."""
        result = saturate(-200, bits=8)  # 8-bit signed min is -128
        assert result == -128

    def test_array_conversion(self):
        """Should handle numpy arrays."""
        arr = np.array([0.0, 0.5, -0.5, 0.25])
        fixed = float_to_fixed(arr, bits=8, frac_bits=FRAC_BITS)
        assert fixed.dtype == np.int8
        assert len(fixed) == 4
