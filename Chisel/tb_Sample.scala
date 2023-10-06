import chisel3._
import chisel3.util._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import scala.util.control.Breaks._

class ToggleTest extends AnyFlatSpec with ChiselScalatestTester {
  "DUT" should "pass" in {

    test(
      new Toggle(
		//
		// Arugments to parameterize the chisel designs
		//
      )
    ) { dut =>
	
      // First, set an input called "start" to 0
      dut.io.start.poke(0.U)
	  
	  // Run the circuit for one-clock
      dut.clock.step(1)

      // Perform the first test
      val test1 = Integer.parseInt(TestingSample.SampleFormulaFunctions(1, 2).U

      // Set the start to 1
      dut.io.start.poke(1.U)

	  // Set an input called "in1" to the test1 value
      dut.io.in1.poke(test1)

	  // Run the circuit for one-clock
      dut.clock.step(1)

      // Check the output from "out1" with a value like 0 
      if (dut.io.out1.peek().litValue.toInt == 0) {
        print("[*] Successful\n");
      } else {
        print("[x] NOT successful!\n");
      }

      // Remove the start bit again (disable chip)
      dut.io.start.poke(0.U)
    }
  }
}