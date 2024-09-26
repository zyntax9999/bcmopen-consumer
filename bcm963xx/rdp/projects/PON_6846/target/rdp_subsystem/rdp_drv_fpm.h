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

#ifndef DRV_FPM_H_INCLUDED
#define DRV_FPM_H_INCLUDED

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/*                                                                           */
/* Include files                                                             */
/*                                                                           */
/*****************************************************************************/
#include "xrdp_drv_fpm_ag.h"

/* default values for FPM */
#define FPM_POOL_BASE_ADDRESS               0
#define FPM_CLEAR_IRQ_STATUS                0xffffffff
#define FPM_DDR_0_POOL_ID                   0
#define FPM_ALLOC_WEIGHT                    1
#define FPM_FREE_WEIGHT                     1
#define FPM_POLL_SLEEP_TIME                 200

#if  defined (XRDP_EMULATION)  || !defined (RDP_SIM)
#define FPM_INIT_TIMEOUT                    0xf000
#else
#define FPM_INIT_TIMEOUT                    0
#endif

#define FPM_INTERRUPT_STATUS                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
#define FPM_INTERRUPT_MASK                  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0}
#define FPM_INTERRUPT_MASK_OFF              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define FPM_INTERRUPT_TIMER_DELAY           1000  /* msec */

#define FPM_BUF_SIZE_0                      512
#define FPM_BUF_SIZE_1                      256
#define FPM_BUF_SIZE_DEFAULT                FPM_BUF_SIZE_0

#define FPM_BUF_SIZE_256                    FPM_BUF_SIZE_1
#define FPM_BUF_SIZE_512                    FPM_BUF_SIZE_0
#define FPM_BUF_SIZE_1K                     1024
#define FPM_BUF_SIZE_2K                     2048
#define FPM_BUF_MAX_BASE_BUFFS              8
#define TOTAL_FPM_TOKENS                    (64*1024)

/* All following definitions must be 100*k since they are percent-wise divided */
#define TOTAL_DYNAMIC_FPM                   61000           /* ( 2 (FPM per DQM) * ( 287 (no. of queues) + 16 (prefetch) ) + 
                                                               ( 64K (maximal number of PDs in Queue) / (2K / 16) number of PDs in FPM) ) * 4(2K allocation )
                                                               = 4472 FPMs (basic size of 512). Worst case DQM FPM allocation.  */

#define FPM_XON_THRESHOLD                   (TOTAL_FPM_TOKENS - TOTAL_DYNAMIC_FPM)
#define FPM_XOFF_THRESHOLD                  (7*FPM_XON_THRESHOLD/8)
#define FPM_EXTRA_TOKENS_FOR_DQM            (4 * 1024)


void drv_fpm_init(void *virt_base, unsigned int fpm_buf_size);

bdmf_error_t drv_fpm_alloc_buffer(uint32_t packet_len, uint32_t *buff_num);
bdmf_error_t drv_fpm_free_buffer(uint32_t packet_len, uint32_t buff_num);
void drv_fpm_copy_from_host_buffer(void *data, uint32_t fpm_bn, uint32_t packet_len, uint16_t offset);
void *drv_fpm_buffer_get_address(uint32_t fpm_bn);

#ifdef USE_BDMF_SHELL
int drv_fpm_cli_debug_get(bdmf_session_handle session, bdmfmon_cmd_parm_t parm[], uint16_t n_parms);
int drv_fpm_cli_sanity_check(bdmf_session_handle session, bdmfmon_cmd_parm_t parm[], uint16_t n_parms);
int drv_fpm_cli_config_get(bdmf_session_handle session, bdmfmon_cmd_parm_t parm[], uint16_t n_parms);
void drv_fpm_cli_init(bdmfmon_handle_t driver_dir);
void drv_fpm_cli_exit(bdmfmon_handle_t driver_dir);
#endif

#ifdef __cplusplus
}
#endif

#endif
