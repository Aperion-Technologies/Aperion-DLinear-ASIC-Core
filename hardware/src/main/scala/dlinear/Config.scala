// hardware/src/main/scala/dlinear/Config.scala
package dlinear

import chisel3._

/**
 * Hardware configuration matching Python ai_model/src/config.py
 *
 * CRITICAL: All values MUST match Python config exactly for bit-accuracy.
 *
 * Per Rule #4 (Bit-Precision): Any mismatch between Python and Chisel
 * quantization parameters is a BUG.
 */
object Config {
  // ===========================================================================
  // Core Parameters (MUST match Python config.py)
  // ===========================================================================

  // Input window size - matches Python WINDOW_SIZE
  // MUST be power of 2 for zero-latency division in decomposition
  val WindowSize: Int = 64

  // Moving average window - matches Python MA_WINDOW
  val MAWindow: Int = 64

  // Bit widths - matches Python WEIGHT_BITS, ACTIVATION_BITS, ACCUMULATOR_BITS
  val WeightBits: Int = 8      // Int8 weights from Brevitas
  val ActivationBits: Int = 8  // Int8 activations
  val AccumulatorBits: Int = 24 // Int24 to prevent overflow during MAC
                                // (64 products of Int8*Int8 can exceed Int16)

  // Fixed-point fractional bits - matches Python FRAC_BITS
  val FracBits: Int = 7  // Q1.7 format: range [-1, 0.992], resolution 0.0078

  // ===========================================================================
  // Pipeline Configuration
  // ===========================================================================

  // LinearLayer pipeline stages (3-stage pipeline)
  // Stage 1: Multiply (registered), Stage 2: Adder tree L1, Stage 3: Final sum + output
  val LinearLayerStages: Int = 4

  // Total pipeline depth (cycles from input to output after fill)
  // = 1 (decomp) + 4 (LinearLayer) + 1 (fusion) = 6 cycles
  val PipelineDepth: Int = 6

  // Legacy: Keep MACPipelineStages for backward compatibility
  val MACPipelineStages: Int = 4

  // ===========================================================================
  // Derived Constants
  // ===========================================================================

  // Bit shift for division by MAWindow (replaces division with wire routing)
  val MAShift: Int = log2(MAWindow)

  // Address width for weight memory
  val WeightAddrBits: Int = log2(WindowSize)

  // Product bit width (input * weight before accumulation)
  val ProductBits: Int = ActivationBits + WeightBits

  // ===========================================================================
  // Compile-Time Verification
  // ===========================================================================

  private def log2(x: Int): Int = (Math.log(x) / Math.log(2)).toInt

  // Verify power of 2 constraints
  require((MAWindow & (MAWindow - 1)) == 0,
    s"MAWindow must be power of 2 for bit-shift division, got $MAWindow")

  require((WindowSize & (WindowSize - 1)) == 0,
    s"WindowSize must be power of 2, got $WindowSize")

  require(WindowSize == MAWindow,
    s"WindowSize ($WindowSize) must equal MAWindow ($MAWindow) in current architecture")

  // Verify bit width constraints
  require(AccumulatorBits >= ProductBits - 4,
    s"AccumulatorBits ($AccumulatorBits) too small for ProductBits ($ProductBits)")
}
