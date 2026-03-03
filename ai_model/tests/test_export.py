# ai_model/tests/test_export.py
"""Tests for weight export to hex format."""

import pytest
import numpy as np
from pathlib import Path
from src.export_weights import (
    int8_array_to_hex,
    hex_to_int8_array,
    export_weights_to_hex
)


class TestHexExport:
    """Test hex file generation and parsing."""

    def test_int8_to_hex_positive(self):
        """Positive int8 values should export correctly."""
        arr = np.array([0, 1, 127], dtype=np.int8)
        hex_lines = int8_array_to_hex(arr)
        assert hex_lines == ['00', '01', '7F']

    def test_int8_to_hex_negative(self):
        """Negative int8 values should use two's complement."""
        arr = np.array([-1, -128], dtype=np.int8)
        hex_lines = int8_array_to_hex(arr)
        assert hex_lines == ['FF', '80']

    def test_roundtrip(self):
        """Hex export and import should be lossless."""
        original = np.array([0, 1, -1, 127, -128, 42, -42], dtype=np.int8)
        hex_lines = int8_array_to_hex(original)
        recovered = hex_to_int8_array(hex_lines)
        np.testing.assert_array_equal(original, recovered)

    def test_file_export(self, tmp_path):
        """Should write valid hex file."""
        weights = np.array([1, 2, 3, -1, -2, -3], dtype=np.int8)
        output_path = tmp_path / "test.hex"

        export_weights_to_hex(weights, output_path)

        # Read back
        with open(output_path, 'r') as f:
            lines = [line.strip() for line in f if line.strip()]

        recovered = hex_to_int8_array(lines)
        np.testing.assert_array_equal(weights, recovered)
