# ai_model/src/hw_simulation.py
"""
Bit-exact hardware simulation for golden reference generation.

This module simulates the EXACT computation performed by the Chisel hardware,
ensuring bit-for-bit match between Python and RTL.

The key insight: Hardware uses Brevitas integer weights directly,
so we must compute: sum(input_q * brevitas_weight_int) with saturation.

CRITICAL: This simulation must match hardware timing exactly:
- Hardware computes trend from CURRENT running_sum (before update)
- Hardware updates running_sum on the NEXT clock edge (registered)
- Buffer subtracts oldest value AFTER buffer is filled (fill_count >= MA_WINDOW)
"""

import numpy as np
from typing import Tuple, Optional
from .config import WINDOW_SIZE, MA_WINDOW, FRAC_BITS, ACCUMULATOR_BITS


class MovingAverageSimulator:
    """
    Stateful simulator for hardware MovingAverageUnit.

    Matches hardware timing exactly:
    - trend is computed from running_sum BEFORE adding current input
    - running_sum is updated AFTER (registered in hardware)
    - Buffer subtracts oldest only when filled
    """

    def __init__(self, window_size: int = MA_WINDOW, data_bits: int = 8):
        self.window_size = window_size
        self.ma_shift = int(np.log2(window_size))
        self.data_bits = data_bits

        # State (matches hardware registers)
        self.buffer = np.zeros(window_size, dtype=np.int32)
        self.running_sum = 0
        self.fill_count = 0

    def reset(self):
        """Reset to initial state."""
        self.buffer = np.zeros(self.window_size, dtype=np.int32)
        self.running_sum = 0
        self.fill_count = 0

    def prefill(self, value: int):
        """
        Prefill buffer with a constant value (matches test fill_pipeline).

        Args:
            value: Int8 value to fill buffer with
        """
        self.buffer = np.full(self.window_size, value, dtype=np.int32)
        self.running_sum = value * self.window_size
        self.fill_count = self.window_size

    @property
    def is_filled(self) -> bool:
        return self.fill_count >= self.window_size

    def step(self, input_val: int) -> Tuple[int, int]:
        """
        Process one input value (one clock cycle).

        CRITICAL TIMING (matches hardware):
        1. Compute trend from CURRENT running_sum (combinational)
        2. Compute seasonal from input and trend (combinational)
        3. Update running_sum for NEXT cycle (registered)

        Args:
            input_val: Int8 input value

        Returns:
            trend: Int8 trend value
            seasonal: Int8 seasonal value
        """
        # Step 1: Compute trend from CURRENT state (before update)
        # Hardware: val trend = (runningSum >> shiftBits).asSInt
        #           io.trend := trend(dataBits - 1, 0).asSInt
        # This is a TRUNCATION to 8 bits, NOT saturation!
        trend_raw = self.running_sum >> self.ma_shift

        # Truncate to 8 bits (two's complement wrap, matching hardware)
        # This matches: trend(dataBits - 1, 0).asSInt
        trend = np.int8(trend_raw & 0xFF)  # Mask to 8 bits, interpret as signed

        # Step 2: Compute seasonal (combinational)
        # Hardware: io.seasonal := io.in - io.trend
        # This is also truncation, not saturation
        seasonal_raw = input_val - int(trend)
        seasonal = np.int8(seasonal_raw & 0xFF)  # Truncate to 8 bits

        # Step 3: Update state for NEXT cycle (registered in hardware)
        oldest = self.buffer[self.window_size - 1] if self.is_filled else 0

        # Shift buffer (newest at index 0, oldest at index window_size-1)
        # Hardware: shiftReg(i) := shiftReg(i-1), shiftReg(0) := io.in
        self.buffer = np.roll(self.buffer, 1)
        self.buffer[0] = input_val

        # Update running sum
        if self.is_filled:
            self.running_sum = self.running_sum + input_val - oldest
        else:
            self.running_sum = self.running_sum + input_val
            self.fill_count += 1

        return trend, seasonal


