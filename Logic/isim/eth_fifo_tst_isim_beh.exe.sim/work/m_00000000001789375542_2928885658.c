/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xcb73ee62 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Workspace/lvk/doc/SP601-USB-Image_12.3/sp601_brd/SP601_BRD_Src/Logic/ETH_RX_PKT_BUF_2048_STREAM.v";
static int ng1[] = {1, 0};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {0U, 0U};
static int ng4[] = {0, 0};



static void NetDecl_57_0(char *t0)
{
    char t6[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;

LAB0:    t1 = (t0 + 3928U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(57, ng0);
    t2 = (t0 + 2760);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 32, t4, 11, t5, 32);
    t7 = (t0 + 5792);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    t10 = (t9 + 40U);
    t11 = *((char **)t10);
    memset(t11, 0, 8);
    t12 = 2047U;
    t13 = t12;
    t14 = (t6 + 4);
    t15 = *((unsigned int *)t6);
    t12 = (t12 & t15);
    t16 = *((unsigned int *)t14);
    t13 = (t13 & t16);
    t17 = (t11 + 4);
    t18 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t18 | t12);
    t19 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t19 | t13);
    xsi_driver_vfirst_trans(t7, 0, 10U);
    t20 = (t0 + 5708);
    *((int *)t20) = 1;

LAB1:    return;
}

static void NetDecl_60_1(char *t0)
{
    char t4[8];
    char t18[8];
    char t25[8];
    char t53[8];
    char t69[8];
    char t77[8];
    char t105[8];
    char t123[8];
    char t139[8];
    char t147[8];
    char *t1;
    char *t2;
    char *t3;
    unsigned int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    char *t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    char *t39;
    char *t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    char *t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    char *t60;
    char *t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    char *t66;
    char *t67;
    char *t68;
    char *t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    char *t76;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    char *t81;
    char *t82;
    char *t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    char *t91;
    char *t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    char *t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    char *t112;
    char *t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    char *t117;
    char *t118;
    char *t119;
    char *t120;
    char *t121;
    char *t122;
    char *t124;
    char *t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    unsigned int t137;
    char *t138;
    char *t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    unsigned int t144;
    unsigned int t145;
    char *t146;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    char *t151;
    char *t152;
    char *t153;
    unsigned int t154;
    unsigned int t155;
    unsigned int t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    char *t161;
    char *t162;
    unsigned int t163;
    unsigned int t164;
    unsigned int t165;
    unsigned int t166;
    unsigned int t167;
    unsigned int t168;
    unsigned int t169;
    unsigned int t170;
    int t171;
    int t172;
    unsigned int t173;
    unsigned int t174;
    unsigned int t175;
    unsigned int t176;
    unsigned int t177;
    unsigned int t178;
    char *t179;
    char *t180;
    char *t181;
    char *t182;
    char *t183;
    unsigned int t184;
    unsigned int t185;
    char *t186;
    unsigned int t187;
    unsigned int t188;
    char *t189;
    unsigned int t190;
    unsigned int t191;
    char *t192;

LAB0:    t1 = (t0 + 4072U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(60, ng0);
    t2 = (t0 + 1244U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t3 + 4);
    t5 = *((unsigned int *)t2);
    t6 = (~(t5));
    t7 = *((unsigned int *)t3);
    t8 = (t7 & t6);
    t9 = (t8 & 1U);
    if (t9 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t2) != 0)
        goto LAB6;

LAB7:    t11 = (t4 + 4);
    t12 = *((unsigned int *)t4);
    t13 = (!(t12));
    t14 = *((unsigned int *)t11);
    t15 = (t13 || t14);
    if (t15 > 0)
        goto LAB8;

LAB9:    memcpy(t25, t4, 8);

LAB10:    memset(t53, 0, 8);
    t54 = (t25 + 4);
    t55 = *((unsigned int *)t54);
    t56 = (~(t55));
    t57 = *((unsigned int *)t25);
    t58 = (t57 & t56);
    t59 = (t58 & 1U);
    if (t59 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t54) != 0)
        goto LAB20;

LAB21:    t61 = (t53 + 4);
    t62 = *((unsigned int *)t53);
    t63 = (!(t62));
    t64 = *((unsigned int *)t61);
    t65 = (t63 || t64);
    if (t65 > 0)
        goto LAB22;

LAB23:    memcpy(t77, t53, 8);

LAB24:    memset(t105, 0, 8);
    t106 = (t77 + 4);
    t107 = *((unsigned int *)t106);
    t108 = (~(t107));
    t109 = *((unsigned int *)t77);
    t110 = (t109 & t108);
    t111 = (t110 & 1U);
    if (t111 != 0)
        goto LAB32;

LAB33:    if (*((unsigned int *)t106) != 0)
        goto LAB34;

LAB35:    t113 = (t105 + 4);
    t114 = *((unsigned int *)t105);
    t115 = *((unsigned int *)t113);
    t116 = (t114 || t115);
    if (t116 > 0)
        goto LAB36;

LAB37:    memcpy(t147, t105, 8);

LAB38:    t179 = (t0 + 5828);
    t180 = (t179 + 32U);
    t181 = *((char **)t180);
    t182 = (t181 + 40U);
    t183 = *((char **)t182);
    memset(t183, 0, 8);
    t184 = 1U;
    t185 = t184;
    t186 = (t147 + 4);
    t187 = *((unsigned int *)t147);
    t184 = (t184 & t187);
    t188 = *((unsigned int *)t186);
    t185 = (t185 & t188);
    t189 = (t183 + 4);
    t190 = *((unsigned int *)t183);
    *((unsigned int *)t183) = (t190 | t184);
    t191 = *((unsigned int *)t189);
    *((unsigned int *)t189) = (t191 | t185);
    xsi_driver_vfirst_trans(t179, 0, 0U);
    t192 = (t0 + 5716);
    *((int *)t192) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t10 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB7;

LAB8:    t16 = (t0 + 1336U);
    t17 = *((char **)t16);
    memset(t18, 0, 8);
    t16 = (t17 + 4);
    t19 = *((unsigned int *)t16);
    t20 = (~(t19));
    t21 = *((unsigned int *)t17);
    t22 = (t21 & t20);
    t23 = (t22 & 1U);
    if (t23 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t16) != 0)
        goto LAB13;

LAB14:    t26 = *((unsigned int *)t4);
    t27 = *((unsigned int *)t18);
    t28 = (t26 | t27);
    *((unsigned int *)t25) = t28;
    t29 = (t4 + 4);
    t30 = (t18 + 4);
    t31 = (t25 + 4);
    t32 = *((unsigned int *)t29);
    t33 = *((unsigned int *)t30);
    t34 = (t32 | t33);
    *((unsigned int *)t31) = t34;
    t35 = *((unsigned int *)t31);
    t36 = (t35 != 0);
    if (t36 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB10;

LAB11:    *((unsigned int *)t18) = 1;
    goto LAB14;

LAB13:    t24 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t24) = 1;
    goto LAB14;

LAB15:    t37 = *((unsigned int *)t25);
    t38 = *((unsigned int *)t31);
    *((unsigned int *)t25) = (t37 | t38);
    t39 = (t4 + 4);
    t40 = (t18 + 4);
    t41 = *((unsigned int *)t39);
    t42 = (~(t41));
    t43 = *((unsigned int *)t4);
    t44 = (t43 & t42);
    t45 = *((unsigned int *)t40);
    t46 = (~(t45));
    t47 = *((unsigned int *)t18);
    t48 = (t47 & t46);
    t49 = (~(t44));
    t50 = (~(t48));
    t51 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t51 & t49);
    t52 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t52 & t50);
    goto LAB17;

