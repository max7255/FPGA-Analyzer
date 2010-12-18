`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:58:28 12/01/2010 
// Design Name: 
// Module Name:    task4 
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
module task4(SCLK,MOSI,setting,start,MISO);
	input SCLK;
	input [32:0] MOSI;
	input [32:0] setting;
	input start;
	output MISO;

	wire [31:0] setting;
	wire SCLK;	
	wire [31:0] MOSI;
	wire start;
	wire MISO;
	parameter [16:0] offset = 1;
	parameter N = 3;
	parameter ptrSize = 1;
	reg [31:0] mask = 4;
	reg [31:0] pattern = 3;
	reg [31:0] maskbuf [N:0];
	reg [31:0] patternbuf [N:0];
	reg [ptrSize:0] maskwptr = 2'b01;
	reg [ptrSize:0] maskrptr = 0;
	reg [ptrSize:0] patternwptr = 1;
	reg [ptrSize:0] patternrptr = 0;
	reg masksw = 0;
	reg patternsw = 0;
	reg [31:0] MOSIbuf;
	reg [16:0] count = offset;
	reg [1:0] switch = 1;	
	assign MISO = switch;
	reg mask_update = 0;
	reg pattern_update = 0;
	reg [1:0] data_state = 0;
	//Установка значений в mask и pattern
	//производится таким путем:
	//Устанавливаем сначала на шине значение 1 (изменение mask) либо 2 (изменение pattern)
	//затем значение
	//затем 0 как обозначение окончание передачи
	//такой костыль необходим, ибо одна 32бит шина для изменения 2 параметров 32бит 
	
	always @(setting) begin
		if (setting > 0) begin
			if (mask_update) begin
				maskbuf[maskwptr] = setting;
				if (masksw == 0)
				begin
					maskwptr = maskwptr + 1;
					masksw = 1;
				end
			end
			if (pattern_update) begin
				patternbuf[patternwptr] = setting;
				if (patternsw == 0)
				begin
					patternwptr = patternwptr + 1;
					patternsw = 1;
				end
			end
			if (setting == 1)
				mask_update = 1;
			if (setting == 2)
				pattern_update = 1;
		end 
		else
		begin
			mask_update = 0;
			pattern_update = 0;
		end
	end
	
	always @(posedge SCLK) begin
		if (datastate == 2'b11)
			datastate = MOSI;
		else 
		if (datastate == 1) begin
			mask = MOSI;
			datastate = 2'b11;
		end
		else if (datastate == 2) begin
			pattern = MOSI;
			datastate = 2'b11;
		end
		else if (datastate == 0) begin
			if (start == 1) begin
				if (count == offset) begin
					//выгрузка mask и pattern
					if (masksw == 1)
						maskrptr = maskrptr + 1;
					mask = maskbuf[maskrptr];
					if (masksw) begin
						masksw = 0;
					end
					if (patternsw == 1)
						patternrptr = patternrptr + 1;
					pattern = patternbuf[patternrptr];
					if (patternsw) begin
						patternsw = 0;
					end
					if ((MOSIbuf & mask) == (MOSIbuf & pattern))  //Changes for task 3
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
		end	
		datastate = 2'b11;
	end
	initial 
	begin
		patternbuf[0] = 4;
		maskbuf[0] = 3;
		patternwptr = 2'b01;
	end
endmodule 