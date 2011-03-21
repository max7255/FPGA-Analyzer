`timescale  1 ns / 1 ns
//-------------------------------------
// ETH_FILTER.v
//-------------------------------------
// History of Changes:
//	01-10-2008 Initial creation
//	06-08-2009 Modified for use on S6demo
//-------------------------------------
// This is a module to Filter packets based on MAC address
// There are two output streams:
// OUT_ETH_STREAM_FILT: Is packet with matching FILT_MAC
// OUT_ETH_STREAM_OTHER: All packets that do not match FILT_MAC
//-------------------------------------
// The ETH_STREAM signals actually includes three signals:
//   Bit 9: CKE: Clock enable sets data rate.  Lower bits are only valid if CKE.
//   Bit 8: FRM: Frame signal, asserted for entire ethernet frame.
//   Bits 7-0: DAT: Frame data, ignored if not FRM.
//-------------------------------------
//-------------------------------------
module ETH_FILTER(
	CLK, 
	IN_ETH_STREAM, 
	OUT_ETH_STREAM_FILT, OUT_ETH_STREAM_OTHER
	);

parameter	FILT_MAC	=	48'h00_18_B7_FF_FF_FF; // MAC to filter on
	
// Master Clock
input			CLK;

// Input data stream
input	[9:0]	IN_ETH_STREAM;
wire			in_cke = IN_ETH_STREAM[9];
wire			in_frm = IN_ETH_STREAM[8];
wire	[7:0]	in_dat = IN_ETH_STREAM[7:0];

// Output data streams
output	[9:0]	OUT_ETH_STREAM_FILT;
output	[9:0]	OUT_ETH_STREAM_OTHER;


// Packet Byte counter
reg 	[3:0] 	byte_cnt = 0; //only care about the first part
always @(posedge CLK) if (in_cke)
	byte_cnt <= !in_frm ? 4'd0 : (byte_cnt != 4'd15) ? byte_cnt+1 : byte_cnt;

// Video Server address
reg 	[7:0]	mac_dat; // combinational result
always @(byte_cnt[3:0])
	case (byte_cnt)
	4'd06: mac_dat = FILT_MAC[47:40];
	4'd07: mac_dat = FILT_MAC[39:32];
	4'd08: mac_dat = FILT_MAC[31:24];
	4'd09: mac_dat = FILT_MAC[23:16];
	4'd10: mac_dat = FILT_MAC[15:8];
	4'd11: mac_dat = FILT_MAC[7:0];
	default: mac_dat = 8'h00;
	endcase

// check the src mac address
wire			src_mac_chk_en = (byte_cnt >= 4'd6) && (byte_cnt < 4'd12) && in_frm; // src is bytes 6-11
reg				match = 0; // Src MAC matched FILT_MAC
wire			mac_mismatch   = (in_dat != mac_dat); 
always @(posedge CLK) if (in_cke)
	match <= (in_frm&&(byte_cnt==3'd0))? 1 : (mac_mismatch && src_mac_chk_en)  ? 1'b0 : match;
	
// delay the data to lag comparison results
reg 	[7:0]	dat_dly[12:1];
reg 	[12:1]	frm_dly = 0;
always @(posedge CLK) if (in_cke)
	begin
	dat_dly[01] <= in_dat;
	dat_dly[02] <= dat_dly[01];
	dat_dly[03] <= dat_dly[02];
	dat_dly[04] <= dat_dly[03];
	dat_dly[05] <= dat_dly[04];
	dat_dly[06] <= dat_dly[05];
	dat_dly[07] <= dat_dly[06];
	dat_dly[08] <= dat_dly[07];
	dat_dly[09] <= dat_dly[08];
	dat_dly[10] <= dat_dly[09];
	dat_dly[11] <= dat_dly[10];
	dat_dly[12] <= dat_dly[11];
	frm_dly <= {frm_dly[11:1], in_frm};
	end

//register outputs
reg 	[9:0]	OUT_ETH_STREAM_FILT;
reg 	[9:0]	OUT_ETH_STREAM_OTHER;
always @(posedge CLK) OUT_ETH_STREAM_FILT <= {in_cke, frm_dly[12] &&  match, dat_dly[12]};
always @(posedge CLK) OUT_ETH_STREAM_OTHER <= {in_cke, frm_dly[12] && !match, dat_dly[12]};



endmodule
