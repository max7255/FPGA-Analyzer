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

// Interface to DDR2 memory
output	wire			DDR2_CLK_P,
output	wire			DDR2_CLK_N,
output	wire			DDR2_CKE,
output	wire	[12:0]	DDR2_A,
output	wire	[2:0]	DDR2_BA,
output	wire			DDR2_RAS_B,
output	wire			DDR2_CAS_B,
output	wire			DDR2_WE_B,
output	wire			DDR2_UDM,
output	wire			DDR2_LDM,
inout	tri 			DDR2_UDQS_P,
inout	tri 			DDR2_UDQS_N,
inout	tri 			DDR2_LDQS_P,
inout	tri 			DDR2_LDQS_N,
inout	tri 	[15:0]	DDR2_DQ,
output	wire 			DDR2_ODT,
inout					FPGA_ONCHIP_TERM1, // ZIO - open?
inout		 			FPGA_ONCHIP_TERM2, // RZQ - soft calibration R

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
parameter	SERVER_MAC	=	48'h00_50_C2_AE_40_00; 
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

//------- DDR2 SDRAM frame buffer controller -------

// Ethernet Write Port - writes original image
wire			eth_wr_clk;
wire	[15:0]	eth_wr_start_x, eth_wr_line, eth_wr_num_pixels;
wire			eth_wr_go, eth_wr_done, eth_wr_busy;
wire	[23:0]	eth_wr_pix;
wire			eth_wr_stb;

// Ethernet Read Port - Reads processed image
wire			eth_rd_clk; 
wire	[15:0]	eth_rd_start_x, eth_rd_line, eth_rd_num_pixels;
wire			eth_rd_frame_sel; // 0 for original, 1 for processed
wire			eth_rd_go, eth_rd_done, eth_rd_busy;
wire			eth_rd_ready, eth_rd_stb;
wire	[23:0]	eth_rd_pix;

// Processing Read Port - Reads original image
wire			proc_rd_clk;
wire	[15:0]	proc_rd_width, proc_rd_height;
wire			proc_rd_go, proc_rd_done, proc_rd_busy;
wire			proc_rd_ready, proc_rd_stb;
wire	[23:0]	proc_rd_pix;

// Processing Write Port - writes processed image
wire			proc_wr_clk; 
wire	[15:0]	proc_wr_width, proc_wr_height;
wire			proc_wr_go, proc_wr_done, proc_wr_busy;
wire	[23:0]	proc_wr_pix;
wire			proc_wr_stb;

SP601_FB fb (
	// Top level interface to DDR2
	.DDR2_CLK_P(DDR2_CLK_P), .DDR2_CLK_N(DDR2_CLK_N), .DDR2_CKE(DDR2_CKE), 
	.DDR2_A(DDR2_A), .DDR2_BA(DDR2_BA), 
	.DDR2_RAS_B(DDR2_RAS_B), .DDR2_CAS_B(DDR2_CAS_B), .DDR2_WE_B(DDR2_WE_B), 
	.DDR2_UDM(DDR2_UDM), .DDR2_LDM(DDR2_LDM), 
	.DDR2_UDQS_P(DDR2_UDQS_P), .DDR2_UDQS_N(DDR2_UDQS_N), 
	.DDR2_LDQS_P(DDR2_LDQS_P), .DDR2_LDQS_N(DDR2_LDQS_N), 
	.DDR2_DQ(DDR2_DQ), 
	.DDR2_ODT(DDR2_ODT), 
	.FPGA_ONCHIP_TERM1(FPGA_ONCHIP_TERM1), .FPGA_ONCHIP_TERM2(FPGA_ONCHIP_TERM2), 
	// Clocks, ctrl
	.MCBCLK_2X_0(mcbclk_2x_0), .MCBCLK_2X_180(mcbclk_2x_180), .MCBCLK_PLL_LOCK(mcbclk_pll_lock), .CALIB_CLK(calib_clk), 
	.RSTCLK(clk20), .RST(RST), 
	// Ethernet Write Port
	.ETH_WR_CLK(eth_wr_clk), .ETH_WR_START_X(eth_wr_start_x), .ETH_WR_LINE(eth_wr_line), .ETH_WR_NUM_PIXELS(eth_wr_num_pixels), 
	.ETH_WR_GO(eth_wr_go), .ETH_WR_DONE(eth_wr_done), .ETH_WR_BUSY(eth_wr_busy), 
	.ETH_WR_PIX(eth_wr_pix), .ETH_WR_STB(eth_wr_stb), 
	// Ethernet Read Port
	.ETH_RD_CLK(eth_rd_clk), .ETH_RD_START_X(eth_rd_start_x), .ETH_RD_LINE(eth_rd_line), .ETH_RD_NUM_PIXELS(eth_rd_num_pixels), 
	.ETH_RD_FRAME_SEL(eth_rd_frame_sel), 
	.ETH_RD_GO(eth_rd_go), .ETH_RD_DONE(eth_rd_done), .ETH_RD_BUSY(eth_rd_busy), 
	.ETH_RD_READY(eth_rd_ready), .ETH_RD_PIX(eth_rd_pix), .ETH_RD_STB(eth_rd_stb), 
	// Processing Read Port
	.PROC_RD_CLK(proc_rd_clk), .PROC_RD_WIDTH(proc_rd_width), .PROC_RD_HEIGHT(proc_rd_height), 
	.PROC_RD_GO(proc_rd_go), .PROC_RD_DONE(proc_rd_done), .PROC_RD_BUSY(proc_rd_busy), 
	.PROC_RD_READY(proc_rd_ready), .PROC_RD_PIX(proc_rd_pix), .PROC_RD_STB(proc_rd_stb), 
	// Processing Write Port
	.PROC_WR_CLK(proc_wr_clk), .PROC_WR_WIDTH(proc_wr_width), .PROC_WR_HEIGHT(proc_wr_height), 
	.PROC_WR_GO(proc_wr_go), .PROC_WR_DONE(proc_wr_done), .PROC_WR_BUSY(proc_wr_busy), 
	.PROC_WR_PIX(proc_wr_pix), .PROC_WR_STB(proc_wr_stb)
	);


