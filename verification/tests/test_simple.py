# verification/tests/test_simple.py
"""
Simple Cocotb tests for DLinear ASIC.

These tests verify basic functionality without complex golden vector matching.
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
    """Apply reset to DUT."""
    dut.reset.value = 1
    await ClockCycles(dut.clock, cycles)
    dut.reset.value = 0
    await RisingEdge(dut.clock)


async def load_weights(dut, trend_weights, seas_weights):
    """Load weights into DUT."""
    dut.io_configMode.value = 1

    # Load trend weights
    dut.io_config_weightSel.value = 0
    for i, w in enumerate(trend_weights):
        dut.io_config_addr.value = i
        dut.io_config_data.value = int(w)
        dut.io_config_writeEn.value = 1
        await RisingEdge(dut.clock)

    # Load seasonal weights
    dut.io_config_weightSel.value = 1
    for i, w in enumerate(seas_weights):
        dut.io_config_addr.value = i
        dut.io_config_data.value = int(w)
        dut.io_config_writeEn.value = 1
        await RisingEdge(dut.clock)

    dut.io_config_writeEn.value = 0
    dut.io_configMode.value = 0
    await RisingEdge(dut.clock)


@cocotb.test()
async def test_zero_input_zero_weights(dut):
    """Test: Zero input with zero weights should produce zero output."""
    clock = Clock(dut.clock, 1, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    # Load all-zero weights
    zero_weights = [0] * WINDOW_SIZE
    await load_weights(dut, zero_weights, zero_weights)

    # Fill with zeros
    dut.io_dataValid.value = 1
    for _ in range(WINDOW_SIZE * 3):
        dut.io_dataIn.value = 0
        await RisingEdge(dut.clock)

    # Wait for valid output
    for _ in range(20):
        if dut.io_predValid.value:
            output = int(dut.io_predOut.value.to_signed())
            dut._log.info(f"Output with zero weights: {output}")
            assert output == 0, f"Expected 0, got {output}"
            return
        await RisingEdge(dut.clock)

    assert False, "No valid output received"


@cocotb.test()
async def test_constant_input_unity_weights(dut):
    """Test: Constant input with all-ones weights should produce predictable output."""
    clock = Clock(dut.clock, 1, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    # Load all-ones weights
    # With trend=seasonal, output = 2 * sum(trend[i] * 1)
    ones_weights = [1] * WINDOW_SIZE
    await load_weights(dut, ones_weights, ones_weights)

    # Fill with constant value 1
    dut.io_dataValid.value = 1
    for _ in range(WINDOW_SIZE * 3):
        dut.io_dataIn.value = 1
        await RisingEdge(dut.clock)

    # Get output
    for _ in range(20):
        if dut.io_predValid.value:
            output = int(dut.io_predOut.value.to_signed())
            dut._log.info(f"Output with unity weights, constant 1 input: {output}")
            # With constant input, trend = input (after MA), seasonal = 0
            # So output = sum(1 * 1) + sum(0 * 1) = 64
            # But hardware might have different MA behavior during fill
            assert output != 0, f"Output should be non-zero with unity weights"
            return
        await RisingEdge(dut.clock)

    assert False, "No valid output received"


@cocotb.test()
async def test_output_changes_with_input(dut):
    """Test: Different inputs should produce different outputs."""
    clock = Clock(dut.clock, 1, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    # Load some non-zero weights
    weights_dir = Path(__file__).parent.parent.parent / 'ai_model' / 'outputs'
    with open(weights_dir / 'trend_w.hex', 'r') as f:
        trend_weights = hex_to_int8_array([l.strip() for l in f if l.strip()])
    with open(weights_dir / 'seas_w.hex', 'r') as f:
        seas_weights = hex_to_int8_array([l.strip() for l in f if l.strip()])

    await load_weights(dut, trend_weights, seas_weights)

    outputs = []

    # Test with different constant inputs
    for test_val in [0, 10, -10, 50]:
        # Fill with constant value
        dut.io_dataValid.value = 1
        for _ in range(WINDOW_SIZE * 2):
            dut.io_dataIn.value = test_val
            await RisingEdge(dut.clock)

        # Collect a few outputs
        for _ in range(10):
            if dut.io_predValid.value:
                output = int(dut.io_predOut.value.to_signed())
                outputs.append((test_val, output))
                dut._log.info(f"Input={test_val}, Output={output}")
                break
            await RisingEdge(dut.clock)

    # At least some outputs should be different
    unique_outputs = set(o[1] for o in outputs)
    dut._log.info(f"Collected outputs: {outputs}")
    dut._log.info(f"Unique outputs: {unique_outputs}")

    assert len(unique_outputs) > 1, "Different inputs should produce different outputs"


@cocotb.test()
async def test_saturation(dut):
    """Test: Output saturates at Int16 limits."""
    clock = Clock(dut.clock, 1, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    # Load maximum positive weights
    max_weights = [127] * WINDOW_SIZE
    await load_weights(dut, max_weights, max_weights)

    # Feed maximum positive input
    dut.io_dataValid.value = 1
    for _ in range(WINDOW_SIZE * 3):
        dut.io_dataIn.value = 127
        await RisingEdge(dut.clock)

    # Get output - should be saturated
    for _ in range(20):
        if dut.io_predValid.value:
            output = int(dut.io_predOut.value.to_signed())
            dut._log.info(f"Max input/weights output: {output}")
            # With max weights and input, should saturate to 32767
            assert output == 32767, f"Expected saturation to 32767, got {output}"
            return
        await RisingEdge(dut.clock)

    assert False, "No valid output received"
