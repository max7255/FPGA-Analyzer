`timescale 	1ns / 1ns
//-------------------------------------
// S6_MULTIBOOT.v
//-------------------------------------
// History of Changes:
//	6-17-2009 Initial creation
//-------------------------------------
// This module does three things via the ICAP port:
// 1. programs the WARM_BOOT_START_ADR
// 2. loads the FALLBACK_START_ADR
// 3. issues the IPROG command - results in reboot
//-------------------------------------
// This operation is 1-shot - this module gets a GO and does its thing.
// CLK should be within the ICAP frequency capability - see datasheet
//-------------------------------------
module S6_MULTIBOOT #(
parameter	WARM_BOOT_START_ADR = 24'h08_00_00, // address to attempt reboot at
parameter	FALLBACK_START_ADR  = 24'h00_00_00, // fallback address if failure
parameter	SPI_RD_OPCODE       =  8'h03        // read opcode (such as 03, E8, 3B, or 6B)
)(
// Master Clock
input	wire	CLK,
input	wire	GO
);

// generate 1-shot counter
reg 	[4:0]	cnt = 5'd31;
always @(posedge CLK) 
	if (GO && (cnt == 5'd31))
		cnt <= 0; // start counter
	else if (cnt[4:1] != 4'b1111) 
		cnt <= cnt +1; // go to 1E
	
wire			cs_l = (cnt[4:1] == 4'b1111);
reg 	[15:0]	dat;
always @(cnt)
	case (cnt)
	5'd00: dat = 16'hFFFF; // dummy word
	5'd01: dat = 16'hFFFF; // dummy word
	5'd02: dat = 16'hAA99; // sync word
	5'd03: dat = 16'h5566; // sync word
	5'd04: dat = 16'h31E1;                          // Type 1, write, CWDT_REG, 1 word
	5'd05: dat = 16'hFFFF;                          // Default long watchdog
	5'd06: dat = 16'h3261;                          // Type 1, write, GENERAL1, 1 word
	5'd07: dat = WARM_BOOT_START_ADR[15:0];         // start address[15:0]
	5'd08: dat = 16'h3281;                          // Type 1, write, GENERAL2, 1 word
	5'd09: dat = {SPI_RD_OPCODE[7:0], WARM_BOOT_START_ADR[23:16]};// Opcode and start address
	5'd10: dat = 16'h32A1;                          // Type 1, write, GENERAL3, 1 word
	5'd11: dat = FALLBACK_START_ADR[15:0];          // start address[15:0]
	5'd12: dat = 16'h32C1;                          // Type 1, write, GENERAL4, 1 word
	5'd13: dat = {SPI_RD_OPCODE[7:0], FALLBACK_START_ADR[23:16]}; // Opcode and start address
	5'd14: dat = 16'h32E1;                          // Type 1, write, GENERAL5, 1 word
	5'd15: dat = 16'h0000;                          // general storage, Not used
	5'd16: dat = 16'h30A1;                          // Type 1, write, CMD,      1 word
	5'd17: dat = 16'h0000;                          // Null
	5'd18: dat = 16'h3301;                          // Type 1, write, MODE_REG, 1 word
	5'd19: dat = 16'h2100;                          // bit, spi x1, mode = 001 SPI, 00h read don't care
	5'd20: dat = 16'h3201;                          // Type 1, write, HC_OPT, 1 word
	5'd21: dat = 16'h001F;                          // don't skip house cleaning
	5'd22: dat = 16'h30A1;                          // Type 1, write, CMD,      1 word
	5'd23: dat = 16'h000E;                          // IPROG Reboot Command
	default: dat = 16'h2000;                        // Type 1, NOP
	endcase

wire	[15:0]	dat_flip = {dat[8], dat[9], dat[10], dat[11], dat[12], dat[13], dat[14], dat[15], dat[0], dat[1], dat[2], dat[3], dat[4], dat[5], dat[6], dat[7]}; 

ICAP_SPARTAN6 icaps6 (
	.CLK(CLK),     // 1-bit Clock input
	.CE(cs_l),     // 1-bit Active low clock enable input
	.I(dat_flip),  // 16-bit Configuration data input bus
	.O(),          // 16-bit Configuartion data output bus
	.WRITE(1'b0),  // 1-bit Active low write input
	.BUSY()        // 1-bit Busy output
	);

endmodule

////-------------------------------------
//// Simulation test bench
////-------------------------------------
//// History of Changes:
////	6-16-2009 Initial creation
////-------------------------------------
//module multiboot_tst;
//// Master Clock
//reg		CLK = 0;
//initial #10 forever #10 CLK = !CLK;
//reg 	GO = 0;
//
//S6_MULTIBOOT #(
//	.WARM_BOOT_START_ADR(24'h08_00_00), // address to attempt reboot at
//	.FALLBACK_START_ADR (24'h00_00_00), // fallback address if failure
//	.SPI_RD_OPCODE      (8'h03)         // read opcode (such as 03, E8, 3B, or 6B)
//) s6multiboot (
//    .CLK(CLK), 
//    .GO(GO)
//    );
//
//initial 
//	begin
//	#1001 GO = 1;
//	end
//
//endmodule
//
