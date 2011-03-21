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
static const char *ng0 = "C:/Workspace/lvk/doc/SP601-USB-Image_12.3/sp601_brd/SP601_BRD_Src/Logic/ETH_TX_CRC.v";
static int ng1[] = {1, 0};
static int ng2[] = {2, 0};
static int ng3[] = {3, 0};
static int ng4[] = {4, 0};
static int ng5[] = {0, 0};
static unsigned int ng6[] = {0U, 0U};



static void NetDecl_34_0(char *t0)
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

LAB0:    t1 = (t0 + 2548U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(34, ng0);
    t2 = (t0 + 692U);
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
    t12 = (t0 + 3844);
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
    t25 = (t0 + 3752);
    *((int *)t25) = 1;

LAB1:    return;
}

static void NetDecl_35_1(char *t0)
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

LAB0:    t1 = (t0 + 2692U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(35, ng0);
    t2 = (t0 + 692U);
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
    t12 = (t0 + 3880);
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
    t25 = (t0 + 3760);
    *((int *)t25) = 1;

LAB1:    return;
}

static void NetDecl_36_2(char *t0)
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

LAB0:    t1 = (t0 + 2836U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(36, ng0);
    t2 = (t0 + 692U);
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
    t12 = (t0 + 3916);
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
    t25 = (t0 + 3768);
    *((int *)t25) = 1;

LAB1:    return;
}

static void Always_44_3(char *t0)
{
    char t13[8];
    char t14[8];
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
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    unsigned int t24;
    int t25;
    char *t26;
    unsigned int t27;
    int t28;
    int t29;
    unsigned int t30;
    unsigned int t31;
    int t32;
    int t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;

LAB0:    t1 = (t0 + 2980U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(44, ng0);
    t2 = (t0 + 3776);
    *((int *)t2) = 1;
    t3 = (t0 + 3008);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(44, ng0);
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

LAB5:    xsi_set_current_line(45, ng0);

LAB8:    xsi_set_current_line(46, ng0);
    t11 = (t0 + 968U);
    t12 = *((char **)t11);
    memcpy(t13, t12, 8);
    t11 = (t0 + 1656);
    t16 = (t0 + 1656);
    t17 = (t16 + 44U);
    t18 = *((char **)t17);
    t19 = (t0 + 1656);
    t20 = (t19 + 40U);
    t21 = *((char **)t20);
    t22 = ((char*)((ng1)));
    xsi_vlog_generic_convert_array_indices(t14, t15, t18, t21, 2, 1, t22, 32, 1);
    t23 = (t14 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (!(t24));
    t26 = (t15 + 4);
    t27 = *((unsigned int *)t26);
    t28 = (!(t27));
    t29 = (t25 && t28);
    if (t29 == 1)
        goto LAB9;

LAB10:    xsi_set_current_line(47, ng0);
    t2 = (t0 + 1656);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = (t0 + 1656);
    t11 = (t5 + 44U);
    t12 = *((char **)t11);
    t16 = (t0 + 1656);
    t17 = (t16 + 40U);
    t18 = *((char **)t17);
    t19 = ((char*)((ng1)));
    xsi_vlog_generic_get_array_select_value(t13, 9, t4, t12, t18, 2, 1, t19, 32, 1);
    t20 = (t0 + 1656);
    t21 = (t0 + 1656);
    t22 = (t21 + 44U);
    t23 = *((char **)t22);
    t26 = (t0 + 1656);
    t34 = (t26 + 40U);
    t35 = *((char **)t34);
    t36 = ((char*)((ng2)));
    xsi_vlog_generic_convert_array_indices(t14, t15, t23, t35, 2, 1, t36, 32, 1);
    t37 = (t14 + 4);
    t6 = *((unsigned int *)t37);
    t25 = (!(t6));
    t38 = (t15 + 4);
    t7 = *((unsigned int *)t38);
    t28 = (!(t7));
    t29 = (t25 && t28);
    if (t29 == 1)
        goto LAB11;

LAB12:    xsi_set_current_line(48, ng0);
    t2 = (t0 + 1656);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = (t0 + 1656);
    t11 = (t5 + 44U);
    t12 = *((char **)t11);
    t16 = (t0 + 1656);
    t17 = (t16 + 40U);
    t18 = *((char **)t17);
    t19 = ((char*)((ng2)));
    xsi_vlog_generic_get_array_select_value(t13, 9, t4, t12, t18, 2, 1, t19, 32, 1);
    t20 = (t0 + 1656);
    t21 = (t0 + 1656);
    t22 = (t21 + 44U);
    t23 = *((char **)t22);
    t26 = (t0 + 1656);
    t34 = (t26 + 40U);
    t35 = *((char **)t34);
    t36 = ((char*)((ng3)));
    xsi_vlog_generic_convert_array_indices(t14, t15, t23, t35, 2, 1, t36, 32, 1);
    t37 = (t14 + 4);
    t6 = *((unsigned int *)t37);
    t25 = (!(t6));
    t38 = (t15 + 4);
    t7 = *((unsigned int *)t38);
    t28 = (!(t7));
    t29 = (t25 && t28);
    if (t29 == 1)
        goto LAB13;

LAB14:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 1656);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = (t0 + 1656);
    t11 = (t5 + 44U);
    t12 = *((char **)t11);
    t16 = (t0 + 1656);
    t17 = (t16 + 40U);
    t18 = *((char **)t17);
    t19 = ((char*)((ng3)));
    xsi_vlog_generic_get_array_select_value(t13, 9, t4, t12, t18, 2, 1, t19, 32, 1);
    t20 = (t0 + 1656);
    t21 = (t0 + 1656);
    t22 = (t21 + 44U);
    t23 = *((char **)t22);
    t26 = (t0 + 1656);
    t34 = (t26 + 40U);
    t35 = *((char **)t34);
    t36 = ((char*)((ng4)));
    xsi_vlog_generic_convert_array_indices(t14, t15, t23, t35, 2, 1, t36, 32, 1);
    t37 = (t14 + 4);
    t6 = *((unsigned int *)t37);
    t25 = (!(t6));
    t38 = (t15 + 4);
    t7 = *((unsigned int *)t38);
    t28 = (!(t7));
    t29 = (t25 && t28);
    if (t29 == 1)
        goto LAB15;

LAB16:    xsi_set_current_line(50, ng0);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = (t0 + 1748);
    t4 = (t2 + 36U);
    t5 = *((char **)t4);
    memset(t14, 0, 8);
    t11 = (t14 + 4);
    t12 = (t5 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (t6 >> 0);
    *((unsigned int *)t14) = t7;
    t8 = *((unsigned int *)t12);
    t9 = (t8 >> 0);
    *((unsigned int *)t11) = t9;
    t10 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t10 & 7U);
    t24 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t24 & 7U);
    xsi_vlogtype_concat(t13, 4, 4, 2U, t14, 3, t3, 1);
    t16 = (t0 + 1748);
    xsi_vlogvar_wait_assign_value(t16, t13, 0, 0, 4, 0LL);
    goto LAB7;

LAB9:    t30 = *((unsigned int *)t14);
    t31 = *((unsigned int *)t15);
    t32 = (t30 - t31);
    t33 = (t32 + 1);
    xsi_vlogvar_wait_assign_value(t11, t13, 0, *((unsigned int *)t15), t33, 0LL);
    goto LAB10;

LAB11:    t8 = *((unsigned int *)t14);
    t9 = *((unsigned int *)t15);
    t32 = (t8 - t9);
    t33 = (t32 + 1);
    xsi_vlogvar_wait_assign_value(t20, t13, 0, *((unsigned int *)t15), t33, 0LL);
    goto LAB12;

LAB13:    t8 = *((unsigned int *)t14);
    t9 = *((unsigned int *)t15);
    t32 = (t8 - t9);
    t33 = (t32 + 1);
    xsi_vlogvar_wait_assign_value(t20, t13, 0, *((unsigned int *)t15), t33, 0LL);
    goto LAB14;

LAB15:    t8 = *((unsigned int *)t14);
    t9 = *((unsigned int *)t15);
    t32 = (t8 - t9);
    t33 = (t32 + 1);
    xsi_vlogvar_wait_assign_value(t20, t13, 0, *((unsigned int *)t15), t33, 0LL);
    goto LAB16;

}

