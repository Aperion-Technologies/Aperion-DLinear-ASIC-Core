// hardware/src/main/scala/dlinear/LinearLayer.scala
package dlinear

import chisel3._
import chisel3.util._

/**
 * Deep-Pipelined Linear Layer for DLinear ASIC.
 *
 * Implements 4-stage pipeline for timing optimization:
 * - Stage 0 (Input Latch): Register inputs and weights from SRAM
 * - Stage 1 (Multiplication): Parallel multiply x × w, store in intermediate regs
 * - Stage 2 (Adder Tree Level 1): Pairwise addition (64→32 partial sums)
 * - Stage 3 (Final Sum): Complete adder tree and register output
 *
 * Design Goals:
 * - No signal path > 4-5ns (targeting 100MHz on 130nm / 1.2GHz on 7nm)
 * - Deterministic latency (Rule #3)
 * - 64 parallel multipliers (Rule #2)
 *
 * @param numInputs Vector size (default: 64)
 * @param dataBits Input/weight bit width (default: 8)
 * @param sumBits Intermediate sum width (default: 16, prevents overflow)
 * @param outputBits Final output width (default: 24)
 */
class LinearLayer(
  numInputs: Int = Config.WindowSize,
  dataBits: Int = Config.ActivationBits,
  outputBits: Int = Config.AccumulatorBits
) extends Module {

  // Product bit width: Int8 × Int8 = Int16
  val productBits = dataBits * 2

  // Intermediate sum width: need extra bits to prevent overflow
  // For 64 inputs: need productBits + log2(64) = 16 + 6 = 22 bits
  val treeLevels = log2Ceil(numInputs)
  val sumBits = productBits + treeLevels

  val io = IO(new Bundle {
    // Data interface
    val in = Input(Vec(numInputs, SInt(dataBits.W)))
    val valid = Input(Bool())
    val result = Output(SInt(outputBits.W))
    val resultValid = Output(Bool())

    // Weight loading interface (for Cocotb initialization)
    val weightEn = Input(Bool())
    val weightAddr = Input(UInt(log2Ceil(numInputs).W))
    val weightData = Input(SInt(dataBits.W))
  })

  // ===========================================================================
  // Weight Storage (Registers for parallel read access)
  // Per CLAUDE.md: Hardwired Weights - each weight physically close to multiplier
  // ===========================================================================

  val weights = Reg(Vec(numInputs, SInt(dataBits.W)))

  when(io.weightEn) {
    weights(io.weightAddr) := io.weightData
  }

  // ===========================================================================
  // Stage 1: Parallel Multiplication
  // 64 multipliers running simultaneously (Rule #2: Fully Unrolled)
  // Products computed combinationally, then registered (matches original MAC)
  // ===========================================================================

  // Combinational multiplication (inputs * weights)
  val productsWire = Wire(Vec(numInputs, SInt(productBits.W)))
  for (i <- 0 until numInputs) {
    productsWire(i) := io.in(i) * weights(i)
  }

  // Register products to break critical path
  val stage1_products = RegNext(productsWire)
  val stage1_valid = RegNext(io.valid)

  // ===========================================================================
  // Stage 2: Adder Tree Level 1
  // Pairwise addition: 64 products → 32 partial sums
  // Use SInt(16.W) to prevent overflow (per stage_8.md)
  // ===========================================================================

  val numPairs = numInputs / 2
  val stage2_sums = Reg(Vec(numPairs, SInt(sumBits.W)))
  val stage2_valid = RegNext(stage1_valid)

  for (i <- 0 until numPairs) {
    // Sign-extend products to sumBits before adding
    val a = stage1_products(2 * i).pad(sumBits)
    val b = stage1_products(2 * i + 1).pad(sumBits)
    stage2_sums(i) := a + b
  }

  // ===========================================================================
  // Stage 3: Final Sum (Complete Adder Tree)
  // Continue reducing: 32 → 16 → 8 → 4 → 2 → 1
  // This is combinational within the stage, registered at output
  // ===========================================================================

  // Combinational adder tree for remaining levels
  def reduceTree(values: Seq[SInt]): SInt = {
    if (values.length == 1) {
      values.head
    } else {
      val pairs = values.grouped(2).toSeq.map { pair =>
        if (pair.length == 2) {
          (pair(0).pad(outputBits) + pair(1).pad(outputBits))
        } else {
          pair(0).pad(outputBits)
        }
      }
      reduceTree(pairs)
    }
  }

  val stage3_sum = reduceTree(stage2_sums.map(_.pad(outputBits)))
  val stage3_valid = RegNext(stage2_valid)

  // Saturate final result
  val maxVal = ((1 << (outputBits - 1)) - 1).S
  val minVal = (-(1 << (outputBits - 1))).S

  val saturated = Wire(SInt(outputBits.W))
  when(stage3_sum > maxVal) {
    saturated := maxVal
  }.elsewhen(stage3_sum < minVal) {
    saturated := minVal
  }.otherwise {
    saturated := stage3_sum(outputBits - 1, 0).asSInt
  }

  io.result := RegNext(saturated)
  io.resultValid := RegNext(stage3_valid)

  // Total latency: 4 cycles (Stage 1 + Stage 2 + Stage 3 + output reg)
  val latency: Int = 4
}
