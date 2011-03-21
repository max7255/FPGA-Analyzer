`timescale  100 ps / 10 ps
//-------------------------------------
// ETH_RX_PKT_BUF_2048.v
//-------------------------------------
// History of Changes:
//	06-13-2009  Initial creation
//-------------------------------------
// This is a module used to store received ethernet packet streams.
// This Buffer uses a block ram to store up to 2048 Bytes of packet data.  
// If there isn't enough buffer space for a new packet or the packet has a
// invalid checksum, the packet is dropped.  
// The packets are stored in block ram as sections of contiguous bytes specified by
// setting the block ram parity bit = 1.  These frames are seperated by
// 2 consequtive cells where the parity bit = 0.
//-------------------------------------
// The ETH_STREAM signal actually includes three signals:
//   Bit 9: CKE: Clock enable sets data rate.  Lower bits are only valid if CKE.
//   Bit 8: FRM: Frame signal, asserted for entire ethernet frame.
//   Bits 7-0: DAT: Frame data, ignored if not FRM.
//-------------------------------------
//-------------------------------------
module ETH_RX_PKT_BUF_2048_STREAM(
	CLK, 
	IN_ETH_STREAM,
	OUT_REQ, OUT_GO, OUT_TICK, 
	OUT_ETH_STREAM
	);

// Master Clock
input			CLK;

// Input data stream
input	[9:0]	IN_ETH_STREAM;

// Output arbitration
output			OUT_REQ; // we have a packet to send
input			OUT_GO; // strobe says we can send one!
input			OUT_TICK; // sets the output data rate.

// Output data stream
output	[9:0]	OUT_ETH_STREAM;


// Test the CRC
wire	[9:0]	crc_out_stream;
wire			start_stb, dat_stb, ok_stb, bad_stb;
wire	[7:0]	dat;
ETH_RX_CRC rxcrc (
	.CLK(CLK), 
	.IN_ETH_STREAM(IN_ETH_STREAM), 
	.OUT_ETH_STREAM(crc_out_stream), 
	.OUT_START_STB(start_stb), .OUT_DAT(dat), .OUT_DAT_STB(dat_stb), .OUT_OK_STB(ok_stb), .OUT_BAD_STB(bad_stb)
	);

// Write the incoming packet if there is space
reg		[10:0]	wrt_a=0,wrt_a_sv=0; // Write Address pointers
wire	[10:0]	wrt_a_nxt=wrt_a+1; // Next write address
reg		[10:0]	rd_a=0; // Read address
reg				wr_e_p_s=0; // strobe to write a second inter-packet-gap (simplifies packet readout)
wire			wr_en=(dat_stb||ok_stb||wr_e_p_s)&&(wrt_a!=wrt_a_sv);
always @(posedge CLK)
	begin
	if (dat_stb||start_stb||ok_stb)
		wrt_a <= (wrt_a_nxt==rd_a)? wrt_a_sv : /* reached end of unused space in fifo, restore ptr to start */ 
				 (wrt_a!=wrt_a_sv||start_stb)? wrt_a+1 : wrt_a; 
	wrt_a_sv <= (wr_e_p_s)? wrt_a : wrt_a_sv;
	wr_e_p_s <= ok_stb;
	end


// Stream out the stored packets
reg				out_go_reg=0; // save OUT_GO until next OUT_TICK
wire	[7:0]	rd_dat; 
wire			rd_frm;
reg				OUT_REQ=0; // high when a packet is available
always @(posedge CLK)
	begin
	out_go_reg <= (OUT_GO&&OUT_REQ)? 1'b1 : (OUT_TICK)? 1'b0 : out_go_reg;
	if (OUT_TICK)
		rd_a <= (out_go_reg||rd_frm)? rd_a+1 : rd_a;
	OUT_REQ <= (OUT_TICK)? (wrt_a_sv!=rd_a)&&!rd_frm&&!out_go_reg : OUT_REQ;
	end

//Receive buffer RAM
RAMB16_S9_S9 ram(	
	// Port A 	-- Written to when receiving
	.CLKA(CLK), 
	.ADDRA(wrt_a), 
	.DIA(dat), .DIPA(dat_stb), 
	.WEA(wr_en), 
	.DOA(), .DOPA(), 
	.ENA(1'b1), .SSRA(1'b0), 
	// Port B  -- Read by processor
	.CLKB(CLK), 
	.ADDRB(rd_a), //11bits
	.DIB(8'd0), .DIPB(0), 
	.WEB(1'b0), // read only
	.DOB(rd_dat), .DOPB(rd_frm),
	.ENB(OUT_TICK), .SSRB(1'b0)
	);	

// Register the outputs
reg		[7:0]	out_dat=0;
reg				out_frm=0;
reg				out_cke=0;
wire	[9:0]	OUT_ETH_STREAM={out_cke,out_frm,out_dat};
always @(posedge CLK)
	begin
	out_dat <= rd_dat;
	out_frm <= rd_frm;
	out_cke <= OUT_TICK;
	end

endmodule





//-------------------------------------
// Simulation test bench
//-------------------------------------
// History of Changes:
//	06-23-2009 Initial creation
//-------------------------------------

module eth_fifo_tst;
// Clock generator
reg				CLK = 0;
initial #4 forever #4 CLK = !CLK;

//generate ticks for 
reg		[3:0]	out_cnt=4'd0;
always @(posedge CLK) out_cnt <= (out_cnt==4'd9)? 0 : out_cnt+1;
wire			IN_TICK=1'b1;//(out_cnt==4'd9);
wire			OUT_TICK=1'b1;//(out_cnt==4'd9);

// test pkt interface
wire 			test_cke = IN_TICK;
reg 			test_frm = 0;
reg 	[7:0]	test_dat;

reg 	[10:0]	test_pkt_size = 65; // 14+7+40+4
reg 	[10:0]	test_cnt = 11'd1536;
always @(posedge CLK) if (test_cke)
	begin
	test_cnt <= test_cnt + 1;
	test_frm <= (test_cnt < test_pkt_size);
	case (test_cnt)
		//Control Packet
		11'd00: test_dat <= 8'h00; // Dest MAC
		11'd01: test_dat <= 8'h10;
		11'd02: test_dat <= 8'h8B;
		11'd03: test_dat <= 8'hF1;
		11'd04: test_dat <= 8'hF5;
		11'd05: test_dat <= 8'h7E;
		11'd06: test_dat <= 8'h00; // Src MAC
		11'd07: test_dat <= 8'h10;
		11'd08: test_dat <= 8'h8B;
		11'd09: test_dat <= 8'hF1;
		11'd10: test_dat <= 8'hF5;
		11'd11: test_dat <= 8'h7D;
		11'd12: test_dat <= 8'h00; // Length
		11'd13: test_dat <= 8'h07;
		11'd14: test_dat <= 8'h04; // Opcode = control
		11'd15: test_dat <= 8'h00; // CTRL
		11'd16: test_dat <= 8'h00; 
		11'd17: test_dat <= 8'h01; // Width
		11'd18: test_dat <= 8'hB2; 
		11'd19: test_dat <= 8'h01; // Height
		11'd20: test_dat <= 8'hF1;
        11'd21: test_dat <= 8'h00;
        11'd22: test_dat <= 8'h00;
        11'd23: test_dat <= 8'h00;
        11'd24: test_dat <= 8'h00;
        11'd25: test_dat <= 8'h00;
        11'd26: test_dat <= 8'h00;
        11'd27: test_dat <= 8'h00;
        11'd28: test_dat <= 8'h00;
        11'd29: test_dat <= 8'h00;
        11'd30: test_dat <= 8'h00;
        11'd31: test_dat <= 8'h00;
        11'd32: test_dat <= 8'h00;
        11'd33: test_dat <= 8'h00;
        11'd34: test_dat <= 8'h00;
        11'd35: test_dat <= 8'h00;
        11'd36: test_dat <= 8'h00;
        11'd37: test_dat <= 8'h00;
        11'd38: test_dat <= 8'h00;
        11'd39: test_dat <= 8'h00;
        11'd40: test_dat <= 8'h00;
        11'd41: test_dat <= 8'h00;
        11'd42: test_dat <= 8'h00;
        11'd43: test_dat <= 8'h00;
        11'd44: test_dat <= 8'h00;
        11'd45: test_dat <= 8'h00;
        11'd46: test_dat <= 8'h00;
        11'd47: test_dat <= 8'h00;
        11'd48: test_dat <= 8'h00;
        11'd49: test_dat <= 8'h00;
        11'd50: test_dat <= 8'h00;
        11'd51: test_dat <= 8'h00;
        11'd52: test_dat <= 8'h00;
        11'd53: test_dat <= 8'h00;
        11'd54: test_dat <= 8'h00;
        11'd55: test_dat <= 8'h00;
        11'd56: test_dat <= 8'h00;
        11'd57: test_dat <= 8'h00;
        11'd58: test_dat <= 8'h00;
        11'd59: test_dat <= 8'h00;
        11'd60: test_dat <= 8'h00;                   
		default: test_dat <= 0; 
	endcase                    
	end                        
                               
// Add CRC to the stream       
wire	[9:0]	IN_TEST_STREAM;
ETH_TX_CRC ctrlcrc(.CLK(CLK), .IN_ETH_STREAM({test_cke, test_frm, test_dat[7:0]}), .OUT_ETH_STREAM(IN_TEST_STREAM)	);

wire			OUT_REQ;
wire			OUT_GO=OUT_REQ;
wire	[9:0]	OUT_ETH_STREAM;
ETH_RX_PKT_BUF_2048_STREAM dut(
	.CLK(CLK), 
	.IN_ETH_STREAM(IN_TEST_STREAM),
	.OUT_REQ(OUT_REQ), .OUT_GO(OUT_GO), .OUT_TICK(OUT_TICK), 
	.OUT_ETH_STREAM(OUT_ETH_STREAM) );

wire			buf_cke = OUT_ETH_STREAM[9];
wire			buf_frm = OUT_ETH_STREAM[8];
wire	[7:0]	buf_dat = OUT_ETH_STREAM[7:0];


endmodule