static void NetDecl_71_4(char *t0)
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
    char *t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;

LAB0:    t1 = (t0 + 3124U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(39, ng0);
    t2 = (t0 + 1932);
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
    t15 = (t0 + 1840);
    t16 = (t15 + 36U);
    t17 = *((char **)t16);
    t18 = (t0 + 2024);
    t19 = (t18 + 36U);
    t20 = *((char **)t19);
    xsi_vlogtype_concat(t3, 10, 10, 3U, t20, 1, t17, 1, t4, 8);
    t21 = (t0 + 3952);
    t22 = (t21 + 32U);
    t23 = *((char **)t22);
    t24 = (t23 + 40U);
    t25 = *((char **)t24);
    memset(t25, 0, 8);
    t26 = 1023U;
    t27 = t26;
    t28 = (t3 + 4);
    t29 = *((unsigned int *)t3);
    t26 = (t26 & t29);
    t30 = *((unsigned int *)t28);
    t27 = (t27 & t30);
    t31 = (t25 + 4);
    t32 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t32 | t26);
    t33 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t33 | t27);
    xsi_driver_vfirst_trans(t21, 0, 9U);
    t34 = (t0 + 3784);
    *((int *)t34) = 1;

LAB1:    return;
}

static void Always_72_5(char *t0)
{
    char t14[8];
    char t24[8];
    char t25[8];
    char t33[8];
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
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    unsigned int t30;
    char *t31;
    char *t32;

LAB0:    t1 = (t0 + 3268U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(72, ng0);
    t2 = (t0 + 3792);
    *((int *)t2) = 1;
    t3 = (t0 + 3296);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(73, ng0);
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

LAB6:    xsi_set_current_line(80, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB7:    goto LAB2;

LAB5:    xsi_set_current_line(74, ng0);

LAB8:    xsi_set_current_line(75, ng0);
    t11 = (t0 + 1748);
    t12 = (t11 + 36U);
    t13 = *((char **)t12);
    memset(t14, 0, 8);
    t15 = (t14 + 4);
    t16 = (t13 + 4);
    t17 = *((unsigned int *)t13);
    t18 = (t17 >> 3);
    t19 = (t18 & 1);
    *((unsigned int *)t14) = t19;
    t20 = *((unsigned int *)t16);
    t21 = (t20 >> 3);
    t22 = (t21 & 1);
    *((unsigned int *)t15) = t22;
    t23 = (t0 + 1840);
    xsi_vlogvar_wait_assign_value(t23, t14, 0, 0, 1, 0LL);
    xsi_set_current_line(76, ng0);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    memset(t24, 0, 8);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB9;

LAB10:    if (*((unsigned int *)t2) != 0)
        goto LAB11;

LAB12:    t5 = (t24 + 4);
    t17 = *((unsigned int *)t24);
    t18 = *((unsigned int *)t5);
    t19 = (t17 || t18);
    if (t19 > 0)
        goto LAB13;

LAB14:    t20 = *((unsigned int *)t24);
    t21 = (~(t20));
    t22 = *((unsigned int *)t5);
    t30 = (t21 || t22);
    if (t30 > 0)
        goto LAB15;

LAB16:    if (*((unsigned int *)t5) > 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t24) > 0)
        goto LAB19;

LAB20:    memcpy(t14, t33, 8);

LAB21:    t31 = (t0 + 1932);
    xsi_vlogvar_wait_assign_value(t31, t14, 0, 0, 8, 0LL);
    xsi_set_current_line(77, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB7;

LAB9:    *((unsigned int *)t24) = 1;
    goto LAB12;

LAB11:    t4 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB12;

LAB13:    t11 = (t0 + 1656);
    t12 = (t11 + 36U);
    t13 = *((char **)t12);
    t15 = (t0 + 1656);
    t16 = (t15 + 44U);
    t23 = *((char **)t16);
    t26 = (t0 + 1656);
    t27 = (t26 + 40U);
    t28 = *((char **)t27);
    t29 = ((char*)((ng4)));
    xsi_vlog_generic_get_array_select_value(t25, 9, t13, t23, t28, 2, 1, t29, 32, 1);
    goto LAB14;

LAB15:    t31 = (t0 + 1152U);
    t32 = *((char **)t31);
    memcpy(t33, t32, 8);
    goto LAB16;

LAB17:    xsi_vlog_unsigned_bit_combine(t14, 9, t25, 9, t33, 9);
    goto LAB21;

LAB19:    memcpy(t14, t25, 8);
    goto LAB21;

}

static void implSig1_execute(char *t0)
{
    char t3[8];
    char t6[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;

LAB0:    t1 = (t0 + 3412U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 1748);
    t4 = (t2 + 36U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t7 = (t6 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 3);
    t11 = (t10 & 1);
    *((unsigned int *)t6) = t11;
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 3);
    t14 = (t13 & 1);
    *((unsigned int *)t7) = t14;
    memset(t3, 0, 8);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t15);
    t17 = (~(t16));
    t18 = *((unsigned int *)t6);
    t19 = (t18 & t17);
    t20 = (t19 & 1U);
    if (t20 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t15) == 0)
        goto LAB4;

LAB6:    t21 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t21) = 1;

LAB7:    t22 = (t0 + 3988);
    t23 = (t22 + 32U);
    t24 = *((char **)t23);
    t25 = (t24 + 40U);
    t26 = *((char **)t25);
    memset(t26, 0, 8);
    t27 = 1U;
    t28 = t27;
    t29 = (t3 + 4);
    t30 = *((unsigned int *)t3);
    t27 = (t27 & t30);
    t31 = *((unsigned int *)t29);
    t28 = (t28 & t31);
    t32 = (t26 + 4);
    t33 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t33 | t27);
    t34 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t34 | t28);
    xsi_driver_vfirst_trans(t22, 0, 0);
    t35 = (t0 + 3800);
    *((int *)t35) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t3) = 1;
    goto LAB7;

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

LAB0:    t1 = (t0 + 3556U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng6)));
    t3 = (t0 + 4024);
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


extern void work_m_00000000004264619605_1987887403_init()
{
	static char *pe[] = {(void *)NetDecl_34_0,(void *)NetDecl_35_1,(void *)NetDecl_36_2,(void *)Always_44_3,(void *)NetDecl_71_4,(void *)Always_72_5,(void *)implSig1_execute,(void *)implSig2_execute};
	xsi_register_didat("work_m_00000000004264619605_1987887403", "isim/eth_fifo_tst_isim_beh.exe.sim/work/m_00000000004264619605_1987887403.didat");
	xsi_register_executes(pe);
}
