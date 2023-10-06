module Switch_Control_tb;

  // Inputs
  reg clock;

  // Outputs
  reg switch;

  // Clock generation process
  always begin
    #5 clock = ~clock; // Toggle the clock every 5 time units (adjust as needed)
  end

  // Initialize signals
  initial begin
    clock = 0;
    switch = 0;

    // Simulate for some time
    #100;

    // Monitor the switch signal
    $display("Switch = %b", switch);

    // Stop simulation
    $finish;
  end

endmodule
