"""
verification/tests/finance_monitor.py
Finance monitoring utilities for ASIC backtesting.

Tracks:
- Per-tick latency (clock cycles from input to output)
- Overflow detection (saturation events)
- Prediction capture for P&L analysis

Per stage_4.md: "Function that counts latency for each real tick
and checks for overflow on real volatility."
"""

import csv
from pathlib import Path
from dataclasses import dataclass, field
from typing import Optional
import numpy as np


@dataclass
class TickResult:
    """Result of processing one market tick."""
    tick_index: int
    input_hex: str
    prediction: int
    expected: Optional[int]
    latency_cycles: int
    overflow_detected: bool
    timestamp_ns: float


@dataclass
class FinanceMonitor:
    """
    Monitor for financial metrics during ASIC backtesting.

    Tracks latency, overflow, and predictions for P&L analysis.
    """

    # Accumulator bit width (for overflow detection)
    acc_bits: int = 16

    # Results storage
    results: list[TickResult] = field(default_factory=list)

    # Running statistics
    total_ticks: int = 0
    overflow_count: int = 0
    latency_sum: int = 0
    latency_max: int = 0
    latency_min: int = 999999

    def record_tick(self, tick_index: int, input_hex: str,
                    prediction: int, expected: Optional[int],
                    latency_cycles: int, timestamp_ns: float) -> TickResult:
        """
        Record results for one tick.

        Args:
            tick_index: Index of this tick in the dataset
            input_hex: Input window as hex string
            prediction: ASIC prediction output (signed int)
            expected: Expected value (if available)
            latency_cycles: Cycles from input to output
            timestamp_ns: Simulation time in nanoseconds

        Returns:
            TickResult with overflow detection
        """
        # Detect overflow (saturation at accumulator limits)
        max_val = 2 ** (self.acc_bits - 1) - 1  # 32767 for 16-bit
        min_val = -(2 ** (self.acc_bits - 1))   # -32768 for 16-bit
        overflow = prediction == max_val or prediction == min_val

        result = TickResult(
            tick_index=tick_index,
            input_hex=input_hex[:16] + "...",  # Truncate for storage
            prediction=prediction,
            expected=expected,
            latency_cycles=latency_cycles,
            overflow_detected=overflow,
            timestamp_ns=timestamp_ns,
        )

        self.results.append(result)

        # Update statistics
        self.total_ticks += 1
        self.latency_sum += latency_cycles
        self.latency_max = max(self.latency_max, latency_cycles)
        self.latency_min = min(self.latency_min, latency_cycles)

        if overflow:
            self.overflow_count += 1

        return result

    @property
    def latency_avg(self) -> float:
        """Average latency in clock cycles."""
        if self.total_ticks == 0:
            return 0.0
        return self.latency_sum / self.total_ticks

    @property
    def overflow_rate(self) -> float:
        """Overflow rate as percentage."""
        if self.total_ticks == 0:
            return 0.0
        return 100.0 * self.overflow_count / self.total_ticks

    def get_predictions(self) -> np.ndarray:
        """Get all predictions as numpy array."""
        return np.array([r.prediction for r in self.results])

    def get_expected(self) -> np.ndarray:
        """Get all expected values as numpy array."""
        return np.array([r.expected for r in self.results if r.expected is not None])

    def get_latencies(self) -> np.ndarray:
        """Get all latencies as numpy array."""
        return np.array([r.latency_cycles for r in self.results])

    def calculate_mse(self) -> Optional[float]:
        """Calculate MSE between predictions and expected values."""
        predictions = self.get_predictions()
        expected = self.get_expected()

        if len(expected) == 0 or len(predictions) != len(expected):
            return None

        return float(np.mean((predictions - expected) ** 2))

    def calculate_correlation(self) -> Optional[float]:
        """Calculate correlation between predictions and expected."""
        predictions = self.get_predictions()
        expected = self.get_expected()

        if len(expected) < 2:
            return None

        # Handle constant arrays
        if np.std(predictions) == 0 or np.std(expected) == 0:
            return 0.0

        return float(np.corrcoef(predictions, expected)[0, 1])

    def save_predictions_csv(self, output_path: Path) -> None:
        """
        Save predictions to CSV for Jupyter analysis.

        Output columns: tick_index, prediction, expected, latency_cycles, overflow
        """
        output_path = Path(output_path)
        output_path.parent.mkdir(parents=True, exist_ok=True)

        with open(output_path, 'w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow([
                'tick_index', 'prediction', 'expected',
                'latency_cycles', 'overflow', 'timestamp_ns'
            ])

            for r in self.results:
                writer.writerow([
                    r.tick_index, r.prediction,
                    r.expected if r.expected is not None else '',
                    r.latency_cycles, int(r.overflow_detected),
                    r.timestamp_ns
                ])

        print(f"Saved {len(self.results)} predictions to {output_path}")

    def print_summary(self, logger=None) -> None:
        """Print summary statistics."""
        log = logger.info if logger else print

        log("=" * 60)
        log("FINANCE MONITOR SUMMARY")
        log("=" * 60)
        log(f"Total Ticks Processed: {self.total_ticks}")
        log(f"Latency (cycles): min={self.latency_min}, avg={self.latency_avg:.2f}, max={self.latency_max}")
        log(f"Latency (ns @ 1GHz): min={self.latency_min}ns, avg={self.latency_avg:.2f}ns, max={self.latency_max}ns")
        log(f"Overflow Events: {self.overflow_count} ({self.overflow_rate:.2f}%)")

        mse = self.calculate_mse()
        corr = self.calculate_correlation()

        if mse is not None:
            log(f"MSE (vs expected): {mse:.4f}")
        if corr is not None:
            log(f"Correlation: {corr:.4f}")

        log("=" * 60)

        # HFT compliance check
        if self.latency_max > self.latency_min:
            log(f"WARNING: Non-deterministic latency detected! (Rule #3 violation)")
        else:
            log(f"PASS: Deterministic latency confirmed (Rule #3)")

        if self.overflow_rate > 1.0:
            log(f"WARNING: High overflow rate! Consider increasing bit width.")
        else:
            log(f"PASS: Overflow rate acceptable (<1%)")
