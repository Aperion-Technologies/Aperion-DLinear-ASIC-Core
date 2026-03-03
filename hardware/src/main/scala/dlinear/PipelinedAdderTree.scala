// hardware/src/main/scala/dlinear/PipelinedAdderTree.scala
package dlinear

import chisel3._
import chisel3.util._

/**
 * Pipelined binary adder tree for high-frequency summation.
 *
 * Inserts pipeline registers at configurable intervals to break
 * the critical path and enable 2 GHz+ operation.
 *
 * Structure (for 8 inputs, 2 stages):
 *   Level 0: 8 inputs
 *   Level 1: 4 adders -> REG
 *   Level 2: 2 adders
 *   Level 3: 1 adder  -> REG -> output
 *
 * @param inputCount Number of values to sum (should be power of 2)
 * @param inputBits Bit width of each input
 * @param pipelineStages Number of register stages to insert
 */
class PipelinedAdderTree(
  inputCount: Int = Config.WindowSize,
  inputBits: Int = Config.AccumulatorBits,
  pipelineStages: Int = 2
) extends Module {

  require(inputCount > 0 && (inputCount & (inputCount - 1)) == 0,
    s"inputCount must be power of 2, got $inputCount")

  val treeLevels = log2Ceil(inputCount)
  val outputBits = inputBits + treeLevels  // Widen to prevent overflow

  // Levels at which to insert pipeline registers
  // Distribute evenly across tree depth (ensures exactly pipelineStages registers)
  val regLevels: Set[Int] = if (pipelineStages > 0 && pipelineStages <= treeLevels) {
    // Distribute registers evenly across tree
    val step = treeLevels.toDouble / pipelineStages
    (1 to pipelineStages).map(i => (i * step).round.toInt).toSet
  } else if (pipelineStages > treeLevels) {
    // More stages than levels - register every level
    (1 to treeLevels).toSet
  } else {
    Set.empty
  }

  val latency: Int = regLevels.size

  val io = IO(new Bundle {
    val inputs = Input(Vec(inputCount, SInt(inputBits.W)))
    val valid = Input(Bool())
    val result = Output(SInt(outputBits.W))
    val resultValid = Output(Bool())
  })

  // Build the adder tree level by level
  var currentLevel: Seq[SInt] = io.inputs.map(_.pad(outputBits))
  var validPipe = io.valid

  for (level <- 1 to treeLevels) {
    val nextCount = currentLevel.length / 2
    val nextLevel = Wire(Vec(nextCount, SInt(outputBits.W)))

    for (i <- 0 until nextCount) {
      nextLevel(i) := currentLevel(2 * i) + currentLevel(2 * i + 1)
    }

    // Insert register if this is a pipeline stage
    if (regLevels.contains(level)) {
      currentLevel = RegNext(nextLevel).toSeq
      validPipe = RegNext(validPipe)
    } else {
      currentLevel = nextLevel.toSeq
    }
  }

  io.result := currentLevel.head
  io.resultValid := validPipe
}

/**
 * Helper object for calculating adder tree parameters.
 */
object PipelinedAdderTree {
  /**
   * Calculate recommended pipeline stages for target frequency.
   *
   * Assumes ~150ps per adder level at modern process nodes.
   * For 2 GHz (500ps period), need register every ~3 levels.
   */
  def recommendedStages(inputCount: Int, targetFreqGHz: Double): Int = {
    val levels = log2Ceil(inputCount)
    val periodPs = 1000.0 / targetFreqGHz  // Period in picoseconds
    val adderDelayPs = 150  // Conservative estimate
    val levelsPerStage = (periodPs / adderDelayPs).toInt.max(1)
    (levels + levelsPerStage - 1) / levelsPerStage
  }
}
