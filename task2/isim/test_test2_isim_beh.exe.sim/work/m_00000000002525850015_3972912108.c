/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                         */
/*  \   \        Copyright (c) 2003-2007 Xilinx, Inc.                 */
/*  /   /        All Right Reserved.                                  */
/* /---/   /\                                                         */
/* \   \  /  \                                                        */
/*  \___\/\___\                                                       */
/**********************************************************************/

/* This file is designed for use with ISim build 0xecc70214 */

#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "D:/lvk/task2/test_test2.v";
static int ng1[] = {3, 0, 0, 0};
static int ng2[] = {1, 0};
static int ng3[] = {32, 0, 0, 0};
static int ng4[] = {0, 0};
static int ng5[] = {0, 0, 0, 0};
static int ng6[] = {10, 0, 0, 0};
static int ng7[] = {4, 0, 0, 0};
static int ng8[] = {5, 0, 0, 0};
static unsigned int ng9[] = {9U, 0U, 0U, 0U};



static void I_54_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 1536U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(54, ng0);

LAB4:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 1732);
    *((int *)t2) = 1;
    t3 = (t0 + 1564);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(61, ng0);

LAB6:    xsi_set_current_line(62, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 920);
    xsi_vlogvar_generic_wait_assign_value(t5, t4, 1, 0, 0, 33, 0LL);
    xsi_set_current_line(63, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1012);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 1, 0LL);
    xsi_set_current_line(65, ng0);
    t2 = (t0 + 1740);
    *((int *)t2) = 1;
    t3 = (t0 + 1564);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB7;
    goto LAB1;

LAB7:    xsi_set_current_line(65, ng0);

LAB8:    xsi_set_current_line(66, ng0);
    t4 = ((char*)((ng3)));
    t5 = (t0 + 920);
    xsi_vlogvar_generic_wait_assign_value(t5, t4, 1, 0, 0, 33, 0LL);
    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1012);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 1, 0LL);
    xsi_set_current_line(69, ng0);
    t2 = (t0 + 1748);
    *((int *)t2) = 1;
    t3 = (t0 + 1564);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB9;
    goto LAB1;

LAB9:    xsi_set_current_line(69, ng0);

LAB10:    xsi_set_current_line(70, ng0);
    t4 = ((char*)((ng5)));
    t5 = (t0 + 920);
    xsi_vlogvar_generic_wait_assign_value(t5, t4, 1, 0, 0, 33, 0LL);
    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1012);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 1, 0LL);
    xsi_set_current_line(73, ng0);
    t2 = (t0 + 1756);
    *((int *)t2) = 1;
    t3 = (t0 + 1564);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB11:    xsi_set_current_line(73, ng0);

LAB12:    xsi_set_current_line(74, ng0);
    t4 = ((char*)((ng6)));
    t5 = (t0 + 920);
    xsi_vlogvar_generic_wait_assign_value(t5, t4, 1, 0, 0, 33, 0LL);
    xsi_set_current_line(75, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1012);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 1, 0LL);
    xsi_set_current_line(77, ng0);
    t2 = (t0 + 1764);
    *((int *)t2) = 1;
    t3 = (t0 + 1564);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB13;
    goto LAB1;

LAB13:    xsi_set_current_line(77, ng0);

LAB14:    xsi_set_current_line(78, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 920);
    xsi_vlogvar_generic_wait_assign_value(t5, t4, 1, 0, 0, 33, 0LL);
    xsi_set_current_line(79, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1012);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 1, 0LL);
    xsi_set_current_line(81, ng0);
    t2 = (t0 + 1772);
    *((int *)t2) = 1;
    t3 = (t0 + 1564);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB15:    xsi_set_current_line(81, ng0);

LAB16:    xsi_set_current_line(82, ng0);
    t4 = ((char*)((ng7)));
    t5 = (t0 + 920);
    xsi_vlogvar_generic_wait_assign_value(t5, t4, 1, 0, 0, 33, 0LL);
    xsi_set_current_line(84, ng0);
    t2 = (t0 + 1780);
    *((int *)t2) = 1;
    t3 = (t0 + 1564);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB17;
    goto LAB1;

LAB17:    xsi_set_current_line(84, ng0);

LAB18:    xsi_set_current_line(85, ng0);
    t4 = ((char*)((ng8)));
    t5 = (t0 + 920);
    xsi_vlogvar_generic_wait_assign_value(t5, t4, 1, 0, 0, 33, 0LL);
    xsi_set_current_line(87, ng0);
    t2 = (t0 + 1788);
    *((int *)t2) = 1;
    t3 = (t0 + 1564);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB19;
    goto LAB1;

LAB19:    xsi_set_current_line(87, ng0);