LAB18:    *((unsigned int *)t53) = 1;
    goto LAB21;

LAB20:    t60 = (t53 + 4);
    *((unsigned int *)t53) = 1;
    *((unsigned int *)t60) = 1;
    goto LAB21;

LAB22:    t66 = (t0 + 3036);
    t67 = (t66 + 36U);
    t68 = *((char **)t67);
    memset(t69, 0, 8);
    t70 = (t68 + 4);
    t71 = *((unsigned int *)t70);
    t72 = (~(t71));
    t73 = *((unsigned int *)t68);
    t74 = (t73 & t72);
    t75 = (t74 & 1U);
    if (t75 != 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t70) != 0)
        goto LAB27;

LAB28:    t78 = *((unsigned int *)t53);
    t79 = *((unsigned int *)t69);
    t80 = (t78 | t79);
    *((unsigned int *)t77) = t80;
    t81 = (t53 + 4);
    t82 = (t69 + 4);
    t83 = (t77 + 4);
    t84 = *((unsigned int *)t81);
    t85 = *((unsigned int *)t82);
    t86 = (t84 | t85);
    *((unsigned int *)t83) = t86;
    t87 = *((unsigned int *)t83);
    t88 = (t87 != 0);
    if (t88 == 1)
        goto LAB29;

LAB30:
LAB31:    goto LAB24;

LAB25:    *((unsigned int *)t69) = 1;
    goto LAB28;

LAB27:    t76 = (t69 + 4);
    *((unsigned int *)t69) = 1;
    *((unsigned int *)t76) = 1;
    goto LAB28;

LAB29:    t89 = *((unsigned int *)t77);
    t90 = *((unsigned int *)t83);
    *((unsigned int *)t77) = (t89 | t90);
    t91 = (t53 + 4);
    t92 = (t69 + 4);
    t93 = *((unsigned int *)t91);
    t94 = (~(t93));
    t95 = *((unsigned int *)t53);
    t96 = (t95 & t94);
    t97 = *((unsigned int *)t92);
    t98 = (~(t97));
    t99 = *((unsigned int *)t69);
    t100 = (t99 & t98);
    t101 = (~(t96));
    t102 = (~(t100));
    t103 = *((unsigned int *)t83);
    *((unsigned int *)t83) = (t103 & t101);
    t104 = *((unsigned int *)t83);
    *((unsigned int *)t83) = (t104 & t102);
    goto LAB31;

LAB32:    *((unsigned int *)t105) = 1;
    goto LAB35;

LAB34:    t112 = (t105 + 4);
    *((unsigned int *)t105) = 1;
    *((unsigned int *)t112) = 1;
    goto LAB35;

LAB36:    t117 = (t0 + 2760);
    t118 = (t117 + 36U);
    t119 = *((char **)t118);
    t120 = (t0 + 2852);
    t121 = (t120 + 36U);
    t122 = *((char **)t121);
    memset(t123, 0, 8);
    t124 = (t119 + 4);
    t125 = (t122 + 4);
    t126 = *((unsigned int *)t119);
    t127 = *((unsigned int *)t122);
    t128 = (t126 ^ t127);
    t129 = *((unsigned int *)t124);
    t130 = *((unsigned int *)t125);
    t131 = (t129 ^ t130);
    t132 = (t128 | t131);
    t133 = *((unsigned int *)t124);
    t134 = *((unsigned int *)t125);
    t135 = (t133 | t134);
    t136 = (~(t135));
    t137 = (t132 & t136);
    if (t137 != 0)
        goto LAB40;

LAB39:    if (t135 != 0)
        goto LAB41;

LAB42:    memset(t139, 0, 8);
    t140 = (t123 + 4);
    t141 = *((unsigned int *)t140);
    t142 = (~(t141));
    t143 = *((unsigned int *)t123);
    t144 = (t143 & t142);
    t145 = (t144 & 1U);
    if (t145 != 0)
        goto LAB43;

LAB44:    if (*((unsigned int *)t140) != 0)
        goto LAB45;

LAB46:    t148 = *((unsigned int *)t105);
    t149 = *((unsigned int *)t139);
    t150 = (t148 & t149);
    *((unsigned int *)t147) = t150;
    t151 = (t105 + 4);
    t152 = (t139 + 4);
    t153 = (t147 + 4);
    t154 = *((unsigned int *)t151);
    t155 = *((unsigned int *)t152);
    t156 = (t154 | t155);
    *((unsigned int *)t153) = t156;
    t157 = *((unsigned int *)t153);
    t158 = (t157 != 0);
    if (t158 == 1)
        goto LAB47;

LAB48:
LAB49:    goto LAB38;

LAB40:    *((unsigned int *)t123) = 1;
    goto LAB42;

LAB41:    t138 = (t123 + 4);
    *((unsigned int *)t123) = 1;
    *((unsigned int *)t138) = 1;
    goto LAB42;

LAB43:    *((unsigned int *)t139) = 1;
    goto LAB46;

LAB45:    t146 = (t139 + 4);
    *((unsigned int *)t139) = 1;
    *((unsigned int *)t146) = 1;
    goto LAB46;

LAB47:    t159 = *((unsigned int *)t147);
    t160 = *((unsigned int *)t153);
    *((unsigned int *)t147) = (t159 | t160);
    t161 = (t105 + 4);
    t162 = (t139 + 4);
    t163 = *((unsigned int *)t105);
    t164 = (~(t163));
    t165 = *((unsigned int *)t161);
    t166 = (~(t165));
    t167 = *((unsigned int *)t139);
    t168 = (~(t167));
    t169 = *((unsigned int *)t162);
    t170 = (~(t169));
    t171 = (t164 & t166);
    t172 = (t168 & t170);
    t173 = (~(t171));
    t174 = (~(t172));
    t175 = *((unsigned int *)t153);
    *((unsigned int *)t153) = (t175 & t173);
    t176 = *((unsigned int *)t153);
    *((unsigned int *)t153) = (t176 & t174);
    t177 = *((unsigned int *)t147);
    *((unsigned int *)t147) = (t177 & t173);
    t178 = *((unsigned int *)t147);
    *((unsigned int *)t147) = (t178 & t174);
    goto LAB49;

}

