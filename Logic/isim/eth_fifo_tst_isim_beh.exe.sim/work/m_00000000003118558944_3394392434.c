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
static unsigned int ng1[] = {9U, 0U};
static int ng2[] = {0, 0};
static int ng3[] = {1, 0};
static unsigned int ng4[] = {1U, 0U};
static unsigned int ng5[] = {0U, 0U};
static unsigned int ng6[] = {16U, 0U};
static unsigned int ng7[] = {2U, 0U};
static unsigned int ng8[] = {139U, 0U};
static unsigned int ng9[] = {3U, 0U};
static unsigned int ng10[] = {241U, 0U};
static unsigned int ng11[] = {4U, 0U};
static unsigned int ng12[] = {245U, 0U};
static unsigned int ng13[] = {5U, 0U};
static unsigned int ng14[] = {126U, 0U};
static unsigned int ng15[] = {6U, 0U};
static unsigned int ng16[] = {7U, 0U};
static unsigned int ng17[] = {8U, 0U};
static unsigned int ng18[] = {10U, 0U};
static unsigned int ng19[] = {11U, 0U};
static unsigned int ng20[] = {125U, 0U};
static unsigned int ng21[] = {12U, 0U};
static unsigned int ng22[] = {13U, 0U};
static unsigned int ng23[] = {14U, 0U};
static unsigned int ng24[] = {15U, 0U};
static unsigned int ng25[] = {17U, 0U};
static unsigned int ng26[] = {18U, 0U};
static unsigned int ng27[] = {178U, 0U};
static unsigned int ng28[] = {19U, 0U};
static unsigned int ng29[] = {20U, 0U};
static unsigned int ng30[] = {21U, 0U};
static unsigned int ng31[] = {22U, 0U};
static unsigned int ng32[] = {23U, 0U};
static unsigned int ng33[] = {24U, 0U};
static unsigned int ng34[] = {25U, 0U};
static unsigned int ng35[] = {26U, 0U};
static unsigned int ng36[] = {27U, 0U};
static unsigned int ng37[] = {28U, 0U};
static unsigned int ng38[] = {29U, 0U};
static unsigned int ng39[] = {30U, 0U};
static unsigned int ng40[] = {31U, 0U};
static unsigned int ng41[] = {32U, 0U};
static unsigned int ng42[] = {33U, 0U};
static unsigned int ng43[] = {34U, 0U};
static unsigned int ng44[] = {35U, 0U};
static unsigned int ng45[] = {36U, 0U};
static unsigned int ng46[] = {37U, 0U};
static unsigned int ng47[] = {38U, 0U};
static unsigned int ng48[] = {39U, 0U};
static unsigned int ng49[] = {40U, 0U};
static unsigned int ng50[] = {41U, 0U};
static unsigned int ng51[] = {42U, 0U};
static unsigned int ng52[] = {43U, 0U};
static unsigned int ng53[] = {44U, 0U};
static unsigned int ng54[] = {45U, 0U};
static unsigned int ng55[] = {46U, 0U};
static unsigned int ng56[] = {47U, 0U};
static unsigned int ng57[] = {48U, 0U};
static unsigned int ng58[] = {49U, 0U};
static unsigned int ng59[] = {50U, 0U};
static unsigned int ng60[] = {51U, 0U};
static unsigned int ng61[] = {52U, 0U};
static unsigned int ng62[] = {53U, 0U};
static unsigned int ng63[] = {54U, 0U};
static unsigned int ng64[] = {55U, 0U};
static unsigned int ng65[] = {56U, 0U};
static unsigned int ng66[] = {57U, 0U};
static unsigned int ng67[] = {58U, 0U};
static unsigned int ng68[] = {59U, 0U};
static unsigned int ng69[] = {60U, 0U};



