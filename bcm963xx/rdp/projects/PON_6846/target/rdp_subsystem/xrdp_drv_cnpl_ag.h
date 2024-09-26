/*
   Copyright (c) 2015 Broadcom
   All Rights Reserved

    <:label-BRCM:2015:DUAL/GPL:standard
    
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation (the "GPL").
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    
    A copy of the GPL is available at http://www.broadcom.com/licenses/GPLv2.php, or by
    writing to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
    
:>
*/

#ifndef _XRDP_DRV_CNPL_AG_H_
#define _XRDP_DRV_CNPL_AG_H_

#include "access_macros.h"
#include "bdmf_interface.h"
#ifdef USE_BDMF_SHELL
#include "bdmf_shell.h"
#endif
#include "rdp_common.h"


/**************************************************************************************************/
/* cn_double: doublle - 1:each counter of the group is double sub-cntr0:each counter of the group */
/*             is single                                                                          */
/* cn0_byts: cntr0_bytes - number of bytes that will hold each sub-counter.0: 1B1: 2B2: 4B        */
/* ba: base_address - counters group base address (in 8B resolution: 0 is 0x0, 1 is 0x8, ...)     */
/* wrap: wrap - 1:wrap at max value0:freeze at max value                                          */
/* clr: clear - 1:read clear when reading0:read no-clear when reading                             */
/**************************************************************************************************/
typedef struct
{
    bdmf_boolean cn_double;
    uint8_t cn0_byts;
    uint16_t ba;
    bdmf_boolean wrap;
    bdmf_boolean clr;
} cnpl_counter_cfg;


/**************************************************************************************************/
/* bk_ba: bkts_base_address - buckets base address(in 8B resolution: 0 is 0x0, 1 is 0x8, ...)     */
/* pa_ba: params_base_address - params base address(in 8B resolution: 0 is 0x0, 1 is 0x8, ...)    */
/* pl_double: doublle - 1:each policer is dual bucket0:each policer is single bucket              */
/* pl_st: pl_start - Index of 1st policer of the group.                                           */
/* pl_end: pl_end - Index of last policer of the group.                                           */
/**************************************************************************************************/
typedef struct
{
    uint16_t bk_ba;
    uint16_t pa_ba;
    bdmf_boolean pl_double;
    uint8_t pl_st;
    uint8_t pl_end;
} cnpl_policer_cfg;


/**************************************************************************************************/
/* cn_rd_st: cnt_rd_status - 0: DONE (ready)1: PROC(not ready)                                    */
/* pl_plc_st: pl_plc_status - 0: DONE (ready)1: PROC(not ready)                                   */
/* pl_rd_st: pl_rd_status - 0: DONE (ready)1: PROC(not ready)                                     */
/**************************************************************************************************/
typedef struct
{
    bdmf_boolean cn_rd_st;
    bdmf_boolean pl_plc_st;
    bdmf_boolean pl_rd_st;
} cnpl_sw_stat;

bdmf_error_t ag_drv_cnpl_counter_cfg_set(uint32_t cnt_loc_profile, const cnpl_counter_cfg *counter_cfg);
bdmf_error_t ag_drv_cnpl_counter_cfg_get(uint32_t cnt_loc_profile, cnpl_counter_cfg *counter_cfg);
bdmf_error_t ag_drv_cnpl_policer_cfg_set(uint32_t conf_idx, const cnpl_policer_cfg *policer_cfg);
bdmf_error_t ag_drv_cnpl_policer_cfg_get(uint32_t conf_idx, cnpl_policer_cfg *policer_cfg);
bdmf_error_t ag_drv_cnpl_sw_stat_get(cnpl_sw_stat *sw_stat);
bdmf_error_t ag_drv_cnpl_memory_data_set(uint32_t mem_idx, uint32_t data);
bdmf_error_t ag_drv_cnpl_memory_data_get(uint32_t mem_idx, uint32_t *data);
bdmf_error_t ag_drv_cnpl_policers_configurations_pl_calc_type_set(uint32_t conf_idx, uint32_t vec);
bdmf_error_t ag_drv_cnpl_policers_configurations_pl_calc_type_get(uint32_t conf_idx, uint32_t *vec);
bdmf_error_t ag_drv_cnpl_policers_configurations_per_up_set(uint8_t n, bdmf_boolean en);
bdmf_error_t ag_drv_cnpl_policers_configurations_per_up_get(uint8_t *n, bdmf_boolean *en);
bdmf_error_t ag_drv_cnpl_misc_arb_prm_set(uint8_t sw_prio);
bdmf_error_t ag_drv_cnpl_misc_arb_prm_get(uint8_t *sw_prio);
bdmf_error_t ag_drv_cnpl_sw_if_sw_cmd_set(uint32_t val);
bdmf_error_t ag_drv_cnpl_sw_if_sw_cmd_get(uint32_t *val);
bdmf_error_t ag_drv_cnpl_sw_if_sw_pl_rslt_get(uint8_t *col);
bdmf_error_t ag_drv_cnpl_sw_if_sw_pl_rd_get(uint32_t bucket, uint32_t *rd);
bdmf_error_t ag_drv_cnpl_sw_if_sw_cnt_rd_get(uint32_t rd_idx, uint32_t *rd);

#ifdef USE_BDMF_SHELL
enum
{
    cli_cnpl_counter_cfg,
    cli_cnpl_policer_cfg,
    cli_cnpl_sw_stat,
    cli_cnpl_memory_data,
    cli_cnpl_policers_configurations_pl_calc_type,
    cli_cnpl_policers_configurations_per_up,
    cli_cnpl_misc_arb_prm,
    cli_cnpl_sw_if_sw_cmd,
    cli_cnpl_sw_if_sw_pl_rslt,
    cli_cnpl_sw_if_sw_pl_rd,
    cli_cnpl_sw_if_sw_cnt_rd,
};

int bcm_cnpl_cli_get(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms);
bdmfmon_handle_t ag_drv_cnpl_cli_init(bdmfmon_handle_t driver_dir);
#endif


#endif