static void Always_61_2(char *t0)
{
    char t6[8];
    char t20[8];
    char t27[8];
    char t55[8];
    char t70[8];
    char t77[8];
    char t111[8];
    char t112[8];
    char t117[8];
    char t147[8];
    char t152[8];
    char t153[8];
    char t160[8];
    char t176[8];
    char t191[8];
    char t198[8];
    char t241[8];
    char t249[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    char *t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    char *t62;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    char *t68;
    char *t69;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    char *t76;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    char *t81;
    char *t82;
    char *t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    char *t91;
    char *t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    char *t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    char *t113;
    char *t114;
    char *t115;
    char *t116;
    char *t118;
    char *t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    char *t132;
    char *t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    unsigned int t137;
    unsigned int t138;
    char *t139;
    char *t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    char *t144;
    char *t145;
    char *t146;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    char *t154;
    char *t155;
    char *t156;
    char *t157;
    char *t158;
    char *t159;
    char *t161;
    char *t162;
    unsigned int t163;
    unsigned int t164;
    unsigned int t165;
    unsigned int t166;
    unsigned int t167;
    unsigned int t168;
    unsigned int t169;
    unsigned int t170;
    unsigned int t171;
    unsigned int t172;
    unsigned int t173;
    unsigned int t174;
    char *t175;
    char *t177;
    unsigned int t178;
    unsigned int t179;
    unsigned int t180;
    unsigned int t181;
    unsigned int t182;
    char *t183;
    char *t184;
    unsigned int t185;
    unsigned int t186;
    unsigned int t187;
    unsigned int t188;
    char *t189;
    char *t190;
    unsigned int t192;
    unsigned int t193;
    unsigned int t194;
    unsigned int t195;
    unsigned int t196;
    char *t197;
    unsigned int t199;
    unsigned int t200;
    unsigned int t201;
    char *t202;
    char *t203;
    char *t204;
    unsigned int t205;
    unsigned int t206;
    unsigned int t207;
    unsigned int t208;
    unsigned int t209;
    unsigned int t210;
    unsigned int t211;
    char *t212;
    char *t213;
    unsigned int t214;
    unsigned int t215;
    unsigned int t216;
    int t217;
    unsigned int t218;
    unsigned int t219;
    unsigned int t220;
    int t221;
    unsigned int t222;
    unsigned int t223;
    unsigned int t224;
    unsigned int t225;
    char *t226;
    unsigned int t227;
    unsigned int t228;
    unsigned int t229;
    unsigned int t230;
    unsigned int t231;
    char *t232;
    char *t233;
    unsigned int t234;
    unsigned int t235;
    unsigned int t236;
    char *t237;
    char *t238;
    char *t239;
    char *t240;
    unsigned int t242;
    unsigned int t243;
    unsigned int t244;
    unsigned int t245;
    char *t246;
    char *t247;
    char *t248;
    char *t250;

LAB0:    t1 = (t0 + 4216U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 5724);
    *((int *)t2) = 1;
    t3 = (t0 + 4244);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(62, ng0);

LAB5:    xsi_set_current_line(63, ng0);
    t4 = (t0 + 1244U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t5 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB6;

LAB7:    if (*((unsigned int *)t4) != 0)
        goto LAB8;

LAB9:    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = (!(t14));
    t16 = *((unsigned int *)t13);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB10;

LAB11:    memcpy(t27, t6, 8);

LAB12:    memset(t55, 0, 8);
    t56 = (t27 + 4);
    t57 = *((unsigned int *)t56);
    t58 = (~(t57));
    t59 = *((unsigned int *)t27);
    t60 = (t59 & t58);
    t61 = (t60 & 1U);
    if (t61 != 0)
        goto LAB20;

LAB21:    if (*((unsigned int *)t56) != 0)
        goto LAB22;

LAB23:    t63 = (t55 + 4);
    t64 = *((unsigned int *)t55);
    t65 = (!(t64));
    t66 = *((unsigned int *)t63);
    t67 = (t65 || t66);
    if (t67 > 0)
        goto LAB24;

LAB25:    memcpy(t77, t55, 8);

LAB26:    t105 = (t77 + 4);
    t106 = *((unsigned int *)t105);
    t107 = (~(t106));
    t108 = *((unsigned int *)t77);
    t109 = (t108 & t107);
    t110 = (t109 != 0);
    if (t110 > 0)
        goto LAB34;

LAB35:
LAB36:    xsi_set_current_line(66, ng0);
    t2 = (t0 + 3036);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    memset(t20, 0, 8);
    t5 = (t4 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB85;

LAB86:    if (*((unsigned int *)t5) != 0)
        goto LAB87;

LAB88:    t13 = (t20 + 4);
    t14 = *((unsigned int *)t20);
    t15 = *((unsigned int *)t13);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB89;

LAB90:    t17 = *((unsigned int *)t20);
    t21 = (~(t17));
    t22 = *((unsigned int *)t13);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB91;

LAB92:    if (*((unsigned int *)t13) > 0)
        goto LAB93;

LAB94:    if (*((unsigned int *)t20) > 0)
        goto LAB95;

LAB96:    memcpy(t6, t33, 8);

LAB97:    t41 = (t0 + 2852);
    xsi_vlogvar_wait_assign_value(t41, t6, 0, 0, 11, 0LL);
    xsi_set_current_line(67, ng0);
    t2 = (t0 + 1336U);
    t3 = *((char **)t2);
    t2 = (t0 + 3036);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 1, 0LL);
    goto LAB2;

LAB6:    *((unsigned int *)t6) = 1;
    goto LAB9;

LAB8:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB9;

LAB10:    t18 = (t0 + 1152U);
    t19 = *((char **)t18);
    memset(t20, 0, 8);
    t18 = (t19 + 4);
    t21 = *((unsigned int *)t18);
    t22 = (~(t21));
    t23 = *((unsigned int *)t19);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t18) != 0)
        goto LAB15;

LAB16:    t28 = *((unsigned int *)t6);
    t29 = *((unsigned int *)t20);
    t30 = (t28 | t29);
    *((unsigned int *)t27) = t30;
    t31 = (t6 + 4);
    t32 = (t20 + 4);
    t33 = (t27 + 4);
    t34 = *((unsigned int *)t31);
    t35 = *((unsigned int *)t32);
    t36 = (t34 | t35);
    *((unsigned int *)t33) = t36;
    t37 = *((unsigned int *)t33);
    t38 = (t37 != 0);
    if (t38 == 1)
        goto LAB17;

LAB18:
LAB19:    goto LAB12;

LAB13:    *((unsigned int *)t20) = 1;
    goto LAB16;

LAB15:    t26 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB16;

LAB17:    t39 = *((unsigned int *)t27);
    t40 = *((unsigned int *)t33);
    *((unsigned int *)t27) = (t39 | t40);
    t41 = (t6 + 4);
    t42 = (t20 + 4);
    t43 = *((unsigned int *)t41);
    t44 = (~(t43));
    t45 = *((unsigned int *)t6);
    t46 = (t45 & t44);
    t47 = *((unsigned int *)t42);
    t48 = (~(t47));
    t49 = *((unsigned int *)t20);
    t50 = (t49 & t48);
    t51 = (~(t46));
    t52 = (~(t50));
    t53 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t53 & t51);
    t54 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t54 & t52);
    goto LAB19;

LAB20:    *((unsigned int *)t55) = 1;
    goto LAB23;

LAB22:    t62 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t62) = 1;
    goto LAB23;

LAB24:    t68 = (t0 + 1336U);
    t69 = *((char **)t68);
    memset(t70, 0, 8);
    t68 = (t69 + 4);
    t71 = *((unsigned int *)t68);
    t72 = (~(t71));
    t73 = *((unsigned int *)t69);
    t74 = (t73 & t72);
    t75 = (t74 & 1U);
    if (t75 != 0)
        goto LAB27;

LAB28:    if (*((unsigned int *)t68) != 0)
        goto LAB29;

LAB30:    t78 = *((unsigned int *)t55);
    t79 = *((unsigned int *)t70);
    t80 = (t78 | t79);
    *((unsigned int *)t77) = t80;
    t81 = (t55 + 4);
    t82 = (t70 + 4);
    t83 = (t77 + 4);
    t84 = *((unsigned int *)t81);
    t85 = *((unsigned int *)t82);
    t86 = (t84 | t85);
    *((unsigned int *)t83) = t86;
    t87 = *((unsigned int *)t83);
    t88 = (t87 != 0);
    if (t88 == 1)
        goto LAB31;

