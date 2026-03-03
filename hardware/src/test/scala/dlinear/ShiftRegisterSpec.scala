// hardware/src/test/scala/dlinear/ShiftRegisterSpec.scala
package dlinear

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class ShiftRegisterSpec extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "ShiftRegister"

  it should "output moving average after filling" in {
    test(new MovingAverageUnit(windowSize = 4, dataBits = 8)) { dut =>
      // Fill with constant value 8
      // MA of [8,8,8,8] = 8
      for (_ <- 0 until 4) {
        dut.io.in.poke(8.S)
        dut.io.valid.poke(true.B)
        dut.clock.step()
      }

      // After 4 cycles, output should be 8 (sum=32, shift by 2 = 8)
      dut.io.trend.expect(8.S)
    }
  }

  it should "compute seasonal as input minus trend" in {
    test(new MovingAverageUnit(windowSize = 4, dataBits = 8)) { dut =>
      // Fill with 8s, then input 12
      for (_ <- 0 until 4) {
        dut.io.in.poke(8.S)
        dut.io.valid.poke(true.B)
        dut.clock.step()
      }

      // Now input 12, MA still ~8 (actually (8+8+8+12)/4 = 9)
      dut.io.in.poke(12.S)
      dut.clock.step()

      // Seasonal = 12 - 9 = 3
      dut.io.seasonal.expect(3.S)
    }
  }
}
