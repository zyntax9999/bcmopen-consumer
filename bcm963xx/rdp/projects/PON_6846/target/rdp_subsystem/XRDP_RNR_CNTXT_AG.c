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

#include "ru.h"

#if RU_INCLUDE_FIELD_DB
/******************************************************************************
 * Field: RNR_CNTXT_MEM_ENTRY_CONTEXT_ENTRY
 ******************************************************************************/
const ru_field_rec RNR_CNTXT_MEM_ENTRY_CONTEXT_ENTRY_FIELD =
{
    "CONTEXT_ENTRY",
#if RU_INCLUDE_DESC
    "Context_mem_entry",
    "Context mem entry",
#endif
    RNR_CNTXT_MEM_ENTRY_CONTEXT_ENTRY_FIELD_MASK,
    0,
    RNR_CNTXT_MEM_ENTRY_CONTEXT_ENTRY_FIELD_WIDTH,
    RNR_CNTXT_MEM_ENTRY_CONTEXT_ENTRY_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

#endif /* RU_INCLUDE_FIELD_DB */

/******************************************************************************
 * Register: RNR_CNTXT_MEM_ENTRY
 ******************************************************************************/
#if RU_INCLUDE_FIELD_DB
static const ru_field_rec *RNR_CNTXT_MEM_ENTRY_FIELDS[] =
{
    &RNR_CNTXT_MEM_ENTRY_CONTEXT_ENTRY_FIELD,
};

#endif /* RU_INCLUDE_FIELD_DB */

const ru_reg_rec RNR_CNTXT_MEM_ENTRY_REG = 
{
    "MEM_ENTRY",
#if RU_INCLUDE_DESC
    "CONTEXT_MEM_ENTRY Register",
    "Context mem entry",
#endif
    RNR_CNTXT_MEM_ENTRY_REG_OFFSET,
    RNR_CNTXT_MEM_ENTRY_REG_RAM_CNT,
    4,
    311,
#if RU_INCLUDE_ACCESS
    ru_access_rw,
#endif
#if RU_INCLUDE_FIELD_DB
    1,
    RNR_CNTXT_MEM_ENTRY_FIELDS
#endif /* RU_INCLUDE_FIELD_DB */
};

/******************************************************************************
 * Block: RNR_CNTXT
 ******************************************************************************/
static const ru_reg_rec *RNR_CNTXT_REGS[] =
{
    &RNR_CNTXT_MEM_ENTRY_REG,
};

unsigned long RNR_CNTXT_ADDRS[] =
{
    0x82c18000,
    0x82c38000,
    0x82c58000,
};

const ru_block_rec RNR_CNTXT_BLOCK = 
{
    "RNR_CNTXT",
    RNR_CNTXT_ADDRS,
    3,
    1,
    RNR_CNTXT_REGS
};

/* End of file XRDP_RNR_CNTXT.c */
