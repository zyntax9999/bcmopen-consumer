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

#ifndef _XRDP_DRV_DQM_AG_H_
#define _XRDP_DRV_DQM_AG_H_

#include "access_macros.h"
#include "bdmf_interface.h"
#ifdef USE_BDMF_SHELL
#include "bdmf_shell.h"
#endif
#include "rdp_common.h"

bdmf_error_t ag_drv_dqm_max_entries_words_set(uint32_t max);
bdmf_error_t ag_drv_dqm_max_entries_words_get(uint32_t *max);
bdmf_error_t ag_drv_dqm_fpm_addr_set(uint32_t fpmaddress);
bdmf_error_t ag_drv_dqm_fpm_addr_get(uint32_t *fpmaddress);
bdmf_error_t ag_drv_dqm_buf_size_set(uint8_t pool_0_size);
bdmf_error_t ag_drv_dqm_buf_size_get(uint8_t *pool_0_size);
bdmf_error_t ag_drv_dqm_buf_base_set(uint32_t base);
bdmf_error_t ag_drv_dqm_buf_base_get(uint32_t *base);
bdmf_error_t ag_drv_dqm_tokens_used_set(uint32_t count);
bdmf_error_t ag_drv_dqm_tokens_used_get(uint32_t *count);
bdmf_error_t ag_drv_dqm_num_pushed_set(uint32_t count);
bdmf_error_t ag_drv_dqm_num_pushed_get(uint32_t *count);
bdmf_error_t ag_drv_dqm_num_popped_set(uint32_t count);
bdmf_error_t ag_drv_dqm_num_popped_get(uint32_t *count);
bdmf_error_t ag_drv_dqm_diag_sel_set(uint8_t sel);
bdmf_error_t ag_drv_dqm_diag_sel_get(uint8_t *sel);
bdmf_error_t ag_drv_dqm_diag_data_get(uint32_t *data);
bdmf_error_t ag_drv_dqm_irq_tst_set(bdmf_boolean pushfullqtst, bdmf_boolean popemptyqtst);
bdmf_error_t ag_drv_dqm_irq_tst_get(bdmf_boolean *pushfullqtst, bdmf_boolean *popemptyqtst);
bdmf_error_t ag_drv_dqm_token_fifo_status_get(bdmf_boolean *full, bdmf_boolean *empty, uint8_t *level, uint8_t *rd_loc);
bdmf_error_t ag_drv_dqm_num_popped_no_commit_set(uint32_t count);
bdmf_error_t ag_drv_dqm_num_popped_no_commit_get(uint32_t *count);
bdmf_error_t ag_drv_dqm_head_ptr_get(uint16_t queue_idx, uint32_t *q_head_ptr);
bdmf_error_t ag_drv_dqm_tail_ptr_get(uint16_t queue_idx, uint32_t *q_tail_ptr);
bdmf_error_t ag_drv_dqm_dqmol_size_get(uint16_t queue_idx, uint32_t *max_entries, bdmf_boolean *q_disable_offload, uint8_t *q_tkn_size);
bdmf_error_t ag_drv_dqm_dqmol_cfga_get(uint16_t queue_idx, uint16_t *q_size, uint16_t *q_start_addr);
bdmf_error_t ag_drv_dqm_dqmol_cfgb_set(uint16_t queue_idx, bdmf_boolean enable);
bdmf_error_t ag_drv_dqm_dqmol_cfgb_get(uint16_t queue_idx, bdmf_boolean *enable);
bdmf_error_t ag_drv_dqm_dqmol_pushtoken_set(uint16_t queue_idx, uint32_t token);
bdmf_error_t ag_drv_dqm_dqmol_pushtoken_get(uint16_t queue_idx, uint32_t *token);
bdmf_error_t ag_drv_dqm_dqmol_pushtokennext_set(uint16_t queue_idx, uint32_t token);
bdmf_error_t ag_drv_dqm_dqmol_pushtokennext_get(uint16_t queue_idx, uint32_t *token);
bdmf_error_t ag_drv_dqm_dqmol_poptoken_set(uint16_t queue_idx, uint32_t token);
bdmf_error_t ag_drv_dqm_dqmol_poptoken_get(uint16_t queue_idx, uint32_t *token);
bdmf_error_t ag_drv_dqm_dqmol_poptokennext_set(uint16_t queue_idx, uint32_t token);
bdmf_error_t ag_drv_dqm_dqmol_poptokennext_get(uint16_t queue_idx, uint32_t *token);

#ifdef USE_BDMF_SHELL
enum
{
    cli_dqm_max_entries_words,
    cli_dqm_fpm_addr,
    cli_dqm_buf_size,
    cli_dqm_buf_base,
    cli_dqm_tokens_used,
    cli_dqm_num_pushed,
    cli_dqm_num_popped,
    cli_dqm_diag_sel,
    cli_dqm_diag_data,
    cli_dqm_irq_tst,
    cli_dqm_token_fifo_status,
    cli_dqm_num_popped_no_commit,
    cli_dqm_head_ptr,
    cli_dqm_tail_ptr,
    cli_dqm_dqmol_size,
    cli_dqm_dqmol_cfga,
    cli_dqm_dqmol_cfgb,
    cli_dqm_dqmol_pushtoken,
    cli_dqm_dqmol_pushtokennext,
    cli_dqm_dqmol_poptoken,
    cli_dqm_dqmol_poptokennext,
};

int bcm_dqm_cli_get(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms);
bdmfmon_handle_t ag_drv_dqm_cli_init(bdmfmon_handle_t driver_dir);
#endif


#endif

