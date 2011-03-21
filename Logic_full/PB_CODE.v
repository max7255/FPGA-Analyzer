//-------------------------------------
// PB_CODE
// Jason Daughenbaugh
//-------------------------------------
// History of Changes:
//	5-11-2004 JAD: created 
//  5-13-2004 JAD: added LOAD_x ports for loading PicoBlaze code
//-------------------------------------
// This is a module for storing a program for the KCPSM3 (aka PicoBlaze)
// The code is assembled as "pbt3" (should be pbt3 for spartan 3)
//-------------------------------------
// Ingredients:
//  1 18kb Block Ram
//-------------------------------------
module PB_CODE(
	CLK, ADDRESS, INSTRUCTION,
	LOAD_CLK, LOAD_ADDRESS, LOAD_INSTRUCTION, LOAD_WE
	);

input			CLK;
input	[9:0]	ADDRESS;
output	[17:0]	INSTRUCTION;

// Load interface for reloading program
input			LOAD_CLK;
input	[9:0]	LOAD_ADDRESS;
input	[17:0]	LOAD_INSTRUCTION;
input			LOAD_WE;

RAMB16_S18_S18 rom(	
	// Port A: Read Port
	.CLKA(CLK), .ADDRA(ADDRESS),
	.DIA(16'h0000), .DIPA(2'b00), .WEA(1'b0),
	.DOA(INSTRUCTION[15:0]), .DOPA(INSTRUCTION[17:16]),
	.ENA(1'b1), .SSRA(1'b0),
	// port B: Load (write) port
	.CLKB(LOAD_CLK), .ADDRB(LOAD_ADDRESS), 
	.DIB(LOAD_INSTRUCTION[15:0]), .DIPB(LOAD_INSTRUCTION[17:16]), .WEB(LOAD_WE),
	.DOB(), .DOPB(),
	.ENB(1'b1), .SSRB(1'b0)
	);


defparam rom.INIT_00  = 256'hA000C00000045413214054102180500D2108500D2104002D0011060740000002;
defparam rom.INIT_01  = 256'h0208010E02001160005000400020E207E106E005A000C0000005A000C0000006;
defparam rom.INIT_02  = 256'h00400021E005A000004262076106001000420010C202D200000600066005D100;
defparam rom.INIT_03  = 256'hA000004F004000120042000ED200000600066005D1000208010E020011600060;
defparam rom.INIT_04  = 256'h1410A0005443C001544AC501050601000200050E004FA5014500030040430320;
defparam rom.INIT_05  = 256'h0000000000000000000000008000A000C400A4A0C400C400C440C400D430A480;
defparam rom.INIT_06  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_07  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_08  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_09  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_0A  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_0B  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_0C  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_0D  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_0E  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_0F  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_10  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_11  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_12  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_13  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_14  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_15  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_16  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_17  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_18  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_19  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_1A  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_1B  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_1C  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_1D  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_1E  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_1F  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_20  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_21  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_22  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_23  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_24  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_25  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_26  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_27  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_28  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_29  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_2A  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_2B  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_2C  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_2D  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_2E  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_2F  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_30  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_31  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_32  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_33  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_34  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_35  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_36  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_37  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_38  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_39  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_3A  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_3B  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_3C  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_3D  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_3E  = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INIT_3F  = 256'h4059000000000000000000000000000000000000000000000000000000000000;
defparam rom.INITP_00 = 256'h0000000000000000000E8A202DD2AC0CBCC28280CAC0C0A0A032AA28A377770F;
defparam rom.INITP_01 = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INITP_02 = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INITP_03 = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INITP_04 = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INITP_05 = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INITP_06 = 256'h0000000000000000000000000000000000000000000000000000000000000000;
defparam rom.INITP_07 = 256'hC000000000000000000000000000000000000000000000000000000000000000;

// synthesis translate_off
// synthesis translate_on

// synthesis attribute INIT_00  of rom is "A000C00000045413214054102180500D2108500D2104002D0011060740000002"
// synthesis attribute INIT_01  of rom is "0208010E02001160005000400020E207E106E005A000C0000005A000C0000006"
// synthesis attribute INIT_02  of rom is "00400021E005A000004262076106001000420010C202D200000600066005D100"
// synthesis attribute INIT_03  of rom is "A000004F004000120042000ED200000600066005D1000208010E020011600060"
// synthesis attribute INIT_04  of rom is "1410A0005443C001544AC501050601000200050E004FA5014500030040430320"
// synthesis attribute INIT_05  of rom is "0000000000000000000000008000A000C400A4A0C400C400C440C400D430A480"
// synthesis attribute INIT_06  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_07  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_08  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_09  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_0A  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_0B  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_0C  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_0D  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_0E  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_0F  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_10  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_11  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_12  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_13  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_14  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_15  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_16  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_17  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_18  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_19  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_1A  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_1B  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_1C  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_1D  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_1E  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_1F  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_20  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_21  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_22  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_23  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_24  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_25  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_26  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_27  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_28  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_29  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_2A  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_2B  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_2C  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_2D  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_2E  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_2F  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_30  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_31  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_32  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_33  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_34  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_35  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_36  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_37  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_38  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_39  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_3A  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_3B  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_3C  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_3D  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_3E  of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INIT_3F  of rom is "4059000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INITP_00 of rom is "0000000000000000000E8A202DD2AC0CBCC28280CAC0C0A0A032AA28A377770F"
// synthesis attribute INITP_01 of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INITP_02 of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INITP_03 of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INITP_04 of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INITP_05 of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INITP_06 of rom is "0000000000000000000000000000000000000000000000000000000000000000"
// synthesis attribute INITP_07 of rom is "C000000000000000000000000000000000000000000000000000000000000000"


endmodule