//------- Video processing path -------
reg 	[7:0]	proc_cycle_cnt = 0;
reg 			proc_tick_1us = 0;
always @(posedge proc_clk) 
	begin
	proc_cycle_cnt <= (proc_cycle_cnt == 0) ? proc_clk_freq -1 : proc_cycle_cnt -1; 
	proc_tick_1us  <= (proc_cycle_cnt == 0); 
	end


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

SP601_PROC proc (
	.CLK(proc_clk), .TICK_1US(proc_tick_1us), 
	// Configuration
	.GAMMA_EN(proc_gamma_en), .INVGAMMA_EN(proc_invgamma_en), 
	.BOUND_ABS(proc_bound_abs), 
	.IMG_SIZE_X(proc_img_size_x), .IMG_SIZE_Y(proc_img_size_y), 
	.CTRL_COEFF(proc_ctrl_coeff), 
	// process control & status
	.PROC_GO(proc_go), .PROC_BUSY(), .PROC_DONE(), .PROC_TIME_US(proc_time_us), 
	// Processing Read Port
	.PROC_RD_CLK(proc_rd_clk), .PROC_RD_WIDTH(proc_rd_width), .PROC_RD_HEIGHT(proc_rd_height), 
	.PROC_RD_GO(proc_rd_go), .PROC_RD_DONE(proc_rd_done), .PROC_RD_BUSY(proc_rd_busy), 
	.PROC_RD_READY(proc_rd_ready), .PROC_RD_PIX(proc_rd_pix), .PROC_RD_STB(proc_rd_stb), 
	// Processing Write Port
	.PROC_WR_CLK(proc_wr_clk), .PROC_WR_WIDTH(proc_wr_width), .PROC_WR_HEIGHT(proc_wr_height), 
	.PROC_WR_GO(proc_wr_go), .PROC_WR_DONE(proc_wr_done), .PROC_WR_BUSY(proc_wr_busy), 
	.PROC_WR_PIX(proc_wr_pix), .PROC_WR_STB(proc_wr_stb)
	);


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
    .OUT_ETH_STREAM_FILT(filt_eth_stream), // packets from software
	.OUT_ETH_STREAM_OTHER() // ignore other packets 
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


// Control Interface
wire	[15:0]	proc_enables;
wire			ctrl_strb; // strobes when proc_enables are written - new values present
assign	proc_en          = proc_enables[15];
assign	eth_rd_frame_sel = proc_enables[15]; // read original if not enabled
assign	proc_gamma_en    = proc_enables[14]; // gamma enable bit - applied if 1
assign	proc_invgamma_en = proc_enables[13]; // inverse gamma enable bit - applied if 1
assign	proc_bound_abs   = proc_enables[12]; // bound negative with abs, not clip
assign	proc_use_dsp     = proc_enables[11]; // use DSP48A1 
reg		[7:0]	buttons=0;
always @(posedge clk125)
	begin
	buttons[3] <= (ctrl_strb&&proc_enables[3])? 1'b0 : (GPIO_BUTTON[3])? 1'b1 : buttons[3];
	buttons[2] <= (ctrl_strb&&proc_enables[2])? 1'b0 : (GPIO_BUTTON[2])? 1'b1 : buttons[2];
	buttons[1] <= (ctrl_strb&&proc_enables[1])? 1'b0 : (GPIO_BUTTON[1])? 1'b1 : buttons[1];
	buttons[0] <= (ctrl_strb&&proc_enables[0])? 1'b0 : (GPIO_BUTTON[0])? 1'b1 : buttons[0];
	end
