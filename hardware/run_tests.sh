#!/bin/bash
# hardware/run_tests.sh
# Run all hardware tests and generate Verilog

set -e  # Exit on error

echo "==========================================="
echo "DLinear ASIC - Hardware Test Suite"
echo "==========================================="

cd "$(dirname "$0")"

echo ""
echo "[1/4] Running Chisel unit tests..."
sbt test
echo "PASS"

echo ""
echo "[2/4] Generating Verilog..."
sbt "runMain dlinear.GenerateDLinear"
echo "PASS"

echo ""
echo "[3/4] Running Verilator lint..."
if command -v verilator &> /dev/null; then
    # Suppress benign Chisel-generated warnings:
    # - DECLFILENAME: all modules in single file
    # - UNUSEDSIGNAL: _RANDOM arrays for simulation only
    verilator --lint-only -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL generated/DLinearTop.sv 2>&1
    echo "PASS"
else
    echo "SKIP (verilator not installed)"
fi

echo ""
echo "[4/4] Checking generated file..."
if [ -f generated/DLinearTop.sv ]; then
    lines=$(wc -l < generated/DLinearTop.sv)
    modules=$(grep -c "^module" generated/DLinearTop.sv || echo 0)
    echo "Generated: $lines lines, $modules modules"
    echo "PASS"
else
    echo "FAIL: DLinearTop.sv not generated"
    exit 1
fi

echo ""
echo "==========================================="
echo "All hardware tests passed!"
echo "==========================================="
echo ""
echo "Output: hardware/generated/DLinearTop.sv"
echo ""
echo "Next steps:"
echo "  1. cd ../verification && make sim  (run Cocotb tests)"
echo "  2. Synthesize with your ASIC tools"
