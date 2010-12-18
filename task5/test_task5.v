`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:23:10 12/01/2010
// Design Name:   task5
// Module Name:   D:/lvk/task5/test_task5.v
// Project Name:  task5
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: task5
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



module test_task5;


	reg[31:0] temp;
	// Inputs
	reg data;
	reg setting;
	reg SlaveSelect;
	reg [31:0] inbuf=0;
	reg [1:0] mode=0;
	reg [4:0] bitcount=0;
	reg [1:0]send = 0;
	// Outputs
	wire out;
	wire clock_w;
	
	// Instantiate the Clock Unit
	clock c(clock_w);
	// Instantiate the Unit Under Test (UUT)
	task5 uut (
		.SCLK(clock_w), 
		.MOSI(data),  
		.MISO(out),
		.SS(SlaveSelect)
	);
	
	always @(negedge clock_w) begin
			SlaveSelect = send > 0;
			unload();
			if (!send) begin
				if (temp == 1) begin
					mode = 2;
					inbuf = 4'b1111;
					send = 1;
				end else
				if (temp == 2) begin
					mode = 3;
					inbuf = 4'b0011;
					send = 1;
				end else 
				if (temp == 3) begin
					mode = 1;
					inbuf = 1;
					send = 1;
				end else
				if (temp == 4) begin
					mode = 0;
					inbuf = 4'b0011;
					send = 1;
				end
				if (temp == 5) begin
					mode = 0;
					inbuf = 4'b1010;
					send = 1;
				end
			end
			if (send == 1)
				temp = temp + 1;
		end

	task unload;
		if (send == 1) begin
			SlaveSelect = 1;
			data = mode[1];
			send[0:0] = 0;
			send[1:1] = 1;
		end
		else
		if (send == 2) begin
			data = mode[0];
			send[0:0] = 1;
			send[1:1] = 1;
		end
		else
		if (send > 2) begin
			if (mode == 0) begin
				data = inbuf[31];
				inbuf = inbuf << 1;
				bitcount = bitcount + 1;
				send = send * (bitcount > 0);
			end
			else
			if (mode == 1) begin
				data = inbuf[0];
				send = 0;
			end
			else
			if (mode >= 2) begin
				data = inbuf[31];
				inbuf = inbuf << 1;
				bitcount = bitcount + 1;
				send = send * (bitcount > 0);
			end
		end
	endtask

	initial begin
		// Initialize Inputs
		data = 0;
		setting = 0;
		temp = 1;
		SlaveSelect = 0;
		
		

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
      
endmodule

