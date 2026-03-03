#!/bin/bash
# run_backtest.sh
# Stage 4: Full financial backtest pipeline

set -e

PROJECT_ROOT="$(cd "$(dirname "$0")" && pwd)"

echo "========================================"
echo "DLinear ASIC - Stage 4 Financial Backtest"
echo "========================================"
echo ""

# Colors
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

# Step 1: Check market data exists
echo "[1/4] Checking market data..."
if [ ! -f "$PROJECT_ROOT/trades.csv" ]; then
    echo "  ERROR: trades.csv not found in project root"
    exit 1
else
    echo "  Market data exists: trades.csv"
fi

# Step 2: Quantize market data
echo ""
echo "[2/4] Quantizing market data for ASIC..."
cd "$PROJECT_ROOT"
python -m ai_model.src.prepare_market_data \
    --csv trades.csv \
    --output ai_model/outputs \
    --max-rows 50000 \
    --type trades

# Step 3: Run ASIC simulation
echo ""
echo "[3/4] Running ASIC backtest simulation..."
cd "$PROJECT_ROOT/verification"
make market 2>&1 | tail -30

# Step 4: Summary
echo ""
echo "[4/4] Backtest Complete"
echo "========================================"
echo ""
echo "Generated files:"
echo "  - ai_model/outputs/market_input.hex"
echo "  - ai_model/outputs/expected_output.hex"
echo "  - verification/outputs/asic_predictions.csv"
echo ""
echo "Next steps:"
echo "  1. jupyter notebook analysis/backtest_analysis.ipynb"
echo "  2. View equity curve in analysis/figures/"
echo ""
echo -e "${GREEN}Stage 4 backtest pipeline complete!${NC}"
