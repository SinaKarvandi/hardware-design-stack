module Switch_Control_tb;

  // Inputs
  reg clock;
  
  // Outputs
  wire switch;

  // Instantiate the Switch_Control module
  Switch_Control DUT (
    .clock(clock),
    .switch(switch)
  );

  // Define clock parameters
  reg clock_enable = 1;
  reg#1 clock_period = 10; // Clock period in time units (adjust as needed)
  
  // Testbench clock generation
  always #clock_period clock = clock_enable ? ~clock : clock;

  // Initialize signals
  initial begin
    clock = 0;
    clock_enable = 1;
    
    // Initialize simulation time
    $dumpfile("Switch_Control_tb.vcd");
    $dumpvars(0, Switch_Control_tb);
    
    // Simulate for some time
    #100;
    
    // Stop simulation
    $finish;
  end

  // Monitor the switch signal
  always @(posedge clock) begin
    $display("Switch = %b", switch);
  end

endmodule
