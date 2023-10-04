module Switch_Control (
    input  wire clock,        // Clock input
    output reg  switch = 0   // Initialize switch to OFF (logic low)
);

reg toggle = 0; // Signal for toggling the switch

always @(posedge clock) begin
    toggle <= ~toggle; // Toggle the switch state on rising edge of the clock
end

always @(toggle) begin
switch = toggle; // Assign the switch state to the output port
end

endmodule