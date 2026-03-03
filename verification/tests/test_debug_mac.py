# verification/tests/test_debug_mac.py
"""
Debug test to isolate bit-exact mismatch issue.
Tests individual components to find the discrepancy.
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).parent.parent.parent / 'ai_model'))

from src.export_weights import hex_to_int8_array
from src.config import WINDOW_SIZE


async def reset_dut(dut, cycles=5):
    """Apply reset."""
    dut.reset.value = 1
    await ClockCycles(dut.clock, cycles)
    dut.reset.value = 0
    await RisingEdge(dut.clock)


async def load_weights_simple(dut, trend_weights, seas_weights):
    """Load weights with debug output."""
    dut.io_configMode.value = 1

    # Load trend weights
    dut.io_config_weightSel.value = 0
    for i, w in enumerate(trend_weights):
        dut.io_config_addr.value = i
        # Convert int8 to proper signed value for hardware
        dut.io_config_data.value = int(w)
        dut.io_config_writeEn.value = 1
        await RisingEdge(dut.clock)

        if i < 3:
            dut._log.info(f"Loaded trend[{i}] = {w} (Python int8)")

    # Load seasonal weights
    dut.io_config_weightSel.value = 1
    for i, w in enumerate(seas_weights):
        dut.io_config_addr.value = i
        dut.io_config_data.value = int(w)
        dut.io_config_writeEn.value = 1
        await RisingEdge(dut.clock)

        if i < 3:
            dut._log.info(f"Loaded seas[{i}] = {w} (Python int8)")

    dut.io_config_writeEn.value = 0
    dut.io_configMode.value = 0
    await RisingEdge(dut.clock)


@cocotb.test()
async def test_simple_mac_manual(dut):
    """
    Test MAC with manually controlled simple values.

    Feed known inputs, compute expected output manually, compare.
    """
    clock = Clock(dut.clock, 1, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    # Create simple weights: all 1s for easy verification
    # MAC with all-ones weights = sum of inputs
    simple_trend_w = [1] * WINDOW_SIZE
    simple_seas_w = [0] * WINDOW_SIZE  # Zero seasonal weights

    dut._log.info("Loading simple test weights (trend=1, seas=0)")
    await load_weights_simple(dut, simple_trend_w, simple_seas_w)

    # Fill pipeline with zeros
    dut.io_dataValid.value = 1
    for _ in range(WINDOW_SIZE * 2):
        dut.io_dataIn.value = 0
        await RisingEdge(dut.clock)

    # Wait for ready
    for _ in range(10):
        if dut.io_status_ready.value:
            break
        await RisingEdge(dut.clock)

    dut._log.info(f"Ready = {dut.io_status_ready.value}")

    # Now feed simple test pattern: all 1s
    # After WINDOW_SIZE cycles of 1s:
    # - MA running_sum = 64 (sum of 64 ones)
    # - trend = 64 >> 6 = 1
    # - seasonal = 1 - 1 = 0
    # - trendWindow should be all 1s eventually
    # - With trend weights = all 1s, MAC = 64 * 1 = 64

    dut._log.info("Feeding all 1s...")
    for i in range(WINDOW_SIZE):
        dut.io_dataIn.value = 1
        await RisingEdge(dut.clock)

    # Capture outputs for next few cycles (pipeline latency)
    outputs = []
    dut._log.info("Waiting for pipeline output...")
    for i in range(10):
        await RisingEdge(dut.clock)
        if dut.io_predValid.value:
            out = int(dut.io_predOut.value.signed_integer)
            outputs.append((i, out))
            dut._log.info(f"Cycle +{i}: predOut = {out}")

    dut._log.info(f"Collected outputs: {outputs}")

    # After feeding 64 ones into a zero-filled system:
    # The trend window will contain trend values computed as each 1 was fed
    # Since we start with running_sum=0:
    #   input 1: trend = 0>>6 = 0, seasonal = 1-0 = 1
    #   input 2: running_sum = 1, trend = 1>>6 = 0, seasonal = 1
    #   ...
    #   input 64: running_sum = 63, trend = 63>>6 = 0, seasonal = 1
    #   input 65 (first after window): running_sum = 64-0 = 64, trend = 64>>6 = 1

    # So after 64 ones: trendWindow = [0,0,0,...,0], seasWindow = [1,1,1,...,1]
    # MAC with trend weights=1: sum of 64 zeros = 0
    # MAC with seas weights=0: 0
    # Total = 0

    # Wait, but we also need to account for when valid outputs start appearing

    assert len(outputs) > 0, "No valid outputs received"


@cocotb.test()
async def test_weight_sign_verification(dut):
    """
    Verify weights are loaded with correct signs.

    Load a weight with a known negative value and verify MAC behavior.
    """
    clock = Clock(dut.clock, 1, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    # Use weights where only first weight is non-zero
    # trend[0] = -10, rest = 0
    # seas = all 0
    trend_w = [-10] + [0] * (WINDOW_SIZE - 1)
    seas_w = [0] * WINDOW_SIZE

    dut._log.info(f"Loading test weights: trend[0]={trend_w[0]}")
    await load_weights_simple(dut, trend_w, seas_w)

    # Fill pipeline
    dut.io_dataValid.value = 1
    for _ in range(WINDOW_SIZE * 2):
        dut.io_dataIn.value = 0
        await RisingEdge(dut.clock)

    while not dut.io_status_ready.value:
        await RisingEdge(dut.clock)

    # Feed pattern that should produce known trend
    # Feed 127 (max positive) for one cycle, then zeros
    # This creates a spike that we can track

    dut._log.info("Feeding value 127 (once) then zeros")
    dut.io_dataIn.value = 127
    await RisingEdge(dut.clock)

    # Now feed zeros
    for i in range(WINDOW_SIZE + 10):
        dut.io_dataIn.value = 0
        await RisingEdge(dut.clock)

        if dut.io_predValid.value:
            out = int(dut.io_predOut.value.signed_integer)
            dut._log.info(f"Cycle {i}: predOut = {out}")


@cocotb.test()
async def test_compare_python_hw_step_by_step(dut):
    """
    Step-by-step comparison: feed same inputs to Python sim and HW.
    """
    clock = Clock(dut.clock, 1, units="ns")
    cocotb.start_soon(clock.start())

    import numpy as np
    from src.hw_simulation import DLinearHardwareSimulator
    from src.golden_reference import load_golden_vectors

    await reset_dut(dut)

    # Load actual weights
    weights_dir = Path(__file__).parent.parent.parent / 'ai_model' / 'outputs'
    with open(weights_dir / 'trend_w.hex', 'r') as f:
        trend_w = hex_to_int8_array([l.strip() for l in f if l.strip()])
    with open(weights_dir / 'seas_w.hex', 'r') as f:
        seas_w = hex_to_int8_array([l.strip() for l in f if l.strip()])

    await load_weights_simple(dut, trend_w, seas_w)

    # Initialize Python simulator
    py_sim = DLinearHardwareSimulator(trend_w, seas_w)
    py_sim.prefill(0)

    # Fill HW pipeline with zeros (matching py_sim.prefill(0))
    dut.io_dataValid.value = 1
    for _ in range(WINDOW_SIZE * 2):
        dut.io_dataIn.value = 0
        await RisingEdge(dut.clock)

    while not dut.io_status_ready.value:
        await RisingEdge(dut.clock)

    # Load first vector
    vectors = load_golden_vectors(weights_dir / 'golden')
    v0 = vectors[0]

    dut._log.info("=== Step-by-step comparison ===")
    dut._log.info(f"First 5 inputs: {v0.input_window[:5]}")

    # Feed inputs and compare
    hw_outputs = []
    py_outputs = []

    for i, val in enumerate(v0.input_window):
        # Python step
        py_out, py_valid = py_sim.step(int(val))
        if py_valid:
            py_outputs.append(py_out)

        # Hardware step
        dut.io_dataIn.value = int(val)
        await RisingEdge(dut.clock)

        if dut.io_predValid.value:
            hw_out = int(dut.io_predOut.value.signed_integer)
            hw_outputs.append(hw_out)

            # Compare with Python's output at same index
            py_idx = len(py_outputs) - 1 if py_outputs else -1
            py_val = py_outputs[-1] if py_outputs else None

            if i < 5 or i > 60:
                dut._log.info(f"Input {i}: val={val}, HW_out={hw_out}, PY_out={py_val}")

    dut._log.info(f"\nTotal HW outputs: {len(hw_outputs)}")
    dut._log.info(f"Total PY outputs: {len(py_outputs)}")
    dut._log.info(f"Last HW output: {hw_outputs[-1] if hw_outputs else None}")
    dut._log.info(f"Last PY output: {py_outputs[-1] if py_outputs else None}")
    dut._log.info(f"Expected: {v0.expected_output}")

    # Check pipeline alignment - HW might be delayed
    if hw_outputs and py_outputs:
        diff = hw_outputs[-1] - py_outputs[-1]
        dut._log.info(f"HW-PY diff: {diff}")
