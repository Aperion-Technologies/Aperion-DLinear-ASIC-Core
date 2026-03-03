// hardware/src/main/scala/dlinear/WeightBank.scala
package dlinear

import chisel3._
import chisel3.util._

/**
 * Register-based weight storage for parallel read access.
 *
 * Unlike SRAM (SyncReadMem), this uses flip-flops for storage,
 * allowing ALL weights to be read simultaneously in one cycle.
 *
 * Per CLAUDE.md "Hardwired Weights": Each weight register is
 * physically placed close to its corresponding multiplier to
 * minimize signal propagation delay.
 *
 * Trade-off: More area than SRAM, but zero read latency.
 *
 * @param size Number of weights (e.g., 64)
 * @param bits Bit width per weight (e.g., 8 for Int8)
 */
class WeightBank(
  size: Int = Config.WindowSize,
  bits: Int = Config.WeightBits
) extends Module {

  val io = IO(new Bundle {
    // Sequential load interface (active before trading session)
    val loadEn = Input(Bool())
    val loadAddr = Input(UInt(log2Ceil(size).W))
    val loadData = Input(SInt(bits.W))

    // Parallel read interface (always available)
    val weights = Output(Vec(size, SInt(bits.W)))
  })

  // Register file - all weights stored in flip-flops
  val weightRegs = RegInit(VecInit(Seq.fill(size)(0.S(bits.W))))

  // Load logic (one weight per cycle during configuration)
  when(io.loadEn) {
    weightRegs(io.loadAddr) := io.loadData
  }

  // All weights available simultaneously (combinational read)
  io.weights := weightRegs
}
