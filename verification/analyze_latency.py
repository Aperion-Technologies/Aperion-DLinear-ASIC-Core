#!/usr/bin/env python3
"""
verification/analyze_latency.py
Analyze FST waveform for pipeline latency measurement.

Per stage_3.md requirement 3.3: Measure cycles between input and output.
Target: 3-5 cycles at 1 GHz = 3-5 ns.

Usage:
    python analyze_latency.py dump.fst
    python analyze_latency.py --report
"""

import argparse
import sys
from pathlib import Path

# Try to import pyvcd for FST parsing
try:
    from vcd import VCDWriter
    HAS_PYVCD = True
except ImportError:
    HAS_PYVCD = False


def analyze_results_xml(results_path: Path) -> dict:
    """
    Parse results.xml to extract latency measurements.

    Cocotb stores test output in results.xml.
    """
    import xml.etree.ElementTree as ET

    if not results_path.exists():
        print(f"ERROR: {results_path} not found")
        print("Run 'make sim' first to generate test results")
        return {}

    tree = ET.parse(results_path)
    root = tree.getroot()

    results = {
        'tests': [],
        'latency_ns': None,
        'throughput_pct': None,
        'bubbles': None,
        'golden_pass': None,
        'golden_total': None,
    }

    for testcase in root.findall('.//testcase'):
        name = testcase.get('name', 'unknown')
        time_ms = float(testcase.get('time', 0)) * 1000
        status = 'PASS' if testcase.find('failure') is None else 'FAIL'

        results['tests'].append({
            'name': name,
            'time_ms': time_ms,
            'status': status,
        })

    return results


def print_latency_report(results: dict):
    """Print formatted latency analysis report."""
    print("=" * 60)
    print("DLINEAR ASIC - LATENCY ANALYSIS REPORT")
    print("=" * 60)
    print()

    print("Test Results:")
    print("-" * 60)
    for test in results.get('tests', []):
        status_color = '\033[92m' if test['status'] == 'PASS' else '\033[91m'
        reset = '\033[0m'
        print(f"  {test['name'][:45]:<45} {status_color}{test['status']}{reset}")
    print()

    # Latency summary
    print("Latency Analysis:")
    print("-" * 60)
    print("  Note: See test output for precise measurements")
    print("  Target: 3-5 cycles (3-5 ns at 1 GHz)")
    print()

    # Performance targets
    print("HFT Performance Targets:")
    print("-" * 60)
    print("  Rule #2 (Fully Unrolled): 1 prediction/cycle throughput")
    print("  Rule #3 (100% Determinism): Constant latency")
    print("  Rule #4 (Bit-Precision): 100% golden vector match")
    print()

    print("=" * 60)
    print("Run 'make view' to analyze waveform in Surfer")
    print("=" * 60)


def main():
    parser = argparse.ArgumentParser(description='Analyze DLinear latency')
    parser.add_argument('fst_file', nargs='?', help='FST waveform file')
    parser.add_argument('--report', action='store_true', help='Show test report')
    parser.add_argument('--results', type=Path, default=Path('results.xml'))
    args = parser.parse_args()

    if args.report or not args.fst_file:
        results = analyze_results_xml(args.results)
        print_latency_report(results)
        return

    fst_path = Path(args.fst_file)
    if not fst_path.exists():
        print(f"ERROR: {fst_path} not found")
        sys.exit(1)

    print(f"FST analysis not implemented yet.")
    print(f"Use 'make view' to open {fst_path} in Surfer.")
    print()
    print("In Surfer:")
    print("  1. Find io_dataValid rising edge")
    print("  2. Find corresponding io_predValid rising edge")
    print("  3. Measure cycle count between them")


if __name__ == '__main__':
    main()
