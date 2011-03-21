`timescale 	100ps / 100ps
//-------------------------------------
// SP601_BRD.v
//-------------------------------------
// History of Changes:
//	5-5-2009 Initial Creation
//-------------------------------------
// This is the top level for SP601 Base Reference Design:
// XC6SLX16-2CSG324C on SP601 board.
//-------------------------------------
//-------------------------------------
module SP601_BRD (

// Local User interface
input	wire	[3:0]	GPIO_SWITCH, 
input	wire	[3:0]	GPIO_BUTTON, 
output	wire	[3:0]	GPIO_LED, 
input	wire			CPU_RESET, 

// Master clock input (muxed from many sources)
input	wire			SYSCLK_P, SYSCLK_N, 


// Ethernet control interface
output	wire			PHY_RESET_L, 
output	wire			PHY_MDC, 
inout	tri 			PHY_MDIO, 

// Interface to gigabit phy:
output	wire			PHY_TXCTL_TXEN, 
output	wire			PHY_TXER, 
output	wire			PHY_TXC_GTXCLK, 
input	wire			PHY_TXCLK, 
output	wire	[7:0]	PHY_TXD, 
	
input	wire			PHY_CRS, 
input	wire		 	PHY_COL, 
input	wire			PHY_RXER, 
input 	wire			PHY_RXCTRL_RXDV, 
input	wire			PHY_RXCLK, 
input	wire	[7:0]	PHY_RXD 
	);

parameter	[7:0]	FIRMWARE_VERSION=8'h2_0; // FPGA version number
parameter	[39:0]	BOARD_TYPE="SP601"; // 5-char string returned in status


// The following paramter is used to control differences between the 
// DSP48A implementation vs. the Logic mode
parameter			IS_DSP48A_VERSION = 0; // Set to 1 unless making 2nd multiboot version.
parameter [7:0] 	proc_clk_freq = IS_DSP48A_VERSION ? 8'd100 : 8'd20; // 100 MHz using DSP48A, else 20 MHz

// SPI Multiboot addresses
parameter [23:0]	primary_spi_multiboot_adr   = 24'h00_00_00;
parameter [23:0]	secondary_spi_multiboot_adr = 24'h08_00_00;
parameter [23:0]	reboot_adr = IS_DSP48A_VERSION ? secondary_spi_multiboot_adr : primary_spi_multiboot_adr;

// MAC addresses
parameter	SERVER_MAC	=	48'h00_21_70_9D_2D_4D;//00_50_C2_AE_40_00; 
parameter	MY_MAC		=	48'h00_50_C2_AE_40_01; 

wire			RST = 0;

//------- Clocks -------
wire			clk200, clk20, clk50, proc_clk, clk125; // GCLK's
wire			mcbclk_2x_0, mcbclk_2x_180, mcbclk_pll_lock, calib_clk; // MCB sigs
wire			clk125_rx; // receive clock from PHY
wire			clk125_rx_bufio;

assign			clk50=calib_clk;

SP601_BRD_CLOCKS #(
	.PROC_CLK_FREQ(proc_clk_freq)
)clocks (
	.SYSCLK_P(SYSCLK_P), .SYSCLK_N(SYSCLK_N), 
	.CLK20(clk20), 
	.CLK200(clk200), 
	.CLK125(clk125),
	.PROC_CLK(proc_clk), 
	.MCBCLK_2X_0(mcbclk_2x_0), .MCBCLK_2X_180(mcbclk_2x_180), .MCBCLK_PLL_LOCK(mcbclk_pll_lock), .CALIB_CLK(calib_clk), 
	.PHY_RXCLK(PHY_RXCLK), .CLK125_RX(clk125_rx), .CLK125_RX_BUFIO(clk125_rx_bufio),
	.RST(RST)
	);   




// Filter Control Interface
wire			proc_en;
wire			proc_gamma_en;    // gamma enable bit - applied if 1
wire			proc_invgamma_en; // inverse gamma enable bit - applied if 1
wire			proc_use_dsp; // use DSP48A1 
wire			proc_bound_abs; // bound negative with abs, not clip
wire	[15:0]	proc_img_size_x;
wire	[15:0]	proc_img_size_y;
wire	[399:0]	proc_ctrl_coeff;
wire 	[23:0]	proc_time_us;

wire			ctrl_busy; // controls are changing, don't start another yet

reg 	proc_go = 0;
always @(posedge proc_clk) proc_go <= proc_en && !ctrl_busy;



//------- Ethernet Interface -------
// Note: all ethernet traffic is handled in 10-bit streams 
// The ETH_STREAM signal actually includes three signals:
//   Bit 9: CKE: Clock enable sets data rate.  Lower bits are only valid if CKE.
//   Bit 8: FRM: Frame signal, asserted for entire ethernet frame.
//   Bits 7-0: DAT: Frame data, ignored if not FRM.

// Simple Ethernet MAC
// PHY_CRS,PHY_COL,PHY_RXER inputs from PHY ignored for now
assign			PHY_TXER=1'b0;
wire	[1:0]	link_speed;
wire	[9:0]	eth_rx_stream;
wire	[9:0]	eth_tx_stream;
wire			fe_out_tick;
GE_MAC_STREAM mac	(
	.LINK_SPEED(link_speed),
	.CLK50(clk50),.PHY_RESET_L(PHY_RESET_L), .PHY_MDC(PHY_MDC), .PHY_MDIO(PHY_MDIO),
	.GE_RXCLK(clk125_rx), .GE_RXDV(PHY_RXCTRL_RXDV), .GE_RXD(PHY_RXD), 
	.GE_TXCLK(PHY_TXC_GTXCLK), .GE_TXEN(PHY_TXCTL_TXEN), .GE_TXD(PHY_TXD),
	.FE_TXCLK(PHY_TXCLK),
	.FE_OUT_TICK(fe_out_tick), // strobe at 12.5Mhz 
	.CLK125(clk125), .RST(RST), .GE_RXCLK_BUFIO(clk125_rx_bufio),
	.ETH_RX_STREAM(eth_rx_stream), 
	.ETH_TX_STREAM(eth_tx_stream)
	);   

// Only accept packets that come from the MAC address used by 
// the Base Reference Design Interface software
wire	[9:0]	filt_eth_stream;
ETH_FILTER #(
	.FILT_MAC(SERVER_MAC)
) mac_filter (
    .CLK(clk125), 
    .IN_ETH_STREAM(eth_rx_stream), 
    .OUT_ETH_STREAM_FILT(eth_tx_stream), // packets from software
	.OUT_ETH_STREAM_OTHER() // ignore other packets
	,.LED(GPIO_LED[1])
    );

// Buffer packets and check CRC
wire			OUT_REQ;
wire			eth_busy;
wire			OUT_GO=OUT_REQ&&!eth_busy;
wire	[9:0]	out_pkt_buff_stream;
ETH_RX_PKT_BUF_2048_STREAM rx_pkt_fifo(
	.CLK(clk125), 
	.IN_ETH_STREAM(filt_eth_stream),
	.OUT_REQ(OUT_REQ), .OUT_GO(OUT_GO), .OUT_TICK(1'b1), // always read from fifo at gigabit speeds
	.OUT_ETH_STREAM(out_pkt_buff_stream) );

// Create tick for sending 1000 or 100 Mbps packets
reg				snd_cke=0;
always @(posedge clk125) snd_cke <= (link_speed==1)? fe_out_tick : 1'b1;





endmodule
