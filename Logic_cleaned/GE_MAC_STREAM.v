`timescale  1 ns / 1 ns
//-------------------------------------
// GE_MAC.v
//-------------------------------------
// History of Changes:
//	6-7-2009 Initial creation
//-------------------------------------
// This module encapsulates the send and receive MAC
// interfaces to the PHY.  It also contains the
// IOBDELAY2 primitives for proper input sample timing
// of the RXD and RXCTRL signals. 
//-------------------------------------

module GE_MAC_STREAM (
	LINK_SPEED,
	CLK50, PHY_RESET_L, PHY_MDC, PHY_MDIO,
	GE_RXCLK, GE_RXDV, GE_RXD, 
	GE_TXCLK, GE_TXEN, GE_TXD,
	FE_TXCLK, FE_OUT_TICK,
	CLK125, RST, GE_RXCLK_BUFIO,
	ETH_RX_STREAM, 
	ETH_TX_STREAM
	);

// Interface to gigabit phy:
output 	[1:0]	LINK_SPEED;

// Ethernet control interface
input			CLK50;
output			PHY_RESET_L; 
output			PHY_MDC; 
inout 			PHY_MDIO; 

// Ethernet GMII/MII interface
input			GE_RXCLK, GE_RXDV, GE_RXCLK_BUFIO;
input	[7:0]	GE_RXD;
output			GE_TXCLK, GE_TXEN;
output	[7:0]	GE_TXD;
input			FE_TXCLK; // clock is supplied by the PHY
output			FE_OUT_TICK;


// Master CLK
input			CLK125;
input			RST;

// TX port (input): 
input	[9:0]	ETH_TX_STREAM;

// RX port (output):
output	[9:0]	ETH_RX_STREAM;



//------- Need to generate a 12.5MBps strobe from FE_TXCLK
(* KEEP = "TRUE" *)reg				fe_txclk_inff=0;
reg		[1:0]	fe_txclk_dly=0; // used to align TXD with 25Mhz clk in MII mode
reg				e_tgl=0; // toggles every detected rising edge FE_OUT_TICK
reg				FE_OUT_TICK=0; // use every other rising edge for FE_OUT_TICK
always @(posedge CLK125)
	begin
	fe_txclk_inff <= FE_TXCLK;
	fe_txclk_dly <= {fe_txclk_inff,fe_txclk_dly[1]};
	FE_OUT_TICK <= fe_txclk_dly[1]&&!fe_txclk_dly[0]&&e_tgl;
	e_tgl <= (fe_txclk_dly[1]&&!fe_txclk_dly[0])? !e_tgl : e_tgl;
	end
  
  
  
//------- Ethernet Link Controller -------
wire	[1:0]	LINK_SPEED;
ETH_MDIO eth_ctrl (
    .CLK(CLK50), 
	.E_RST_L(PHY_RESET_L), .E_MDC(PHY_MDC), .E_MDIO(PHY_MDIO), .E_LINK_SPEED(LINK_SPEED)
	);

//------- Transmitter -------
GMII_ETH_TX_STREAM trans(
	.CLK125(CLK125), .SPEED(LINK_SPEED),
	.TXD(GE_TXD),.TXCTRL(GE_TXEN),.TXC(GE_TXCLK),
	.ETH_TX_STREAM(ETH_TX_STREAM)
);

// Input signals after the IOBDELAY is added
wire			ge_rxdv_dly;
wire	[7:0]	ge_rxd_dly;


   IODELAY2 #(
      .COUNTER_WRAPAROUND("WRAPAROUND"), // Sets behavior when tap count exceeds max or min, depending on
                                         // whether tap setting is being incremented or decremented.
      .DATA_RATE("SDR"),
      .DELAY_SRC("IDATAIN"),             // ODATAIN indicates delay source is the ODATAIN pin from the OSERDES
                                         // or OLOGIC. IDATAIN indicates the delay source is from the IDATAIN
                                         // pin; one of the dedicated IOB (P/N) Pads. IO means that the signal
                                         // source switches between IDATAIN and ODATAIN depending on the sense
                                         // of the T (tristate) input.
      .IDELAY2_VALUE(0),                 // Delay tap value for IDELAY Mode. Only used when IDELAY_MODE is set
                                         // to PCI.
      .IDELAY_MODE("NORMAL"),            // Delay Mode setting - PCI is for handling PCI/Extended Mode. Affects
                                         // Input delays only.
      .IDELAY_TYPE("FIXED"),           // Delay Type. VARIABLE refers to the customer calibrated delay mode.
                                         // DEFAULT will utilize physical chip settings for best approximation
                                         // of zero hold time programming. VARIABLE_FROM_ZERO and
                                         // VARIABLE_FROM_HALF_MAX refer to the reset behavior.
                                         // DIFF_PHASE_DETECTOR is a special mode where the master and slave
                                         // IODELAY2s are cascaded for video application support.
      .IDELAY_VALUE(6),                  // Delay tap value for IDELAY Mode.
      .ODELAY_VALUE(0),                  // Delay tap value for ODELAY Mode.
      .SERDES_MODE("NONE"),
      .SIM_TAPDELAY_VALUE(75) 
   )
   IODELAY2_GE_RXDV (
      .BUSY(),
      .DATAOUT(ge_rxdv_dly),   // 1-bit Delayed data signal to DDLY of ILOGIC2 or ISERDES2 sites.
      .DATAOUT2(), // 1-bit Delayed data signal to DDLY2 of ILOGIC2 or ISERDES2 sites.
      .DOUT(),         // 1-bit Delayed data signal to IOB.
      .TOUT(),         // 1-bit Delayed Tristate signal to IOB.
      .CAL(1'b0),           // 1-bit Enter the IODELAY calibration sequence. This will last between 8 and 16
                           // GCLK cycles. Drives RDY HIGH when complete. Shared with DRP pin ADD(add).

      .CE(1'b0),             // 1-bit Enable the Increment/Decrement signal.
      .CLK(1'b0),           // 1-bit CLK0 from INT connects to "Master" and CLK1 from INT connects to "Slave" 
      .IDATAIN(GE_RXDV),   // 1-bit Data signal from IOB.
      .INC(1'b0),           // 1-bit Increment / Decrement signal. Used for setting tap or delay length.
      // IOCLK0 - IOCLK1: 1-bit (each) Optionally Invertible IO clock network input.
      .IOCLK0(1'b0),
      .IOCLK1(1'b0),
      .ODATAIN(1'b0),   // 1-bit Data input signal from OLOGIC or OSERDES.
      .RST(1'b0),           // 1-bit Reset the IODELAY2 to either zero or 1/2 of total period. RST_VALUE
                           // attribute controls this choice.

      .T(1'b1)                // 1-bit Tristate input signal from OLOGIC or OSERDES.
   );


// Latch all of the filter Coefficients
genvar i;
generate
  for (i=0; i<8; i=i+1) 
  begin: rxd_dly

   IODELAY2 #(
      .COUNTER_WRAPAROUND("WRAPAROUND"), // Sets behavior when tap count exceeds max or min, depending on
                                         // whether tap setting is being incremented or decremented.
      .DATA_RATE("SDR"),
      .DELAY_SRC("IDATAIN"),             // ODATAIN indicates delay source is the ODATAIN pin from the OSERDES
                                         // or OLOGIC. IDATAIN indicates the delay source is from the IDATAIN
                                         // pin; one of the dedicated IOB (P/N) Pads. IO means that the signal
                                         // source switches between IDATAIN and ODATAIN depending on the sense
                                         // of the T (tristate) input.
      .IDELAY2_VALUE(0),                 // Delay tap value for IDELAY Mode. Only used when IDELAY_MODE is set
                                         // to PCI.
      .IDELAY_MODE("NORMAL"),            // Delay Mode setting - PCI is for handling PCI/Extended Mode. Affects
                                         // Input delays only.
      .IDELAY_TYPE("FIXED"),           // Delay Type. VARIABLE refers to the customer calibrated delay mode.
                                         // DEFAULT will utilize physical chip settings for best approximation
                                         // of zero hold time programming. VARIABLE_FROM_ZERO and
                                         // VARIABLE_FROM_HALF_MAX refer to the reset behavior.
                                         // DIFF_PHASE_DETECTOR is a special mode where the master and slave
                                         // IODELAY2s are cascaded for video application support.
      .IDELAY_VALUE(6),                  // Delay tap value for IDELAY Mode.
      .ODELAY_VALUE(0),                  // Delay tap value for ODELAY Mode.
      .SERDES_MODE("NONE"),
      .SIM_TAPDELAY_VALUE(75) 
   )
   IODELAY2_GE_RXD (
      .BUSY(),
      .DATAOUT(ge_rxd_dly[i]),   // 1-bit Delayed data signal to DDLY of ILOGIC2 or ISERDES2 sites.
      .DATAOUT2(), // 1-bit Delayed data signal to DDLY2 of ILOGIC2 or ISERDES2 sites.
      .DOUT(),         // 1-bit Delayed data signal to IOB.
      .TOUT(),         // 1-bit Delayed Tristate signal to IOB.
      .CAL(1'b0),           // 1-bit Enter the IODELAY calibration sequence. This will last between 8 and 16
                           // GCLK cycles. Drives RDY HIGH when complete. Shared with DRP pin ADD(add).

      .CE(1'b0),             // 1-bit Enable the Increment/Decrement signal.
      .CLK(1'b0),           // 1-bit CLK0 from INT connects to "Master" and CLK1 from INT connects to "Slave" 
      .IDATAIN(GE_RXD[i]),   // 1-bit Data signal from IOB.
      .INC(1'b0),           // 1-bit Increment / Decrement signal. Used for setting tap or delay length.
      // IOCLK0 - IOCLK1: 1-bit (each) Optionally Invertible IO clock network input.
      .IOCLK0(1'b0),
      .IOCLK1(1'b0),
      .ODATAIN(1'b0),   // 1-bit Data input signal from OLOGIC or OSERDES.
      .RST(1'b0),           // 1-bit Reset the IODELAY2 to either zero or 1/2 of total period. RST_VALUE
                           // attribute controls this choice.

      .T(1'b1)                // 1-bit Tristate input signal from OLOGIC or OSERDES.
   );

  end
endgenerate


//------- Receiver -------
GMII_ETH_RCV_STREAM receive(
	.CLK125(CLK125),
	.RST(RST),
	.RXCLK(GE_RXCLK),.RXD(ge_rxd_dly),.RXCTRL(ge_rxdv_dly), .SPEED(LINK_SPEED), .RXCLK_BUFIO(GE_RXCLK_BUFIO),
	.ETH_RX_STREAM(ETH_RX_STREAM)
);


	
endmodule





//-------------------------------------
// Simulation test bench
//-------------------------------------
// History of Changes:
//	5-07-2009 Initial creation
//-------------------------------------

module eth_mac_rx_tx_testbench;

// Clock generator
reg				CLK = 0;
initial #4 forever #4 CLK = !CLK;
reg 			TICK_10US = 0;
initial #4000 forever 
	begin
	#9992 TICK_10US = 1;
//	#992 TICK_10US = 1;
	#8 TICK_10US = 0;
	end

reg				CLK25 = 0;
initial #20 forever #20 CLK25 = !CLK25;


reg 			RST = 1;
initial #2000
	begin
	RST = 0;
	end

wire	[1:0]	speed; // 1=fast ethernet, 2=gigabit

// Input data stream fast ethernet
wire			fe_out_tick;

reg 			eth_frm = 0;
reg 	[7:0]	eth_dat;

reg 	[10:0]	pkt_size = 80;
reg 	[10:0]	cnt = 11'd1536;
always @(posedge CLK) if (fe_out_tick)
	begin
	cnt <= cnt + 1 ;
	eth_frm <= (cnt < pkt_size);
	case (cnt)
	11'd00: eth_dat <= 8'h00; // Dest MAC
	11'd01: eth_dat <= 8'h18;
	11'd02: eth_dat <= 8'hb7;
	11'd03: eth_dat <= 8'h00;
	11'd04: eth_dat <= 8'h20;
	11'd05: eth_dat <= 8'hf3;
	11'd06: eth_dat <= 8'h00; // Src MAC
	11'd07: eth_dat <= 8'h18;
	11'd08: eth_dat <= 8'hB7;
	11'd09: eth_dat <= 8'hFF;
	11'd10: eth_dat <= 8'hFF;
	11'd11: eth_dat <= 8'hFF;
	11'd12: eth_dat <= 8'h05; // Length
	11'd13: eth_dat <= 8'h4A;
	11'd14: eth_dat <= 8'h41; // Opcode
	11'd15: eth_dat <= 8'h40; // Packet ID
	11'd16: eth_dat <= 8'h02; // Device ID
	11'd17: eth_dat <= 8'hAD;
	11'd18: eth_dat <= 8'h00; // HDR: CTRL
	11'd19: eth_dat <= 8'h20; 
	11'd20: eth_dat <= 8'h00; // HDR: VS_DELAY
	11'd21: eth_dat <= 8'h33; 
	default: eth_dat <= 8'h00;
	endcase
	end



// Add CRC to the stream
wire	[9:0]	TX_ETH_STREAM;
wire	[9:0]	RX_ETH_STREAM;
ETH_TX_CRC txcrc(.CLK(CLK), .IN_ETH_STREAM({fe_out_tick, eth_frm, eth_dat[7:0]}), .OUT_ETH_STREAM(TX_ETH_STREAM)	);

wire	[7:0]	txd;
wire			txen;
wire			txc;


wire			rx_cke=RX_ETH_STREAM[9];
wire			rx_frm=RX_ETH_STREAM[8];
wire	[7:0]	rx_dat=RX_ETH_STREAM[7:0];
GE_MAC_STREAM uut(
	.LINK_SPEED(speed),
	.GE_RXCLK((speed==2'd1)? CLK25 : txc), .GE_RXDV(txen), .GE_RXD(txd),  // feed back transmit signals to simulate what would come from phy
	.GE_TXCLK(txc), .GE_TXEN(txen), .GE_TXD(txd),
	.FE_TXCLK(CLK25),
	.FE_OUT_TICK(fe_out_tick),
	.CLK125(CLK), .RST(RST),
	.ETH_RX_STREAM(RX_ETH_STREAM), 
	.ETH_TX_STREAM(TX_ETH_STREAM) ); // special case for pass thru
	



endmodule

