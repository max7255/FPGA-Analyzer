`timescale  1 ns / 1 ns
//-------------------------------------
// GMII_ETH_RCV_STREAM.v
//-------------------------------------
// History of Changes:
//  7-1-2009 Created based on previous RGMII_ETH_RCV	 						
//-------------------------------------
// This module receives ethernet packets via the MII or GMII interface to the PHY.
// It then outputs the ethernet packets in the following streaming format:
//   Bit 9: CKE: Clock enable sets data rate.  Lower bits are only valid if CKE.
//   Bit 8: FRM: Frame signal, asserted for entire ethernet frame
//   Bits 7-0: DAT: Frame data, ignored if not FRM.
//-------------------------------------
// Notes:
//	The streaming ethernet frame includes all bytes from the Destination MAC through
//	the CRC bytes.
//
//	This module is intended move the received packets from the RXCLK domain into a
//	125Mhz internal clock domain.  
//
//	Because the 125Mhz internal clock can be slightly faster than the RXCLK, 
//  it is possible for CKE to deassert for a cycle during the ETH_RX_STREAM
//  frame.  This is not a problem if ETH_RX_STREAM is later stored in a buffer and 
//  eventually re-timed.  However, if ETH_RX_STREAM was to drive
//  a RGMII_ETH_TX module directly, the cke sequence would likely not be correct.
//  Ie. cke=1 for duration of frame (1000Mbps)
//-------------------------------------
module GMII_ETH_RCV_STREAM(
	CLK125, RST,
	RXCLK,RXD,RXCTRL,SPEED,RXCLK_BUFIO,
	ETH_RX_STREAM	
);

//inputs
input				CLK125;	// 125 MHz reference CLK for Ethernet
input				RST;
input				RXCLK;	// receive clock	
input				RXCLK_BUFIO;	// receive clock	
input	[7:0]		RXD;	// nybbles from phy
input				RXCTRL;	// Receiver CTRL signal 
input	[1:0]		SPEED;	//  0 = Off, 1 = 100Mbit, 2 = 1Gbit, 3 = RSVD 

//outputs
output	[9:0]		ETH_RX_STREAM; // data payload (little endian)


/********* INFFs **********/
(* KEEP = "TRUE" *)reg 			rx_en_inff=0;// reg'd version of RXCTRL
(* KEEP = "TRUE" *)reg 	[7:0]	rxdat_inff=0; //reg'd version of RXD
always @(posedge RXCLK_BUFIO)
	begin
	rxdat_inff <= RXD;
	rx_en_inff <= RXCTRL;			
	end		
/******************************************************/


/********* 1000Mbps Mode Sigs **********/
reg 			ge_rxd_byte_en=0;// ge received byte strobe (skip preamble)
reg 	[7:0]	ge_rxd_byte=0; // ge received byte
reg				ge_frame_low=0; // after packet done write 1 extra byte with frame bit cleared
always @(posedge RXCLK)
	begin
	ge_rxd_byte <= rxdat_inff;
	ge_rxd_byte_en <= (rx_en_inff&&(ge_rxd_byte==8'hd5))? 1'b1 : (!rx_en_inff)? 1'b0 : ge_rxd_byte_en;
	ge_frame_low <= ge_rxd_byte_en&&!rx_en_inff;
	end
/***************************************/			

/********* 100Mbps Mode Sigs **********/
reg 			fe_rxd_byte_en=0;// fe received byte strobe
reg 	[7:0]	fe_rxd_byte=0; // fe received byte
reg				fe_tgl=0; //used to choose nybble location in fe_rxd_byte
reg				fe_frame_low=0; // after packet done write 1 extra byte with frame bit cleared
always @(posedge RXCLK)
	begin
	fe_tgl <= ((fe_rxd_byte==8'hd5)&&!fe_rxd_byte_en)? 1'b0 : ~fe_tgl;
	fe_rxd_byte <= {rxdat_inff[3:0],fe_rxd_byte[7:4]};	// form 2 consequtive nybbles into a byte
	fe_rxd_byte_en <= (rx_en_inff&&(fe_rxd_byte==8'hd5))? 1'b1 : (!rx_en_inff)? 1'b0 : fe_rxd_byte_en;
	fe_frame_low <= fe_rxd_byte_en&&!rx_en_inff;
	end
/***************************************/	



/********* Choose signals based on SPEED *************/
wire 			wr_stb=(SPEED==2'd2)? ge_rxd_byte_en||ge_frame_low : fe_rxd_byte_en&&fe_tgl||fe_frame_low;// strobe for writing to fifo
wire 	[7:0]	wr_rx_byte=(SPEED==2'd2)? ge_rxd_byte : fe_rxd_byte; // received byte
wire 			wr_rx_frm=ge_frame_low||fe_frame_low? 1'b0 : 1'b1;	
/*****************************************************/

/*** Use asynchronous fifo to go from RXCLK (125Mhz or 25Mhz) to 125Mhz ***/
reg		[3:0]	out_cnt=4'd0; //generate tick for readout of fifo
reg				cke=0;
always @(posedge CLK125) 
	begin
	out_cnt <= ((out_cnt==4'd9)||(SPEED==2'd2))? 0 : out_cnt+1;
	cke <= (out_cnt==4'd0);
	end

wire			fifo_empty; // fifo empty indicator
wire			fifo_rd_en=!fifo_empty&&cke;
wire 	[8:0]	fifo_dout;
/* Note: this fifo is a first word fall through type */
afifo clkchng_fifo (
	.wr_clk(RXCLK),
	.din({wr_rx_frm,wr_rx_byte}), // Bus [8 : 0] 
	.wr_en(wr_stb),
	.rd_clk(CLK125),
	.rd_en(fifo_rd_en),
	.dout(fifo_dout), // Bus [8 : 0] 
	.empty(fifo_empty),
	.full());


reg				out_cke=0;
reg				out_frm=0; // set when sfd found
reg		[7:0]	out_dat=0; //rxd formatted into a byte
always @(posedge CLK125)
	begin
//	out_cke <= fifo_dout[8]? fifo_rd_en : cke;	// during a frame want to lower_cke when fifo empty, otherwise let it free run
	out_cke <= fifo_empty&&out_frm? 1'b0 : cke;	// during a frame want to lower_cke when fifo empty, otherwise let it free run
	if (fifo_rd_en)
	out_frm <= fifo_dout[8];
	out_dat <= fifo_dout[7:0];
	end

// make our new ethernet format
wire	[9:0]	ETH_RX_STREAM = {out_cke, out_frm, out_dat[7:0]};

endmodule