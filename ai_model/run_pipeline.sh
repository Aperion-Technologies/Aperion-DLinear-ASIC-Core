#!/bin/bash
# ai_model/run_pipeline.sh
# Full pipeline: Generate data -> Train -> Export weights -> Generate golden vectors

set -e  # Exit on error

echo "=========================================="
echo "DLinear ASIC - AI Pipeline"
echo "=========================================="

cd "$(dirname "$0")"

echo ""
echo "[1/4] Generating synthetic market data..."
python -m src.data_generator
echo "Done."

echo ""
echo "[2/4] Training quantized DLinear model..."
python -m src.train --epochs 100 --output outputs/
echo "Done."

echo ""
echo "[3/4] Exporting weights to hex..."
python -m src.export_weights --model outputs/dlinear_quantized.pt --output outputs/
echo "Done."

echo ""
echo "[4/4] Generating golden reference vectors..."
python -m src.golden_reference \
    --model outputs/dlinear_quantized.pt \
    --data data/ticks.parquet \
    --output outputs/golden/ \
    --n 100
echo "Done."

echo ""
echo "=========================================="
echo "Pipeline complete!"
echo "=========================================="
echo "Outputs:"
echo "  - Model:   outputs/dlinear_quantized.pt"
echo "  - Weights: outputs/trend_w.hex, outputs/seas_w.hex"
echo "  - Golden:  outputs/golden/input_*.hex, output_*.hex"
echo ""
echo "Next steps:"
echo "  1. cd ../hardware && sbt 'runMain dlinear.DLinearTop'"
echo "  2. cd ../verification && make sim"
