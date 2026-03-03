# ai_model/src/config.py
"""
Hardware-constrained configuration for DLinear ASIC.
All values here MUST match Chisel implementation exactly.
"""

# Input window size - MUST be power of 2 for zero-latency division
WINDOW_SIZE = 64

# Moving average window for trend extraction - MUST be power of 2
MA_WINDOW = 64

# Quantization bit-widths
WEIGHT_BITS = 8       # Int8 weights
ACTIVATION_BITS = 8   # Int8 activations
ACCUMULATOR_BITS = 24 # Int24 for MAC results (prevents overflow with large weight sums)

# Weight regularization (L2) - INCREASED to prevent overflow
WEIGHT_DECAY = 0.05   # Was 0.01, now 5x stronger

# Maximum weight magnitude for clipping
MAX_WEIGHT = 0.25     # Was 0.5 (implicit), now explicit and stricter

# Fixed-point scaling (2^FRAC_BITS represents 1.0)
FRAC_BITS = 7  # Q1.7 format for weights: range [-1, 0.992] with 0.0078 precision

# Output prediction horizon (ticks ahead)
PREDICTION_HORIZON = 1

# Training
BATCH_SIZE = 32
LEARNING_RATE = 1e-3
EPOCHS = 100

# Golden reference vectors count
GOLDEN_VECTORS_COUNT = 100

# Pipeline configuration (matches Chisel Config.scala)
MAC_PIPELINE_STAGES = 4  # Adder tree pipeline stages
PIPELINE_DEPTH = 8       # Total cycles: 1 window + 1 mult + 4 adder + 1 sat + 1 fusion
