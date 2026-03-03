// hardware/src/main/scala/dlinear/DLinearTop.scala
package dlinear

import chisel3._
import chisel3.util._

/**
 * Configuration interface for pre-session weight loading.
 */
class ConfigInterface(windowSize: Int, weightBits: Int) extends Bundle {
  val addr = Input(UInt(log2Ceil(windowSize).W))
  val data = Input(SInt(weightBits.W))
  val writeEn = Input(Bool())
  val weightSel = Input(Bool())  // 0 = trend, 1 = seasonal
}

/**
 * Status signals for monitoring.
 */
class StatusInterface extends Bundle {
  val ready = Output(Bool())         // Pipeline filled, can produce outputs
  val weightsLoaded = Output(Bool()) // Weights have been written
}

/**
 * Top-level DLinear ASIC module.
 *
 * Architecture (per CLAUDE.md):
 * 1. Decomposition: MovingAverageUnit splits input into Trend and Seasonal
 * 2. Linear Projection: Two ParallelMAC units with pipelined adder trees
 * 3. Output Fusion: SaturatingAdder combines predictions
 *
 * Pipeline Stages:
 * - Stage 1: Input registration + Decomposition (1 cycle)
 * - Stage 2: MAC multiplication (1 cycle)
 * - Stage 3: MAC adder tree (pipelineStages cycles)
 * - Stage 4: Saturation + Output fusion (1 cycle)
 *
 * Total latency after fill: macPipelineStages + 3 cycles
 *
 * Per Rule #3 (100% Determinism): Latency is constant regardless of data values.
 * Per Rule #2 (Fully Unrolled): 128 parallel multipliers (64 trend + 64 seasonal).
 *
 * @param windowSize Input window size (must be power of 2)
 * @param dataBits Bit width for activations
 * @param weightBits Bit width for weights
 * @param accBits Bit width for accumulator
 * @param macPipelineStages Pipeline stages in MAC adder tree
 */
class DLinearTop(
  windowSize: Int = Config.WindowSize,
  dataBits: Int = Config.ActivationBits,
  weightBits: Int = Config.WeightBits,
  accBits: Int = Config.AccumulatorBits,
  macPipelineStages: Int = Config.MACPipelineStages
) extends Module {

  val io = IO(new Bundle {
    // Data interface (active during trading)
    val dataIn = Input(SInt(dataBits.W))
    val dataValid = Input(Bool())

    // Prediction output
    val predOut = Output(SInt(accBits.W))
    val predValid = Output(Bool())

    // Configuration interface (active before trading)
    val configMode = Input(Bool())
    val config = new ConfigInterface(windowSize, weightBits)

    // Status
    val status = new StatusInterface
  })

  // =========================================================================
  // Track if weights have ever been loaded
  // =========================================================================

  val weightsLoadedReg = RegInit(false.B)
  when(io.configMode && io.config.writeEn) {
    weightsLoadedReg := true.B
  }
  io.status.weightsLoaded := weightsLoadedReg

  // =========================================================================
  // Stage 1: Decomposition (Moving Average)
  // =========================================================================

  val decomp = Module(new MovingAverageUnit(windowSize, dataBits))
  decomp.io.in := io.dataIn
  decomp.io.valid := io.dataValid && !io.configMode

  // =========================================================================
  // Input Window Buffer
  // Store trend and seasonal values for parallel MAC access
  // =========================================================================

  val trendWindow = Reg(Vec(windowSize, SInt(dataBits.W)))
  val seasWindow = Reg(Vec(windowSize, SInt(dataBits.W)))
  val windowFillCount = RegInit(0.U(log2Ceil(windowSize + 1).W))
  val windowFilled = windowFillCount >= windowSize.U

  when(io.dataValid && !io.configMode && decomp.io.ready) {
    // Shift and insert new values
    for (i <- windowSize - 1 to 1 by -1) {
      trendWindow(i) := trendWindow(i - 1)
      seasWindow(i) := seasWindow(i - 1)
    }
    trendWindow(0) := decomp.io.trend
    seasWindow(0) := decomp.io.seasonal

    when(!windowFilled) {
      windowFillCount := windowFillCount + 1.U
    }
  }

  // =========================================================================
  // Stage 2-3: Linear Projection (Deep Pipeline)
  // Using LinearLayer for optimized timing (per stage_8.md)
  // =========================================================================

  val trendLayer = Module(new LinearLayer(windowSize, dataBits, accBits))
  val seasLayer = Module(new LinearLayer(windowSize, dataBits, accBits))

  // Connect data inputs
  trendLayer.io.in := trendWindow
  trendLayer.io.valid := windowFilled && decomp.io.ready && io.dataValid && !io.configMode

  seasLayer.io.in := seasWindow
  seasLayer.io.valid := windowFilled && decomp.io.ready && io.dataValid && !io.configMode

  // Weight loading passthrough (LinearLayer has internal weight storage)
  trendLayer.io.weightEn := io.configMode && io.config.writeEn && !io.config.weightSel
  trendLayer.io.weightAddr := io.config.addr
  trendLayer.io.weightData := io.config.data

  seasLayer.io.weightEn := io.configMode && io.config.writeEn && io.config.weightSel
  seasLayer.io.weightAddr := io.config.addr
  seasLayer.io.weightData := io.config.data

  // =========================================================================
  // Stage 4: Output Fusion (Saturating Add, pipelined)
  // =========================================================================

  val fusionAdder = Module(new SaturatingAdder(accBits, pipelined = true))
  fusionAdder.io.a := trendLayer.io.result
  fusionAdder.io.b := seasLayer.io.result
  fusionAdder.io.valid := trendLayer.io.resultValid && seasLayer.io.resultValid

  io.predOut := fusionAdder.io.result
  io.predValid := fusionAdder.io.resultValid

  // =========================================================================
  // Status
  // =========================================================================

  io.status.ready := decomp.io.ready && windowFilled
}

/**
 * Verilog generation entry point.
 */
object GenerateDLinear extends App {
  val targetDir = "generated"
  new java.io.File(targetDir).mkdirs()

  println("Generating DLinearTop with default configuration:")
  println(s"  Window Size: ${Config.WindowSize}")
  println(s"  Data Bits: ${Config.ActivationBits}")
  println(s"  Weight Bits: ${Config.WeightBits}")
  println(s"  Accumulator Bits: ${Config.AccumulatorBits}")
  println(s"  MAC Pipeline Stages: ${Config.MACPipelineStages}")

  val verilog = chisel3.getVerilogString(new DLinearTop())

  val writer = new java.io.PrintWriter(s"$targetDir/DLinearTop.sv")
  writer.write(verilog)
  writer.close()

  println(s"\nGenerated DLinearTop.sv in hardware/$targetDir/")
}
