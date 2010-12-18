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
module task4(clock,data,setting,start,out);
	input clock;
	input [32:0] data;
	input [32:0] setting;
	input start;
	output out;

	wire [31:0] setting;
	wire clock;	
	wire [31:0] data;
	wire start;
	wire out;
	parameter [16:0] offset = 1;
	reg [31:0] mask = 4;
	reg [31:0] pattern = 3;
	reg [31:0] maskbuf = 4;
	reg [31:0] patternbuf = 3;
	reg [31:0] databuf;
	reg [16:0] count = offset;
	reg [1:0] switch = 1;	
	assign out = switch;
	reg mask_update = 0;
	reg pattern_update = 0;
	
	//”становка значений в mask и pattern
	//производитс€ таким путем:
	//”станавливаем сначала на шине значение 1 (изменение mask) либо 2 (изменение pattern)
	//затем значение
	//затем 0 как обозначение окончание передачи
	//такой костыль необходим, ибо одна 32бит шина дл€ изменени€ 2 параметров 32бит 
	
	always @(setting) begin
		if (setting > 0) begin
			if (mask_update)
				maskbuf = setting;
			if (pattern_update)
				patternbuf = setting;
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
	
	always @(posedge clock) begin
				//‘иксирую изменение mask и pattern перед анализом фрейма
				//чтобы гарантировано не помен€лись их значени€ во врем€ анализа
				if (mask != maskbuf)
					mask = maskbuf;
				if (pattern != patternbuf)
					pattern = patternbuf;
				databuf = data;  //сохранение данных в буфер.
				if (start == 1) begin
					if (count == offset) begin
						//ѕри фиксации изменений mask и pattern здесь может
						//возникнуть ситуаци€, когда мы одновременно с data
						//сменим значени€ mask и pattern
						//и у нас в силу синхронности выполнени€ (обработчика шины setting и шины clock) может 
						//успеть изменитьс€ только mask, и тогда у нас будут смешанные параметры (один старый, один новый)
						//“ак что € предпочитаю использовать старые значени€ дл€ анализа фрейма
						//если они изменились уже во врем€ анализа фрейма
						if ((databuf & mask) == (databuf & pattern))  //Changes for task 3
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
	
endmodule 