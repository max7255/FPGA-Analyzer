`timescale  1 ns / 1 ns
//-------------------------------------
// FIR_2D_5x5.v
//-------------------------------------
// History of Changes:
//	06-14-2009 Initial creation
//-------------------------------------
//-------------------------------------
// This module implements a 2D 5x5 Pixel FIR Filter.
// See FIR_1D_5.v for more details of filtering each line.
//-------------------------------------
// This module receives video data packets and writes this data to a frame buffer
// It also can respond to a command to return a copy of the video data
//-------------------------------------
//	FILT_COEFF = {C0,C1,C2...C24}
//	
//	[	C00	C01	C02	C03	C04	]
//	[	C05	C06	C07	C08	C09	]
//	[	C10	C11	C12	C13	C14	]
//	[	C15	C16	C17	C18	C19	]
//	[	C20	C21	C22	C23	C24	]
//
// C0-C24: 12-bit inputs represent range -8 to 7.99 using the following format
// 		BIT#: 				11 10 09 08 07 06 05 04 03 02 01 00
//  	H0-H4:				Q  m  m  m . f  f  f  f  f  f  f  f
//
// pixel inputs to FIR
// 		BIT#: 				11 10 09 08 07 06 05 04 03 02 01 00
//  	cm_in:			   . f  f  f  f  f  f  f  f  f  f  f  f
// binary pt is before bit 19 of output
//-------------------------------------
module FIR_2D_5x5(

input					CLK,	// Master Clock
input					RST, 	// Reset
input	wire			CE,   // clock enable

input	wire	[15:0]	IMG_SIZE_X, IMG_SIZE_Y,
input	wire	[399:0]	FILT_COEFF,
input	wire			BOUND_ABS, 

input	wire	[11:0]	DIN,
input	wire			DIN_STRB,
output	reg		[11:0]	DOUT,
output	reg				DOUT_STRB

);

parameter	MAX_DELAY = 8192;
parameter	IN_WIDTH=12;
parameter	OUT_WIDTH=24;

wire	[IN_WIDTH-1:0]		C0 =  {FILT_COEFF[399],FILT_COEFF[399],FILT_COEFF[399:384]};
wire	[IN_WIDTH-1:0]		C1 =  {FILT_COEFF[383],FILT_COEFF[383],FILT_COEFF[383:368]};
wire	[IN_WIDTH-1:0]		C2 =  {FILT_COEFF[367],FILT_COEFF[367],FILT_COEFF[367:352]};
wire	[IN_WIDTH-1:0]		C3 =  {FILT_COEFF[351],FILT_COEFF[351],FILT_COEFF[351:336]};
wire	[IN_WIDTH-1:0]		C4 =  {FILT_COEFF[335],FILT_COEFF[335],FILT_COEFF[335:320]};
wire	[IN_WIDTH-1:0]		C5 =  {FILT_COEFF[319],FILT_COEFF[319],FILT_COEFF[319:304]};
wire	[IN_WIDTH-1:0]		C6 =  {FILT_COEFF[303],FILT_COEFF[303],FILT_COEFF[303:288]};
wire	[IN_WIDTH-1:0]		C7 =  {FILT_COEFF[287],FILT_COEFF[287],FILT_COEFF[287:272]};
wire	[IN_WIDTH-1:0]		C8 =  {FILT_COEFF[271],FILT_COEFF[271],FILT_COEFF[271:256]};
wire	[IN_WIDTH-1:0]		C9 =  {FILT_COEFF[255],FILT_COEFF[255],FILT_COEFF[255:240]};
wire	[IN_WIDTH-1:0]		C10 = {FILT_COEFF[239],FILT_COEFF[239],FILT_COEFF[239:224]};
wire	[IN_WIDTH-1:0]		C11 = {FILT_COEFF[223],FILT_COEFF[223],FILT_COEFF[223:208]};
wire	[IN_WIDTH-1:0]		C12 = {FILT_COEFF[207],FILT_COEFF[207],FILT_COEFF[207:192]};
wire	[IN_WIDTH-1:0]		C13 = {FILT_COEFF[191],FILT_COEFF[191],FILT_COEFF[191:176]};
wire	[IN_WIDTH-1:0]		C14 = {FILT_COEFF[175],FILT_COEFF[175],FILT_COEFF[175:160]};
wire	[IN_WIDTH-1:0]		C15 = {FILT_COEFF[159],FILT_COEFF[159],FILT_COEFF[159:144]};
wire	[IN_WIDTH-1:0]		C16 = {FILT_COEFF[143],FILT_COEFF[143],FILT_COEFF[143:128]};
wire	[IN_WIDTH-1:0]		C17 = {FILT_COEFF[127],FILT_COEFF[127],FILT_COEFF[127:112]};
wire	[IN_WIDTH-1:0]		C18 = {FILT_COEFF[111],FILT_COEFF[111],FILT_COEFF[111:096]};
wire	[IN_WIDTH-1:0]		C19 = {FILT_COEFF[095],FILT_COEFF[095],FILT_COEFF[095:080]};
wire	[IN_WIDTH-1:0]		C20 = {FILT_COEFF[079],FILT_COEFF[079],FILT_COEFF[079:064]};
wire	[IN_WIDTH-1:0]		C21 = {FILT_COEFF[063],FILT_COEFF[063],FILT_COEFF[063:048]};
wire	[IN_WIDTH-1:0]		C22 = {FILT_COEFF[047],FILT_COEFF[047],FILT_COEFF[047:032]};
wire	[IN_WIDTH-1:0]		C23 = {FILT_COEFF[031],FILT_COEFF[031],FILT_COEFF[031:016]};
wire	[IN_WIDTH-1:0]		C24 = {FILT_COEFF[015],FILT_COEFF[015],FILT_COEFF[015:000]};



wire	[15:0]	ADJ_DELAY=IMG_SIZE_X*3+16'd5; // Fixme figure the actual delay out


wire	[OUT_WIDTH-1:0]			line1_cascade_to_line2;
FIR_1D_5_LOGIC	#(.IN_WIDTH(IN_WIDTH), .OUT_WIDTH(OUT_WIDTH)) fir_line1	(
	.CLK(CLK), .RST(RST), .CE(CE),
	.H0(C24),.H1(C23),.H2(C22),.H3(C21),.H4(C20),  // Filter Coefficients
	.X(DIN),    // 12-bit inputs 
	.X_STRB(1'b1),	
	.BCOUT(),    // cascade input to next FIR
	.C(48'd0),
	.PCIN(48'd0), // Cascade input to first DSP slice
	.OPMODE(8'b0_0_0_0_11_01), // use C
	.Y(),
	.PCOUT(line1_cascade_to_line2),    // Filter output
	.Y_STRB()  // Strobes when done
);

wire	[IN_WIDTH-1:0]	din_line2;
BIG_ADJ_DELAY	#( .MAX_DELAY(MAX_DELAY), .WIDTH(IN_WIDTH) )	b_adj_d1	(
	.CLK(CLK),
	.CE(CE),
	.DELAY(ADJ_DELAY),
	.DIN(DIN),
	.DOUT(din_line2)
);



wire	[OUT_WIDTH-1:0]			line2_cascade_to_line3;
FIR_1D_5_LOGIC	#(.IN_WIDTH(IN_WIDTH), .OUT_WIDTH(OUT_WIDTH)) fir_line2	(
	.CLK(CLK), .RST(RST), .CE(CE),
	.H0(C19),.H1(C18),.H2(C17),.H3(C16),.H4(C15),  // Filter Coefficients
	.X(din_line2),    // turn 12-bit inputs into 18 bits
	.X_STRB(1'b1),	
	.BCOUT(),    // cascade input to next FIR
	.C(48'd0),
	.PCIN(line1_cascade_to_line2), // Cascade input to first DSP slice
	.OPMODE(8'b0_0_0_0_01_01), // use PCIN	
	.Y(line2_cascade_to_line3),
	.PCOUT(),    // Filter output
	.Y_STRB()  // Strobes when done
);

wire	[IN_WIDTH-1:0]	din_line3;
BIG_ADJ_DELAY	#( .MAX_DELAY(MAX_DELAY), .WIDTH(IN_WIDTH) )	b_adj_d2	(
	.CLK(CLK),
	.CE(CE),
	.DELAY(ADJ_DELAY+2),
	.DIN(din_line2),
	.DOUT(din_line3)
);


/**** Break cascade chain here because of 16 DSPSlice limit *****/
reg		[OUT_WIDTH-1:0]	c_break=0;
always @(posedge CLK)
	c_break <= line2_cascade_to_line3;



wire	[OUT_WIDTH-1:0]			line3_cascade_to_line4;
FIR_1D_5_LOGIC	#(.IN_WIDTH(IN_WIDTH), .OUT_WIDTH(OUT_WIDTH)) fir_line3	(
	.CLK(CLK), .RST(RST), .CE(CE),
	.H0(C14),.H1(C13),.H2(C12),.H3(C11),.H4(C10),  // Filter Coefficients
	.X(din_line3),    // turn 12-bit inputs into 18 bits
	.X_STRB(1'b1),	
	.BCOUT(),    // cascade input to next FIR
	.C(c_break),
	.PCIN(48'd0), // Cascade input to first DSP slice
	.OPMODE(8'b0_0_0_0_11_01), // use C	
	.Y(),
	.PCOUT(line3_cascade_to_line4),    // Filter output
	.Y_STRB()  // Strobes when done
);

wire	[IN_WIDTH-1:0]	din_line4;
BIG_ADJ_DELAY	#( .MAX_DELAY(MAX_DELAY), .WIDTH(IN_WIDTH) )	b_adj_d3	(
	.CLK(CLK),
	.CE(CE),
	.DELAY(ADJ_DELAY),
	.DIN(din_line3),
	.DOUT(din_line4)
);



wire	[OUT_WIDTH-1:0]			line4_cascade_to_line5;
FIR_1D_5_LOGIC	#(.IN_WIDTH(IN_WIDTH), .OUT_WIDTH(OUT_WIDTH)) fir_line4	(
	.CLK(CLK), .RST(RST), .CE(CE),
	.H0(C9),.H1(C8),.H2(C7),.H3(C6),.H4(C5),  // Filter Coefficients
	.X(din_line4),    // turn 12-bit inputs into 18 bits
	.X_STRB(1'b1),	
	.BCOUT(),    // cascade input to next FIR
	.C(48'd0),
	.PCIN(line3_cascade_to_line4), // Cascade input to first DSP slice
	.OPMODE(8'b0_0_0_0_01_01), // use PCIN		
	.Y(),
	.PCOUT(line4_cascade_to_line5),    // Filter output
	.Y_STRB()  // Strobes when done
);

wire	[IN_WIDTH-1:0]	din_line5;
BIG_ADJ_DELAY	#( .MAX_DELAY(MAX_DELAY), .WIDTH(IN_WIDTH) )	b_adj_d4	(
	.CLK(CLK),
	.CE(CE),
	.DELAY(ADJ_DELAY),
	.DIN(din_line4),
	.DOUT(din_line5)
);


wire	[OUT_WIDTH-1:0]	y_out_full;
FIR_1D_5_LOGIC	#(.IN_WIDTH(IN_WIDTH), .OUT_WIDTH(OUT_WIDTH)) fir_line5	(
	.CLK(CLK), .RST(RST), .CE(CE),
	.H0(C4),.H1(C3),.H2(C2),.H3(C1),.H4(C0),  // Filter Coefficients
	.X(din_line5),    // turn 12-bit inputs into 18 bits
	.X_STRB(1'b1),	
	.BCOUT(),    // cascade input to next FIR
	.C(48'd0),
	.PCIN(line4_cascade_to_line5), // Cascade input to first DSP slice
	.OPMODE(8'b0_0_0_0_01_01), // use PCIN		
	.Y(y_out_full),
	.PCOUT(),    // Filter output
	.Y_STRB()  // Strobes when done
);



// Generate the appropriate frame strobes
reg					din_strb_reg=0;
wire				start_frame=DIN_STRB&&!din_strb_reg;
reg		[1:0]		rgb_cnt=0;  // used to generate pixel increment strobe for serialized RGB data
reg		[15:0]		pix_cnt=0;
reg		[15:0]		line_cnt=0;
reg		[2:0]		line_buff_dly=0;
reg		[7:0]		fir_dly=0;
wire				last_pix=(pix_cnt==IMG_SIZE_X)&&(rgb_cnt==2'd2);	
always @(posedge CLK)
	begin
	din_strb_reg <= DIN_STRB;
	pix_cnt <= (start_frame ||last_pix)? 16'd1 : (rgb_cnt==2'd2)? pix_cnt+1 : pix_cnt;
	rgb_cnt <=	(start_frame || rgb_cnt==2'd2)? 2'b0 : (fir_dly==8'd0)? rgb_cnt+1 : rgb_cnt;	
	fir_dly <= (start_frame)? 5*4+13-1+2 : (fir_dly!=8'd0)? fir_dly-1 : fir_dly;
	line_buff_dly <= (start_frame)? 3'd2 : (last_pix&&(line_buff_dly!=0))? line_buff_dly-1 : line_buff_dly;
	line_cnt <= (start_frame)? IMG_SIZE_Y : (last_pix&&(line_buff_dly==0)&&(line_cnt!=0))? line_cnt-1 : line_cnt;
	end

// Apply bounding
// first handle negative:
reg 	[OUT_WIDTH-2:0]	not_negative;
reg 			not_negative_strobe = 0;
always @(posedge CLK)
	begin
	if (y_out_full[OUT_WIDTH-1]) // negative
		begin
		if (BOUND_ABS) // absolute value
			not_negative <= 0 - y_out_full; 
		else // clip to zero
			not_negative <= 0; 
		end
	else
		not_negative <= y_out_full[OUT_WIDTH-2:0];
	not_negative_strobe <= (line_cnt!=0)&&(line_buff_dly==0);
	end

// Next handle greater than one
always @(posedge CLK)
	begin
	if (not_negative[OUT_WIDTH-2:20]!=0) // >1
		DOUT <= 12'hFFF;
	else
		DOUT <= not_negative[19:8];
	DOUT_STRB <= not_negative_strobe;
	end

//// Register the outputs
//always @(posedge CLK)
//	begin
//	DOUT <= y_out_full[23:12];
//	DOUT_STRB <= (line_cnt!=0)&&(line_buff_dly==0);
//	end

/*
// Chipscope
wire	[35:0]	ctrl0;
icon_tst icontst (.CONTROL0(ctrl0));
tst_ila tstila (
    .CONTROL(ctrl0), // INOUT BUS [35:0]
    .CLK(CLK), // IN
    .TRIG0({not_negative_strobe, not_negative[34:12]}) // IN BUS [23:0]
	);
*/

endmodule

//-------------------------------------
// Simulation test bench
//-------------------------------------
// History of Changes:
//	6-15-2009 Initial creation
//-------------------------------------

module fir2D_tst;
// Clock generator
reg				CLK = 0;
initial #4 forever #4 CLK = !CLK;



wire	[399:0]		FILT_COEFF	=	{	16'h01_00,	16'h01_00,	16'h01_00,	16'h01_00,	16'h01_00,	
										16'h01_00,	16'h01_00,	16'h01_00,	16'h01_00,	16'h01_00,
										16'h01_00,	16'h01_00,	16'h01_00,	16'h01_00,	16'h01_00,
										16'h01_00,	16'h01_00,	16'h01_00,	16'h01_00,	16'h01_00,
										16'h01_00,	16'h01_00,	16'h01_00,	16'h01_00,	16'h01_00	};	
		

reg		[2:0]		one_in_three=1;
reg		[12:0]		tb_cnt=0; 
always @(posedge CLK)
	begin
	one_in_three <= {one_in_three[1:0],one_in_three[2]};
	tb_cnt <= (one_in_three[2])? tb_cnt+1 : tb_cnt;
	end

wire	[15:0]	IMG_SIZE_X=256;
wire	[15:0]	IMG_SIZE_Y=16;

wire	[11:0]	DIN=(tb_cnt[7:0]==0)&&one_in_three[2]? 12'hfff : 12'd0;
wire			DIN_STRB=tb_cnt[12];
wire	[15:0]	DOUT;
wire			DOUT_STRB;

FIR_2D_5x5	fir2d_logic_tst(
	.CLK(CLK),.RST(1'b0), .CE(1'b1),
	.IMG_SIZE_X(IMG_SIZE_X),.IMG_SIZE_Y(IMG_SIZE_Y),
	.FILT_COEFF(FILT_COEFF),
	.DIN(DIN),.DIN_STRB(DIN_STRB),
	.DOUT(DOUT),.DOUT_STRB(DOUT_STRB)	);


endmodule

