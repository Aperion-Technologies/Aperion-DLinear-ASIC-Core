// hardware/src/main/scala/dlinear/MAC.scala
package dlinear

import chisel3._
import chisel3.util._

/**
 * Fully Unrolled Parallel Multiply-Accumulate unit with pipelined adder tree.
 *
 * Computes dot product: sum(inputs[i] * weights[i])
 * Uses parallel multipliers (one per vector element) and PIPELINED adder tree.
 *
 * Hardware: vecSize multipliers + pipelined adder tree
 * Latency: (pipelineStages in adder tree) + 1 cycle (output register)
 *
 * @param vecSize Number of parallel multiplications (e.g., 64)
 * @param dataBits Input/weight bit width (e.g., 8 for Int8)
 * @param accBits Accumulator bit width (e.g., 16 for Int16)
 * @param pipelineStages Pipeline stages in adder tree (0 = combinational)
 */
class ParallelMAC(
  vecSize: Int = Config.WindowSize,
  dataBits: Int = Config.ActivationBits,
  accBits: Int = Config.AccumulatorBits,
  pipelineStages: Int = 2
) extends Module {

  // Product needs 2x bits to avoid overflow
  val productBits = dataBits * 2

  val io = IO(new Bundle {
    val inputs = Input(Vec(vecSize, SInt(dataBits.W)))
    val weights = Input(Vec(vecSize, SInt(dataBits.W)))
    val valid = Input(Bool())
    val result = Output(SInt(accBits.W))
    val resultValid = Output(Bool())
  })

  // Stage 1: Parallel multiplication (all vecSize multipliers run simultaneously)
  // This is combinational - all products computed in same cycle
  val productsWire = Wire(Vec(vecSize, SInt(productBits.W)))
  for (i <- 0 until vecSize) {
    productsWire(i) := io.inputs(i) * io.weights(i)
  }

  // Register multiplication outputs to break critical path
  val products = RegNext(productsWire)
  val validAfterMult = RegNext(io.valid)

  // Stage 2: Pipelined adder tree
  val adderTree = Module(new PipelinedAdderTree(
    inputCount = vecSize,
    inputBits = productBits,
    pipelineStages = pipelineStages
  ))

  adderTree.io.inputs := products
  adderTree.io.valid := validAfterMult

  // Stage 3: Saturate to accumulator width and register output
  val rawSum = adderTree.io.result
  val saturated = saturate(rawSum, accBits)

  io.result := RegNext(saturated)
  io.resultValid := RegNext(adderTree.io.resultValid)

  // Total latency: 1 (mult reg) + adder tree stages + 1 (output register)
  val latency: Int = adderTree.latency + 2

  /**
   * Saturating conversion to target bit width.
   * Handles input values of any width (sign-extends narrower inputs).
   */
  private def saturate(value: SInt, bits: Int): SInt = {
    val maxVal = ((1 << (bits - 1)) - 1).S
    val minVal = (-(1 << (bits - 1))).S

    val result = Wire(SInt(bits.W))
    when(value > maxVal) {
      result := maxVal
    }.elsewhen(value < minVal) {
      result := minVal
    }.otherwise {
      // Sign-extend or truncate as needed
      result := value.pad(bits)
    }
    result
  }
}

/**
 * Saturating adder for output fusion.
 *
 * Adds two values with saturation (no wraparound).
 * Optionally pipelined for timing optimization.
 *
 * @param bits Bit width of inputs/output
 * @param pipelined If true, adds 1 cycle latency with registered output
 */
class SaturatingAdder(bits: Int = Config.AccumulatorBits, pipelined: Boolean = false) extends Module {
  val io = IO(new Bundle {
    val a = Input(SInt(bits.W))
    val b = Input(SInt(bits.W))
    val valid = Input(Bool())
    val result = Output(SInt(bits.W))
    val resultValid = Output(Bool())
  })

  // Widen for addition
  val sum = (io.a.pad(bits + 1)) + (io.b.pad(bits + 1))

  // Saturate
  val maxVal = ((1 << (bits - 1)) - 1).S((bits + 1).W)
  val minVal = (-(1 << (bits - 1))).S((bits + 1).W)

  val saturated = Wire(SInt(bits.W))
  when(sum > maxVal) {
    saturated := maxVal(bits - 1, 0).asSInt
  }.elsewhen(sum < minVal) {
    saturated := minVal(bits - 1, 0).asSInt
  }.otherwise {
    saturated := sum(bits - 1, 0).asSInt
  }

  if (pipelined) {
    io.result := RegNext(saturated)
    io.resultValid := RegNext(io.valid)
  } else {
    io.result := saturated
    io.resultValid := io.valid
  }
}