def hw_decompose(
    input_window: np.ndarray,
    prefill_value: Optional[int] = None
) -> Tuple[np.ndarray, np.ndarray]:
    """
    Simulate hardware MovingAverageUnit decomposition.

    Hardware computes:
    - trend = running_sum >> MA_SHIFT (bit-shift division)
    - seasonal = input - trend

    CRITICAL: Matches hardware timing where trend uses OLD running_sum.

    Args:
        input_window: Int8 array of WINDOW_SIZE values
        prefill_value: If set, prefill buffer with this value (matches test setup)

    Returns:
        trend: Int8 array (moving average)
        seasonal: Int8 array (residual)
    """
    sim = MovingAverageSimulator(MA_WINDOW)

    if prefill_value is not None:
        sim.prefill(prefill_value)

    trend = np.zeros(len(input_window), dtype=np.int32)
    seasonal = np.zeros(len(input_window), dtype=np.int32)

    for i, val in enumerate(input_window):
        t, s = sim.step(int(val))
        trend[i] = t
        seasonal[i] = s

    return trend.astype(np.int8), seasonal.astype(np.int8)


def hw_mac(inputs: np.ndarray, weights: np.ndarray) -> int:
    """
    Simulate hardware ParallelMAC operation.

    Hardware computes: sum(inputs[i] * weights[i]) with saturation to ACCUMULATOR_BITS.

    Args:
        inputs: Int8 input values
        weights: Int8 weight values (from Brevitas)

    Returns:
        Saturated result (ACCUMULATOR_BITS width)
    """
    # Widen to int64 for multiplication to handle larger accumulators
    products = inputs.astype(np.int64) * weights.astype(np.int64)
    acc = int(np.sum(products))

    # Saturate to ACCUMULATOR_BITS
    max_val = (1 << (ACCUMULATOR_BITS - 1)) - 1   # e.g., 8388607 for 24-bit
    min_val = -(1 << (ACCUMULATOR_BITS - 1))      # e.g., -8388608 for 24-bit
    if acc > max_val:
        return max_val
    elif acc < min_val:
        return min_val
    return acc


def hw_saturating_add(a: int, b: int) -> int:
    """
    Simulate hardware SaturatingAdder.

    Args:
        a: ACCUMULATOR_BITS value
        b: ACCUMULATOR_BITS value

    Returns:
        Saturated sum (ACCUMULATOR_BITS width)
    """
    result = a + b
    max_val = (1 << (ACCUMULATOR_BITS - 1)) - 1   # e.g., 8388607 for 24-bit
    min_val = -(1 << (ACCUMULATOR_BITS - 1))      # e.g., -8388608 for 24-bit
    if result > max_val:
        return max_val
    elif result < min_val:
        return min_val
    return result


def hw_dlinear_forward(
    input_window: np.ndarray,
    trend_weights: np.ndarray,
    seas_weights: np.ndarray,
    prefill_value: Optional[int] = None
) -> Tuple[int, np.ndarray, np.ndarray]:
    """
    Simulate complete DLinearTop forward pass.

    CRITICAL HARDWARE TIMING:
    In hardware, window registers update on clock edge AFTER MAC reads them.
    When feeding input[N], MAC sees window containing decomp from inputs 0..N-1.

    For a 64-input window:
    - On cycle 64 (feeding input[63]), MAC sees: [trend[62], ..., trend[0], prefill]
    - Window updates at end of cycle 64: [trend[63], ..., trend[0]]

    The "final" output (when test stops feeding) comes from cycle 64, which
    used window with only 63 real decomposition values.

    For the golden reference, we need the output after ALL 64 inputs have
    been incorporated. This happens on cycle 65 (if we feed one more value).
    Since we want a self-contained computation, we compute MAC on the
    fully-populated window (all 64 decomposition values).

    Args:
        input_window: Int8[WINDOW_SIZE] input data
        trend_weights: Int8[WINDOW_SIZE] trend head weights
        seas_weights: Int8[WINDOW_SIZE] seasonal head weights
        prefill_value: If set, prefill decomposition buffer (matches test setup)

    Returns:
        output: Int16 prediction
        trend: Int8[WINDOW_SIZE] intermediate trend values (chronological order)
        seasonal: Int8[WINDOW_SIZE] intermediate seasonal values (chronological order)
    """
    # Stage 1: Decomposition of all inputs
    trend, seasonal = hw_decompose(input_window, prefill_value=prefill_value)

    # Stage 2: Build window state with ALL 64 decomposition values
    # Window ordering: newest at index 0, oldest at index 63
    # window[0] = trend[63] (decomp from last input)
    # window[63] = trend[0] (decomp from first input)
    trend_window = trend[::-1]
    seasonal_window = seasonal[::-1]

    # Stage 3: Parallel MAC on complete window
    trend_pred = hw_mac(trend_window, trend_weights)
    seas_pred = hw_mac(seasonal_window, seas_weights)

    # Stage 4: Output fusion
    output = hw_saturating_add(trend_pred, seas_pred)

    return output, trend, seasonal


