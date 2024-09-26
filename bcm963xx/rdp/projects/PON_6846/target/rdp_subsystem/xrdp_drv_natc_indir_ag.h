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

#ifndef _XRDP_DRV_NATC_INDIR_AG_H_
#define _XRDP_DRV_NATC_INDIR_AG_H_

#include "access_macros.h"
#include "bdmf_interface.h"
#ifdef USE_BDMF_SHELL
#include "bdmf_shell.h"
#endif
#include "rdp_common.h"


/**************************************************************************************************/
/* data:  - Indirect register access data register, bits[31:0].---------------------------------- */
/*       ---------------------For NAT Cache nd Statics Memory write operation,first, write all th */
/*       e data to Indirect Data Registers[N-1:0],N is number of words including key, result, hit */
/*        count and byte count.Indirect Data Register[1:0] are for Statics Memory.Indirect Data r */
/*       egister[0] is for hit count and 4 lsb of byte count.Indirect Data register[0] bits 27:0  */
/*       are 28-bit hit count.Indirect Data register[0] bits 31:28 are 4 lsb of 36-bit byte count */
/*       .Indirect Data Register[1] is for 32 msb of 36-bit byte count.{Indirect Data Register[1] */
/*       , Indirect Data register[0][31:28]} is the 36-bit byte count.indirect Data register [N-1 */
/*       :2] are for NAT Cache Memory (key and result), key is first,followed by result, followed */
/*        by {ddr_miss, nat_ddr_bin, nat_tbl}then followed by a write to Indirect Address Registe */
/*       r to set upNAT Cache Entry Number and W_R bit to 1, this will initiate the write operati */
/*       on.--------------------------------------------------------For NAT Cache Memory and stat */
/*       ics Memory read operation,first, write to Indirect Address Register to set upNAT Cache E */
/*       ntry Number and W_R bit to 0, this will initiate the read operation.the read data from N */
/*       AT Cache Memory and statics Memory will be loaded into Indirect Data Registers[N-1:0].th */
/*       en followed by read from Indirect Data Registers[N-1:0] for all data.                    */
/**************************************************************************************************/
typedef struct
{
    uint32_t data[21];
} natc_indir_data;

bdmf_error_t ag_drv_natc_indir_addr_set(bdmf_boolean w_r, uint16_t natc_entry);
bdmf_error_t ag_drv_natc_indir_addr_get(bdmf_boolean *w_r, uint16_t *natc_entry);
bdmf_error_t ag_drv_natc_indir_data_set(uint8_t zero, const natc_indir_data *data);
bdmf_error_t ag_drv_natc_indir_data_get(uint8_t zero, natc_indir_data *data);

#ifdef USE_BDMF_SHELL
enum
{
    cli_natc_indir_addr,
    cli_natc_indir_data,
};

int bcm_natc_indir_cli_get(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms);
bdmfmon_handle_t ag_drv_natc_indir_cli_init(bdmfmon_handle_t driver_dir);
#endif


#endif

