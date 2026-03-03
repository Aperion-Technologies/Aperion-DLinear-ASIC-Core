// hardware/src/test/scala/dlinear/WeightBankSpec.scala
package dlinear

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class WeightBankSpec extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "WeightBank"

  it should "load weights sequentially" in {
    test(new WeightBank(size = 4, bits = 8)) { dut =>
      // Load weights [10, 20, 30, 40]
      dut.io.loadEn.poke(true.B)
      for (i <- 0 until 4) {
        dut.io.loadAddr.poke(i.U)
        dut.io.loadData.poke(((i + 1) * 10).S)
        dut.clock.step()
      }
      dut.io.loadEn.poke(false.B)
      dut.clock.step()

      // Read all weights in parallel
      dut.io.weights(0).expect(10.S)
      dut.io.weights(1).expect(20.S)
      dut.io.weights(2).expect(30.S)
      dut.io.weights(3).expect(40.S)
    }
  }

  it should "provide all weights simultaneously for parallel MAC" in {
    test(new WeightBank(size = 4, bits = 8)) { dut =>
      // Load
      dut.io.loadEn.poke(true.B)
      for (i <- 0 until 4) {
        dut.io.loadAddr.poke(i.U)
        dut.io.loadData.poke(i.S)
        dut.clock.step()
      }
      dut.io.loadEn.poke(false.B)

      // All weights available combinationally (no cycle delay)
      dut.io.weights(0).expect(0.S)
      dut.io.weights(1).expect(1.S)
      dut.io.weights(2).expect(2.S)
      dut.io.weights(3).expect(3.S)
    }
  }

  it should "preserve weights during operation" in {
    test(new WeightBank(size = 4, bits = 8)) { dut =>
      // Load weights
      dut.io.loadEn.poke(true.B)
      for (i <- 0 until 4) {
        dut.io.loadAddr.poke(i.U)
        dut.io.loadData.poke(100.S)
        dut.clock.step()
      }
      dut.io.loadEn.poke(false.B)

      // Run many cycles - weights should persist
      for (_ <- 0 until 100) {
        dut.clock.step()
        dut.io.weights(0).expect(100.S)
      }
    }
  }
}
