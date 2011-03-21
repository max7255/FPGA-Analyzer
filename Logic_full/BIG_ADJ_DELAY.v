`timescale  1 ns / 1 ns
//-------------------------------------
// BIG_ADJ_DELAY.v
//-------------------------------------
// History of Changes:
//	06-15-2009 Initial creation
//-------------------------------------
//-------------------------------------
// This module uses inferred block ram to
// create a large adjustable shift register.  
// For more information see WP335 "Creative Uses of Block Ram"
//-------------------------------------
module BIG_ADJ_DELAY
#(
parameter	MAX_DELAY = 1024,
parameter	WIDTH = 12
)
(

input	wire	[15:0]		DELAY, 

// Master Clock
input	wire				CLK,
input	wire				CE,

input	wire	[WIDTH-1:0]	DIN,
output	reg 	[WIDTH-1:0]	DOUT

);




// DELAY is assumed to be mostly constant
reg 	[15:0]	last_adr=0;
always @(posedge CLK) last_adr <= DELAY -3; 

(* RAM_STYLE="AUTO" *)
reg [WIDTH-1:0] ram [MAX_DELAY-1:0];
reg 	[15:0]	adr=0;
reg				adr_is_last=0;
always @(posedge CLK)
	if (CE) 
	begin
	DOUT <= ram[adr];
	ram[adr] <= DIN;
	adr_is_last <= (adr == last_adr);
	adr <= adr_is_last ? 0 : adr +1;
	end

endmodule

//-------------------------------------
// Simulation test bench
//-------------------------------------
// History of Changes:
//	1-08-2008 Initial creation
//-------------------------------------

module adj_delay_tst;
// Clock generator
reg				CLK = 0;
initial #4 forever #4 CLK = !CLK;


// test signals
reg		[15:0]	X=0;
reg				X_EN=0;	// Clock enable
always @(posedge CLK)
	begin
	X <= X + 1;
	X_EN <= (X==255)? 1 : X_EN;
	end


wire	[15:0]	Y;
BIG_ADJ_DELAY	#(.MAX_DELAY(1024),.WIDTH(16))	
	dut (	.DELAY(10), 
			.CLK(CLK),
			.CE(1'b1),
			.DIN(X),
			.DOUT(Y)	);


endmodule

