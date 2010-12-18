`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:39:45 09/18/2010
// Design Name:   task3
// Module Name:   C:/Workspace/lvk/task3/test_task3.v
// Project Name:  task3
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: task3
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

module test_task3;

	// Inputs
	reg [32:0] data;
	reg start;

	// Outputs
	wire out;
	wire clock_w;
	clock c(clock_w);
	task3 uut (
			.clock(clock_w),
			.data(data), 
			.start(start), 
			.out(out)
		);
		
	initial begin
		
		// Instantiate the Unit Under Test (UUT)
	
		
	
		// Initialize Inputs
		@(posedge clock_w) begin
			data <= 3;
			start <= 1;
		end;
		@(posedge clock_w) begin
			data <= 32;
			start <= 0;
		end;
		@(posedge clock_w) begin
			data <= 0;
			start <= 1;
		end;
		@(posedge clock_w) begin
			data <= 10;
			start <= 0;
		end;
		@(posedge clock_w) begin
			data <= 3;
			start <= 1;
		end;
		@(posedge clock_w) begin
			data <= 4;
		end;
		@(posedge clock_w) begin
			data <= 5;
		end;
		@(posedge clock_w) begin
			data <= 32'b1001;
		end;
		@(posedge clock_w) begin
			data <= 5;
		end;
		@(posedge clock_w) begin
			data <= 4;
			start <= 0;
		end;
		@(posedge clock_w) begin
			data <= 3;
			start <= 1;
		end;
		@(posedge clock_w) begin
			data <= 4;
		end;
		@(posedge clock_w) begin
			data <= 5;
		end;
		@(posedge clock_w) begin
			data <= 32'b1001;
		end;
		@(posedge clock_w) begin
			data <= 5;
		end;
		@(posedge clock_w) begin
			data <= 4;
			start <= 0;
		end;
		#100;
     		
	end;
	
   
endmodule