LAB32:
LAB33:    goto LAB26;

LAB27:    *((unsigned int *)t70) = 1;
    goto LAB30;

LAB29:    t76 = (t70 + 4);
    *((unsigned int *)t70) = 1;
    *((unsigned int *)t76) = 1;
    goto LAB30;

LAB31:    t89 = *((unsigned int *)t77);
    t90 = *((unsigned int *)t83);
    *((unsigned int *)t77) = (t89 | t90);
    t91 = (t55 + 4);
    t92 = (t70 + 4);
    t93 = *((unsigned int *)t91);
    t94 = (~(t93));
    t95 = *((unsigned int *)t55);
    t96 = (t95 & t94);
    t97 = *((unsigned int *)t92);
    t98 = (~(t97));
    t99 = *((unsigned int *)t70);
    t100 = (t99 & t98);
    t101 = (~(t96));
    t102 = (~(t100));
    t103 = *((unsigned int *)t83);
    *((unsigned int *)t83) = (t103 & t101);
    t104 = *((unsigned int *)t83);
    *((unsigned int *)t83) = (t104 & t102);
    goto LAB33;

LAB34:    xsi_set_current_line(64, ng0);
    t113 = (t0 + 1612U);
    t114 = *((char **)t113);
    t113 = (t0 + 2944);
    t115 = (t113 + 36U);
    t116 = *((char **)t115);
    memset(t117, 0, 8);
    t118 = (t114 + 4);
    t119 = (t116 + 4);
    t120 = *((unsigned int *)t114);
    t121 = *((unsigned int *)t116);
    t122 = (t120 ^ t121);
    t123 = *((unsigned int *)t118);
    t124 = *((unsigned int *)t119);
    t125 = (t123 ^ t124);
    t126 = (t122 | t125);
    t127 = *((unsigned int *)t118);
    t128 = *((unsigned int *)t119);
    t129 = (t127 | t128);
    t130 = (~(t129));
    t131 = (t126 & t130);
    if (t131 != 0)
        goto LAB40;

LAB37:    if (t129 != 0)
        goto LAB39;

LAB38:    *((unsigned int *)t117) = 1;

LAB40:    memset(t112, 0, 8);
    t133 = (t117 + 4);
    t134 = *((unsigned int *)t133);
    t135 = (~(t134));
    t136 = *((unsigned int *)t117);
    t137 = (t136 & t135);
    t138 = (t137 & 1U);
    if (t138 != 0)
        goto LAB41;

LAB42:    if (*((unsigned int *)t133) != 0)
        goto LAB43;

LAB44:    t140 = (t112 + 4);
    t141 = *((unsigned int *)t112);
    t142 = *((unsigned int *)t140);
    t143 = (t141 || t142);
    if (t143 > 0)
        goto LAB45;

LAB46:    t148 = *((unsigned int *)t112);
    t149 = (~(t148));
    t150 = *((unsigned int *)t140);
    t151 = (t149 || t150);
    if (t151 > 0)
        goto LAB47;

LAB48:    if (*((unsigned int *)t140) > 0)
        goto LAB49;

LAB50:    if (*((unsigned int *)t112) > 0)
        goto LAB51;

LAB52:    memcpy(t111, t152, 8);

LAB53:    t250 = (t0 + 2760);
    xsi_vlogvar_wait_assign_value(t250, t111, 0, 0, 11, 0LL);
    goto LAB36;

LAB39:    t132 = (t117 + 4);
    *((unsigned int *)t117) = 1;
    *((unsigned int *)t132) = 1;
    goto LAB40;

LAB41:    *((unsigned int *)t112) = 1;
    goto LAB44;

LAB43:    t139 = (t112 + 4);
    *((unsigned int *)t112) = 1;
    *((unsigned int *)t139) = 1;
    goto LAB44;

LAB45:    t144 = (t0 + 2852);
    t145 = (t144 + 36U);
    t146 = *((char **)t145);
    memcpy(t147, t146, 8);
    goto LAB46;

LAB47:    t154 = (t0 + 2760);
    t155 = (t154 + 36U);
    t156 = *((char **)t155);
    t157 = (t0 + 2852);
    t158 = (t157 + 36U);
    t159 = *((char **)t158);
    memset(t160, 0, 8);
    t161 = (t156 + 4);
    t162 = (t159 + 4);
    t163 = *((unsigned int *)t156);
    t164 = *((unsigned int *)t159);
    t165 = (t163 ^ t164);
    t166 = *((unsigned int *)t161);
    t167 = *((unsigned int *)t162);
    t168 = (t166 ^ t167);
    t169 = (t165 | t168);
    t170 = *((unsigned int *)t161);
    t171 = *((unsigned int *)t162);
    t172 = (t170 | t171);
    t173 = (~(t172));
    t174 = (t169 & t173);
    if (t174 != 0)
        goto LAB55;

LAB54:    if (t172 != 0)
        goto LAB56;

LAB57:    memset(t176, 0, 8);
    t177 = (t160 + 4);
    t178 = *((unsigned int *)t177);
    t179 = (~(t178));
    t180 = *((unsigned int *)t160);
    t181 = (t180 & t179);
    t182 = (t181 & 1U);
    if (t182 != 0)
        goto LAB58;

LAB59:    if (*((unsigned int *)t177) != 0)
        goto LAB60;

LAB61:    t184 = (t176 + 4);
    t185 = *((unsigned int *)t176);
    t186 = (!(t185));
    t187 = *((unsigned int *)t184);
    t188 = (t186 || t187);
    if (t188 > 0)
        goto LAB62;

LAB63:    memcpy(t198, t176, 8);

LAB64:    memset(t153, 0, 8);
    t226 = (t198 + 4);
    t227 = *((unsigned int *)t226);
    t228 = (~(t227));
    t229 = *((unsigned int *)t198);
    t230 = (t229 & t228);
    t231 = (t230 & 1U);
    if (t231 != 0)
        goto LAB72;

LAB73:    if (*((unsigned int *)t226) != 0)
        goto LAB74;

LAB75:    t233 = (t153 + 4);
    t234 = *((unsigned int *)t153);
    t235 = *((unsigned int *)t233);
    t236 = (t234 || t235);
    if (t236 > 0)
        goto LAB76;

LAB77:    t242 = *((unsigned int *)t153);
    t243 = (~(t242));
    t244 = *((unsigned int *)t233);
    t245 = (t243 || t244);
    if (t245 > 0)
        goto LAB78;

LAB79:    if (*((unsigned int *)t233) > 0)
        goto LAB80;

LAB81:    if (*((unsigned int *)t153) > 0)
        goto LAB82;

LAB83:    memcpy(t152, t249, 8);

LAB84:    goto LAB48;

LAB49:    xsi_vlog_unsigned_bit_combine(t111, 32, t147, 32, t152, 32);
    goto LAB53;

LAB51:    memcpy(t111, t147, 8);
    goto LAB53;

LAB55:    *((unsigned int *)t160) = 1;
    goto LAB57;

LAB56:    t175 = (t160 + 4);
    *((unsigned int *)t160) = 1;
    *((unsigned int *)t175) = 1;
    goto LAB57;

LAB58:    *((unsigned int *)t176) = 1;
    goto LAB61;

LAB60:    t183 = (t176 + 4);
    *((unsigned int *)t176) = 1;
    *((unsigned int *)t183) = 1;
    goto LAB61;

