`timescale 	1ns / 1ns
//-------------------------------------
// SP601_PROC.v
//-------------------------------------
// History of Changes:
//	6-16-2009 Initial creation
//-------------------------------------
//-------------------------------------
module SP601_PROC (

// Master Clock
input	wire			CLK,
input	wire			TICK_1US, 

// Filter Config Interface
input	wire			GAMMA_EN,    // gamma enable bit - applied if 1
input	wire			INVGAMMA_EN, // inverse gamma enable bit - applied if 1
input	wire			BOUND_ABS,   // bound negative as absolute values, else clip to 0
input	wire	[15:0]	IMG_SIZE_X,
input	wire	[15:0]	IMG_SIZE_Y,
input	wire	[399:0]	CTRL_COEFF,

// status
input	wire 			PROC_GO, // can tie GO high for continuous looping
output	reg 			PROC_BUSY=0,
output	reg 			PROC_DONE=0, 
output	reg 	[23:0]	PROC_TIME_US=0,

// Processing Read Port - Reads original image
output	wire			PROC_RD_CLK,       // Processing clock (200MHz?)
output	wire	[15:0]	PROC_RD_WIDTH,     // in pixels (max 4k)
output	wire	[15:0]	PROC_RD_HEIGHT,    // in pixels (max 4k)
output	reg 			PROC_RD_GO=0,      // Strobe to start frame read - latches parameters, starts
input	wire			PROC_RD_DONE,      // Strobes when done
input	wire			PROC_RD_BUSY,      // Asserted from GO to DONE
input	wire			PROC_RD_READY,     // indicates that read FIFO has pixels ready for RD_STB
input	wire	[23:0]	PROC_RD_PIX,
output	reg 			PROC_RD_STB=0,     // Strobe to pull RD_PIX from FIFO

// Processing Write Port - writes processed image
output	wire			PROC_WR_CLK,       // Processing clock (200MHz?)
output	wire	[15:0]	PROC_WR_WIDTH,     // in pixels (max 4k)
output	wire	[15:0]	PROC_WR_HEIGHT,    // in pixels (max 4k)
output	reg 			PROC_WR_GO=0,      // strobe before start of frame - latches parameters
input	wire			PROC_WR_DONE,      // Strobes when done
input	wire			PROC_WR_BUSY,      // Asserted from GO to DONE
output	reg 	[23:0]	PROC_WR_PIX,
output	reg 			PROC_WR_STB=0      // Start strobing in pixels after GO

);


// Main controller-
always @(posedge CLK)
	begin
	PROC_DONE <= PROC_WR_DONE; // Use the write status to know if we are done w/ frame
	PROC_BUSY <= PROC_DONE ? 0 : PROC_GO ? 1'b1 : PROC_BUSY;
	end

// Measure the processing time
reg 	[23:0]	timer = 0;
always @(posedge CLK)
	begin
	timer <= !PROC_BUSY ? 0 : TICK_1US ? timer +1 : timer;
	if (PROC_WR_DONE) PROC_TIME_US  <= timer;
	end

// Read Pixels from the frame buffer
assign PROC_RD_CLK    = CLK;
assign PROC_RD_WIDTH  = IMG_SIZE_X;
assign PROC_RD_HEIGHT = IMG_SIZE_Y;
// Serialize R,G,B from read pixels
reg 	[1:0]	rd_cycle_cnt = 0;
reg 	[23:0]	rd_pix;
wire	[7:0]	rd_byte = rd_pix[23:16];
reg 			rd_byte_strobe = 0;
always @(posedge CLK)
	begin
	rd_cycle_cnt   <= PROC_RD_GO ? 0 : (PROC_RD_READY || (rd_cycle_cnt != 2'b00))? (rd_cycle_cnt[1] ? 0 : rd_cycle_cnt +1) : rd_cycle_cnt;
	PROC_RD_STB    <= ((rd_cycle_cnt == 0) && PROC_RD_READY);
	rd_pix         <= ((rd_cycle_cnt == 0) && PROC_RD_READY) ? PROC_RD_PIX : {rd_pix[15:0], 8'h00};
	rd_byte_strobe <= ((rd_cycle_cnt == 0) && PROC_RD_READY) || (rd_cycle_cnt != 2'b00);
	PROC_RD_GO     <= PROC_GO && !PROC_BUSY;
	end

// Gamma table
wire	[11:0]	gamma_out_dat;
reg 			gamma_out_strobe = 0;
always @(posedge CLK) gamma_out_strobe <= rd_byte_strobe; // match gamma latency
GAMMA_8_12 gamma (.CLK(CLK), .CE(1'b1), .EN(GAMMA_EN), .DIN(rd_byte), .DOUT(gamma_out_dat) );

// 2DFIR
// First latch X,Y so they don't change during processing:
reg 	[15:0]	fir2d_size_x = 16'd256;
reg 	[15:0]	fir2d_size_y = 16'd256;
always @(posedge CLK) if (PROC_GO && !PROC_BUSY)
	begin
	fir2d_size_x <= IMG_SIZE_X;
	fir2d_size_y <= IMG_SIZE_Y;
	end

wire	[11:0]	proc_out_data;
wire			proc_out_strobe;
FIR_2D_5x5	fir2d(
	.CLK(CLK), .RST(1'b0), .CE(1'b1),
	.IMG_SIZE_X(fir2d_size_x),.IMG_SIZE_Y(fir2d_size_y),
	.FILT_COEFF(CTRL_COEFF), .BOUND_ABS(BOUND_ABS), 
	.DIN(gamma_out_dat),.DIN_STRB(gamma_out_strobe),
	.DOUT(proc_out_data),.DOUT_STRB(proc_out_strobe)	);


// bypass FIR.
//assign proc_out_data = gamma_out_dat;
//assign proc_out_strobe = gamma_out_strobe;

// inverse gamma table
wire	[7:0]	invgamma_byte;
reg 			inv_gamma_dly = 0, invgamma_strobe = 0;
INV_GAMMA_12_8 invgamma (.CLK(CLK), .CE(1'b1), .EN(INVGAMMA_EN), .DIN(proc_out_data), .DOUT(invgamma_byte) );
always @(posedge CLK) 
	begin
	inv_gamma_dly <= proc_out_strobe; // match gamma latency
	invgamma_strobe <= inv_gamma_dly; // match gamma latency
	end

// Write pixels to the frame buffer
assign PROC_WR_CLK    = CLK;
assign PROC_WR_WIDTH  = IMG_SIZE_X;
assign PROC_WR_HEIGHT = IMG_SIZE_Y;
// parallel-up RGB pixels for write
reg 	[1:0]	wr_cycle_cnt = 0;
always @(posedge CLK)
	begin
	wr_cycle_cnt <= PROC_WR_GO ? 0 : invgamma_strobe ? (wr_cycle_cnt[1] ? 0 : wr_cycle_cnt +1) : wr_cycle_cnt;
	PROC_WR_PIX  <= invgamma_strobe ? {PROC_WR_PIX[15:0], invgamma_byte} : PROC_WR_PIX;
	PROC_WR_STB  <= invgamma_strobe && (wr_cycle_cnt == 2'd2);
	PROC_WR_GO   <= PROC_GO && !PROC_BUSY;
	end

	
endmodule

//-------------------------------------
// Simulation test bench
//-------------------------------------
// History of Changes:
//	6-16-2009  Initial creation
//-------------------------------------
module proc_tst;
// Master Clock
reg				CLK = 0;
initial #5 forever #5 CLK = !CLK;
reg 			TICK_1US = 0;
initial #301 forever #1000 TICK_1US = 1;
always @(posedge CLK) TICK_1US <= 0;

// Filter Control Interface
reg 			GAMMA_EN = 1;
reg 			INVGAMMA_EN = 1;
reg 	[15:0]	IMG_SIZE_X = 16'd80;
reg 	[15:0]	IMG_SIZE_Y = 16'd10;
reg 	[399:0]	CTRL_COEFF;

// status
reg  			PROC_GO = 0; // can tie GO high for continuous looping
wire			PROC_BUSY;
wire			PROC_DONE; 
wire	[23:0]	PROC_TIME_US;


// Processing Read Port - Reads original image
wire			PROC_RD_CLK;       // Processing clock (200MHz?)
wire	[15:0]	PROC_RD_WIDTH;     // in pixels (max 4k)
wire	[15:0]	PROC_RD_HEIGHT;    // in pixels (max 4k)
wire			PROC_RD_GO;        // Strobe to start frame read - latches parameters; starts
wire			PROC_RD_DONE;      // Strobes when done
wire			PROC_RD_BUSY;      // Asserted from GO to DONE
wire			PROC_RD_READY;     // indicates that read FIFO has pixels ready for RD_STB
wire	[23:0]	PROC_RD_PIX;
wire			PROC_RD_STB;       // Strobe to pull RD_PIX from FIFO

// Processing Write Port - writes processed image
wire			PROC_WR_CLK;       // Processing clock (200MHz?)
wire	[15:0]	PROC_WR_WIDTH;     // in pixels (max 4k)
wire	[15:0]	PROC_WR_HEIGHT;    // in pixels (max 4k)
wire			PROC_WR_GO;        // strobe before start of frame - latches parameters
wire			PROC_WR_DONE;      // Strobes when done
wire			PROC_WR_BUSY;      // Asserted from GO to DONE
wire	[23:0]	PROC_WR_PIX;
wire			PROC_WR_STB;       // Start strobing in pixels after GO

SP601_FB_sim FBsim (
	.PROC_RD_CLK(PROC_RD_CLK), 
	.PROC_RD_WIDTH(PROC_RD_WIDTH), 
	.PROC_RD_HEIGHT(PROC_RD_HEIGHT), 
	.PROC_RD_GO(PROC_RD_GO), 
	.PROC_RD_DONE(PROC_RD_DONE), 
	.PROC_RD_BUSY(PROC_RD_BUSY), 
	.PROC_RD_READY(PROC_RD_READY), 
	.PROC_RD_PIX(PROC_RD_PIX), 
	.PROC_RD_STB(PROC_RD_STB), 
	.PROC_WR_CLK(PROC_WR_CLK), 
	.PROC_WR_WIDTH(PROC_WR_WIDTH), 
	.PROC_WR_HEIGHT(PROC_WR_HEIGHT), 
	.PROC_WR_GO(PROC_WR_GO), 
	.PROC_WR_DONE(PROC_WR_DONE), 
	.PROC_WR_BUSY(PROC_WR_BUSY), 
	.PROC_WR_PIX(PROC_WR_PIX), 
	.PROC_WR_STB(PROC_WR_STB)
    );


SP601_PROC dut (
	.CLK(CLK), 
	.TICK_1US(TICK_1US), 
	.GAMMA_EN(GAMMA_EN), 
	.INVGAMMA_EN(INVGAMMA_EN), 
	.IMG_SIZE_X(IMG_SIZE_X), 
	.IMG_SIZE_Y(IMG_SIZE_Y), 
	.CTRL_COEFF(CTRL_COEFF), 
	.PROC_GO(PROC_GO), 
	.PROC_BUSY(PROC_BUSY), 
	.PROC_DONE(PROC_DONE), 
	.PROC_TIME_US(PROC_TIME_US), 
	.PROC_RD_CLK(PROC_RD_CLK), 
	.PROC_RD_WIDTH(PROC_RD_WIDTH), 
	.PROC_RD_HEIGHT(PROC_RD_HEIGHT), 
	.PROC_RD_GO(PROC_RD_GO), 
	.PROC_RD_DONE(PROC_RD_DONE), 
	.PROC_RD_BUSY(PROC_RD_BUSY), 
	.PROC_RD_READY(PROC_RD_READY), 
	.PROC_RD_PIX(PROC_RD_PIX), 
	.PROC_RD_STB(PROC_RD_STB), 
	.PROC_WR_CLK(PROC_WR_CLK), 
	.PROC_WR_WIDTH(PROC_WR_WIDTH), 
	.PROC_WR_HEIGHT(PROC_WR_HEIGHT), 
	.PROC_WR_GO(PROC_WR_GO), 
	.PROC_WR_DONE(PROC_WR_DONE), 
	.PROC_WR_BUSY(PROC_WR_BUSY), 
	.PROC_WR_PIX(PROC_WR_PIX), 
	.PROC_WR_STB(PROC_WR_STB)
	);

always @(posedge CLK) PROC_GO <= 0; // single loops

initial 
	begin
	#1001 PROC_GO = 1;
	#30000
		begin
		GAMMA_EN = 0;
		INVGAMMA_EN = 0;
		PROC_GO = 1;
		end
	end

endmodule

