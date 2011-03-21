`timescale  1 ns / 1 ns
//-------------------------------------
// GMII_ETH_TX_STREAM.v
//-------------------------------------
// History of Changes:
//  6-25-2009 Initial creation
//-------------------------------------
//	Basic Functions:
//	  Provides the electrical interface to a PHY using the GMII or MII spec.
//	  Takes a ethernet stream (post crc) and appends the preamble
//	  All bytes sent LSNybble first.	
//			Send Preamble (7 bytes)	01010101 
//			Send SFD (1 byte) 11010101
//	  Both 1000Mbps and 100Mbps is supported 	
//-------------------------------------	
//	NOTES:
//		This module must receive exactly 1 byte per clock cycle during a gigabit ethernet
//		frame (ie. cke must be high for duration of frame)
//		This module does not pad ethernet packets to the minimum ethernet frame size.
//		This module does not enforce the Inter Frame Gap time (96 ns for 1Gb/s implementation)
//		This module was tested using a Marvell 88E1111 PHY
//-------------------------------------
module GMII_ETH_TX_STREAM(
	CLK125, SPEED,
	TXD,TXCTRL,TXC,
	ETH_TX_STREAM
);


input				CLK125;	// 125 MHz reference CLK for Ethernet
input	[1:0]		SPEED;	//  0 = Off, 1 = 100Mbit, 2 = 1Gbit, 3 = RSVD

//rgmii interface
output	[7:0]		TXD;	// nybbles to phy
output				TXCTRL;	// phy data valid
output				TXC; // gigabit phy tx clock

//txbuffer interface  
input	[9:0]	ETH_TX_STREAM;

             
wire			in_cke = ETH_TX_STREAM[9];  
wire			in_frm = ETH_TX_STREAM[8];  
wire	[7:0]	in_dat = ETH_TX_STREAM[7:0];


// delay the data by eight bytes to insert the preamble
reg 	[7:0]	data_dly[8:1];
reg 	[8:1]	frm_dly = 0;
always @(posedge CLK125) 
	if (in_cke)
		begin
		data_dly[1] <= in_dat;
		data_dly[2] <= data_dly[1];
		data_dly[3] <= data_dly[2];
		data_dly[4] <= data_dly[3];
		data_dly[5] <= data_dly[4];
		data_dly[6] <= data_dly[5];
		data_dly[7] <= data_dly[6];
		data_dly[8] <= data_dly[7];
		frm_dly <= {frm_dly[7:1], in_frm};
		end
	

// Register the Data byte to send -----------------------
reg		[7:0]	txdat_reg=0;
reg				txen_reg=0;
always@(posedge CLK125)
	if (in_cke)
		begin
		txdat_reg <= frm_dly[8] ? data_dly[8] : frm_dly[7] ? 8'hd5 : 8'h55;
		txen_reg <= (in_frm||frm_dly[8]);
		end


// Handle 100Mbps/1000Mbps Modes------------------------------------------
reg		[7:0]	TXD=0;
reg				TXCTRL=0;
reg		[2:0]	outcnt=0;
always@(posedge CLK125)
begin
	outcnt <= (in_cke)? 3'd0 : (outcnt!=7)? outcnt+1 : outcnt;
	TXD <=#2 (in_cke)? txdat_reg : (outcnt==3'd4)? {4'd0,TXD[7:4]} : TXD;
	TXCTRL <=#2 (in_cke)? txen_reg : TXCTRL;
end

// Create the 125Mhz and 25Mhz transmit clocks
ODDR2 #(
  .DDR_ALIGNMENT("NONE"), // Sets output alignment to "NONE", "C0" or "C1" 
  .INIT(1'b0),    // Sets initial state of the Q output to 1'b0 or 1'b1
  .SRTYPE("SYNC") // Specifies "SYNC" or "ASYNC" set/reset
) txc_ddr (
  .Q(TXC),   // 1-bit DDR output data
  .C0(CLK125),   // 1-bit clock input
  .C1(~CLK125),   // 1-bit clock input
  .CE(1'b1), // 1-bit clock enable input
  .D0(1'b1), // 1-bit data input (associated with C0)
  .D1(1'b0), // 1-bit data input (associated with C1)
  .R(1'b0),   // 1-bit reset input
  .S(1'b0)    // 1-bit set input
);


endmodule