def simulate_hardware_output(
    input_float: np.ndarray,
    trend_weights: np.ndarray,
    seas_weights: np.ndarray,
    input_scale: float = None,
    prefill_value: Optional[int] = None
) -> Tuple[int, np.ndarray, np.ndarray]:
    """
    Convert float input to fixed-point and simulate hardware.

    This simulates the EXACT hardware behavior including pipeline timing.
    Uses the streaming DLinearHardwareSimulator to match test behavior.

    Args:
        input_float: Float32 input data (normalized)
        trend_weights: Int8 Brevitas weights
        seas_weights: Int8 Brevitas weights
        input_scale: Optional custom input scale (default: 2^FRAC_BITS)
        prefill_value: If set, prefill decomposition buffer (matches test setup)

    Returns:
        output: Int16 hardware prediction
        trend: Int8 intermediate trend
        seasonal: Int8 intermediate seasonal
    """
    if input_scale is None:
        input_scale = 2 ** FRAC_BITS

    # Quantize input to Int8 (matching hardware input interface)
    input_q = np.round(input_float * input_scale)
    input_q = np.clip(input_q, -128, 127).astype(np.int8)

    # Use streaming simulation for exact hardware matching
    return simulate_streaming_output(
        input_q, trend_weights, seas_weights, prefill_value=prefill_value
    )


def simulate_streaming_output(
    input_window: np.ndarray,
    trend_weights: np.ndarray,
    seas_weights: np.ndarray,
    prefill_value: Optional[int] = None,
    drain_cycles: int = 8
) -> Tuple[int, np.ndarray, np.ndarray]:
    """
    Simulate hardware output using streaming (cycle-by-cycle) computation.

    This exactly matches the test behavior:
    1. Prefill with zeros (or specified value)
    2. Feed all inputs from window
    3. Feed drain cycles (zeros) to flush MAC pipeline
    4. Return output from MAC computed on the complete window

    The MAC pipeline has ~3 cycles of latency. After feeding all 64 inputs,
    the window contains all 64 decomposition values. The drain cycles
    trigger MAC on this complete window, and we capture that output.

    Args:
        input_window: Int8[WINDOW_SIZE] input data
        trend_weights: Int8[WINDOW_SIZE] weights
        seas_weights: Int8[WINDOW_SIZE] weights
        prefill_value: Prefill value (default 0)
        drain_cycles: Number of drain cycles after inputs (default 4)

    Returns:
        output: Int16 prediction (from MAC on complete window)
        trend: Int8[WINDOW_SIZE] trend values
        seasonal: Int8[WINDOW_SIZE] seasonal values
    """
    sim = DLinearHardwareSimulator(trend_weights, seas_weights)

    if prefill_value is not None:
        sim.prefill(prefill_value)
    else:
        sim.prefill(0)

    # Collect decomposition values for reference
    trends = []
    seasonals = []
    outputs = []

    # Feed all inputs
    for val in input_window:
        output, valid = sim.step(int(val))
        # Capture decomposition from the simulator's internal state
        trends.append(sim.decomp.buffer[0])  # Most recent value in MA buffer
        seasonals.append(int(val) - (sim.decomp.running_sum >> sim.decomp.ma_shift))
        if valid:
            outputs.append(output)

    # Get actual decomposition using hw_decompose for consistency
    trend_arr, seasonal_arr = hw_decompose(input_window, prefill_value=prefill_value if prefill_value else 0)

    # Feed drain cycles to get the MAC output for the complete window
    # Step 64 (last input): MAC computed on window with trends 0-62
    # Step 65 (first drain): MAC computed on window with ALL 64 trends
    # Due to MAC_PIPELINE_DELAY=3, step 65's output appears at step 68
    for _ in range(drain_cycles):
        output, valid = sim.step(0)
        if valid:
            outputs.append(output)

    # The output we want is from step 65's MAC (first drain), which has all 64 trends
    # With MAC_PIPELINE_DELAY=3, this appears 3 steps later
    # So we need outputs[65 + 3 - 1] = outputs[67] when indexing from 0
    # This equals outputs[-1] after 64+4=68 steps
    target_output = outputs[-1] if outputs else 0

    return target_output, trend_arr, seasonal_arr


# =============================================================================
# Streaming simulation for test synchronization
# =============================================================================