static void Initial_130_0(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;

LAB0:    t1 = (t0 + 2732U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(130, ng0);
    t2 = (t0 + 2632);
    xsi_process_wait(t2, 400LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(130, ng0);

LAB5:    xsi_set_current_line(130, ng0);
    t3 = (t0 + 2632);
    xsi_process_wait(t3, 400LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(130, ng0);
    t5 = (t0 + 1748);
    t6 = (t5 + 36U);
    t7 = *((char **)t6);
    memset(t4, 0, 8);
    t8 = (t7 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB10;

LAB8:    if (*((unsigned int *)t8) == 0)
        goto LAB7;

LAB9:    t14 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t14) = 1;

LAB10:    t15 = (t0 + 1748);
    xsi_vlogvar_assign_value(t15, t4, 0, 0, 1);
    goto LAB5;

LAB7:    *((unsigned int *)t4) = 1;
    goto LAB10;

LAB11:    goto LAB1;

}

static void Always_134_1(char *t0)
{
    char t4[8];
    char t5[8];
    char t10[8];
    char t46[8];
    char *t1;
    char *t2;
    char *t3;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    char *t43;
    char *t44;
    char *t45;
    char *t47;

LAB0:    t1 = (t0 + 2876U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(134, ng0);
    t2 = (t0 + 4368);
    *((int *)t2) = 1;
    t3 = (t0 + 2904);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(134, ng0);
    t6 = (t0 + 1840);
    t7 = (t6 + 36U);
    t8 = *((char **)t7);
    t9 = ((char*)((ng1)));
    memset(t10, 0, 8);
    t11 = (t8 + 4);
    t12 = (t9 + 4);
    t13 = *((unsigned int *)t8);
    t14 = *((unsigned int *)t9);
    t15 = (t13 ^ t14);
    t16 = *((unsigned int *)t11);
    t17 = *((unsigned int *)t12);
    t18 = (t16 ^ t17);
    t19 = (t15 | t18);
    t20 = *((unsigned int *)t11);
    t21 = *((unsigned int *)t12);
    t22 = (t20 | t21);
    t23 = (~(t22));
    t24 = (t19 & t23);
    if (t24 != 0)
        goto LAB8;

LAB5:    if (t22 != 0)
        goto LAB7;

LAB6:    *((unsigned int *)t10) = 1;

LAB8:    memset(t5, 0, 8);
    t26 = (t10 + 4);
    t27 = *((unsigned int *)t26);
    t28 = (~(t27));
    t29 = *((unsigned int *)t10);
    t30 = (t29 & t28);
    t31 = (t30 & 1U);
    if (t31 != 0)
        goto LAB9;

LAB10:    if (*((unsigned int *)t26) != 0)
        goto LAB11;

LAB12:    t33 = (t5 + 4);
    t34 = *((unsigned int *)t5);
    t35 = *((unsigned int *)t33);
    t36 = (t34 || t35);
    if (t36 > 0)
        goto LAB13;

LAB14:    t38 = *((unsigned int *)t5);
    t39 = (~(t38));
    t40 = *((unsigned int *)t33);
    t41 = (t39 || t40);
    if (t41 > 0)
        goto LAB15;

LAB16:    if (*((unsigned int *)t33) > 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t5) > 0)
        goto LAB19;

LAB20:    memcpy(t4, t46, 8);

LAB21:    t47 = (t0 + 1840);
    xsi_vlogvar_wait_assign_value(t47, t4, 0, 0, 4, 0LL);
    goto LAB2;

LAB7:    t25 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB8;

LAB9:    *((unsigned int *)t5) = 1;
    goto LAB12;

LAB11:    t32 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t32) = 1;
    goto LAB12;

LAB13:    t37 = ((char*)((ng2)));
    goto LAB14;

LAB15:    t42 = (t0 + 1840);
    t43 = (t42 + 36U);
    t44 = *((char **)t43);
    t45 = ((char*)((ng3)));
    memset(t46, 0, 8);
    xsi_vlog_unsigned_add(t46, 32, t44, 4, t45, 32);
    goto LAB16;

LAB17:    xsi_vlog_unsigned_bit_combine(t4, 32, t37, 32, t46, 32);
    goto LAB21;

LAB19:    memcpy(t4, t37, 8);
    goto LAB21;

}

static void NetDecl_135_2(char *t0)
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

LAB0:    t1 = (t0 + 3020U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(135, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 4468);
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
    xsi_driver_vfirst_trans(t3, 0, 0U);

LAB1:    return;
}

static void NetDecl_136_3(char *t0)
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

LAB0:    t1 = (t0 + 3164U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(136, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 4504);
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
    xsi_driver_vfirst_trans(t3, 0, 0U);

LAB1:    return;
}

static void NetDecl_139_4(char *t0)
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
    char *t16;

LAB0:    t1 = (t0 + 3308U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(139, ng0);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = (t0 + 4540);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t2, 0, 0U);
    t16 = (t0 + 4376);
    *((int *)t16) = 1;

LAB1:    return;
}

static void Always_145_5(char *t0)
{
    char t15[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t16;
    char *t17;
    int t18;

LAB0:    t1 = (t0 + 3452U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(145, ng0);
    t2 = (t0 + 4384);
    *((int *)t2) = 1;
    t3 = (t0 + 3480);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(145, ng0);
    t4 = (t0 + 784U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB5;

LAB6:
LAB7:    goto LAB2;

LAB5:    xsi_set_current_line(146, ng0);

LAB8:    xsi_set_current_line(147, ng0);
    t11 = (t0 + 2208);
    t12 = (t11 + 36U);
    t13 = *((char **)t12);
    t14 = ((char*)((ng3)));
    memset(t15, 0, 8);
    xsi_vlog_unsigned_add(t15, 32, t13, 11, t14, 32);
    t16 = (t0 + 2208);
    xsi_vlogvar_wait_assign_value(t16, t15, 0, 0, 11, 0LL);
    xsi_set_current_line(148, ng0);
    t2 = (t0 + 2208);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = (t0 + 2116);
    t11 = (t5 + 36U);
    t12 = *((char **)t11);
    memset(t15, 0, 8);
    t13 = (t4 + 4);
    if (*((unsigned int *)t13) != 0)
        goto LAB10;

LAB9:    t14 = (t12 + 4);
    if (*((unsigned int *)t14) != 0)
        goto LAB10;

LAB13:    if (*((unsigned int *)t4) < *((unsigned int *)t12))
        goto LAB11;

LAB12:    t17 = (t0 + 1932);
    xsi_vlogvar_wait_assign_value(t17, t15, 0, 0, 1, 0LL);
    xsi_set_current_line(149, ng0);
    t2 = (t0 + 2208);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);

LAB14:    t5 = ((char*)((ng5)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t5, 11);
    if (t18 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng4)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng7)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng9)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB21;

LAB22:    t2 = ((char*)((ng11)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng13)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB25;

LAB26:    t2 = ((char*)((ng15)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB27;

LAB28:    t2 = ((char*)((ng16)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB29;

LAB30:    t2 = ((char*)((ng17)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB31;

LAB32:    t2 = ((char*)((ng1)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB33;

LAB34:    t2 = ((char*)((ng18)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB35;

LAB36:    t2 = ((char*)((ng19)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB37;

LAB38:    t2 = ((char*)((ng21)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB39;

LAB40:    t2 = ((char*)((ng22)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB41;

LAB42:    t2 = ((char*)((ng23)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB43;

LAB44:    t2 = ((char*)((ng24)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB45;

LAB46:    t2 = ((char*)((ng6)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB47;

LAB48:    t2 = ((char*)((ng25)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB49;

LAB50:    t2 = ((char*)((ng26)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB51;

LAB52:    t2 = ((char*)((ng28)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB53;

LAB54:    t2 = ((char*)((ng29)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB55;

LAB56:    t2 = ((char*)((ng30)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB57;

LAB58:    t2 = ((char*)((ng31)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB59;

LAB60:    t2 = ((char*)((ng32)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB61;

LAB62:    t2 = ((char*)((ng33)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB63;

LAB64:    t2 = ((char*)((ng34)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB65;

LAB66:    t2 = ((char*)((ng35)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB67;

LAB68:    t2 = ((char*)((ng36)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB69;

LAB70:    t2 = ((char*)((ng37)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB71;

LAB72:    t2 = ((char*)((ng38)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB73;

LAB74:    t2 = ((char*)((ng39)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB75;

LAB76:    t2 = ((char*)((ng40)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB77;

LAB78:    t2 = ((char*)((ng41)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB79;

LAB80:    t2 = ((char*)((ng42)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB81;

LAB82:    t2 = ((char*)((ng43)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB83;

LAB84:    t2 = ((char*)((ng44)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB85;

LAB86:    t2 = ((char*)((ng45)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB87;

LAB88:    t2 = ((char*)((ng46)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB89;

LAB90:    t2 = ((char*)((ng47)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB91;

LAB92:    t2 = ((char*)((ng48)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB93;

LAB94:    t2 = ((char*)((ng49)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB95;

LAB96:    t2 = ((char*)((ng50)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB97;

LAB98:    t2 = ((char*)((ng51)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB99;

LAB100:    t2 = ((char*)((ng52)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB101;

LAB102:    t2 = ((char*)((ng53)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB103;

LAB104:    t2 = ((char*)((ng54)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB105;

LAB106:    t2 = ((char*)((ng55)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB107;

LAB108:    t2 = ((char*)((ng56)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB109;

LAB110:    t2 = ((char*)((ng57)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB111;

LAB112:    t2 = ((char*)((ng58)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB113;

LAB114:    t2 = ((char*)((ng59)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB115;

LAB116:    t2 = ((char*)((ng60)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB117;

LAB118:    t2 = ((char*)((ng61)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB119;

LAB120:    t2 = ((char*)((ng62)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB121;

LAB122:    t2 = ((char*)((ng63)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB123;

LAB124:    t2 = ((char*)((ng64)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB125;

LAB126:    t2 = ((char*)((ng65)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB127;

LAB128:    t2 = ((char*)((ng66)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB129;

LAB130:    t2 = ((char*)((ng67)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB131;

LAB132:    t2 = ((char*)((ng68)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB133;

LAB134:    t2 = ((char*)((ng69)));
    t18 = xsi_vlog_unsigned_case_compare(t4, 11, t2, 11);
    if (t18 == 1)
        goto LAB135;

LAB136:
LAB138:
LAB137:    xsi_set_current_line(212, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 8, 0LL);

LAB139:    goto LAB7;

LAB10:    t16 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB12;

LAB11:    *((unsigned int *)t15) = 1;
    goto LAB12;

LAB15:    xsi_set_current_line(151, ng0);
    t11 = ((char*)((ng5)));
    t12 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 8, 0LL);
    goto LAB139;

LAB17:    xsi_set_current_line(152, ng0);
    t3 = ((char*)((ng6)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB19:    xsi_set_current_line(153, ng0);
    t3 = ((char*)((ng8)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB21:    xsi_set_current_line(154, ng0);
    t3 = ((char*)((ng10)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB23:    xsi_set_current_line(155, ng0);
    t3 = ((char*)((ng12)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB25:    xsi_set_current_line(156, ng0);
    t3 = ((char*)((ng14)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB27:    xsi_set_current_line(157, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB29:    xsi_set_current_line(158, ng0);
    t3 = ((char*)((ng6)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB31:    xsi_set_current_line(159, ng0);
    t3 = ((char*)((ng8)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB33:    xsi_set_current_line(160, ng0);
    t3 = ((char*)((ng10)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB35:    xsi_set_current_line(161, ng0);
    t3 = ((char*)((ng12)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB37:    xsi_set_current_line(162, ng0);
    t3 = ((char*)((ng20)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB39:    xsi_set_current_line(163, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB41:    xsi_set_current_line(164, ng0);
    t3 = ((char*)((ng16)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB43:    xsi_set_current_line(165, ng0);
    t3 = ((char*)((ng11)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB45:    xsi_set_current_line(166, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB47:    xsi_set_current_line(167, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB49:    xsi_set_current_line(168, ng0);
    t3 = ((char*)((ng4)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB51:    xsi_set_current_line(169, ng0);
    t3 = ((char*)((ng27)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB53:    xsi_set_current_line(170, ng0);
    t3 = ((char*)((ng4)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB55:    xsi_set_current_line(171, ng0);
    t3 = ((char*)((ng10)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB57:    xsi_set_current_line(172, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB59:    xsi_set_current_line(173, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB61:    xsi_set_current_line(174, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB63:    xsi_set_current_line(175, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB65:    xsi_set_current_line(176, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB67:    xsi_set_current_line(177, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB69:    xsi_set_current_line(178, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB71:    xsi_set_current_line(179, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB73:    xsi_set_current_line(180, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB75:    xsi_set_current_line(181, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB77:    xsi_set_current_line(182, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB79:    xsi_set_current_line(183, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB81:    xsi_set_current_line(184, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB83:    xsi_set_current_line(185, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB85:    xsi_set_current_line(186, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB87:    xsi_set_current_line(187, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB89:    xsi_set_current_line(188, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB91:    xsi_set_current_line(189, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB93:    xsi_set_current_line(190, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB95:    xsi_set_current_line(191, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB97:    xsi_set_current_line(192, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB99:    xsi_set_current_line(193, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB101:    xsi_set_current_line(194, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB103:    xsi_set_current_line(195, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB105:    xsi_set_current_line(196, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB107:    xsi_set_current_line(197, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB109:    xsi_set_current_line(198, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB111:    xsi_set_current_line(199, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB113:    xsi_set_current_line(200, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB115:    xsi_set_current_line(201, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB117:    xsi_set_current_line(202, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB119:    xsi_set_current_line(203, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB121:    xsi_set_current_line(204, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB123:    xsi_set_current_line(205, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB125:    xsi_set_current_line(206, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB127:    xsi_set_current_line(207, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB129:    xsi_set_current_line(208, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB131:    xsi_set_current_line(209, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB133:    xsi_set_current_line(210, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

LAB135:    xsi_set_current_line(211, ng0);
    t3 = ((char*)((ng5)));
    t5 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    goto LAB139;

}

static void NetDecl_221_6(char *t0)
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
    char *t16;

LAB0:    t1 = (t0 + 3596U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(221, ng0);
    t2 = (t0 + 968U);
    t3 = *((char **)t2);
    t2 = (t0 + 4576);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t2, 0, 0U);
    t16 = (t0 + 4392);
    *((int *)t16) = 1;

LAB1:    return;
}

static void NetDecl_229_7(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
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

LAB0:    t1 = (t0 + 3740U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(229, ng0);
    t2 = (t0 + 1152U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4);
    t5 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 9);
    t8 = (t7 & 1);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 9);
    t11 = (t10 & 1);
    *((unsigned int *)t2) = t11;
    t12 = (t0 + 4612);
    t13 = (t12 + 32U);
    t14 = *((char **)t13);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    memset(t16, 0, 8);
    t17 = 1U;
    t18 = t17;
    t19 = (t4 + 4);
    t20 = *((unsigned int *)t4);
    t17 = (t17 & t20);
    t21 = *((unsigned int *)t19);
    t18 = (t18 & t21);
    t22 = (t16 + 4);
    t23 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t23 | t17);
    t24 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t24 | t18);
    xsi_driver_vfirst_trans(t12, 0, 0U);
    t25 = (t0 + 4400);
    *((int *)t25) = 1;

LAB1:    return;
}

static void NetDecl_230_8(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
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

LAB0:    t1 = (t0 + 3884U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(230, ng0);
    t2 = (t0 + 1152U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4);
    t5 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 8);
    t8 = (t7 & 1);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 8);
    t11 = (t10 & 1);
    *((unsigned int *)t2) = t11;
    t12 = (t0 + 4648);
    t13 = (t12 + 32U);
    t14 = *((char **)t13);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    memset(t16, 0, 8);
    t17 = 1U;
    t18 = t17;
    t19 = (t4 + 4);
    t20 = *((unsigned int *)t4);
    t17 = (t17 & t20);
    t21 = *((unsigned int *)t19);
    t18 = (t18 & t21);
    t22 = (t16 + 4);
    t23 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t23 | t17);
    t24 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t24 | t18);
    xsi_driver_vfirst_trans(t12, 0, 0U);
    t25 = (t0 + 4408);
    *((int *)t25) = 1;

LAB1:    return;
}

static void NetDecl_231_9(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
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

LAB0:    t1 = (t0 + 4028U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(231, ng0);
    t2 = (t0 + 1152U);
    t4 = *((char **)t2);
    memset(t3, 0, 8);
    t2 = (t3 + 4);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (t6 >> 0);
    *((unsigned int *)t3) = t7;
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 0);
    *((unsigned int *)t2) = t9;
    t10 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t10 & 255U);
    t11 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t11 & 255U);
    t12 = (t0 + 4684);
    t13 = (t12 + 32U);
    t14 = *((char **)t13);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    memset(t16, 0, 8);
    t17 = 255U;
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
    xsi_driver_vfirst_trans(t12, 0, 7U);
    t25 = (t0 + 4416);
    *((int *)t25) = 1;

LAB1:    return;
}

static void implSig1_execute(char *t0)
{
    char t3[8];
    char t4[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;

LAB0:    t1 = (t0 + 4172U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 2024);
    t5 = (t2 + 36U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t7 = (t4 + 4);
    t8 = (t6 + 4);
    t9 = *((unsigned int *)t6);
    t10 = (t9 >> 0);
    *((unsigned int *)t4) = t10;
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 0);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t13 & 255U);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 & 255U);
    t15 = (t0 + 1932);
    t16 = (t15 + 36U);
    t17 = *((char **)t16);
    t18 = (t0 + 784U);
    t19 = *((char **)t18);
    xsi_vlogtype_concat(t3, 10, 10, 3U, t19, 1, t17, 1, t4, 8);
    t18 = (t0 + 4720);
    t20 = (t18 + 32U);
    t21 = *((char **)t20);
    t22 = (t21 + 40U);
    t23 = *((char **)t22);
    memset(t23, 0, 8);
    t24 = 1023U;
    t25 = t24;
    t26 = (t3 + 4);
    t27 = *((unsigned int *)t3);
    t24 = (t24 & t27);
    t28 = *((unsigned int *)t26);
    t25 = (t25 & t28);
    t29 = (t23 + 4);
    t30 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t30 | t24);
    t31 = *((unsigned int *)t29);
    *((unsigned int *)t29) = (t31 | t25);
    xsi_driver_vfirst_trans(t18, 0, 9);
    t32 = (t0 + 4424);
    *((int *)t32) = 1;

LAB1:    return;
}


extern void work_m_00000000003118558944_3394392434_init()
{
	static char *pe[] = {(void *)Initial_130_0,(void *)Always_134_1,(void *)NetDecl_135_2,(void *)NetDecl_136_3,(void *)NetDecl_139_4,(void *)Always_145_5,(void *)NetDecl_221_6,(void *)NetDecl_229_7,(void *)NetDecl_230_8,(void *)NetDecl_231_9,(void *)implSig1_execute};
	xsi_register_didat("work_m_00000000003118558944_3394392434", "isim/eth_fifo_tst_isim_beh.exe.sim/work/m_00000000003118558944_3394392434.didat");
	xsi_register_executes(pe);
}
