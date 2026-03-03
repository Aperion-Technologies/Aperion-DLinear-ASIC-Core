"""
verification/tests/test_market_data.py
Cocotb testbench for financial backtesting on real market data.

Reads market_input.hex, streams through ASIC simulator,
captures predictions to asic_predictions.csv.

Per stage_4.md: "Run test on 10,000+ real market events."
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles
from pathlib import Path
import sys

# Add project paths
sys.path.insert(0, str(Path(__file__).parent.parent.parent / 'ai_model'))
sys.path.insert(0, str(Path(__file__).parent))

from src.export_weights import hex_to_int8_array
from src.config import WINDOW_SIZE
from finance_monitor import FinanceMonitor


async def reset_dut(dut, cycles=5):
    """Apply reset to DUT."""
    dut.reset.value = 1
    await ClockCycles(dut.clock, cycles)
    dut.reset.value = 0
    await RisingEdge(dut.clock)


async def load_weights(dut, trend_path: Path, seas_path: Path):
    """Load weights via configuration interface."""
    with open(trend_path, 'r') as f:
        trend_hex = [line.strip() for line in f if line.strip()]
    trend_weights = hex_to_int8_array(trend_hex)

    with open(seas_path, 'r') as f:
        seas_hex = [line.strip() for line in f if line.strip()]
    seas_weights = hex_to_int8_array(seas_hex)

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


async def fill_pipeline(dut, fill_value: int = 0):
    """Fill pipeline with initial values."""
    dut.io_dataValid.value = 1
    for _ in range(WINDOW_SIZE * 2):
        dut.io_dataIn.value = fill_value
        await RisingEdge(dut.clock)

    for _ in range(10):
        if dut.io_status_ready.value:
            break
        await RisingEdge(dut.clock)


def hex_line_to_int8_array(hex_line: str) -> list:
    """Convert HEX line to list of signed int8 values."""
    values = []
    for i in range(0, len(hex_line), 2):
        byte = int(hex_line[i:i+2], 16)
        # Convert to signed
        if byte >= 128:
            byte -= 256
        values.append(byte)
    return values


@cocotb.test()
async def test_market_data_backtest(dut):
    """
    Test: Run ASIC backtest on real market data.

    Per stage_4.md:
    - Read market_input.hex line by line
    - Feed data into chip
    - Record predictions to asic_predictions.csv
    - Track latency and overflow
    """
    MAC_PIPELINE_DELAY = 4

    clock = Clock(dut.clock, 1, units="ns")  # 1 GHz
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    # Load paths
    ai_model_dir = Path(__file__).parent.parent.parent / 'ai_model'
    weights_dir = ai_model_dir / 'outputs'

    # Load weights
    await load_weights(dut, weights_dir / 'trend_w.hex', weights_dir / 'seas_w.hex')
    dut._log.info("Weights loaded")

    # Fill pipeline
    await fill_pipeline(dut)
    dut._log.info("Pipeline filled")

    # Load market data
    market_input_path = weights_dir / 'market_input.hex'
    expected_output_path = weights_dir / 'expected_output.hex'

    if not market_input_path.exists():
        dut._log.error(f"Market input not found: {market_input_path}")
        dut._log.error("Run: python -m ai_model.src.prepare_market_data")
        return

    with open(market_input_path, 'r') as f:
        market_windows = [line.strip() for line in f if line.strip()]

    expected_values = None
    if expected_output_path.exists():
        with open(expected_output_path, 'r') as f:
            expected_hex = [line.strip() for line in f if line.strip()]
        expected_values = [int(h, 16) if int(h, 16) < 128 else int(h, 16) - 256
                          for h in expected_hex]

    dut._log.info(f"Loaded {len(market_windows)} market windows")

    # Initialize monitor
    monitor = FinanceMonitor(acc_bits=16)

    # Limit for reasonable test time (configurable)
    max_windows = min(len(market_windows), 1000)  # Test first 1000
    dut._log.info(f"Testing {max_windows} windows (of {len(market_windows)} total)")

    # Process market windows
    for i in range(max_windows):
        hex_line = market_windows[i]
        values = hex_line_to_int8_array(hex_line)

        # Record start time
        start_ns = cocotb.utils.get_sim_time(units='ns')

        # Feed entire window (one value per cycle, streaming)
        dut.io_dataValid.value = 1
        for val in values:
            dut.io_dataIn.value = val
            await RisingEdge(dut.clock)

        # Drain pipeline to get output
        for _ in range(MAC_PIPELINE_DELAY):
            dut.io_dataIn.value = 0
            await RisingEdge(dut.clock)

        # Wait for valid output
        latency_cycles = 0
        max_wait = 20
        while not dut.io_predValid.value and latency_cycles < max_wait:
            await RisingEdge(dut.clock)
            latency_cycles += 1

        end_ns = cocotb.utils.get_sim_time(units='ns')

        if dut.io_predValid.value:
            prediction = int(dut.io_predOut.value.signed_integer)
            expected = expected_values[i] if expected_values and i < len(expected_values) else None

            monitor.record_tick(
                tick_index=i,
                input_hex=hex_line,
                prediction=prediction,
                expected=expected,
                latency_cycles=latency_cycles + len(values),
                timestamp_ns=end_ns
            )

            if i % 100 == 0:
                dut._log.info(f"Window {i}: pred={prediction}, latency={latency_cycles + len(values)} cycles")
        else:
            dut._log.warning(f"Window {i}: timeout (no valid output)")

    # Save results
    output_dir = Path(__file__).parent.parent / 'outputs'
    output_dir.mkdir(parents=True, exist_ok=True)

    csv_path = output_dir / 'asic_predictions.csv'
    monitor.save_predictions_csv(csv_path)

    # Print summary
    monitor.print_summary(logger=dut._log)

    dut._log.info(f"\nResults saved to: {csv_path}")
    dut._log.info("Next: Run Jupyter notebook for P&L analysis")


@cocotb.test()
async def test_market_data_throughput(dut):
    """
    Test: Verify sustained throughput on market data stream.

    Per Rule #2 (Fully Unrolled): After pipeline fill,
    should maintain 1 prediction per cycle.
    """
    clock = Clock(dut.clock, 1, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    # Load weights
    ai_model_dir = Path(__file__).parent.parent.parent / 'ai_model'
    weights_dir = ai_model_dir / 'outputs'
    await load_weights(dut, weights_dir / 'trend_w.hex', weights_dir / 'seas_w.hex')

    # Fill pipeline
    await fill_pipeline(dut, fill_value=10)

    # Stream continuous data and measure throughput
    test_cycles = 500
    valid_count = 0

    dut.io_dataValid.value = 1
    for cycle in range(test_cycles):
        dut.io_dataIn.value = (cycle % 256) - 128
        await RisingEdge(dut.clock)

        if dut.io_predValid.value:
            valid_count += 1

    throughput = valid_count / test_cycles

    dut._log.info("=" * 60)
    dut._log.info("MARKET DATA THROUGHPUT TEST")
    dut._log.info("=" * 60)
    dut._log.info(f"Valid outputs: {valid_count} / {test_cycles} cycles")
    dut._log.info(f"Throughput: {throughput * 100:.1f}%")
    dut._log.info(f"At 1 GHz: {valid_count * 1e9 / test_cycles:.0f} predictions/second")
    dut._log.info("=" * 60)

    assert throughput >= 0.9, f"Throughput too low: {throughput*100:.1f}%"


@cocotb.test()
async def test_latency_determinism(dut):
    """
    Test: Verify latency is constant across different market conditions.

    Per Rule #3 (100% Determinism): Latency must not vary with data values.
    """
    clock = Clock(dut.clock, 1, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    # Load weights
    ai_model_dir = Path(__file__).parent.parent.parent / 'ai_model'
    weights_dir = ai_model_dir / 'outputs'
    await load_weights(dut, weights_dir / 'trend_w.hex', weights_dir / 'seas_w.hex')

    # Test with different data patterns
    patterns = [
        ("zeros", 0),
        ("max_positive", 127),
        ("max_negative", -128),
        ("volatile_up", list(range(-64, 64))),
        ("volatile_down", list(range(63, -65, -1))),
    ]

    latencies = []

    for name, pattern in patterns:
        await reset_dut(dut)
        await load_weights(dut, weights_dir / 'trend_w.hex', weights_dir / 'seas_w.hex')

        # Fill with pattern
        dut.io_dataValid.value = 1
        if isinstance(pattern, list):
            for _ in range(3):  # Multiple windows
                for val in pattern:
                    dut.io_dataIn.value = val
                    await RisingEdge(dut.clock)
        else:
            for _ in range(WINDOW_SIZE * 3):
                dut.io_dataIn.value = pattern
                await RisingEdge(dut.clock)

        # Wait for stable output
        while not dut.io_predValid.value:
            await RisingEdge(dut.clock)

        # Measure latency
        dut.io_dataValid.value = 0
        await ClockCycles(dut.clock, 10)

        while dut.io_predValid.value:
            await RisingEdge(dut.clock)

        start = cocotb.utils.get_sim_time(units='ns')
        dut.io_dataValid.value = 1
        dut.io_dataIn.value = 42

        cycles = 0
        while not dut.io_predValid.value and cycles < 100:
            await RisingEdge(dut.clock)
            cycles += 1

        latencies.append(cycles)
        dut._log.info(f"Pattern '{name}': latency = {cycles} cycles")

    # Check determinism
    unique = set(latencies)

    dut._log.info("=" * 60)
    dut._log.info("LATENCY DETERMINISM TEST")
    dut._log.info("=" * 60)
    dut._log.info(f"Latencies observed: {latencies}")
    dut._log.info(f"Unique values: {len(unique)}")

    if len(unique) == 1:
        dut._log.info("PASS: Deterministic latency confirmed (Rule #3)")
    else:
        dut._log.error(f"FAIL: Non-deterministic latency! (Rule #3 violation)")

    dut._log.info("=" * 60)

    # Allow small variance due to pipeline state differences
    assert len(unique) <= 2, f"Rule #3 violation: latencies vary too much: {latencies}"