class DLinearHardwareSimulator:
    """
    Full stateful simulation of DLinearTop hardware.

    Use this for test synchronization where you need to track state
    across multiple input windows.

    IMPORTANT: Models the MAC pipeline delay (default 3 cycles) to match
    actual hardware timing. Output from step N appears at step N+pipeline_delay.
    """

    MAC_PIPELINE_DELAY = 6  # LinearLayer (4) + fusion (1) + margin (1)

    def __init__(
        self,
        trend_weights: np.ndarray,
        seas_weights: np.ndarray,
        window_size: int = WINDOW_SIZE
    ):
        self.trend_weights = trend_weights.astype(np.int8)
        self.seas_weights = seas_weights.astype(np.int8)
        self.window_size = window_size

        # Decomposition stage
        self.decomp = MovingAverageSimulator(window_size)

        # Window buffers for MAC (stores trend/seasonal values)
        self.trend_window = np.zeros(window_size, dtype=np.int8)
        self.seas_window = np.zeros(window_size, dtype=np.int8)
        self.window_fill_count = 0

        # MAC pipeline simulation (FIFO of outputs in flight)
        self.mac_pipeline = []
        self.pipeline_valid = []

    def reset(self):
        """Reset all state."""
        self.decomp.reset()
        self.trend_window = np.zeros(self.window_size, dtype=np.int8)
        self.seas_window = np.zeros(self.window_size, dtype=np.int8)
        self.window_fill_count = 0
        self.mac_pipeline = []
        self.pipeline_valid = []

    def prefill(self, value: int):
        """Prefill all buffers (matches test fill_pipeline)."""
        self.decomp.prefill(value)

        # After decomposition prefill, trend=value, seasonal=0
        prefill_trend = value  # MA of constant = constant
        prefill_seasonal = 0   # value - value = 0

        self.trend_window = np.full(self.window_size, prefill_trend, dtype=np.int8)
        self.seas_window = np.full(self.window_size, prefill_seasonal, dtype=np.int8)
        self.window_fill_count = self.window_size

        # Prime the pipeline with prefill outputs (zeros)
        prefill_output = hw_saturating_add(
            hw_mac(self.trend_window, self.trend_weights),
            hw_mac(self.seas_window, self.seas_weights)
        )
        self.mac_pipeline = [prefill_output] * self.MAC_PIPELINE_DELAY
        self.pipeline_valid = [True] * self.MAC_PIPELINE_DELAY

    @property
    def is_ready(self) -> bool:
        """Hardware ready signal: both decomp and window buffers filled."""
        return self.decomp.is_filled and self.window_fill_count >= self.window_size

    def step(self, input_val: int) -> Tuple[Optional[int], bool]:
        """
        Process one input value (one clock cycle).

        CRITICAL TIMING (matches hardware exactly):
        1. Decomposition computes trend/seasonal combinationally
        2. MAC reads CURRENT window values (before update)
        3. MAC result enters pipeline (3-cycle delay)
        4. Window registers update at clock edge (for next cycle)
        5. Output is the MAC result from 3 cycles ago

        Args:
            input_val: Int8 input value

        Returns:
            output: Int16 prediction (or None if not ready)
            valid: True if output is valid
        """
        # Stage 1: Decomposition (combinational in hardware)
        trend, seasonal = self.decomp.step(input_val)

        # Stage 2: Compute MAC on CURRENT window (before update)
        mac_valid = self.is_ready
        if mac_valid:
            trend_pred = hw_mac(self.trend_window, self.trend_weights)
            seas_pred = hw_mac(self.seas_window, self.seas_weights)
            mac_result = hw_saturating_add(trend_pred, seas_pred)
        else:
            mac_result = 0

        # Stage 3: Push MAC result into pipeline
        self.mac_pipeline.append(mac_result)
        self.pipeline_valid.append(mac_valid)

        # Stage 4: Pop output from pipeline (delayed by MAC_PIPELINE_DELAY)
        if len(self.mac_pipeline) > self.MAC_PIPELINE_DELAY:
            output = self.mac_pipeline.pop(0)
            valid = self.pipeline_valid.pop(0)
        else:
            output = None
            valid = False

        # Stage 5: Update window for NEXT cycle (register writes in HW)
        self.trend_window = np.roll(self.trend_window, 1)
        self.trend_window[0] = trend

        self.seas_window = np.roll(self.seas_window, 1)
        self.seas_window[0] = seasonal

        if self.window_fill_count < self.window_size:
            self.window_fill_count += 1

        return output, valid
