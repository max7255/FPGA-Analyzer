//-------------------------------------
// ETH_MDIO.v
//-------------------------------------
// History of Changes:
//	5-5-2009  Initial creation
//-------------------------------------
// This module utilizes a Picoblaze processor to read PHY status
// using the MDIO interface.  Specifically it discovers the 
// current LINK speed of the ethernet connection which is used
// by the ethernet routing logic external to this module.
//
// This Picoblaze can also be used for other miscellaneous control.
//-------------------------------------
module ETH_MDIO(
	CLK, 
	E_RST_L, E_MDC, E_MDIO, E_LINK_SPEED
	);

// Master Clock input
input			CLK;

// Ethernet control interface
output			E_RST_L;
output			E_MDC;
inout			E_MDIO;
output	[1:0]	E_LINK_SPEED; //  0 = Off, 1 = 100Mbit, 2 = 1Gbit, 3 = RSVD


//------- Picoblaze data bus -------
wire	[7:0]	adr, wr_dat, rd_dat;
wire			rd_strobe, wr_strobe;

//------- PicoBlaze data bus stuff ----------
parameter [7:0]	mdio_reg_adr  = 8'h00;

// MDIO Register - Ethernet phy control interface
 reg 			mdio_out=0;
 reg 			mdio_z=1;
 reg			E_MDC=0;
 reg 			E_RST_L = 1;
 reg	[1:0]	E_LINK_SPEED=0; //  0 = Off, 1 = 100Mbit, 2 = 1Gbit, 3 = RSVD
 wire			E_MDIO;
 wire 			mdio_in; 
 IOBUF	IOBUF_mdio (.O (mdio_in),.IO (E_MDIO),.I (mdio_out),.T (mdio_z)); 
 always @(posedge CLK) 
	begin
	mdio_out <=#1 (adr == mdio_reg_adr) && wr_strobe ? wr_dat[7] : mdio_out;
	mdio_z <=#1 (adr == mdio_reg_adr) && wr_strobe ? wr_dat[5] : mdio_z;
	E_MDC <=#1 (adr == mdio_reg_adr) && wr_strobe ? wr_dat[6] : E_MDC;
	E_RST_L <=#1 (adr == mdio_reg_adr) && wr_dat[4] && wr_strobe ? wr_dat[3] : E_RST_L;
	E_LINK_SPEED <=#1 (adr == mdio_reg_adr) && wr_dat[2] && wr_strobe ? wr_dat[1:0] : E_LINK_SPEED;
	end

 wire	[7:0]	mdio_rd = {7'd0,mdio_in}; 


// register read interface to Picoblaze
assign rd_dat =
	(adr == mdio_reg_adr) ? mdio_rd :
	8'h00; 

//------- Picoblaze Program -------
wire	[9:0]	instruction_address;
wire	[17:0]	instruction;
PB_CODE prog (
    .CLK(CLK), .ADDRESS(instruction_address), .INSTRUCTION(instruction),
	.LOAD_CLK(1'b0), .LOAD_ADDRESS(10'd0), .LOAD_INSTRUCTION(18'd0), .LOAD_WE(1'b0)
	);

// ------- Picoblaze Processor -------
reg  		interrupt = 0;
wire		interrupt_ack;
kcpsm3 cpu (
    .clk(CLK), 
    .interrupt(interrupt), .interrupt_ack(interrupt_ack),
    .address(instruction_address), .instruction(instruction), 
    .port_id(adr), .in_port(rd_dat), .out_port(wr_dat), 
    .read_strobe(rd_strobe), .write_strobe(wr_strobe), 
    .reset(1'b0)
    );

endmodule

