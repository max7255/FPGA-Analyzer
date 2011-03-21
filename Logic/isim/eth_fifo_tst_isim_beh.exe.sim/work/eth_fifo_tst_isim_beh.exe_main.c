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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000002201343478_2850302102_init();
    work_m_00000000004264619605_1987887403_init();
    work_m_00000000001140941075_2686788150_init();
    unisims_ver_m_00000000002996766886_2101574695_init();
    work_m_00000000001789375542_2928885658_init();
    work_m_00000000003118558944_3394392434_init();
    work_m_00000000002013452923_2073120511_init();


    xsi_register_tops("work_m_00000000003118558944_3394392434");
    xsi_register_tops("work_m_00000000002013452923_2073120511");


    return xsi_run_simulation(argc, argv);

}
