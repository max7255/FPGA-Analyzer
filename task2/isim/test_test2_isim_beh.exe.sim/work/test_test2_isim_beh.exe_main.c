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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000000130381086_2964965119_init();
    work_m_00000000002531326666_0494531893_init();
    work_m_00000000002525850015_3972912108_init();
    work_m_00000000000751492074_2073120511_init();


    xsi_register_tops("work_m_00000000002525850015_3972912108");
    xsi_register_tops("work_m_00000000000751492074_2073120511");


    return xsi_run_simulation(argc, argv);

}
