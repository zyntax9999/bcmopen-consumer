/*
    <:copyright-BRCM:2013-2016:DUAL/GPL:standard
    
       Copyright (c) 2013-2016 Broadcom 
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

#ifndef _RDP_CPU_SIM_H_
#define _RDP_CPU_SIM_H_

#ifdef RDP_SIM
#include <stdio.h>
#include "rdpa_types.h"
#include "rdd_defs.h"
#include "bdmf_session.h"
#include "bdmf_shell.h"
#include "rdp_cpu_sim_if_auto.h"

extern FILE *g_cpu_rx_file;
extern bdmf_session_handle g_cpu_rx_file_session;

void cpu_runner_sim_send_data(uint32_t length, char *buffer);
uint32_t cpu_runner_sim_receive_data(char *buffer);
uint32_t cpu_runner_sim_get_msg_length(sw2hw_msg *msg);
int cpu_runner_sim_connect(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms);
void rdp_cpu_qm_req(uint32_t *cpu_tx_descriptor, uint16_t qm_queue_num);
int rdp_cpu_fpm_alloc(uint32_t packet_len, uint32_t *buff_num);
void rdp_cpu_fpm_free(uint32_t buffer_num);
void rdp_cpu_runner_wakeup(uint32_t runner_id, uint32_t task_id);
int rdp_cpu_counter_read(uint32_t group_id, uint32_t start_counter, uint32_t* cntr_arr, uint32_t num_of_counters, bdmf_boolean* cntr_double, uint8_t* cn0_bytes);
int cpu_sim_rx_file_write(bdmf_session_handle session, const char *buf, uint32_t size);
#endif
#endif
