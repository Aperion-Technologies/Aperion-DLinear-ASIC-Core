// hardware/src/main/scala/dlinear/ShiftRegister.scala
package dlinear

import chisel3._
import chisel3.util._

/**
 * Moving Average decomposition unit using shift registers.
 *
 * Computes Trend = MovingAverage(input) using bit-shift division.
 * Computes Seasonal = Input - Trend.
 *
 * Hardware: windowSize registers + adders + bit-shift (no divider)
 * Latency: Combinational (0 cycles after initial fill)
 *
 * @param windowSize Moving average window (MUST be power of 2)
 * @param dataBits Bit width of input/output data
 */
class MovingAverageUnit(
  windowSize: Int = Config.MAWindow,
  dataBits: Int = Config.ActivationBits
) extends Module {

  require((windowSize & (windowSize - 1)) == 0, s"windowSize must be power of 2")

  val shiftBits = log2Ceil(windowSize)
  val sumBits = dataBits + shiftBits  // Extra bits to prevent overflow in sum

  val io = IO(new Bundle {
    val in = Input(SInt(dataBits.W))
    val valid = Input(Bool())
    val trend = Output(SInt(dataBits.W))
    val seasonal = Output(SInt(dataBits.W))
    val ready = Output(Bool())  // High after initial fill
  })

  // Shift register to hold last windowSize values
  val shiftReg = Reg(Vec(windowSize, SInt(dataBits.W)))

  // Fill counter
  val fillCount = RegInit(0.U(log2Ceil(windowSize + 1).W))
  val filled = fillCount >= windowSize.U

  // Running sum (updated incrementally)
  val runningSum = RegInit(0.S(sumBits.W))

  when(io.valid) {
    // Shift values through register
    for (i <- windowSize - 1 to 1 by -1) {
      shiftReg(i) := shiftReg(i - 1)
    }
    shiftReg(0) := io.in

    // Update running sum: add new value, subtract oldest
    when(filled) {
      runningSum := runningSum + io.in - shiftReg(windowSize - 1)
    }.otherwise {
      runningSum := runningSum + io.in
      fillCount := fillCount + 1.U
    }
  }

  // Trend = sum >> shiftBits (division by windowSize via bit shift)
  val trend = (runningSum >> shiftBits).asSInt
  io.trend := trend(dataBits - 1, 0).asSInt

  // Seasonal = Input - Trend
  io.seasonal := io.in - io.trend

  // Ready when filled
  io.ready := filled
}
