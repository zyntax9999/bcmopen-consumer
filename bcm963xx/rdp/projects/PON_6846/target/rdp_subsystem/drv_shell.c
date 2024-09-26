/*
   <:copyright-BRCM:2015:DUAL/GPL:standard
   
      Copyright (c) 2015 Broadcom 
      All Rights Reserved
   
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

#ifdef USE_BDMF_SHELL

#include "drv_shell.h"
#include "rdp_common.h"
#include "rdp_drv_bbh_rx.h"
#include "rdp_drv_bbh_tx.h"
#include "rdp_drv_dma.h"
#include "rdp_drv_sbpm.h"
#include "xrdp_drv_psram_ag.h"
#if !defined(BCM63158)
#include "xrdp_drv_psram_mem_ag.h"
#endif
#include "rdp_drv_fpm.h"
#include "rdp_drv_qm.h"
#include "rdp_drv_dqm.h"
#include "rdp_drv_rnr.h"
#include "rdp_drv_cnpl.h"
#include "rdp_drv_tcam.h"
#include "rdp_drv_natc.h"
#include "rdp_drv_dis_reor.h"
#include "rdp_drv_hash.h"
#include "rdp_drv_system.h"

void drv_cli_init(bdmfmon_handle_t driver_dir)
{
    ru_cli_init(driver_dir);
    drv_bbh_rx_cli_init(driver_dir);
    drv_bbh_tx_cli_init(driver_dir);
    drv_dma_cli_init(driver_dir);
    drv_sbpm_cli_init(driver_dir);
    drv_cnpl_cli_init(driver_dir);
    ag_drv_psram_cli_init(driver_dir);
#if !defined(BCM63158)
    ag_drv_psram_mem_cli_init(driver_dir);
#endif
    drv_fpm_cli_init(driver_dir);
    drv_qm_cli_init(driver_dir);
    drv_dqm_cli_init(driver_dir);
    drv_rnr_cli_init(driver_dir);
    drv_tcam_cli_init(driver_dir);
    drv_dis_reor_cli_init(driver_dir);
    drv_natc_cli_init(driver_dir);
    drv_system_cli_init(driver_dir);
    drv_hash_cli_init(driver_dir);
}

void drv_cli_exit(bdmfmon_handle_t driver_dir)
{
    ru_cli_exit(driver_dir);
    drv_bbh_rx_cli_exit(driver_dir);
    drv_bbh_tx_cli_exit(driver_dir);
    drv_dma_cli_exit(driver_dir);
    drv_sbpm_cli_exit(driver_dir);
    drv_cnpl_cli_exit(driver_dir);
    drv_qm_cli_exit(driver_dir);
    drv_dqm_cli_exit(driver_dir);
    drv_rnr_cli_exit(driver_dir);
    drv_tcam_cli_exit(driver_dir);
    drv_dis_reor_cli_exit(driver_dir);
    drv_fpm_cli_exit(driver_dir);
    drv_system_cli_exit();
    drv_hash_cli_exit(driver_dir);
}

#endif