LAB62:    t189 = (t0 + 1152U);
    t190 = *((char **)t189);
    memset(t191, 0, 8);
    t189 = (t190 + 4);
    t192 = *((unsigned int *)t189);
    t193 = (~(t192));
    t194 = *((unsigned int *)t190);
    t195 = (t194 & t193);
    t196 = (t195 & 1U);
    if (t196 != 0)
        goto LAB65;

LAB66:    if (*((unsigned int *)t189) != 0)
        goto LAB67;

LAB68:    t199 = *((unsigned int *)t176);
    t200 = *((unsigned int *)t191);
    t201 = (t199 | t200);
    *((unsigned int *)t198) = t201;
    t202 = (t176 + 4);
    t203 = (t191 + 4);
    t204 = (t198 + 4);
    t205 = *((unsigned int *)t202);
    t206 = *((unsigned int *)t203);
    t207 = (t205 | t206);
    *((unsigned int *)t204) = t207;
    t208 = *((unsigned int *)t204);
    t209 = (t208 != 0);
    if (t209 == 1)
        goto LAB69;

LAB70:
LAB71:    goto LAB64;

LAB65:    *((unsigned int *)t191) = 1;
    goto LAB68;

LAB67:    t197 = (t191 + 4);
    *((unsigned int *)t191) = 1;
    *((unsigned int *)t197) = 1;
    goto LAB68;

LAB69:    t210 = *((unsigned int *)t198);
    t211 = *((unsigned int *)t204);
    *((unsigned int *)t198) = (t210 | t211);
    t212 = (t176 + 4);
    t213 = (t191 + 4);
    t214 = *((unsigned int *)t212);
    t215 = (~(t214));
    t216 = *((unsigned int *)t176);
    t217 = (t216 & t215);
    t218 = *((unsigned int *)t213);
    t219 = (~(t218));
    t220 = *((unsigned int *)t191);
    t221 = (t220 & t219);
    t222 = (~(t217));
    t223 = (~(t221));
    t224 = *((unsigned int *)t204);
    *((unsigned int *)t204) = (t224 & t222);
    t225 = *((unsigned int *)t204);
    *((unsigned int *)t204) = (t225 & t223);
    goto LAB71;

LAB72:    *((unsigned int *)t153) = 1;
    goto LAB75;

LAB74:    t232 = (t153 + 4);
    *((unsigned int *)t153) = 1;
    *((unsigned int *)t232) = 1;
    goto LAB75;

LAB76:    t237 = (t0 + 2760);
    t238 = (t237 + 36U);
    t239 = *((char **)t238);
    t240 = ((char*)((ng1)));
    memset(t241, 0, 8);
    xsi_vlog_unsigned_add(t241, 32, t239, 11, t240, 32);
    goto LAB77;

LAB78:    t246 = (t0 + 2760);
    t247 = (t246 + 36U);
    t248 = *((char **)t247);
    memcpy(t249, t248, 8);
    goto LAB79;

LAB80:    xsi_vlog_unsigned_bit_combine(t152, 32, t241, 32, t249, 32);
    goto LAB84;

LAB82:    memcpy(t152, t241, 8);
    goto LAB84;

LAB85:    *((unsigned int *)t20) = 1;
    goto LAB88;

LAB87:    t12 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB88;

LAB89:    t18 = (t0 + 2760);
    t19 = (t18 + 36U);
    t26 = *((char **)t19);
    goto LAB90;

LAB91:    t31 = (t0 + 2852);
    t32 = (t31 + 36U);
    t33 = *((char **)t32);
    goto LAB92;

LAB93:    xsi_vlog_unsigned_bit_combine(t6, 11, t26, 11, t33, 11);
    goto LAB97;

LAB95:    memcpy(t6, t26, 8);
    goto LAB97;

}

static void Always_76_3(char *t0)
{
    char t4[8];
    char t5[8];
    char t8[8];
    char t22[8];
    char t30[8];
    char t78[8];
    char t79[8];
    char t102[8];
    char t111[8];
    char t122[8];
    char t130[8];
    char *t1;
    char *t2;
    char *t3;
    char *t6;
    char *t7;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t20;
    char *t21;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    char *t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    char *t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    int t54;
    int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    char *t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    char *t68;
    char *t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    char *t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    char *t80;
    char *t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    char *t87;
    char *t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    char *t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    char *t97;
    char *t98;
    char *t99;
    char *t100;
    unsigned int t101;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    char *t112;
    char *t113;
    char *t114;
    char *t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    char *t121;
    char *t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    char *t129;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    char *t134;
    char *t135;
    char *t136;
    unsigned int t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    char *t144;
    char *t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    unsigned int t152;
    unsigned int t153;
    int t154;
    int t155;
    unsigned int t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    unsigned int t161;
    unsigned int t162;
    unsigned int t163;
    unsigned int t164;
    unsigned int t165;
    char *t166;
    char *t167;
    char *t168;
    char *t169;

LAB0:    t1 = (t0 + 4360U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(76, ng0);
    t2 = (t0 + 5732);
    *((int *)t2) = 1;
    t3 = (t0 + 4388);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(77, ng0);

LAB5:    xsi_set_current_line(78, ng0);
    t6 = (t0 + 784U);
    t7 = *((char **)t6);
    memset(t8, 0, 8);
    t6 = (t7 + 4);
    t9 = *((unsigned int *)t6);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB6;

LAB7:    if (*((unsigned int *)t6) != 0)
        goto LAB8;

LAB9:    t15 = (t8 + 4);
    t16 = *((unsigned int *)t8);
    t17 = *((unsigned int *)t15);
    t18 = (t16 || t17);
    if (t18 > 0)
        goto LAB10;

LAB11:    memcpy(t30, t8, 8);

LAB12:    memset(t5, 0, 8);
    t62 = (t30 + 4);
    t63 = *((unsigned int *)t62);
    t64 = (~(t63));
    t65 = *((unsigned int *)t30);
    t66 = (t65 & t64);
    t67 = (t66 & 1U);
    if (t67 != 0)
        goto LAB20;

LAB21:    if (*((unsigned int *)t62) != 0)
        goto LAB22;

LAB23:    t69 = (t5 + 4);
    t70 = *((unsigned int *)t5);
    t71 = *((unsigned int *)t69);
    t72 = (t70 || t71);
    if (t72 > 0)
        goto LAB24;

LAB25:    t74 = *((unsigned int *)t5);
    t75 = (~(t74));
    t76 = *((unsigned int *)t69);
    t77 = (t75 || t76);
    if (t77 > 0)
        goto LAB26;

LAB27:    if (*((unsigned int *)t69) > 0)
        goto LAB28;

LAB29:    if (*((unsigned int *)t5) > 0)
        goto LAB30;

LAB31:    memcpy(t4, t78, 8);

LAB32:    t100 = (t0 + 3128);
    xsi_vlogvar_wait_assign_value(t100, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(79, ng0);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB46;

LAB47:
LAB48:    xsi_set_current_line(81, ng0);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    memset(t5, 0, 8);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB76;

LAB77:    if (*((unsigned int *)t2) != 0)
        goto LAB78;

LAB79:    t7 = (t5 + 4);
    t16 = *((unsigned int *)t5);
    t17 = *((unsigned int *)t7);
    t18 = (t16 || t17);
    if (t18 > 0)
        goto LAB80;

LAB81:    t162 = *((unsigned int *)t5);
    t163 = (~(t162));
    t164 = *((unsigned int *)t7);
    t165 = (t163 || t164);
    if (t165 > 0)
        goto LAB82;

LAB83:    if (*((unsigned int *)t7) > 0)
        goto LAB84;

LAB85:    if (*((unsigned int *)t5) > 0)
        goto LAB86;

LAB87:    memcpy(t4, t168, 8);

LAB88:    t169 = (t0 + 2668);
    xsi_vlogvar_wait_assign_value(t169, t4, 0, 0, 1, 0LL);
    goto LAB2;

LAB6:    *((unsigned int *)t8) = 1;
    goto LAB9;

LAB8:    t14 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB9;

LAB10:    t19 = (t0 + 2668);
    t20 = (t19 + 36U);
    t21 = *((char **)t20);
    memset(t22, 0, 8);
    t23 = (t21 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t21);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t23) != 0)
        goto LAB15;

LAB16:    t31 = *((unsigned int *)t8);
    t32 = *((unsigned int *)t22);
    t33 = (t31 & t32);
    *((unsigned int *)t30) = t33;
    t34 = (t8 + 4);
    t35 = (t22 + 4);
    t36 = (t30 + 4);
    t37 = *((unsigned int *)t34);
    t38 = *((unsigned int *)t35);
    t39 = (t37 | t38);
    *((unsigned int *)t36) = t39;
    t40 = *((unsigned int *)t36);
    t41 = (t40 != 0);
    if (t41 == 1)
        goto LAB17;

LAB18:
LAB19:    goto LAB12;

LAB13:    *((unsigned int *)t22) = 1;
    goto LAB16;

LAB15:    t29 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB16;

LAB17:    t42 = *((unsigned int *)t30);
    t43 = *((unsigned int *)t36);
    *((unsigned int *)t30) = (t42 | t43);
    t44 = (t8 + 4);
    t45 = (t22 + 4);
    t46 = *((unsigned int *)t8);
    t47 = (~(t46));
    t48 = *((unsigned int *)t44);
    t49 = (~(t48));
    t50 = *((unsigned int *)t22);
    t51 = (~(t50));
    t52 = *((unsigned int *)t45);
    t53 = (~(t52));
    t54 = (t47 & t49);
    t55 = (t51 & t53);
    t56 = (~(t54));
    t57 = (~(t55));
    t58 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t58 & t56);
    t59 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t59 & t57);
    t60 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t60 & t56);
    t61 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t61 & t57);
    goto LAB19;

