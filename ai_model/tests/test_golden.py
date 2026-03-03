# ai_model/tests/test_golden.py
"""Tests for golden reference vector generation."""

import pytest
import numpy as np
from pathlib import Path
from src.golden_reference import (
    generate_golden_vectors,
    GoldenVector,
    save_golden_vectors,
    load_golden_vectors
)
from src.config import WINDOW_SIZE


class TestGoldenReference:
    """Test golden vector generation and I/O."""

    def test_vector_structure(self):
        """Golden vector should have correct fields."""
        vec = GoldenVector(
            input_window=np.zeros(WINDOW_SIZE, dtype=np.int8),
            expected_output=np.int16(0),
            trend=np.zeros(WINDOW_SIZE, dtype=np.int8),
            seasonal=np.zeros(WINDOW_SIZE, dtype=np.int8)
        )
        assert vec.input_window.shape == (WINDOW_SIZE,)
        assert isinstance(vec.expected_output, (int, np.int16))

    def test_save_load_roundtrip(self, tmp_path):
        """Vectors should survive save/load cycle."""
        vectors = [
            GoldenVector(
                input_window=np.arange(WINDOW_SIZE, dtype=np.int8),
                expected_output=np.int16(42),
                trend=np.ones(WINDOW_SIZE, dtype=np.int8),
                seasonal=np.zeros(WINDOW_SIZE, dtype=np.int8)
            )
        ]

        save_golden_vectors(vectors, tmp_path)
        loaded = load_golden_vectors(tmp_path)

        assert len(loaded) == 1
        np.testing.assert_array_equal(vectors[0].input_window, loaded[0].input_window)
        assert vectors[0].expected_output == loaded[0].expected_output
