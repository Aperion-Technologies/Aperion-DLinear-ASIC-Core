// hardware/src/test/scala/dlinear/LinearLayerSpec.scala
package dlinear

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class LinearLayerSpec extends AnyFlatSpec with ChiselScalatestTester {

  behavior of "LinearLayer"

  it should "produce correct output for known weights and inputs" in {
    test(new LinearLayer(numInputs = 4, dataBits = 8, outputBits = 24)) { dut =>
      // Load weights: [1, 2, 3, 4]
      dut.io.weightEn.poke(true.B)
      for (i <- 0 until 4) {
        dut.io.weightAddr.poke(i.U)
        dut.io.weightData.poke((i + 1).S)
        dut.clock.step()
      }
      dut.io.weightEn.poke(false.B)

      // Input: [1, 1, 1, 1]
      // Expected: 1*1 + 1*2 + 1*3 + 1*4 = 10
      for (i <- 0 until 4) {
        dut.io.in(i).poke(1.S)
      }
      dut.io.valid.poke(true.B)

      // Wait for pipeline latency (5 cycles)
      dut.clock.step(6)

      // Check result
      dut.io.resultValid.expect(true.B)
      dut.io.result.expect(10.S)
    }
  }

  it should "have deterministic 4-cycle latency" in {
    test(new LinearLayer(numInputs = 4, dataBits = 8, outputBits = 24)) { dut =>
      // Load zero weights
      dut.io.weightEn.poke(true.B)
      for (i <- 0 until 4) {
        dut.io.weightAddr.poke(i.U)
        dut.io.weightData.poke(1.S)
        dut.clock.step()
      }
      dut.io.weightEn.poke(false.B)

      // Feed input
      for (i <- 0 until 4) {
        dut.io.in(i).poke(1.S)
      }
      dut.io.valid.poke(true.B)
      dut.clock.step()
      dut.io.valid.poke(false.B)

      // Check latency - should be valid after exactly 4 cycles
      // Already did 1 step after valid=true, need 3 more for total of 4
      for (cycle <- 2 until 4) {
        dut.clock.step()
        dut.io.resultValid.expect(false.B, s"Should not be valid at cycle $cycle")
      }
      dut.clock.step()  // 4th cycle
      dut.io.resultValid.expect(true.B, "Should be valid at cycle 4")
    }
  }

  it should "saturate on overflow" in {
    test(new LinearLayer(numInputs = 4, dataBits = 8, outputBits = 24)) { dut =>
      // Load max weights: [127, 127, 127, 127]
      dut.io.weightEn.poke(true.B)
      for (i <- 0 until 4) {
        dut.io.weightAddr.poke(i.U)
        dut.io.weightData.poke(127.S)
        dut.clock.step()
      }
      dut.io.weightEn.poke(false.B)

      // Input max: [127, 127, 127, 127]
      for (i <- 0 until 4) {
        dut.io.in(i).poke(127.S)
      }
      dut.io.valid.poke(true.B)

      dut.clock.step(6)

      // 127 * 127 * 4 = 64516 - should not overflow Int24
      dut.io.resultValid.expect(true.B)
      dut.io.result.expect(64516.S)
    }
  }
}
