# ai_model/tests/test_hw_simulation.py
"""
Unit tests for bit-exact hardware simulation.

These tests verify that hw_simulation.py matches expected hardware behavior.
"""

import pytest
import numpy as np
from src.hw_simulation import (
    MovingAverageSimulator,
    hw_decompose,
    hw_mac,
    hw_saturating_add,
    hw_dlinear_forward,
    DLinearHardwareSimulator
)
from src.config import WINDOW_SIZE, MA_WINDOW


class TestMovingAverageSimulator:
    """Test MovingAverageSimulator matches hardware timing."""

    def test_initial_state(self):
        """Simulator should start empty."""
        sim = MovingAverageSimulator(window_size=4)
        assert sim.fill_count == 0
        assert not sim.is_filled
        assert sim.running_sum == 0

    def test_fill_count_increments(self):
        """Fill count should increment until window is full."""
        sim = MovingAverageSimulator(window_size=4)

        for i in range(4):
            assert sim.fill_count == i
            assert not sim.is_filled
            sim.step(10)

        assert sim.fill_count == 4
        assert sim.is_filled

    def test_prefill(self):
        """Prefill should initialize buffer correctly."""
        sim = MovingAverageSimulator(window_size=4)
        sim.prefill(10)

        assert sim.is_filled
        assert sim.running_sum == 40  # 4 * 10
        assert np.all(sim.buffer == 10)

    def test_trend_uses_old_sum(self):
        """CRITICAL: Trend must use running_sum BEFORE update (hardware timing)."""
        sim = MovingAverageSimulator(window_size=4)
        sim.prefill(0)

        # First input after prefill
        # Hardware: trend = old_sum >> shift = 0 >> 2 = 0
        # Then sum is updated to 0 + 10 - 0 = 10
        trend, seasonal = sim.step(10)

        assert trend == 0, "Trend should use OLD sum (0), not new sum"
        assert seasonal == 10, "Seasonal = input - trend = 10 - 0 = 10"

        # Second input
        # Hardware: trend = sum >> shift = 10 >> 2 = 2
        trend2, seasonal2 = sim.step(10)

        assert trend2 == 2, "Trend should be 10 >> 2 = 2"
        assert seasonal2 == 8, "Seasonal = 10 - 2 = 8"

    def test_oldest_subtracted_when_filled(self):
        """Running sum should subtract oldest value after buffer fills."""
        sim = MovingAverageSimulator(window_size=4)

        # Fill with values 1, 2, 3, 4
        for v in [1, 2, 3, 4]:
            sim.step(v)

        # Sum should be 1 + 2 + 3 + 4 = 10
        assert sim.running_sum == 10
        assert sim.is_filled

        # Add 5, subtract oldest (1)
        sim.step(5)
        # Sum should be 10 + 5 - 1 = 14
        assert sim.running_sum == 14

        # Add 6, subtract oldest (2)
        sim.step(6)
        # Sum should be 14 + 6 - 2 = 18
        assert sim.running_sum == 18


class TestHwDecompose:
    """Test hw_decompose function."""

    def test_constant_input_no_prefill(self):
        """Constant input without prefill: trend ramps up, seasonal decreases."""
        input_window = np.full(WINDOW_SIZE, 10, dtype=np.int8)
        trend, seasonal = hw_decompose(input_window, prefill_value=None)

        # First value: trend=0 (empty buffer), seasonal=10
        assert trend[0] == 0
        assert seasonal[0] == 10

        # Last value: trend should approach 10 (MA of constant)
        # After 64 values of 10, sum = 10*64 = 640, trend = 640 >> 6 = 10
        # But due to timing, last trend uses sum BEFORE last input
        # sum = 10 * 63 = 630, trend = 630 >> 6 = 9
        assert trend[-1] == 9

    def test_constant_input_with_prefill(self):
        """Constant input with prefill: trend and seasonal should be stable."""
        input_window = np.full(WINDOW_SIZE, 10, dtype=np.int8)
        trend, seasonal = hw_decompose(input_window, prefill_value=10)

        # With prefill of 10, sum starts at 640
        # First trend = 640 >> 6 = 10
        assert trend[0] == 10

        # Since input equals prefill, trend stays at 10
        assert trend[-1] == 10

        # Seasonal = input - trend = 10 - 10 = 0
        assert np.all(seasonal == 0)

    def test_prefill_zero_varying_input(self):
        """Prefill with zero, then varying input."""
        input_window = np.arange(WINDOW_SIZE, dtype=np.int8)  # 0, 1, 2, ..., 63
        trend, seasonal = hw_decompose(input_window, prefill_value=0)

        # First trend should be 0 (prefilled sum = 0)
        assert trend[0] == 0

        # Seasonal[0] = 0 - 0 = 0
        assert seasonal[0] == 0


