`timescale  1 ns / 1 ns
//-------------------------------------
// FIR_1D_5.v
//-------------------------------------
// History of Changes:
//	06-14-2009 Initial creation
//-------------------------------------
//-------------------------------------
// 	This module implements a 5 tap FIR filter using
//	Spartan 6 DSP48A1 primitives.  This is a basically
//	a 5 tap version of the FIR Filter Adder Tree detailed
//  in the Spartan-6 FPGA DSP48A1 User Guide.
// 
//	y(n)=H0*x(n)+H1*x(n-1)+H2*x(n-2)+H3*x(n-3)+H4*x(n-4)
//  
//-------------------------------------
module FIR_1D_5_LOGIC(

// Master Clock
input			CLK,
input			RST,
input			CE,

// Filter signals
input		wire	[IN_WIDTH-1:0]	H0,H1,H2,H3,H4,  // Filter Coefficients
input		wire	[IN_WIDTH-1:0]	X,    // 
output		wire	[IN_WIDTH-1:0]	BCOUT,    // 
input 		wire					X_STRB,	// Clock enable
input		wire	[OUT_WIDTH-1:0]	C, // C input to first DSP slice
input		wire	[OUT_WIDTH-1:0]	PCIN, // Cascade input to first DSP slice
input		wire	[7:0]			OPMODE, // b0_0_0_0_01_01(use PCIN) or b0_0_0_0_11_01(C)
output 		wire	[OUT_WIDTH-1:0]	Y,PCOUT,    // Filter output
output		wire 			Y_STRB  // Strobes when done

);

parameter	IN_WIDTH=18;
parameter	OUT_WIDTH=48;

/* Extra logic necessary for the Adder tree */
reg			[7:1]				ce_dly=0; // create delayed version of X_STRB for different reg levels
assign							Y_STRB=ce_dly[7];
wire		[IN_WIDTH-1:0]				X_n_minus_0=X; // renamed version of input
always @(posedge CLK) 
		begin
		ce_dly <= {ce_dly[6:1],X_STRB};
		end



reg		[IN_WIDTH-1:0]				X_dly1=0,X_dly2=0,X_dly3=0,X_dly4=0,X_dly5=0,X_dly6=0,X_dly7=0,X_dly8=0,X_dly9=0,X_dly10=0,X_dly11=0,X_dly12=0,X_dly13=0,X_dly14=0,X_dly15=0;
always @(posedge CLK) 
	begin
	X_dly1 <= X; 
	X_dly2 <= X_dly1; X_dly3 <= X_dly2; X_dly4 <= X_dly3;
	X_dly5 <= X_dly4; X_dly6 <= X_dly5; X_dly7 <= X_dly6; 
	X_dly8 <= X_dly7; X_dly9 <= X_dly8; X_dly10 <= X_dly9; 
	X_dly11 <= X_dly10; X_dly12 <= X_dly11; X_dly13 <= X_dly12; 
	X_dly14 <= X_dly13; X_dly15 <= X_dly14;
	end

wire		[IN_WIDTH-1:0]				X_n_minus_1=X_dly3; //
wire		[IN_WIDTH-1:0]				X_n_minus_2=X_dly7; //
wire		[IN_WIDTH-1:0]				X_n_minus_3=X_dly11; //
wire		[IN_WIDTH-1:0]				X_n_minus_4=X_dly15; // 

/***** H0 Term *****/
/******** skip A0B0, A1B1 reg'd, mult reg'd, use PCIN, Pout reg'd *********/
/******** Mult 2 18 bit numbers *********/
wire		[OUT_WIDTH-1:0]				H0Xn; //
DSP_SLC_LOGIC	#(.IN_WIDTH(IN_WIDTH), .OUT_WIDTH(OUT_WIDTH))	dspH0	(
	.CLK(CLK),
	.RST(RST),
	.CE(CE),
	.A(H0), .B(X_n_minus_0),  // Inputs
	.C(C), // C input to first DSP slice
	.PCIN(PCIN), // Cascade input to first DSP slice
	.use_inreg0(1'b0), .use_pcin(!OPMODE[3]),
	.BCOUT(),    // 
	.P(),.PCOUT(H0Xn)	);    // Filter output




/***** H1 Term *****/
/******** A0B0 reg'd, A1B1 reg'd, mult reg'd, no Cin, Pout reg'd *********/
/******** Mult 2 18 bit numbers *********/
wire		[OUT_WIDTH-1:0]				H1X_n_minus_1_plus_prev; //
DSP_SLC_LOGIC	#(.IN_WIDTH(IN_WIDTH), .OUT_WIDTH(OUT_WIDTH))	dspH1	(
	.CLK(CLK),
	.RST(RST),
	.CE(CE),
	.A(H1), .B(X_n_minus_1),  // Inputs
	.C(C), // C input to first DSP slice
	.PCIN(H0Xn), // Cascade input to first DSP slice
	.use_inreg0(1'b1), .use_pcin(1'b1),
	.BCOUT(),    // 
	.P(),.PCOUT(H1X_n_minus_1_plus_prev)	);    // Filter output




/***** H2 Term *****/
/******** A0B0 reg'd, A1B1 reg'd, mult reg'd, no Cin, Pout reg'd *********/
/******** Mult 2 18 bit numbers *********/
wire		[OUT_WIDTH-1:0]				H2X_n_minus_2_plus_prev; //cascade Y output to next DSP slice
DSP_SLC_LOGIC	#(.IN_WIDTH(IN_WIDTH), .OUT_WIDTH(OUT_WIDTH))	dspH2	(
	.CLK(CLK),
	.RST(RST),
	.CE(CE),
	.A(H2), .B(X_n_minus_2),  // Inputs
	.C(C), // C input to first DSP slice
	.PCIN(H1X_n_minus_1_plus_prev), // Cascade input to first DSP slice
	.use_inreg0(1'b1), .use_pcin(1'b1),
	.BCOUT(),    // 
	.P(),.PCOUT(H2X_n_minus_2_plus_prev)	);    // Filter output



/***** H3 Term *****/
/******** A0B0 reg'd, A1B1 reg'd, mult reg'd, no Cin, Pout reg'd *********/
/******** Mult 2 18 bit numbers *********/
wire		[OUT_WIDTH-1:0]				H3X_n_minus_3_plus_prev; //cascade Y output to next DSP slice
DSP_SLC_LOGIC	#(.IN_WIDTH(IN_WIDTH), .OUT_WIDTH(OUT_WIDTH))	dspH3	(
	.CLK(CLK),
	.RST(RST),
	.CE(CE),
	.A(H3), .B(X_n_minus_3),  // Inputs
	.C(C), // C input to first DSP slice
	.PCIN(H2X_n_minus_2_plus_prev), // Cascade input to first DSP slice
	.use_inreg0(1'b1), .use_pcin(1'b1),
	.BCOUT(),    // 
	.P(),.PCOUT(H3X_n_minus_3_plus_prev)	);    // Filter output


/***** H4 Term *****/
/******** A0B0 reg'd, A1B1 reg'd, mult reg'd, no Cin, Pout reg'd *********/
/******** Mult 2 18 bit numbers *********/
DSP_SLC_LOGIC	#(.IN_WIDTH(IN_WIDTH), .OUT_WIDTH(OUT_WIDTH))	dspH4	(
	.CLK(CLK),
	.RST(RST),
	.CE(CE),
	.A(H4), .B(X_n_minus_4),  // Inputs
	.C(C), // C input to first DSP slice
	.PCIN(H3X_n_minus_3_plus_prev), // Cascade input to first DSP slice
	.use_inreg0(1'b1), .use_pcin(1'b1),
	.BCOUT(BCOUT),    // 
	.P(Y),.PCOUT(PCOUT)	);    // Filter output




endmodule

//-------------------------------------
// Simulation test bench
//-------------------------------------
// History of Changes:
//	6-15-2009 Initial creation
//-------------------------------------

module fir_tst;
// Clock generator
reg				CLK = 0;
initial #4 forever #4 CLK = !CLK;





//------- Inputs to Filters
// H0-H4: 16-bit inputs represent range -128 to 127.99 using the following format
// 		BIT#: 				15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
//  	H0-H4:				Q  m  m  m  m  m  m  m . f  f  f  f  f  f  f  f
//
// Sign extend H0-H4 to 18-bit inputs
// 		BIT#: 				17 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
//  	cm_in:				Qe Qe Q  m  m  m  m  m  m  m . f  f  f  f  f  f  f  f
//
// pixel inputs to FIR
// 		BIT#: 				17 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
//  	cm_in:				0  0 . f  f  f  f  f  f  f  f  f  f  f  f  f  f  f  f
// binary pt is before bit 23 of output
wire	[17:0]	H0=18'd256; // Filter Coefficients
wire	[17:0]	H1=18'd256; // Filter Coefficients
wire	[17:0]	H2=18'd256; // Filter Coefficients
wire	[17:0]	H3=18'd256; // Filter Coefficients
wire	[17:0]	H4=18'd256; // Filter Coefficients
wire	[47:0]	PCIN=48'd0;
wire	[17:0]	BCOUT;
wire	[47:0]	Y;    // Filter output
wire	[47:0]	PCOUT;    // Filter output
wire 			Y_STRB;  // Strobes when done

// test signals
reg		[15:0]	X=0;    // in pixels
reg				X_STRB=0;	// Clock enable
always @(posedge CLK)
	begin
	X <= X + 1;
	X_STRB <= (X==255)? 1 : X_STRB;
	end

FIR_1D_5_S6 dut(
	.CLK(CLK),.RST(1'b0),
	.H0(H0), .H1(H1), .H2(H2), .H3(H3), .H4(H4),
	.X({X[15],X[15],X[15],X}), .X_STRB(X_STRB), .BCOUT(BCOUT), .PCIN(PCIN),
	.Y(Y), .PCOUT(PCOUT), .Y_STRB(Y_STRB)	);


wire	[15:0]	FILT_PIX=Y[31:16];



	

endmodule

