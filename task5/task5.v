`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:58:28 12/01/2010 
// Design Name: 
// Module Name:    task5
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
module task5(SCLK, MOSI, MISO, SS);

	//SS (slave select) for my module must be equal to = 4'b1111
	//Due to full synchronicity of SPI bus
	//I removed all sync creating functionality
	//Signal over MOSI (from master to our slave module)
	//follow in order
	//first - value code (0 - data, 1 - start flag, 2 - mask, 3 - pattern)
	//second - corresponding value

	input SCLK;
	input MOSI;
	input SS;
	output MISO;

	wire SS;
	wire SCLK;	
	wire MOSI;
	wire MISO;
	reg [4:0] bitcount = 0;
	reg param = 1;
	parameter [16:0] offset = 0;
	parameter N = 4; // Size of data buffer
	parameter K = 2; //equals to log2(N)
	parameter ptrSize = 1;
	reg [31:0] mask = 4;
	reg start;
	reg [31:0] pattern = 3;
	reg [31:0]databuf[N-1:0];
	reg [K:0] databufadr = 0;
	reg [K:0] datareadbufadr = 0;
	reg [16:0] count = 0;
	reg [1:0] switch = 1;	
	reg write = 1;
	reg dataset = 0;
	assign MISO = switch;

	reg [1:0] datastate = 0;

	always @(posedge SCLK) 
	begin
		if (SS) begin
			if (param) begin
				datastate = (datastate << 1) + MOSI;
				param = bitcount < 2;
				bitcount = bitcount * param;
			end
			else
			if (datastate == 1) begin
				start = MOSI;
				param = 1;
				bitcount = 0;
			end
			else
			if (datastate == 2) begin
				mask = (mask << 1) + MOSI;
				param = !(bitcount);
			end
			else if (datastate == 3) begin
				pattern = (pattern << 1) + MOSI;
				param = !(bitcount);
			end
			else if (datastate == 0) begin
				databuf[databufadr] = (databuf[databufadr] << 1) + MOSI;
				param = !(bitcount);
				dataset = param;
			end
		end
		if ((!bitcount) & dataset)
		begin
			datareadbufadr = databufadr;
			databufadr = databufadr + 1;
			if (start == 1) begin
				if (count == offset) begin
					if ((databuf[datareadbufadr] & mask) == (databuf[datareadbufadr] & pattern))  //Changes for task 3
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
			dataset = 0;
		end
		bitcount = bitcount + 1;
	end
	initial begin
		for(databufadr = 0; databufadr < N; databufadr = databufadr + 1) 
			databuf[databufadr] = 0;
		databufadr = 0;
			
	end
endmodule 