LAB20:    *((unsigned int *)t5) = 1;
    goto LAB23;

LAB22:    t68 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t68) = 1;
    goto LAB23;

LAB24:    t73 = ((char*)((ng2)));
    goto LAB25;

LAB26:    t80 = (t0 + 876U);
    t81 = *((char **)t80);
    memset(t79, 0, 8);
    t80 = (t81 + 4);
    t82 = *((unsigned int *)t80);
    t83 = (~(t82));
    t84 = *((unsigned int *)t81);
    t85 = (t84 & t83);
    t86 = (t85 & 1U);
    if (t86 != 0)
        goto LAB33;

LAB34:    if (*((unsigned int *)t80) != 0)
        goto LAB35;

LAB36:    t88 = (t79 + 4);
    t89 = *((unsigned int *)t79);
    t90 = *((unsigned int *)t88);
    t91 = (t89 || t90);
    if (t91 > 0)
        goto LAB37;

LAB38:    t93 = *((unsigned int *)t79);
    t94 = (~(t93));
    t95 = *((unsigned int *)t88);
    t96 = (t94 || t95);
    if (t96 > 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t88) > 0)
        goto LAB41;

LAB42:    if (*((unsigned int *)t79) > 0)
        goto LAB43;

LAB44:    memcpy(t78, t99, 8);

LAB45:    goto LAB27;

LAB28:    xsi_vlog_unsigned_bit_combine(t4, 1, t73, 1, t78, 1);
    goto LAB32;

LAB30:    memcpy(t4, t73, 8);
    goto LAB32;

LAB33:    *((unsigned int *)t79) = 1;
    goto LAB36;

LAB35:    t87 = (t79 + 4);
    *((unsigned int *)t79) = 1;
    *((unsigned int *)t87) = 1;
    goto LAB36;

LAB37:    t92 = ((char*)((ng3)));
    goto LAB38;

LAB39:    t97 = (t0 + 3128);
    t98 = (t97 + 36U);
    t99 = *((char **)t98);
    goto LAB40;

LAB41:    xsi_vlog_unsigned_bit_combine(t78, 1, t92, 1, t99, 1);
    goto LAB45;

LAB43:    memcpy(t78, t92, 8);
    goto LAB45;

LAB46:    xsi_set_current_line(80, ng0);
    t6 = (t0 + 3128);
    t7 = (t6 + 36U);
    t14 = *((char **)t7);
    memset(t8, 0, 8);
    t15 = (t14 + 4);
    t16 = *((unsigned int *)t15);
    t17 = (~(t16));
    t18 = *((unsigned int *)t14);
    t24 = (t18 & t17);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB49;

LAB50:    if (*((unsigned int *)t15) != 0)
        goto LAB51;

LAB52:    t20 = (t8 + 4);
    t26 = *((unsigned int *)t8);
    t27 = (!(t26));
    t28 = *((unsigned int *)t20);
    t31 = (t27 || t28);
    if (t31 > 0)
        goto LAB53;

LAB54:    memcpy(t30, t8, 8);

LAB55:    memset(t5, 0, 8);
    t62 = (t30 + 4);
    t65 = *((unsigned int *)t62);
    t66 = (~(t65));
    t67 = *((unsigned int *)t30);
    t70 = (t67 & t66);
    t71 = (t70 & 1U);
    if (t71 != 0)
        goto LAB63;

LAB64:    if (*((unsigned int *)t62) != 0)
        goto LAB65;

LAB66:    t69 = (t5 + 4);
    t72 = *((unsigned int *)t5);
    t74 = *((unsigned int *)t69);
    t75 = (t72 || t74);
    if (t75 > 0)
        goto LAB67;

LAB68:    t76 = *((unsigned int *)t5);
    t77 = (~(t76));
    t82 = *((unsigned int *)t69);
    t83 = (t77 || t82);
    if (t83 > 0)
        goto LAB69;

LAB70:    if (*((unsigned int *)t69) > 0)
        goto LAB71;

LAB72:    if (*((unsigned int *)t5) > 0)
        goto LAB73;

LAB74:    memcpy(t4, t79, 8);

LAB75:    t98 = (t0 + 2944);
    xsi_vlogvar_wait_assign_value(t98, t4, 0, 0, 11, 0LL);
    goto LAB48;

LAB49:    *((unsigned int *)t8) = 1;
    goto LAB52;

LAB51:    t19 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB52;

LAB53:    t21 = (t0 + 1888U);
    t23 = *((char **)t21);
    memset(t22, 0, 8);
    t21 = (t23 + 4);
    t32 = *((unsigned int *)t21);
    t33 = (~(t32));
    t37 = *((unsigned int *)t23);
    t38 = (t37 & t33);
    t39 = (t38 & 1U);
    if (t39 != 0)
        goto LAB56;

LAB57:    if (*((unsigned int *)t21) != 0)
        goto LAB58;

