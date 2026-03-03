# ai_model/src/model.py
"""
Quantized DLinear model for ASIC deployment.

Architecture:
1. Decomposition: Split input into Trend (moving average) and Seasonal (residual)
2. Linear Projection: Apply separate quantized linear layers to each component
3. Output Fusion: Sum predictions with saturation

CRITICAL: All operations must have bit-exact hardware equivalents.
"""

import torch
import torch.nn as nn
import brevitas.nn as qnn
from brevitas.quant import Int8WeightPerTensorFloat, Int8ActPerTensorFloat

from .config import WINDOW_SIZE, MA_WINDOW, WEIGHT_BITS, ACTIVATION_BITS


class MovingAverageDecomposition(nn.Module):
    """
    Decompose input into Trend and Seasonal components.

    Trend = Moving Average over MA_WINDOW
    Seasonal = Input - Trend

    Hardware equivalent: ShiftRegister + Adders + BitShift (no division)
    """

    def __init__(self, window_size: int = WINDOW_SIZE, ma_window: int = MA_WINDOW):
        super().__init__()
        self.window_size = window_size
        self.ma_window = ma_window

        # Verify MA window is power of 2 for hardware bit-shift division
        assert (ma_window & (ma_window - 1)) == 0, \
            f"MA window must be power of 2, got {ma_window}"

        # Create averaging kernel (uniform weights)
        # In hardware this is sum + bit-shift, not actual division
        kernel = torch.ones(1, 1, ma_window) / ma_window
        self.register_buffer('kernel', kernel)

    def forward(self, x: torch.Tensor) -> tuple[torch.Tensor, torch.Tensor]:
        """
        Decompose input sequence.

        Args:
            x: Input tensor of shape (batch, window_size)

        Returns:
            trend: Moving average, shape (batch, window_size)
            seasonal: Residual (x - trend), shape (batch, window_size)
        """
        batch_size = x.shape[0]

        # Pad for valid convolution to maintain size
        # Replicate padding at start (causal)
        padded = nn.functional.pad(
            x.unsqueeze(1),  # (batch, 1, window_size)
            (self.ma_window - 1, 0),  # left padding only
            mode='replicate'
        )

        # Compute moving average via 1D convolution
        trend = nn.functional.conv1d(padded, self.kernel)
        trend = trend.squeeze(1)  # (batch, window_size)

        # Seasonal is residual
        seasonal = x - trend

        return trend, seasonal


class QuantDLinear(nn.Module):
    """
    Quantized DLinear for HFT ASIC deployment.

    Fully unrolled architecture:
    - 64 multipliers for trend head
    - 64 multipliers for seasonal head
    - 128 total parallel MAC units
    """

    def __init__(
        self,
        window_size: int = WINDOW_SIZE,
        weight_bits: int = WEIGHT_BITS,
        act_bits: int = ACTIVATION_BITS
    ):
        super().__init__()
        self.window_size = window_size

        # Decomposition block
        self.decomp = MovingAverageDecomposition(window_size=window_size)

        # Quantized linear heads
        # Input: window_size features -> Output: 1 prediction
        self.trend_head = qnn.QuantLinear(
            in_features=window_size,
            out_features=1,
            bias=False,  # No bias for simpler hardware
            weight_bit_width=weight_bits,
            weight_quant=Int8WeightPerTensorFloat
        )

        self.seasonal_head = qnn.QuantLinear(
            in_features=window_size,
            out_features=1,
            bias=False,
            weight_bit_width=weight_bits,
            weight_quant=Int8WeightPerTensorFloat
        )

        # Quantized activation for inputs to linear layers
        self.quant_act = qnn.QuantIdentity(
            bit_width=act_bits,
            act_quant=Int8ActPerTensorFloat
        )

    def decompose(self, x: torch.Tensor) -> tuple[torch.Tensor, torch.Tensor]:
        """Expose decomposition for testing."""
        return self.decomp(x)

    def forward(self, x: torch.Tensor) -> torch.Tensor:
        """
        Forward pass through DLinear.

        Args:
            x: Input price window, shape (batch, window_size)

        Returns:
            Prediction for next tick, shape (batch, 1)
        """
        # Decompose into trend and seasonal
        trend, seasonal = self.decomp(x)

        # Quantize activations before linear projection
        trend_q = self.quant_act(trend)
        seasonal_q = self.quant_act(seasonal)

        # Parallel linear projections (in hardware: 128 MAC units)
        trend_pred = self.trend_head(trend_q)
        seasonal_pred = self.seasonal_head(seasonal_q)

        # Output fusion (saturating add in hardware)
        output = trend_pred + seasonal_pred

        return output

    def get_quantized_weights(self) -> dict:
        """
        Extract quantized weights as integer tensors.

        Returns:
            Dict with 'trend_w' and 'seas_w' as int8 numpy arrays
        """
        trend_qw = self.trend_head.quant_weight()
        seas_qw = self.seasonal_head.quant_weight()

        return {
            'trend_w': trend_qw.int().detach().cpu().numpy().astype('int8'),
            'seas_w': seas_qw.int().detach().cpu().numpy().astype('int8'),
            'trend_scale': float(trend_qw.scale.detach().cpu()),
            'seas_scale': float(seas_qw.scale.detach().cpu())
        }
