`timescale  1 ns / 1 ns
//-------------------------------------
// FIR_1D_5.v
//-------------------------------------
// History of Changes:
//	06-14-2009 CJL: Created
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
module DSP_SLC_LOGIC(

// Master Clock
input			CLK,
input			RST,
input			CE,

// Filter signals
input		wire	[IN_WIDTH-1:0]	A,B,  // Inputs
input		wire	[OUT_WIDTH-1:0]	C, // C input to first DSP slice
input		wire	[OUT_WIDTH-1:0]	PCIN, // Cascade input to first DSP slice
input		wire					use_inreg0,use_pcin,
output		reg		[IN_WIDTH-1:0]	BCOUT=0,    // 
output 		reg		[OUT_WIDTH-1:0]	P,PCOUT    // Filter output

);

parameter	IN_WIDTH=18;
parameter	OUT_WIDTH=48;

reg		[IN_WIDTH-1:0]	a0_reg=0,b0_reg=0,a1_reg=0,b1_reg=0;
reg		[OUT_WIDTH-1:0]	c_reg=0;
always @(posedge CLK)
	begin
	a0_reg <= A; b0_reg <= B; 
	a1_reg <= (use_inreg0)? a0_reg : A; 
	b1_reg <= (use_inreg0)? b0_reg : B;
	BCOUT <= (use_inreg0)? b0_reg : B; 
	c_reg <= C;
	end

wire	[2*IN_WIDTH-1:0]	a1_reg_sign_extend = {{IN_WIDTH{a1_reg[IN_WIDTH-1]}},a1_reg[IN_WIDTH-1:0]};

reg		[2*IN_WIDTH-1:0]	m_reg=0;
always @(posedge CLK)
	begin
//	m_reg[2*IN_WIDTH-1:4] <= a1_reg[IN_WIDTH-1:2]*b1_reg[IN_WIDTH-1:2];
	m_reg[2*IN_WIDTH-1:8] <= a1_reg_sign_extend[2*IN_WIDTH-1:4]*b1_reg[IN_WIDTH-1:4];
	m_reg[7:0] <= 0;
//	m_reg[2*IN_WIDTH-1:4] <= a1_reg[IN_WIDTH-1:2]*b1_reg[IN_WIDTH-1:2];
//	m_reg[3:0] <= 0;
//	m_reg <= {a1_reg[IN_WIDTH-1:4],4'b0000}*{b1_reg[IN_WIDTH-1:4], 4'b0000};
	end
always @(posedge CLK)
	begin
	P     <= (use_pcin)? m_reg + PCIN :  m_reg + c_reg; 
	PCOUT <= (use_pcin)? m_reg + PCIN :  m_reg + c_reg; 	
//	P[OUT_WIDTH-1:8] <= (use_pcin)? m_reg[2*IN_WIDTH-1:8] + PCIN[OUT_WIDTH-1:8] :  m_reg[2*IN_WIDTH-1:8] + C[OUT_WIDTH-1:8]; 
//	PCOUT[OUT_WIDTH-1:8] <= (use_pcin)? m_reg[2*IN_WIDTH-1:8] + PCIN[OUT_WIDTH-1:8] :  m_reg[2*IN_WIDTH-1:8] + C[OUT_WIDTH-1:8]; 	
//	P[7:0] <= 8'd0; 
//	PCOUT[7:0] <= 8'd0; 	
	end

endmodule

//-------------------------------------
// Simulation test bench
//-------------------------------------
// History of Changes:
//	6-15-2009 CJL: created
//-------------------------------------

module slc_tst;
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

