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
	
	//��������� �������� � mask � pattern
	//������������ ����� �����:
	//������������� ������� �� ���� �������� 1 (��������� mask) ���� 2 (��������� pattern)
	//����� ��������
	//����� 0 ��� ����������� ��������� ��������
	//����� ������� ���������, ��� ���� 32��� ���� ��� ��������� 2 ���������� 32��� 
	
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
				//�������� ��������� mask � pattern ����� �������� ������
				//����� ������������� �� ���������� �� �������� �� ����� �������
				if (mask != maskbuf)
					mask = maskbuf;
				if (pattern != patternbuf)
					pattern = patternbuf;
				databuf = data;  //���������� ������ � �����.
				if (start == 1) begin
					if (count == offset) begin
						//��� �������� ��������� mask � pattern ����� �����
						//���������� ��������, ����� �� ������������ � data
						//������ �������� mask � pattern
						//� � ��� � ���� ������������ ���������� (����������� ���� setting � ���� clock) ����� 
						//������ ���������� ������ mask, � ����� � ��� ����� ��������� ��������� (���� ������, ���� �����)
						//��� ��� � ����������� ������������ ������ �������� ��� ������� ������
						//���� ��� ���������� ��� �� ����� ������� ������
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