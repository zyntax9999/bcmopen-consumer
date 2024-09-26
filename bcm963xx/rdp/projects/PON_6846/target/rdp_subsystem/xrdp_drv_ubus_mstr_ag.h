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

#ifndef _XRDP_DRV_UBUS_MSTR_AG_H_
#define _XRDP_DRV_UBUS_MSTR_AG_H_

#include "access_macros.h"
#include "bdmf_interface.h"
#ifdef USE_BDMF_SHELL
#include "bdmf_shell.h"
#endif
#include "rdp_common.h"


/**************************************************************************************************/
/* pkt_id: packet_id - ID that can be added to a packet                                           */
/* pkt_tag: packet_tag - enable packet tagging                                                    */
/* endian_mode: endian_mode - endian mode of the requester                                        */
/* repin_eswap: repin_eswap - repin endian swap                                                   */
/* reqout_eswap: reqout_eswap - reqout endian swap                                                */
/* dev_err: dev_error - indicate an error on Ubus                                                 */
/* max_pkt_len: Max_Packet_len - Max packet len that the bridge can support                       */
/**************************************************************************************************/
typedef struct
{
    uint8_t pkt_id;
    bdmf_boolean pkt_tag;
    uint8_t endian_mode;
    bdmf_boolean repin_eswap;
    bdmf_boolean reqout_eswap;
    bdmf_boolean dev_err;
    uint8_t max_pkt_len;
} ubus_mstr_req_cntrl;


/**************************************************************************************************/
/* hp_en: hp_en - enables the hp mechanism                                                        */
/* hp_sel: hp_sel - selects between external control and internal control of the HP bit           */
/* hp_comb: hp_combine - combines both internal and external HP control (OR between them)         */
/* hp_cnt_high: hp_cnt_high - counter will count according to this setting the amount of cycles t */
/*              he HP will be asserted in the internal mech                                       */
/* hp_cnt_total: hp_cnt_total - includes both asserted and deasserted cycles of the HP counter. c */
/*               an control with hp_cnt_high the frequnecy of the HP assertion                    */
/**************************************************************************************************/
typedef struct
{
    bdmf_boolean hp_en;
    bdmf_boolean hp_sel;
    bdmf_boolean hp_comb;
    uint8_t hp_cnt_high;
    uint8_t hp_cnt_total;
} ubus_mstr_hp;

bdmf_error_t ag_drv_ubus_mstr_en_set(uint8_t ubus_mstr_id, bdmf_boolean en);
bdmf_error_t ag_drv_ubus_mstr_en_get(uint8_t ubus_mstr_id, bdmf_boolean *en);
bdmf_error_t ag_drv_ubus_mstr_req_cntrl_set(uint8_t ubus_mstr_id, const ubus_mstr_req_cntrl *req_cntrl);
bdmf_error_t ag_drv_ubus_mstr_req_cntrl_get(uint8_t ubus_mstr_id, ubus_mstr_req_cntrl *req_cntrl);
bdmf_error_t ag_drv_ubus_mstr_hyst_ctrl_set(uint8_t ubus_mstr_id, uint16_t cmd_space, uint16_t data_space);
bdmf_error_t ag_drv_ubus_mstr_hyst_ctrl_get(uint8_t ubus_mstr_id, uint16_t *cmd_space, uint16_t *data_space);
bdmf_error_t ag_drv_ubus_mstr_hp_set(uint8_t ubus_mstr_id, const ubus_mstr_hp *hp);
bdmf_error_t ag_drv_ubus_mstr_hp_get(uint8_t ubus_mstr_id, ubus_mstr_hp *hp);
bdmf_error_t ag_drv_ubus_mstr_reply_add_set(uint8_t ubus_mstr_id, uint32_t add);
bdmf_error_t ag_drv_ubus_mstr_reply_add_get(uint8_t ubus_mstr_id, uint32_t *add);
bdmf_error_t ag_drv_ubus_mstr_reply_data_set(uint8_t ubus_mstr_id, uint32_t data);
bdmf_error_t ag_drv_ubus_mstr_reply_data_get(uint8_t ubus_mstr_id, uint32_t *data);

#ifdef USE_BDMF_SHELL
enum
{
    cli_ubus_mstr_en,
    cli_ubus_mstr_req_cntrl,
    cli_ubus_mstr_hyst_ctrl,
    cli_ubus_mstr_hp,
    cli_ubus_mstr_reply_add,
    cli_ubus_mstr_reply_data,
};

int bcm_ubus_mstr_cli_get(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms);
bdmfmon_handle_t ag_drv_ubus_mstr_cli_init(bdmfmon_handle_t driver_dir);
#endif


#endif

