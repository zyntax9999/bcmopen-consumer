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

#ifndef _XRDP_DRV_TCAM_AG_H_
#define _XRDP_DRV_TCAM_AG_H_

#include "access_macros.h"
#include "bdmf_interface.h"
#ifdef USE_BDMF_SHELL
#include "bdmf_shell.h"
#endif
#include "rdp_common.h"

bdmf_error_t ag_drv_tcam_counters_get(uint32_t *srch_256, uint32_t *hit_256, uint32_t *srch_512, uint32_t *hit_512);
bdmf_error_t ag_drv_tcam_context_set(uint16_t ctx_idx, uint32_t data);
bdmf_error_t ag_drv_tcam_context_get(uint16_t ctx_idx, uint32_t *data);
bdmf_error_t ag_drv_tcam_bank_enable_set(uint8_t value);
bdmf_error_t ag_drv_tcam_bank_enable_get(uint8_t *value);
bdmf_error_t ag_drv_tcam_global_mask_set(uint8_t word_idx, uint32_t value);
bdmf_error_t ag_drv_tcam_global_mask_get(uint8_t word_idx, uint32_t *value);
bdmf_error_t ag_drv_tcam_op_set(uint8_t cmd);
bdmf_error_t ag_drv_tcam_op_get(uint8_t *cmd);
bdmf_error_t ag_drv_tcam_op_done_get(bdmf_boolean *done);
bdmf_error_t ag_drv_tcam_address_set(bdmf_boolean key1_ind, uint16_t entry_addr);
bdmf_error_t ag_drv_tcam_address_get(bdmf_boolean *key1_ind, uint16_t *entry_addr);
bdmf_error_t ag_drv_tcam_valid_in_set(bdmf_boolean valid);
bdmf_error_t ag_drv_tcam_valid_in_get(bdmf_boolean *valid);
bdmf_error_t ag_drv_tcam_valid_out_set(bdmf_boolean valid);
bdmf_error_t ag_drv_tcam_valid_out_get(bdmf_boolean *valid);
bdmf_error_t ag_drv_tcam_result_get(bdmf_boolean *match, uint16_t *index);
bdmf_error_t ag_drv_tcam_key_in_set(uint8_t word_idx, uint32_t value);
bdmf_error_t ag_drv_tcam_key_in_get(uint8_t word_idx, uint32_t *value);
bdmf_error_t ag_drv_tcam_key_out_get(uint8_t word_idx, uint32_t *value);
bdmf_error_t ag_drv_tcam_debug_bus_tcam_debug_bus_select_set(uint8_t select_module);
bdmf_error_t ag_drv_tcam_debug_bus_tcam_debug_bus_select_get(uint8_t *select_module);

#ifdef USE_BDMF_SHELL
enum
{
    cli_tcam_counters,
    cli_tcam_context,
    cli_tcam_bank_enable,
    cli_tcam_global_mask,
    cli_tcam_op,
    cli_tcam_op_done,
    cli_tcam_address,
    cli_tcam_valid_in,
    cli_tcam_valid_out,
    cli_tcam_result,
    cli_tcam_key_in,
    cli_tcam_key_out,
    cli_tcam_debug_bus_tcam_debug_bus_select,
};

int bcm_tcam_cli_get(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms);
bdmfmon_handle_t ag_drv_tcam_cli_init(bdmfmon_handle_t driver_dir);
#endif


#endif

