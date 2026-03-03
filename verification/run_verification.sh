#!/bin/bash
# verification/run_verification.sh
# Stage 3: Full verification pipeline for DLinear ASIC

set -e  # Exit on error

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"

echo "=========================================="
echo "DLinear ASIC - Stage 3 Verification"
echo "=========================================="
echo ""

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Step 1: Check prerequisites
echo "[1/5] Checking prerequisites..."

check_command() {
    if ! command -v $1 &> /dev/null; then
        echo -e "${RED}ERROR: $1 not found${NC}"
        exit 1
    fi
    echo "  $1: $(which $1)"
}

check_command verilator
check_command python3
check_command surfer

# Verify Verilator is ARM64 native
VERILATOR_ARCH=$(file $(which verilator) | grep -o "arm64\|x86_64")
echo "  Verilator arch: $VERILATOR_ARCH"
if [[ "$VERILATOR_ARCH" != "arm64" ]]; then
    echo -e "${YELLOW}WARNING: Verilator is not ARM64 native${NC}"
fi

echo -e "${GREEN}Prerequisites OK${NC}"
echo ""

# Step 2: Generate Verilog
echo "[2/5] Generating Verilog from Chisel..."
cd "$PROJECT_ROOT/hardware"
sbt "runMain dlinear.GenerateDLinear" 2>&1 | tail -5

if [ ! -f generated/DLinearTop.sv ]; then
    echo -e "${RED}ERROR: Verilog generation failed${NC}"
    exit 1
fi
echo -e "${GREEN}Verilog generated: hardware/generated/DLinearTop.sv${NC}"
echo ""

# Step 3: Run Cocotb tests
echo "[3/5] Running Cocotb verification tests..."
cd "$SCRIPT_DIR"
make cleanall 2>/dev/null || true

# Run tests and capture result
if make sim 2>&1 | tee test_output.log | grep -E "(PASS|FAIL|Error)"; then
    echo ""
fi

# Check results
PASS_COUNT=$(grep -c "PASS" results.xml 2>/dev/null || echo "0")
FAIL_COUNT=$(grep -c "FAIL" results.xml 2>/dev/null || echo "0")

echo ""
echo "Test Results:"
echo "  Passed: $PASS_COUNT"
echo "  Failed: $FAIL_COUNT"

if [ "$FAIL_COUNT" != "0" ]; then
    echo -e "${RED}VERIFICATION FAILED${NC}"
    echo "See results.xml for details"
    exit 1
fi
echo -e "${GREEN}All tests PASSED${NC}"
echo ""

# Step 4: Analyze waveform
echo "[4/5] Waveform analysis..."
FST_FILE=$(find . -name "*.fst" -type f | head -1)

if [ -n "$FST_FILE" ]; then
    FST_SIZE=$(ls -lh "$FST_FILE" | awk '{print $5}')
    echo "  Waveform: $FST_FILE ($FST_SIZE)"
    echo "  Format: FST (Surfer-optimized)"

    # Extract latency from test output
    LATENCY=$(grep -o "Latency: [0-9]* clock cycles" test_output.log | head -1 || echo "N/A")
    echo "  $LATENCY"
else
    echo -e "${YELLOW}WARNING: No FST file generated${NC}"
fi
echo ""

# Step 5: Summary
echo "[5/5] Verification Summary"
echo "=========================================="
echo ""
echo "  Hardware:  DLinearTop.sv"
echo "  Tests:     $PASS_COUNT passed, $FAIL_COUNT failed"
echo "  Waveform:  $FST_FILE"
echo ""
echo "=========================================="
echo -e "${GREEN}Stage 3 Verification COMPLETE${NC}"
echo "=========================================="
echo ""
echo "Next steps:"
echo "  1. make view    - Open waveform in Surfer"
echo "  2. Review latency measurements in test output"
echo "  3. Verify no pipeline bubbles visually"
echo ""

# Cleanup
rm -f test_output.log