LAB20:    xsi_set_current_line(88, ng0);
    t4 = ((char*)((ng9)));
    t5 = (t0 + 920);
    xsi_vlogvar_generic_wait_assign_value(t5, t4, 2, 0, 0, 33, 0LL);
    xsi_set_current_line(90, ng0);
    t2 = (t0 + 1796);
    *((int *)t2) = 1;
    t3 = (t0 + 1564);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB21;
    goto LAB1;

LAB21:    xsi_set_current_line(90, ng0);

LAB22:    xsi_set_current_line(91, ng0);
    t4 = ((char*)((ng8)));
    t5 = (t0 + 920);
    xsi_vlogvar_generic_wait_assign_value(t5, t4, 1, 0, 0, 33, 0LL);
    xsi_set_current_line(93, ng0);
    t2 = (t0 + 1804);
    *((int *)t2) = 1;
    t3 = (t0 + 1564);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB23;
    goto LAB1;

LAB23:    xsi_set_current_line(93, ng0);

LAB24:    xsi_set_current_line(94, ng0);
    t4 = ((char*)((ng7)));
    t5 = (t0 + 920);
    xsi_vlogvar_generic_wait_assign_value(t5, t4, 1, 0, 0, 33, 0LL);
    xsi_set_current_line(95, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1012);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 1, 0LL);
    xsi_set_current_line(97, ng0);
    t2 = (t0 + 1812);
    *((int *)t2) = 1;
    t3 = (t0 + 1564);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB25;
    goto LAB1;

LAB25:    xsi_set_current_line(97, ng0);

LAB26:    xsi_set_current_line(98, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 920);
    xsi_vlogvar_generic_wait_assign_value(t5, t4, 1, 0, 0, 33, 0LL);
    xsi_set_current_line(99, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1012);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 1, 0LL);
    xsi_set_current_line(101, ng0);
    t2 = (t0 + 1820);
    *((int *)t2) = 1;
    t3 = (t0 + 1564);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB27;
    goto LAB1;

LAB27:    xsi_set_current_line(101, ng0);

LAB28:    xsi_set_current_line(102, ng0);
    t4 = ((char*)((ng7)));
    t5 = (t0 + 920);
    xsi_vlogvar_generic_wait_assign_value(t5, t4, 1, 0, 0, 33, 0LL);
    xsi_set_current_line(104, ng0);
    t2 = (t0 + 1828);
    *((int *)t2) = 1;
    t3 = (t0 + 1564);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB29;
    goto LAB1;

LAB29:    xsi_set_current_line(104, ng0);

LAB30:    xsi_set_current_line(105, ng0);
    t4 = ((char*)((ng8)));
    t5 = (t0 + 920);
    xsi_vlogvar_generic_wait_assign_value(t5, t4, 1, 0, 0, 33, 0LL);
    xsi_set_current_line(107, ng0);
    t2 = (t0 + 1836);
    *((int *)t2) = 1;
    t3 = (t0 + 1564);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB31;
    goto LAB1;

LAB31:    xsi_set_current_line(107, ng0);

LAB32:    xsi_set_current_line(108, ng0);
    t4 = ((char*)((ng9)));
    t5 = (t0 + 920);
    xsi_vlogvar_generic_wait_assign_value(t5, t4, 2, 0, 0, 33, 0LL);
    xsi_set_current_line(110, ng0);
    t2 = (t0 + 1844);
    *((int *)t2) = 1;
    t3 = (t0 + 1564);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB33;
    goto LAB1;

LAB33:    xsi_set_current_line(110, ng0);

LAB34:    xsi_set_current_line(111, ng0);
    t4 = ((char*)((ng8)));
    t5 = (t0 + 920);
    xsi_vlogvar_generic_wait_assign_value(t5, t4, 1, 0, 0, 33, 0LL);
    xsi_set_current_line(113, ng0);
    t2 = (t0 + 1852);
    *((int *)t2) = 1;
    t3 = (t0 + 1564);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB35;
    goto LAB1;

LAB35:    xsi_set_current_line(113, ng0);

LAB36:    xsi_set_current_line(114, ng0);
    t4 = ((char*)((ng7)));
    t5 = (t0 + 920);
    xsi_vlogvar_generic_wait_assign_value(t5, t4, 1, 0, 0, 33, 0LL);
    xsi_set_current_line(115, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1012);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 1, 0LL);
    xsi_set_current_line(117, ng0);
    t2 = (t0 + 1436);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB37;
    goto LAB1;

LAB37:    goto LAB1;

}


extern void work_m_00000000002525850015_3972912108_init()
{
	static char *pe[] = {(void *)I_54_0};
	xsi_register_didat("work_m_00000000002525850015_3972912108", "isim/test_test2_isim_beh.exe.sim/work/m_00000000002525850015_3972912108.didat");
	xsi_register_executes(pe);
}