class TestHwMac:
    """Test hw_mac function."""

    def test_simple_dot_product(self):
        """Basic dot product computation."""
        inputs = np.array([1, 2, 3, 4], dtype=np.int8)
        weights = np.array([1, 1, 1, 1], dtype=np.int8)

        result = hw_mac(inputs, weights)
        assert result == 10  # 1+2+3+4

    def test_negative_values(self):
        """Dot product with negative values."""
        inputs = np.array([-5, 10, -3, 8], dtype=np.int8)
        weights = np.array([2, -1, 4, 1], dtype=np.int8)

        # -5*2 + 10*(-1) + (-3)*4 + 8*1 = -10 - 10 - 12 + 8 = -24
        result = hw_mac(inputs, weights)
        assert result == -24

    def test_saturation_positive(self):
        """Result should saturate at Int16 max."""
        inputs = np.full(64, 127, dtype=np.int8)
        weights = np.full(64, 127, dtype=np.int8)

        # 64 * 127 * 127 = 1032256 > 32767
        result = hw_mac(inputs, weights)
        assert result == 32767

    def test_saturation_negative(self):
        """Result should saturate at Int16 min."""
        inputs = np.full(64, 127, dtype=np.int8)
        weights = np.full(64, -128, dtype=np.int8)

        # 64 * 127 * (-128) = -1040384 < -32768
        result = hw_mac(inputs, weights)
        assert result == -32768


class TestHwSaturatingAdd:
    """Test hw_saturating_add function."""

    def test_normal_addition(self):
        """Normal addition without overflow."""
        assert hw_saturating_add(100, 200) == 300
        assert hw_saturating_add(-100, -200) == -300

    def test_positive_saturation(self):
        """Positive overflow should saturate to 32767."""
        assert hw_saturating_add(32000, 1000) == 32767
        assert hw_saturating_add(32767, 1) == 32767

    def test_negative_saturation(self):
        """Negative overflow should saturate to -32768."""
        assert hw_saturating_add(-32000, -1000) == -32768
        assert hw_saturating_add(-32768, -1) == -32768


class TestDLinearHardwareSimulator:
    """Test full DLinear hardware simulation."""

    def test_prefill_state(self):
        """Prefill should initialize all buffers correctly."""
        weights = np.ones(WINDOW_SIZE, dtype=np.int8)
        sim = DLinearHardwareSimulator(weights, weights)

        sim.prefill(10)

        assert sim.is_ready
        assert np.all(sim.trend_window == 10)
        assert np.all(sim.seas_window == 0)

    def test_output_after_prefill(self):
        """Should produce valid output immediately after prefill."""
        weights = np.ones(WINDOW_SIZE, dtype=np.int8)
        sim = DLinearHardwareSimulator(weights, weights)

        sim.prefill(0)

        output, valid = sim.step(10)
        assert valid
        assert output is not None

    def test_consistent_output_stream(self):
        """After prefill, should produce output every cycle."""
        weights = np.ones(WINDOW_SIZE, dtype=np.int8)
        sim = DLinearHardwareSimulator(weights, weights)

        sim.prefill(0)

        valid_count = 0
        for i in range(100):
            output, valid = sim.step(10)
            if valid:
                valid_count += 1

        assert valid_count == 100, "Should produce valid output every cycle after prefill"


class TestBitExactMatch:
    """Integration tests for bit-exact matching."""

    def test_zero_weights_zero_output(self):
        """Zero weights should always produce zero output."""
        input_window = np.random.randint(-128, 127, WINDOW_SIZE, dtype=np.int8)
        zero_weights = np.zeros(WINDOW_SIZE, dtype=np.int8)

        output, trend, seasonal = hw_dlinear_forward(
            input_window, zero_weights, zero_weights, prefill_value=0
        )

        assert output == 0

    def test_reproducibility(self):
        """Same inputs should produce same outputs."""
        input_window = np.random.randint(-128, 127, WINDOW_SIZE, dtype=np.int8)
        weights = np.random.randint(-128, 127, WINDOW_SIZE, dtype=np.int8)

        out1, _, _ = hw_dlinear_forward(input_window, weights, weights, prefill_value=0)
        out2, _, _ = hw_dlinear_forward(input_window, weights, weights, prefill_value=0)

        assert out1 == out2
