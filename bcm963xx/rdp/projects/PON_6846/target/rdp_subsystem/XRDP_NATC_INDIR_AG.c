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
 * Field: NATC_INDIR_C_INDIR_ADDR_REG_RESERVED0
 ******************************************************************************/
const ru_field_rec NATC_INDIR_C_INDIR_ADDR_REG_RESERVED0_FIELD =
{
    "RESERVED0",
#if RU_INCLUDE_DESC
    "",
    "",
#endif
    NATC_INDIR_C_INDIR_ADDR_REG_RESERVED0_FIELD_MASK,
    0,
    NATC_INDIR_C_INDIR_ADDR_REG_RESERVED0_FIELD_WIDTH,
    NATC_INDIR_C_INDIR_ADDR_REG_RESERVED0_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

/******************************************************************************
 * Field: NATC_INDIR_C_INDIR_ADDR_REG_W_R
 ******************************************************************************/
const ru_field_rec NATC_INDIR_C_INDIR_ADDR_REG_W_R_FIELD =
{
    "W_R",
#if RU_INCLUDE_DESC
    "",
    "NAT Cache Memory and Statics Memory Transaction."
    "1 : NAT Cache Memory and Statics Memory Write."
    "0 : NAT Cache Memory and Statics Memory Read.",
#endif
    NATC_INDIR_C_INDIR_ADDR_REG_W_R_FIELD_MASK,
    0,
    NATC_INDIR_C_INDIR_ADDR_REG_W_R_FIELD_WIDTH,
    NATC_INDIR_C_INDIR_ADDR_REG_W_R_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

/******************************************************************************
 * Field: NATC_INDIR_C_INDIR_ADDR_REG_NATC_ENTRY
 ******************************************************************************/
const ru_field_rec NATC_INDIR_C_INDIR_ADDR_REG_NATC_ENTRY_FIELD =
{
    "NATC_ENTRY",
#if RU_INCLUDE_DESC
    "",
    "NAT Cache Entry number.",
#endif
    NATC_INDIR_C_INDIR_ADDR_REG_NATC_ENTRY_FIELD_MASK,
    0,
    NATC_INDIR_C_INDIR_ADDR_REG_NATC_ENTRY_FIELD_WIDTH,
    NATC_INDIR_C_INDIR_ADDR_REG_NATC_ENTRY_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

/******************************************************************************
 * Field: NATC_INDIR_C_INDIR_DATA_REG_DATA
 ******************************************************************************/
const ru_field_rec NATC_INDIR_C_INDIR_DATA_REG_DATA_FIELD =
{
    "DATA",
#if RU_INCLUDE_DESC
    "",
    "Indirect register access data register, bits[31:0]."
    "-------------------------------------------------------"
    "For NAT Cache nd Statics Memory write operation,"
    "first, write all the data to Indirect Data Registers[N-1:0],"
    "N is number of words including key, result, hit count and byte count."
    "Indirect Data Register[1:0] are for Statics Memory."
    "Indirect Data register[0] is for hit count and 4 lsb of byte count."
    "Indirect Data register[0] bits 27:0 are 28-bit hit count."
    "Indirect Data register[0] bits 31:28 are 4 lsb of 36-bit byte count."
    "Indirect Data Register[1] is for 32 msb of 36-bit byte count."
    "{Indirect Data Register[1], Indirect Data register[0][31:28]} is the 36-bit byte count."
    "indirect Data register [N-1:2] are for NAT Cache Memory (key and result), key is first,"
    "followed by result, followed by {ddr_miss, nat_ddr_bin, nat_tbl}"
    "then followed by a write to Indirect Address Register to set up"
    "NAT Cache Entry Number and W_R bit to 1, this will initiate the write operation."
    "--------------------------------------------------------"
    "For NAT Cache Memory and statics Memory read operation,"
    "first, write to Indirect Address Register to set up"
    "NAT Cache Entry Number and W_R bit to 0, this will initiate the read operation."
    "the read data from NAT Cache Memory and statics Memory "
    "will be loaded into Indirect Data Registers[N-1:0]."
    "then followed by read from Indirect Data Registers[N-1:0] for all data.",
#endif
    NATC_INDIR_C_INDIR_DATA_REG_DATA_FIELD_MASK,
    0,
    NATC_INDIR_C_INDIR_DATA_REG_DATA_FIELD_WIDTH,
    NATC_INDIR_C_INDIR_DATA_REG_DATA_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

#endif /* RU_INCLUDE_FIELD_DB */

/******************************************************************************
 * Register: NATC_INDIR_C_INDIR_ADDR_REG
 ******************************************************************************/
#if RU_INCLUDE_FIELD_DB
static const ru_field_rec *NATC_INDIR_C_INDIR_ADDR_REG_FIELDS[] =
{
    &NATC_INDIR_C_INDIR_ADDR_REG_RESERVED0_FIELD,
    &NATC_INDIR_C_INDIR_ADDR_REG_W_R_FIELD,
    &NATC_INDIR_C_INDIR_ADDR_REG_NATC_ENTRY_FIELD,
};

#endif /* RU_INCLUDE_FIELD_DB */

const ru_reg_rec NATC_INDIR_C_INDIR_ADDR_REG_REG = 
{
    "C_INDIR_ADDR_REG",
#if RU_INCLUDE_DESC
    "NATC Indirect Address Register",
    "",
#endif
    NATC_INDIR_C_INDIR_ADDR_REG_REG_OFFSET,
    0,
    0,
    1114,
#if RU_INCLUDE_ACCESS
    ru_access_rw,
#endif
#if RU_INCLUDE_FIELD_DB
    3,
    NATC_INDIR_C_INDIR_ADDR_REG_FIELDS
#endif /* RU_INCLUDE_FIELD_DB */
};

/******************************************************************************
 * Register: NATC_INDIR_C_INDIR_DATA_REG
 ******************************************************************************/
#if RU_INCLUDE_FIELD_DB
static const ru_field_rec *NATC_INDIR_C_INDIR_DATA_REG_FIELDS[] =
{
    &NATC_INDIR_C_INDIR_DATA_REG_DATA_FIELD,
};

#endif /* RU_INCLUDE_FIELD_DB */

const ru_reg_rec NATC_INDIR_C_INDIR_DATA_REG_REG = 
{
    "C_INDIR_DATA_REG",
#if RU_INCLUDE_DESC
    "MATC Indirect Data Register",
    "",
#endif
    NATC_INDIR_C_INDIR_DATA_REG_REG_OFFSET,
    NATC_INDIR_C_INDIR_DATA_REG_REG_RAM_CNT,
    4,
    1115,
#if RU_INCLUDE_ACCESS
    ru_access_rw,
#endif
#if RU_INCLUDE_FIELD_DB
    1,
    NATC_INDIR_C_INDIR_DATA_REG_FIELDS
#endif /* RU_INCLUDE_FIELD_DB */
};

/******************************************************************************
 * Block: NATC_INDIR
 ******************************************************************************/
static const ru_reg_rec *NATC_INDIR_REGS[] =
{
    &NATC_INDIR_C_INDIR_ADDR_REG_REG,
    &NATC_INDIR_C_INDIR_DATA_REG_REG,
};

unsigned long NATC_INDIR_ADDRS[] =
{
    0x82e50400,
};

const ru_block_rec NATC_INDIR_BLOCK = 
{
    "NATC_INDIR",
    NATC_INDIR_ADDRS,
    1,
    2,
    NATC_INDIR_REGS
};

/* End of file XRDP_NATC_INDIR.c */