LAB59:    t40 = *((unsigned int *)t8);
    t41 = *((unsigned int *)t22);
    t42 = (t40 | t41);
    *((unsigned int *)t30) = t42;
    t34 = (t8 + 4);
    t35 = (t22 + 4);
    t36 = (t30 + 4);
    t43 = *((unsigned int *)t34);
    t46 = *((unsigned int *)t35);
    t47 = (t43 | t46);
    *((unsigned int *)t36) = t47;
    t48 = *((unsigned int *)t36);
    t49 = (t48 != 0);
    if (t49 == 1)
        goto LAB60;

LAB61:
LAB62:    goto LAB55;

LAB56:    *((unsigned int *)t22) = 1;
    goto LAB59;

LAB58:    t29 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB59;

LAB60:    t50 = *((unsigned int *)t30);
    t51 = *((unsigned int *)t36);
    *((unsigned int *)t30) = (t50 | t51);
    t44 = (t8 + 4);
    t45 = (t22 + 4);
    t52 = *((unsigned int *)t44);
    t53 = (~(t52));
    t56 = *((unsigned int *)t8);
    t54 = (t56 & t53);
    t57 = *((unsigned int *)t45);
    t58 = (~(t57));
    t59 = *((unsigned int *)t22);
    t55 = (t59 & t58);
    t60 = (~(t54));
    t61 = (~(t55));
    t63 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t63 & t60);
    t64 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t64 & t61);
    goto LAB62;

LAB63:    *((unsigned int *)t5) = 1;
    goto LAB66;

LAB65:    t68 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t68) = 1;
    goto LAB66;

LAB67:    t73 = (t0 + 2944);
    t80 = (t73 + 36U);
    t81 = *((char **)t80);
    t87 = ((char*)((ng1)));
    memset(t78, 0, 8);
    xsi_vlog_unsigned_add(t78, 32, t81, 11, t87, 32);
    goto LAB68;

LAB69:    t88 = (t0 + 2944);
    t92 = (t88 + 36U);
    t97 = *((char **)t92);
    memcpy(t79, t97, 8);
    goto LAB70;

LAB71:    xsi_vlog_unsigned_bit_combine(t4, 32, t78, 32, t79, 32);
    goto LAB75;

LAB73:    memcpy(t4, t78, 8);
    goto LAB75;

LAB76:    *((unsigned int *)t5) = 1;
    goto LAB79;

LAB78:    t6 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t6) = 1;
    goto LAB79;

LAB80:    t14 = (t0 + 2852);
    t15 = (t14 + 36U);
    t19 = *((char **)t15);
    t20 = (t0 + 2944);
    t21 = (t20 + 36U);
    t23 = *((char **)t21);
    memset(t8, 0, 8);
    t29 = (t19 + 4);
    t34 = (t23 + 4);
    t24 = *((unsigned int *)t19);
    t25 = *((unsigned int *)t23);
    t26 = (t24 ^ t25);
    t27 = *((unsigned int *)t29);
    t28 = *((unsigned int *)t34);
    t31 = (t27 ^ t28);
    t32 = (t26 | t31);
    t33 = *((unsigned int *)t29);
    t37 = *((unsigned int *)t34);
    t38 = (t33 | t37);
    t39 = (~(t38));
    t40 = (t32 & t39);
    if (t40 != 0)
        goto LAB90;

LAB89:    if (t38 != 0)
        goto LAB91;

LAB92:    memset(t22, 0, 8);
    t36 = (t8 + 4);
    t41 = *((unsigned int *)t36);
    t42 = (~(t41));
    t43 = *((unsigned int *)t8);
    t46 = (t43 & t42);
    t47 = (t46 & 1U);
    if (t47 != 0)
        goto LAB93;

LAB94:    if (*((unsigned int *)t36) != 0)
        goto LAB95;

LAB96:    t45 = (t22 + 4);
    t48 = *((unsigned int *)t22);
    t49 = *((unsigned int *)t45);
    t50 = (t48 || t49);
    if (t50 > 0)
        goto LAB97;

LAB98:    memcpy(t79, t22, 8);

LAB99:    memset(t102, 0, 8);
    t98 = (t79 + 4);
    t103 = *((unsigned int *)t98);
    t104 = (~(t103));
    t105 = *((unsigned int *)t79);
    t106 = (t105 & t104);
    t107 = (t106 & 1U);
    if (t107 != 0)
        goto LAB111;

LAB112:    if (*((unsigned int *)t98) != 0)
        goto LAB113;

LAB114:    t100 = (t102 + 4);
    t108 = *((unsigned int *)t102);
    t109 = *((unsigned int *)t100);
    t110 = (t108 || t109);
    if (t110 > 0)
        goto LAB115;

LAB116:    memcpy(t130, t102, 8);

LAB117:    goto LAB81;

LAB82:    t166 = (t0 + 2668);
    t167 = (t166 + 36U);
    t168 = *((char **)t167);
    goto LAB83;

LAB84:    xsi_vlog_unsigned_bit_combine(t4, 1, t130, 1, t168, 1);
    goto LAB88;

LAB86:    memcpy(t4, t130, 8);
    goto LAB88;

LAB90:    *((unsigned int *)t8) = 1;
    goto LAB92;

LAB91:    t35 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t35) = 1;
    goto LAB92;

LAB93:    *((unsigned int *)t22) = 1;
    goto LAB96;

LAB95:    t44 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB96;

LAB97:    t62 = (t0 + 1888U);
    t68 = *((char **)t62);
    memset(t30, 0, 8);
    t62 = (t68 + 4);
    t51 = *((unsigned int *)t62);
    t52 = (~(t51));
    t53 = *((unsigned int *)t68);
    t56 = (t53 & t52);
    t57 = (t56 & 1U);
    if (t57 != 0)
        goto LAB103;

LAB101:    if (*((unsigned int *)t62) == 0)
        goto LAB100;

LAB102:    t69 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t69) = 1;

LAB103:    memset(t78, 0, 8);
    t73 = (t30 + 4);
    t58 = *((unsigned int *)t73);
    t59 = (~(t58));
    t60 = *((unsigned int *)t30);
    t61 = (t60 & t59);
    t63 = (t61 & 1U);
    if (t63 != 0)
        goto LAB104;

LAB105:    if (*((unsigned int *)t73) != 0)
        goto LAB106;

LAB107:    t64 = *((unsigned int *)t22);
    t65 = *((unsigned int *)t78);
    t66 = (t64 & t65);
    *((unsigned int *)t79) = t66;
    t81 = (t22 + 4);
    t87 = (t78 + 4);
    t88 = (t79 + 4);
    t67 = *((unsigned int *)t81);
    t70 = *((unsigned int *)t87);
    t71 = (t67 | t70);
    *((unsigned int *)t88) = t71;
    t72 = *((unsigned int *)t88);
    t74 = (t72 != 0);
    if (t74 == 1)
        goto LAB108;

LAB109:
LAB110:    goto LAB99;

LAB100:    *((unsigned int *)t30) = 1;
    goto LAB103;

LAB104:    *((unsigned int *)t78) = 1;
    goto LAB107;

LAB106:    t80 = (t78 + 4);
    *((unsigned int *)t78) = 1;
    *((unsigned int *)t80) = 1;
    goto LAB107;

