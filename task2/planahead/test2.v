`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:43:59 09/18/2010 
// Design Name: 
// Module Name:    test2 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module test2(clock,data,start,out);
	input clock;
	input [32:0] data;
	input start;
	output out;
	
	wire clock;
	wire [32:0] data;
	wire start;
	wire [32:0] out;
	parameter [16:0] offset = 1;
	parameter [32:0] mask = 4;
	reg [16:0] count = offset;

	reg [1:0] switch = 1;	
	/*assign out = switch;

	always @(posedge clock) begin
			if (start == 1) begin
				if (count == offset) begin
					if (data == mask)
						switch <= 1;
					else
						switch <= 0;
				end
				else
					switch <= 0;
				count <= count + 1;
			end
			else begin
				count <= 0;
				switch <= 0;
			end
	end*/	
	always @(posedge clock) begin
		if (start)
			count <= count + 1;
		else
			count <= 0;
	end

	assign out = (~|(count ^ offset)) & (~|(data ^ mask)) & start;
	
endmodule 