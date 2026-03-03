// hardware/src/test/scala/dlinear/MACSpec.scala
package dlinear

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class MACSpec extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "ParallelMAC"

  it should "compute dot product with pipeline delay" in {
    test(new ParallelMAC(vecSize = 4, dataBits = 8, accBits = 16, pipelineStages = 1)) { dut =>
      // inputs: [1, 2, 3, 4], weights: [1, 1, 1, 1]
      // Expected: 1*1 + 2*1 + 3*1 + 4*1 = 10

      dut.io.inputs(0).poke(1.S)
      dut.io.inputs(1).poke(2.S)
      dut.io.inputs(2).poke(3.S)
      dut.io.inputs(3).poke(4.S)

      dut.io.weights(0).poke(1.S)
      dut.io.weights(1).poke(1.S)
      dut.io.weights(2).poke(1.S)
      dut.io.weights(3).poke(1.S)

      dut.io.valid.poke(true.B)

      // Wait for pipeline (1 stage for adder tree + 1 for output reg)
      dut.clock.step()
      dut.clock.step()

      dut.io.result.expect(10.S)
      dut.io.resultValid.expect(true.B)
    }
  }

  it should "handle negative values correctly" in {
    test(new ParallelMAC(vecSize = 4, dataBits = 8, accBits = 16, pipelineStages = 1)) { dut =>
      // inputs: [-5, 10, -3, 8], weights: [2, -1, 4, 1]
      // Expected: -5*2 + 10*(-1) + (-3)*4 + 8*1 = -10 - 10 - 12 + 8 = -24

      dut.io.inputs(0).poke((-5).S)
      dut.io.inputs(1).poke(10.S)
      dut.io.inputs(2).poke((-3).S)
      dut.io.inputs(3).poke(8.S)

      dut.io.weights(0).poke(2.S)
      dut.io.weights(1).poke((-1).S)
      dut.io.weights(2).poke(4.S)
      dut.io.weights(3).poke(1.S)

      dut.io.valid.poke(true.B)
      dut.clock.step()
      dut.clock.step()

      dut.io.result.expect((-24).S)
    }
  }

  it should "saturate on overflow" in {
    test(new ParallelMAC(vecSize = 4, dataBits = 8, accBits = 16, pipelineStages = 1)) { dut =>
      // inputs: [127, 127, 127, 127], weights: [127, 127, 127, 127]
      // Raw: 4 * 127 * 127 = 64516 (fits in 16-bit signed max 32767) -> saturate
      // Actually 127*127*4 = 64516 > 32767, so should saturate to 32767

      for (i <- 0 until 4) {
        dut.io.inputs(i).poke(127.S)
        dut.io.weights(i).poke(127.S)
      }

      dut.io.valid.poke(true.B)
      dut.clock.step()
      dut.clock.step()

      dut.io.result.expect(32767.S)  // Saturated to Int16 max
    }
  }

  it should "report latency correctly" in {
    // 64-element MAC with 2 pipeline stages in adder tree
    test(new ParallelMAC(vecSize = 64, dataBits = 8, accBits = 16, pipelineStages = 2)) { dut =>
      assert(dut.latency == 3, s"Expected latency 3 (2 adder + 1 output), got ${dut.latency}")
    }
  }
}