LAB108:    t75 = *((unsigned int *)t79);
    t76 = *((unsigned int *)t88);
    *((unsigned int *)t79) = (t75 | t76);
    t92 = (t22 + 4);
    t97 = (t78 + 4);
    t77 = *((unsigned int *)t22);
    t82 = (~(t77));
    t83 = *((unsigned int *)t92);
    t84 = (~(t83));
    t85 = *((unsigned int *)t78);
    t86 = (~(t85));
    t89 = *((unsigned int *)t97);
    t90 = (~(t89));
    t54 = (t82 & t84);
    t55 = (t86 & t90);
    t91 = (~(t54));
    t93 = (~(t55));
    t94 = *((unsigned int *)t88);
    *((unsigned int *)t88) = (t94 & t91);
    t95 = *((unsigned int *)t88);
    *((unsigned int *)t88) = (t95 & t93);
    t96 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t96 & t91);
    t101 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t101 & t93);
    goto LAB110;

LAB111:    *((unsigned int *)t102) = 1;
    goto LAB114;

LAB113:    t99 = (t102 + 4);
    *((unsigned int *)t102) = 1;
    *((unsigned int *)t99) = 1;
    goto LAB114;

LAB115:    t112 = (t0 + 3128);
    t113 = (t112 + 36U);
    t114 = *((char **)t113);
    memset(t111, 0, 8);
    t115 = (t114 + 4);
    t116 = *((unsigned int *)t115);
    t117 = (~(t116));
    t118 = *((unsigned int *)t114);
    t119 = (t118 & t117);
    t120 = (t119 & 1U);
    if (t120 != 0)
        goto LAB121;

LAB119:    if (*((unsigned int *)t115) == 0)
        goto LAB118;

LAB120:    t121 = (t111 + 4);
    *((unsigned int *)t111) = 1;
    *((unsigned int *)t121) = 1;

LAB121:    memset(t122, 0, 8);
    t123 = (t111 + 4);
    t124 = *((unsigned int *)t123);
    t125 = (~(t124));
    t126 = *((unsigned int *)t111);
    t127 = (t126 & t125);
    t128 = (t127 & 1U);
    if (t128 != 0)
        goto LAB122;

LAB123:    if (*((unsigned int *)t123) != 0)
        goto LAB124;

LAB125:    t131 = *((unsigned int *)t102);
    t132 = *((unsigned int *)t122);
    t133 = (t131 & t132);
    *((unsigned int *)t130) = t133;
    t134 = (t102 + 4);
    t135 = (t122 + 4);
    t136 = (t130 + 4);
    t137 = *((unsigned int *)t134);
    t138 = *((unsigned int *)t135);
    t139 = (t137 | t138);
    *((unsigned int *)t136) = t139;
    t140 = *((unsigned int *)t136);
    t141 = (t140 != 0);
    if (t141 == 1)
        goto LAB126;

LAB127:
LAB128:    goto LAB117;

LAB118:    *((unsigned int *)t111) = 1;
    goto LAB121;

LAB122:    *((unsigned int *)t122) = 1;
    goto LAB125;

LAB124:    t129 = (t122 + 4);
    *((unsigned int *)t122) = 1;
    *((unsigned int *)t129) = 1;
    goto LAB125;

LAB126:    t142 = *((unsigned int *)t130);
    t143 = *((unsigned int *)t136);
    *((unsigned int *)t130) = (t142 | t143);
    t144 = (t102 + 4);
    t145 = (t122 + 4);
    t146 = *((unsigned int *)t102);
    t147 = (~(t146));
    t148 = *((unsigned int *)t144);
    t149 = (~(t148));
    t150 = *((unsigned int *)t122);
    t151 = (~(t150));
    t152 = *((unsigned int *)t145);
    t153 = (~(t152));
    t154 = (t147 & t149);
    t155 = (t151 & t153);
    t156 = (~(t154));
    t157 = (~(t155));
    t158 = *((unsigned int *)t136);
    *((unsigned int *)t136) = (t158 & t156);
    t159 = *((unsigned int *)t136);
    *((unsigned int *)t136) = (t159 & t157);
    t160 = *((unsigned int *)t130);
    *((unsigned int *)t130) = (t160 & t156);
    t161 = *((unsigned int *)t130);
    *((unsigned int *)t130) = (t161 & t157);
    goto LAB128;

}

static void NetDecl_106_4(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;

LAB0:    t1 = (t0 + 4504U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(41, ng0);
    t2 = (t0 + 3220);
    t4 = (t2 + 36U);
    t5 = *((char **)t4);
    t6 = (t0 + 3312);
    t7 = (t6 + 36U);
    t8 = *((char **)t7);
    t9 = (t0 + 3404);
    t10 = (t9 + 36U);
    t11 = *((char **)t10);
    xsi_vlogtype_concat(t3, 10, 10, 3U, t11, 1, t8, 1, t5, 8);
    t12 = (t0 + 5864);
    t13 = (t12 + 32U);
    t14 = *((char **)t13);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    memset(t16, 0, 8);
    t17 = 1023U;
    t18 = t17;
    t19 = (t3 + 4);
    t20 = *((unsigned int *)t3);
    t17 = (t17 & t20);
    t21 = *((unsigned int *)t19);
    t18 = (t18 & t21);
    t22 = (t16 + 4);
    t23 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t23 | t17);
    t24 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t24 | t18);
    xsi_driver_vfirst_trans(t12, 0, 9U);
    t25 = (t0 + 5740);
    *((int *)t25) = 1;

LAB1:    return;
}

static void Always_107_5(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 4648U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(107, ng0);
    t2 = (t0 + 5748);
    *((int *)t2) = 1;
    t3 = (t0 + 4676);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(108, ng0);

LAB5:    xsi_set_current_line(109, ng0);
    t4 = (t0 + 1796U);
    t5 = *((char **)t4);
    t4 = (t0 + 3220);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 8, 0LL);
    xsi_set_current_line(110, ng0);
    t2 = (t0 + 1888U);
    t3 = *((char **)t2);
    t2 = (t0 + 3312);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(111, ng0);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = (t0 + 3404);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 1, 0LL);
    goto LAB2;

}

static void implSig1_execute(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 4792U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng2)));
    t3 = (t0 + 5900);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 0);

LAB1:    return;
}

static void implSig2_execute(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 4936U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng3)));
    t3 = (t0 + 5936);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 0);

LAB1:    return;
}

static void implSig3_execute(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 5080U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng3)));
    t3 = (t0 + 5972);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 255U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 7);

LAB1:    return;
}

static void implSig4_execute(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    t1 = (t0 + 5224U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng4)));
    t3 = (t0 + 6008);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    memcpy(t7, t2, 8);
    xsi_driver_vfirst_trans(t3, 0, 31);

LAB1:    return;
}

static void implSig5_execute(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 5368U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng3)));
    t3 = (t0 + 6044);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 0);

LAB1:    return;
}

static void implSig6_execute(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 5512U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng3)));
    t3 = (t0 + 6080);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 0);

LAB1:    return;
}


extern void work_m_00000000001789375542_2928885658_init()
{
	static char *pe[] = {(void *)NetDecl_57_0,(void *)NetDecl_60_1,(void *)Always_61_2,(void *)Always_76_3,(void *)NetDecl_106_4,(void *)Always_107_5,(void *)implSig1_execute,(void *)implSig2_execute,(void *)implSig3_execute,(void *)implSig4_execute,(void *)implSig5_execute,(void *)implSig6_execute};
	xsi_register_didat("work_m_00000000001789375542_2928885658", "isim/eth_fifo_tst_isim_beh.exe.sim/work/m_00000000001789375542_2928885658.didat");
	xsi_register_executes(pe);
}
