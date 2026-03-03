// hardware/src/test/scala/dlinear/PipelinedAdderTreeSpec.scala
package dlinear

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class PipelinedAdderTreeSpec extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "PipelinedAdderTree"

  it should "sum 8 values correctly with pipeline delay" in {
    test(new PipelinedAdderTree(inputCount = 8, inputBits = 8, pipelineStages = 2)) { dut =>
      // Input: [1, 2, 3, 4, 5, 6, 7, 8] = sum 36
      for (i <- 0 until 8) {
        dut.io.inputs(i).poke((i + 1).S)
      }
      dut.io.valid.poke(true.B)

      // Wait for pipeline (2 stages)
      dut.clock.step()
      dut.clock.step()

      dut.io.result.expect(36.S)
      dut.io.resultValid.expect(true.B)
    }
  }

  it should "handle negative numbers" in {
    test(new PipelinedAdderTree(inputCount = 4, inputBits = 8, pipelineStages = 1)) { dut =>
      // Input: [-10, 20, -30, 40] = sum 20
      dut.io.inputs(0).poke((-10).S)
      dut.io.inputs(1).poke(20.S)
      dut.io.inputs(2).poke((-30).S)
      dut.io.inputs(3).poke(40.S)
      dut.io.valid.poke(true.B)

      dut.clock.step()

      dut.io.result.expect(20.S)
    }
  }

  it should "have deterministic latency" in {
    test(new PipelinedAdderTree(inputCount = 8, inputBits = 8, pipelineStages = 2)) { dut =>
      // Send multiple inputs and verify consistent delay
      for (testRun <- 0 until 3) {
        for (i <- 0 until 8) {
          dut.io.inputs(i).poke((testRun * 10 + i).S)
        }
        dut.io.valid.poke(true.B)
        dut.clock.step()
      }

      // After 2 more cycles, first result should appear
      dut.clock.step()
      dut.io.resultValid.expect(true.B)
    }
  }

  it should "report correct pipeline depth" in {
    test(new PipelinedAdderTree(inputCount = 64, inputBits = 16, pipelineStages = 3)) { dut =>
      // 64 inputs -> log2(64) = 6 levels -> with 3 stages
      assert(dut.latency == 3, s"Expected latency 3, got ${dut.latency}")
    }
  }
}
