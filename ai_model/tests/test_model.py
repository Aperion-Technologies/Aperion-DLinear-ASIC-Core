# ai_model/tests/test_model.py
"""Tests for quantized DLinear model."""

import pytest
import torch
import numpy as np
from src.model import QuantDLinear
from src.config import WINDOW_SIZE, WEIGHT_BITS, ACTIVATION_BITS


class TestQuantDLinear:
    """Test DLinear model structure and forward pass."""

    @pytest.fixture
    def model(self):
        """Create a fresh model instance."""
        return QuantDLinear(
            window_size=WINDOW_SIZE,
            weight_bits=WEIGHT_BITS,
            act_bits=ACTIVATION_BITS
        )

    def test_model_creation(self, model):
        """Model should instantiate without errors."""
        assert model is not None

    def test_forward_shape(self, model):
        """Forward pass should return correct shape."""
        batch_size = 4
        x = torch.randn(batch_size, WINDOW_SIZE)
        output = model(x)
        assert output.shape == (batch_size, 1)

    def test_decomposition(self, model):
        """Trend + Seasonal should approximately equal input mean."""
        x = torch.randn(1, WINDOW_SIZE)
        trend, seasonal = model.decompose(x)

        # Trend is moving average, seasonal is residual
        reconstructed = trend + seasonal
        # Should be close to original (within numerical tolerance)
        assert torch.allclose(reconstructed, x, atol=1e-5)

    def test_trend_is_moving_average(self, model):
        """Trend should be the moving average of input."""
        # Constant input should give same constant as trend
        x = torch.ones(1, WINDOW_SIZE) * 42.0
        trend, _ = model.decompose(x)
        assert torch.allclose(trend, x, atol=1e-5)

    def test_weights_are_quantized(self, model):
        """After training, weights should be quantizable to int8."""
        # Access quantized weight from Brevitas layer
        trend_weight = model.trend_head.quant_weight()
        assert trend_weight.bit_width == WEIGHT_BITS
