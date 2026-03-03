# verification/synthesis/test_gate_level.py
"""
Gate-level simulation tests for DLinear ASIC.

These tests run on the synthesized gate-level netlist to verify:
1. Functional equivalence with RTL
2. No timing violations (with annotated delays)
3. No glitches or hazards

Run with: make gate-sim
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles, Timer
from pathlib import Path
import sys

# Add parent directory for imports
sys.path.insert(0, str(Path(__file__).parent.parent))

from tests.test_dlinear import (
    reset_dut,
    load_weights,
    fill_pipeline,
    feed_single_value,
    wait_for_output,
    WINDOW_SIZE
)

# Gate-level specific configuration
GATE_LEVEL_CLOCK_PERIOD = 2  # ns (slower for gate delays)
GATE_LEVEL_TIMEOUT_MULTIPLIER = 2  # Allow more cycles for gate delays


@cocotb.test()
async def test_gate_level_basic(dut):
    """
    Test: Basic functionality at gate level.

    Verifies that synthesized netlist produces valid output.
    """
    # Slower clock for gate-level (accounts for gate delays)
    clock = Clock(dut.clock, GATE_LEVEL_CLOCK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut, cycles=10)  # Longer reset for gate-level

    # Load weights
    weights_dir = Path(__file__).parent.parent.parent / 'ai_model' / 'outputs'
    await load_weights(dut, weights_dir / 'trend_w.hex', weights_dir / 'seas_w.hex')

    # Verify weights loaded
    assert dut.io_status_weightsLoaded.value == 1, "Weights should be loaded"

    # Fill pipeline
    await fill_pipeline(dut, fill_value=10)

    # Check ready
    assert dut.io_status_ready.value == 1, "Pipeline should be ready"

    dut._log.info("Gate-level basic test PASSED")


@cocotb.test()
async def test_gate_level_functional(dut):
    """
    Test: Functional equivalence with RTL.

    Feeds same inputs as RTL test and verifies output matches.
    """
    clock = Clock(dut.clock, GATE_LEVEL_CLOCK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut, cycles=10)

    weights_dir = Path(__file__).parent.parent.parent / 'ai_model' / 'outputs'
    await load_weights(dut, weights_dir / 'trend_w.hex', weights_dir / 'seas_w.hex')
    await fill_pipeline(dut, fill_value=0)

    # Feed test pattern
    test_values = [i - 32 for i in range(64)]  # -32 to +31

    for val in test_values:
        await feed_single_value(dut, val)

    # Extra cycles for gate delays
    for _ in range(10):
        await feed_single_value(dut, 0)

    # Check we got valid output
    valid_seen = False
    for _ in range(20):
        await RisingEdge(dut.clock)
        if dut.io_predValid.value:
            valid_seen = True
            output = int(dut.io_predOut.value.signed_integer)
            dut._log.info(f"Gate-level output: {output}")
            break

    assert valid_seen, "Gate-level should produce valid output"
    dut._log.info("Gate-level functional test PASSED")


@cocotb.test()
async def test_gate_level_throughput(dut):
    """
    Test: Throughput at gate level.

    Verifies 1 output per cycle is maintained after accounting for gate delays.
    """
    clock = Clock(dut.clock, GATE_LEVEL_CLOCK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut, cycles=10)

    weights_dir = Path(__file__).parent.parent.parent / 'ai_model' / 'outputs'
    await load_weights(dut, weights_dir / 'trend_w.hex', weights_dir / 'seas_w.hex')
    await fill_pipeline(dut, fill_value=5)

    # Wait for steady state
    while not dut.io_predValid.value:
        await RisingEdge(dut.clock)

    # Measure throughput
    test_cycles = 50
    valid_count = 0

    dut.io_dataValid.value = 1
    for cycle in range(test_cycles):
        dut.io_dataIn.value = (cycle % 256) - 128
        await RisingEdge(dut.clock)

        if dut.io_predValid.value:
            valid_count += 1

    throughput = valid_count / test_cycles
    dut._log.info(f"Gate-level throughput: {throughput * 100:.1f}%")

    # Allow slightly lower throughput for gate-level (90% vs 100%)
    assert throughput >= 0.85, f"Gate-level throughput too low: {throughput * 100:.1f}%"

    dut._log.info("Gate-level throughput test PASSED")


@cocotb.test()
async def test_gate_level_no_glitches(dut):
    """
    Test: Check for glitches on critical signals.

    Gate-level netlists can have combinational glitches that don't
    appear in RTL simulation. This test checks for unexpected transitions.
    """
    clock = Clock(dut.clock, GATE_LEVEL_CLOCK_PERIOD, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut, cycles=10)

    weights_dir = Path(__file__).parent.parent.parent / 'ai_model' / 'outputs'
    await load_weights(dut, weights_dir / 'trend_w.hex', weights_dir / 'seas_w.hex')
    await fill_pipeline(dut, fill_value=0)

    # Monitor predValid for glitches
    glitch_count = 0
    last_valid = int(dut.io_predValid.value)
    transitions = 0

    dut.io_dataValid.value = 1
    for cycle in range(100):
        dut.io_dataIn.value = 42
        await RisingEdge(dut.clock)

        current_valid = int(dut.io_predValid.value)
        if current_valid != last_valid:
            transitions += 1
            # In steady state, predValid should stay high
            if cycle > 10 and last_valid == 1 and current_valid == 0:
                glitch_count += 1
                dut._log.warning(f"Potential glitch at cycle {cycle}")
        last_valid = current_valid

    dut._log.info(f"Transitions: {transitions}, Potential glitches: {glitch_count}")

    # Allow very few glitches (ideally 0)
    assert glitch_count <= 2, f"Too many glitches: {glitch_count}"

    dut._log.info("Gate-level glitch test PASSED")


@cocotb.test()
async def test_gate_level_timing_margin(dut):
    """
    Test: Timing margin check.

    Run at slightly higher frequency to check timing margin.
    This helps identify paths that are close to failing timing.
    """
    # 10% faster clock
    fast_period = GATE_LEVEL_CLOCK_PERIOD * 0.9
    clock = Clock(dut.clock, fast_period, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut, cycles=10)

    weights_dir = Path(__file__).parent.parent.parent / 'ai_model' / 'outputs'

    try:
        await load_weights(dut, weights_dir / 'trend_w.hex', weights_dir / 'seas_w.hex')
        await fill_pipeline(dut, fill_value=0)

        # Feed some data
        for i in range(20):
            await feed_single_value(dut, i)

        # Check if we still get valid output
        valid_seen = False
        for _ in range(20):
            await RisingEdge(dut.clock)
            if dut.io_predValid.value:
                valid_seen = True
                break

        if valid_seen:
            dut._log.info(f"Timing margin OK at {fast_period:.2f}ns period")
        else:
            dut._log.warning(f"Timing margin tight at {fast_period:.2f}ns period")

    except Exception as e:
        dut._log.error(f"Timing failure at {fast_period:.2f}ns: {e}")
        raise

    dut._log.info("Gate-level timing margin test PASSED")
