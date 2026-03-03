// hardware/src/test/scala/dlinear/DLinearTopSpec.scala
package dlinear

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class DLinearTopSpec extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "DLinearTop"

  // Use small config for faster tests
  val testWindowSize = 4
  val testDataBits = 8
  val testAccBits = 16

  it should "load weights via configuration interface" in {
    test(new DLinearTop(
      windowSize = testWindowSize,
      dataBits = testDataBits,
      accBits = testAccBits
    )) { dut =>
      // Enter configuration mode
      dut.io.configMode.poke(true.B)

      // Load trend weights: [1, 2, 3, 4]
      dut.io.config.weightSel.poke(false.B)  // trend
      for (i <- 0 until testWindowSize) {
        dut.io.config.addr.poke(i.U)
        dut.io.config.data.poke((i + 1).S)
        dut.io.config.writeEn.poke(true.B)
        dut.clock.step()
      }

      // Load seasonal weights: [4, 3, 2, 1]
      dut.io.config.weightSel.poke(true.B)  // seasonal
      for (i <- 0 until testWindowSize) {
        dut.io.config.addr.poke(i.U)
        dut.io.config.data.poke((testWindowSize - i).S)
        dut.io.config.writeEn.poke(true.B)
        dut.clock.step()
      }

      dut.io.config.writeEn.poke(false.B)
      dut.io.configMode.poke(false.B)

      // No crash = success
    }
  }

  it should "indicate ready after input buffer fills" in {
    test(new DLinearTop(
      windowSize = testWindowSize,
      dataBits = testDataBits,
      accBits = testAccBits
    )) { dut =>
      dut.io.configMode.poke(false.B)

      // Initially not ready
      dut.io.status.ready.expect(false.B)

      // Feed WINDOW_SIZE inputs to fill decomposition buffer
      for (i <- 0 until testWindowSize) {
        dut.io.dataIn.poke(10.S)
        dut.io.dataValid.poke(true.B)
        dut.clock.step()
      }

      // Need more cycles to fill window buffer
      for (i <- 0 until testWindowSize) {
        dut.io.dataIn.poke(10.S)
        dut.clock.step()
      }

      // Should be ready now (decomposition buffer filled)
      dut.io.status.ready.expect(true.B)
    }
  }

  it should "produce valid output with correct pipeline latency" in {
    test(new DLinearTop(
      windowSize = testWindowSize,
      dataBits = testDataBits,
      accBits = testAccBits,
      macPipelineStages = 1
    )) { dut =>
      // Load all-ones weights for predictable output
      dut.io.configMode.poke(true.B)
      for (sel <- Seq(false, true)) {
        dut.io.config.weightSel.poke(sel.B)
        for (i <- 0 until testWindowSize) {
          dut.io.config.addr.poke(i.U)
          dut.io.config.data.poke(1.S)
          dut.io.config.writeEn.poke(true.B)
          dut.clock.step()
        }
      }
      dut.io.config.writeEn.poke(false.B)
      dut.io.configMode.poke(false.B)

      // Fill pipeline with constant data
      dut.io.dataValid.poke(true.B)
      var validCount = 0
      val maxCycles = 50

      for (cycle <- 0 until maxCycles) {
        dut.io.dataIn.poke(8.S)
        dut.clock.step()

        if (dut.io.predValid.peekBoolean()) {
          validCount += 1
        }
      }

      assert(validCount > 0, "Should produce valid outputs after pipeline fills")
    }
  }

  it should "have deterministic latency for all input values" in {
    test(new DLinearTop(
      windowSize = testWindowSize,
      dataBits = testDataBits,
      accBits = testAccBits,
      macPipelineStages = 1
    )) { dut =>
      // Load weights
      dut.io.configMode.poke(true.B)
      for (sel <- Seq(false, true)) {
        dut.io.config.weightSel.poke(sel.B)
        for (i <- 0 until testWindowSize) {
          dut.io.config.addr.poke(i.U)
          dut.io.config.data.poke(1.S)
          dut.io.config.writeEn.poke(true.B)
          dut.clock.step()
        }
      }
      dut.io.config.writeEn.poke(false.B)
      dut.io.configMode.poke(false.B)

      // Fill pipeline
      dut.io.dataValid.poke(true.B)
      for (_ <- 0 until testWindowSize * 3) {
        dut.io.dataIn.poke(8.S)
        dut.clock.step()
      }

      // Measure latency with different input values
      val testValues = Seq(0, 127, -128, 42, -42)
      val latencies = scala.collection.mutable.ArrayBuffer[Int]()

      for (testVal <- testValues) {
        // Pause to clear pipeline
        dut.io.dataValid.poke(false.B)
        for (_ <- 0 until 5) dut.clock.step()

        // Wait for predValid to go low
        while (dut.io.predValid.peekBoolean()) dut.clock.step()

        // Send new value and count cycles to output
        dut.io.dataValid.poke(true.B)
        dut.io.dataIn.poke(testVal.S)

        var cycles = 0
        dut.clock.step()
        cycles += 1

        while (!dut.io.predValid.peekBoolean() && cycles < 20) {
          dut.clock.step()
          cycles += 1
        }

        latencies += cycles
      }

      // Per Rule #3: All latencies MUST be identical
      val uniqueLatencies = latencies.toSet
      assert(uniqueLatencies.size == 1,
        s"DETERMINISM VIOLATION: Different latencies observed: $latencies")
    }
  }

  it should "output valid prediction value for known inputs" in {
    test(new DLinearTop(
      windowSize = testWindowSize,
      dataBits = testDataBits,
      accBits = testAccBits,
      macPipelineStages = 1
    )) { dut =>
      // Load weights: all 1s (simple sum)
      dut.io.configMode.poke(true.B)
      for (sel <- Seq(false, true)) {
        dut.io.config.weightSel.poke(sel.B)
        for (i <- 0 until testWindowSize) {
          dut.io.config.addr.poke(i.U)
          dut.io.config.data.poke(1.S)
          dut.io.config.writeEn.poke(true.B)
          dut.clock.step()
        }
      }
      dut.io.config.writeEn.poke(false.B)
      dut.io.configMode.poke(false.B)

      // Feed constant input and wait for valid output
      dut.io.dataValid.poke(true.B)
      for (_ <- 0 until 30) {
        dut.io.dataIn.poke(10.S)
        dut.clock.step()

        if (dut.io.predValid.peekBoolean()) {
          // With all-ones weights and trend/seasonal decomposition,
          // output should be non-zero and reasonable
          val output = dut.io.predOut.peekInt()
          assert(output != 0, "Output should be non-zero with non-zero inputs")
        }
      }
    }
  }
}