assign GPIO_LED = {proc_enables[7:4]}; 

// Status
wire	[15:0]	sysmon_temperature =16'h0;
wire	[15:0]	sysmon_vccint      =16'h0;
wire	[15:0]	sysmon_vccaux      =16'h0;

/***** User Controls section *****/
wire	[7:0]	user_ctrl_en;    // 8 seperate enables controlled via GUI
wire	[15:0]	user_ctrl;       // 16-bit value entered via GUI
reg		[127:0]	user_status=0;	   // 16 bytes of status that reported back to GUI
wire			user_ctrl_stb;        // strobe to signal when user controls written
always @(posedge clk125) 
	user_status <= (user_ctrl_en[0])? 	{"Goodbye world",24'd0} :  // need to align first character w/ msb
										{"Hello Logic",40'd0};	// zero byte terminates the string in the GUI

// Ethernet packet engine - recieves packets from Software, generates response packets
BRD_PACKET_ENGINE #(	
	.SERVER_MAC(SERVER_MAC),
	.MY_MAC(MY_MAC),
	.FIRMWARE_VERSION(FIRMWARE_VERSION),
	.BOARD_TYPE(BOARD_TYPE)
)eth_pkt_engine(
    .CLK(clk125), 
    .IN_ETH_STREAM(out_pkt_buff_stream),
    .ETH_BUSY(eth_busy),
	.CTRL_BUSY(ctrl_busy), .CTRL_ENABLES(proc_enables), .IMG_SIZE_X(proc_img_size_x), .IMG_SIZE_Y(proc_img_size_y), 
	.CTRL_COEFF(proc_ctrl_coeff), .CTRL_STRB(ctrl_strb),
	.PROCESS_TIME(proc_time_us), .TEMPERATURE(sysmon_temperature), .V_VCCINT(sysmon_vccint), .V_VCCAUX(sysmon_vccaux), .BUTTONS(buttons),
	.ETH_WR_CLK(eth_wr_clk),
	.ETH_WR_START_X(eth_wr_start_x),.ETH_WR_LINE(eth_wr_line),.ETH_WR_NUM_PIXELS(eth_wr_num_pixels),
	.ETH_WR_GO(eth_wr_go),.ETH_WR_DONE(eth_wr_done),.ETH_WR_BUSY(eth_wr_busy),
	.ETH_WR_PIX(eth_wr_pix),.ETH_WR_STB(eth_wr_stb),
	.ETH_RD_CLK(eth_rd_clk),
	.ETH_RD_START_X(eth_rd_start_x),.ETH_RD_LINE(eth_rd_line),.ETH_RD_NUM_PIXELS(eth_rd_num_pixels),
	.ETH_RD_GO(eth_rd_go),.ETH_RD_DONE(eth_rd_done),.ETH_RD_BUSY(eth_rd_busy),
	.ETH_RD_READY(eth_rd_ready), .ETH_RD_PIX(eth_rd_pix),.ETH_RD_STB(eth_rd_stb),
    .OUT_ETH_STREAM(eth_tx_stream), .OUT_TICK(snd_cke),
   	.USER_CTRL_EN(user_ctrl_en),
	.USER_CTRL(user_ctrl),
	.USER_STATUS(user_status),
	.USER_CTRL_STB(user_ctrl_stb) );

//------- Multiboot controller -------
// detect reboot condition
reg 			reboot_go = 0;
always @(posedge clk125) if (ctrl_strb) // new controls came in
	reboot_go <= (proc_use_dsp != IS_DSP48A_VERSION); // not correct version

S6_MULTIBOOT #(
	.WARM_BOOT_START_ADR(reboot_adr), // address to attempt reboot at 
	.FALLBACK_START_ADR (primary_spi_multiboot_adr), // fallback address if failure
	.SPI_RD_OPCODE      (8'h03)         // read opcode (such as 03, E8, 3B, or 6B)
) s6multiboot (
    .CLK(clk20), 
    .GO(reboot_go) 
    );

endmodule
