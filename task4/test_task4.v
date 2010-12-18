`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:23:10 12/01/2010
// Design Name:   task4
// Module Name:   D:/lvk/task4/test_task4.v
// Project Name:  task4
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: task4
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module clock (clock_w);
output clock_w;
reg clock_r = 0;
wire clock_w;
assign clock_w = clock_r;
initial clock_r = 0;

always begin
	#1 clock_r <= ~clock_r;
end
endmodule

module test_task4;


	reg temp;
	// Inputs
	reg [31:0] data;
	reg [31:0] setting;
	reg start;

	// Outputs
	wire out;
	wire clock_w;
	
	// Instantiate the Clock Unit
	clock c(clock_w);
	// Instantiate the Unit Under Test (UUT)
	task4 uut (
		.clock(clock_w), 
		.data(data), 
		.setting(setting), 
		.start(start), 
		.out(out)
	);

	initial begin
		// Initialize Inputs
		data = 0;
		setting = 0;
		start = 0;
		
		
		@(posedge clock_w) begin
			setting = 1;
			start = 1;
			data = 4'b0110;
		end
		@(posedge clock_w) begin
			setting = 0110;
			data = 4'b0111;
		end
		@(posedge clock_w) begin
			setting = 0;
			data = 4'b0110;
		end
		@(posedge clock_w) begin
			setting = 2;
			start = 1;
			data = 4'b0110;
		end
		@(posedge clock_w) begin
			setting = 0110;
			data = 4'b0111;
		end
		@(posedge clock_w) begin
			setting = 0;
			start = 0;
			data = 4'b0110;
		end
		@(posedge clock_w) begin
			start = 1;
			data = 4'b0110;
		end
		
		

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
      
endmodule

