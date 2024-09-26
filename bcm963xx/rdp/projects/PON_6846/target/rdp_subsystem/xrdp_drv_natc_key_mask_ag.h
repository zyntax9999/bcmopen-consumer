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

#ifndef _XRDP_DRV_NATC_KEY_MASK_AG_H_
#define _XRDP_DRV_NATC_KEY_MASK_AG_H_

#include "access_macros.h"
#include "bdmf_interface.h"
#ifdef USE_BDMF_SHELL
#include "bdmf_shell.h"
#endif
#include "rdp_common.h"

bdmf_error_t ag_drv_natc_key_mask_tbl_key_mask_set(uint8_t tbl_idx, uint32_t key_mask);
bdmf_error_t ag_drv_natc_key_mask_tbl_key_mask_get(uint8_t tbl_idx, uint32_t *key_mask);

#ifdef USE_BDMF_SHELL
enum
{
    cli_natc_key_mask_tbl_key_mask,
};

int bcm_natc_key_mask_cli_get(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms);
bdmfmon_handle_t ag_drv_natc_key_mask_cli_init(bdmfmon_handle_t driver_dir);
#endif


#endif

