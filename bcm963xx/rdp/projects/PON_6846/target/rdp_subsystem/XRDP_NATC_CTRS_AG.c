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
 * Field: NATC_CTRS_CACHE_HIT_COUNT_CACHE_HIT_COUNT
 ******************************************************************************/
const ru_field_rec NATC_CTRS_CACHE_HIT_COUNT_CACHE_HIT_COUNT_FIELD =
{
    "CACHE_HIT_COUNT",
#if RU_INCLUDE_DESC
    "",
    "32-bit total cache hit count value for statistics collection",
#endif
    NATC_CTRS_CACHE_HIT_COUNT_CACHE_HIT_COUNT_FIELD_MASK,
    0,
    NATC_CTRS_CACHE_HIT_COUNT_CACHE_HIT_COUNT_FIELD_WIDTH,
    NATC_CTRS_CACHE_HIT_COUNT_CACHE_HIT_COUNT_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

/******************************************************************************
 * Field: NATC_CTRS_CACHE_MISS_COUNT_CACHE_MISS_COUNT
 ******************************************************************************/
const ru_field_rec NATC_CTRS_CACHE_MISS_COUNT_CACHE_MISS_COUNT_FIELD =
{
    "CACHE_MISS_COUNT",
#if RU_INCLUDE_DESC
    "",
    "32-bit total cache miss count value for statistics collection",
#endif
    NATC_CTRS_CACHE_MISS_COUNT_CACHE_MISS_COUNT_FIELD_MASK,
    0,
    NATC_CTRS_CACHE_MISS_COUNT_CACHE_MISS_COUNT_FIELD_WIDTH,
    NATC_CTRS_CACHE_MISS_COUNT_CACHE_MISS_COUNT_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

/******************************************************************************
 * Field: NATC_CTRS_DDR_REQUEST_COUNT_DDR_REQUEST_COUNT
 ******************************************************************************/
const ru_field_rec NATC_CTRS_DDR_REQUEST_COUNT_DDR_REQUEST_COUNT_FIELD =
{
    "DDR_REQUEST_COUNT",
#if RU_INCLUDE_DESC
    "",
    "32-bit total DDR request count value for statistics collection",
#endif
    NATC_CTRS_DDR_REQUEST_COUNT_DDR_REQUEST_COUNT_FIELD_MASK,
    0,
    NATC_CTRS_DDR_REQUEST_COUNT_DDR_REQUEST_COUNT_FIELD_WIDTH,
    NATC_CTRS_DDR_REQUEST_COUNT_DDR_REQUEST_COUNT_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

/******************************************************************************
 * Field: NATC_CTRS_DDR_EVICT_COUNT_DDR_EVICT_COUNT
 ******************************************************************************/
const ru_field_rec NATC_CTRS_DDR_EVICT_COUNT_DDR_EVICT_COUNT_FIELD =
{
    "DDR_EVICT_COUNT",
#if RU_INCLUDE_DESC
    "",
    "32-bit total DDR evict count value for statistics collection",
#endif
    NATC_CTRS_DDR_EVICT_COUNT_DDR_EVICT_COUNT_FIELD_MASK,
    0,
    NATC_CTRS_DDR_EVICT_COUNT_DDR_EVICT_COUNT_FIELD_WIDTH,
    NATC_CTRS_DDR_EVICT_COUNT_DDR_EVICT_COUNT_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

/******************************************************************************
 * Field: NATC_CTRS_DDR_BLOCK_COUNT_DDR_BLOCK_COUNT
 ******************************************************************************/
const ru_field_rec NATC_CTRS_DDR_BLOCK_COUNT_DDR_BLOCK_COUNT_FIELD =
{
    "DDR_BLOCK_COUNT",
#if RU_INCLUDE_DESC
    "",
    "32-bit total DDR blocked access count value for statistics collection",
#endif
    NATC_CTRS_DDR_BLOCK_COUNT_DDR_BLOCK_COUNT_FIELD_MASK,
    0,
    NATC_CTRS_DDR_BLOCK_COUNT_DDR_BLOCK_COUNT_FIELD_WIDTH,
    NATC_CTRS_DDR_BLOCK_COUNT_DDR_BLOCK_COUNT_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

#endif /* RU_INCLUDE_FIELD_DB */

/******************************************************************************
 * Register: NATC_CTRS_CACHE_HIT_COUNT
 ******************************************************************************/
#if RU_INCLUDE_FIELD_DB
static const ru_field_rec *NATC_CTRS_CACHE_HIT_COUNT_FIELDS[] =
{
    &NATC_CTRS_CACHE_HIT_COUNT_CACHE_HIT_COUNT_FIELD,
};

#endif /* RU_INCLUDE_FIELD_DB */

const ru_reg_rec NATC_CTRS_CACHE_HIT_COUNT_REG = 
{
    "CACHE_HIT_COUNT",
#if RU_INCLUDE_DESC
    "NAT table 7 NAT Cache Hit Count",
    "NATC CACHE HIT COUNT",
#endif
    NATC_CTRS_CACHE_HIT_COUNT_REG_OFFSET,
    0,
    0,
    1101,
#if RU_INCLUDE_ACCESS
    ru_access_rw,
#endif
#if RU_INCLUDE_FIELD_DB
    1,
    NATC_CTRS_CACHE_HIT_COUNT_FIELDS
#endif /* RU_INCLUDE_FIELD_DB */
};

/******************************************************************************
 * Register: NATC_CTRS_CACHE_MISS_COUNT
 ******************************************************************************/
#if RU_INCLUDE_FIELD_DB
static const ru_field_rec *NATC_CTRS_CACHE_MISS_COUNT_FIELDS[] =
{
    &NATC_CTRS_CACHE_MISS_COUNT_CACHE_MISS_COUNT_FIELD,
};

#endif /* RU_INCLUDE_FIELD_DB */

const ru_reg_rec NATC_CTRS_CACHE_MISS_COUNT_REG = 
{
    "CACHE_MISS_COUNT",
#if RU_INCLUDE_DESC
    "NAT table 7 NAT Cache Miss Count",
    "NATC CACHE MISS COUNT",
#endif
    NATC_CTRS_CACHE_MISS_COUNT_REG_OFFSET,
    0,
    0,
    1102,
#if RU_INCLUDE_ACCESS
    ru_access_rw,
#endif
#if RU_INCLUDE_FIELD_DB
    1,
    NATC_CTRS_CACHE_MISS_COUNT_FIELDS
#endif /* RU_INCLUDE_FIELD_DB */
};

/******************************************************************************
 * Register: NATC_CTRS_DDR_REQUEST_COUNT
 ******************************************************************************/
#if RU_INCLUDE_FIELD_DB
static const ru_field_rec *NATC_CTRS_DDR_REQUEST_COUNT_FIELDS[] =
{
    &NATC_CTRS_DDR_REQUEST_COUNT_DDR_REQUEST_COUNT_FIELD,
};

#endif /* RU_INCLUDE_FIELD_DB */

const ru_reg_rec NATC_CTRS_DDR_REQUEST_COUNT_REG = 
{
    "DDR_REQUEST_COUNT",
#if RU_INCLUDE_DESC
    "NAT table 7 NAT DDR Request Count",
    "NATC DDR REQUEST COUNT",
#endif
    NATC_CTRS_DDR_REQUEST_COUNT_REG_OFFSET,
    0,
    0,
    1103,
#if RU_INCLUDE_ACCESS
    ru_access_rw,
#endif
#if RU_INCLUDE_FIELD_DB
    1,
    NATC_CTRS_DDR_REQUEST_COUNT_FIELDS
#endif /* RU_INCLUDE_FIELD_DB */
};

/******************************************************************************
 * Register: NATC_CTRS_DDR_EVICT_COUNT
 ******************************************************************************/
#if RU_INCLUDE_FIELD_DB
static const ru_field_rec *NATC_CTRS_DDR_EVICT_COUNT_FIELDS[] =
{
    &NATC_CTRS_DDR_EVICT_COUNT_DDR_EVICT_COUNT_FIELD,
};

#endif /* RU_INCLUDE_FIELD_DB */

const ru_reg_rec NATC_CTRS_DDR_EVICT_COUNT_REG = 
{
    "DDR_EVICT_COUNT",
#if RU_INCLUDE_DESC
    "NAT table 7 NAT DDR Evict Count",
    "NATC DDR EVICT COUNT",
#endif
    NATC_CTRS_DDR_EVICT_COUNT_REG_OFFSET,
    0,
    0,
    1104,
#if RU_INCLUDE_ACCESS
    ru_access_rw,
#endif
#if RU_INCLUDE_FIELD_DB
    1,
    NATC_CTRS_DDR_EVICT_COUNT_FIELDS
#endif /* RU_INCLUDE_FIELD_DB */
};

/******************************************************************************
 * Register: NATC_CTRS_DDR_BLOCK_COUNT
 ******************************************************************************/
#if RU_INCLUDE_FIELD_DB
static const ru_field_rec *NATC_CTRS_DDR_BLOCK_COUNT_FIELDS[] =
{
    &NATC_CTRS_DDR_BLOCK_COUNT_DDR_BLOCK_COUNT_FIELD,
};

#endif /* RU_INCLUDE_FIELD_DB */

const ru_reg_rec NATC_CTRS_DDR_BLOCK_COUNT_REG = 
{
    "DDR_BLOCK_COUNT",
#if RU_INCLUDE_DESC
    "NAT table 7 NAT DDR Block Count",
    "DDR BLOCK COUNT",
#endif
    NATC_CTRS_DDR_BLOCK_COUNT_REG_OFFSET,
    0,
    0,
    1105,
#if RU_INCLUDE_ACCESS
    ru_access_rw,
#endif
#if RU_INCLUDE_FIELD_DB
    1,
    NATC_CTRS_DDR_BLOCK_COUNT_FIELDS
#endif /* RU_INCLUDE_FIELD_DB */
};

/******************************************************************************
 * Block: NATC_CTRS
 ******************************************************************************/
static const ru_reg_rec *NATC_CTRS_REGS[] =
{
    &NATC_CTRS_CACHE_HIT_COUNT_REG,
    &NATC_CTRS_CACHE_MISS_COUNT_REG,
    &NATC_CTRS_DDR_REQUEST_COUNT_REG,
    &NATC_CTRS_DDR_EVICT_COUNT_REG,
    &NATC_CTRS_DDR_BLOCK_COUNT_REG,
};

unsigned long NATC_CTRS_ADDRS[] =
{
    0x82e50310,
    0x82e50324,
    0x82e50338,
    0x82e5034c,
    0x82e50360,
    0x82e50374,
    0x82e50388,
    0x82e5039c,
};

const ru_block_rec NATC_CTRS_BLOCK = 
{
    "NATC_CTRS",
    NATC_CTRS_ADDRS,
    8,
    5,
    NATC_CTRS_REGS
};

/* End of file XRDP_NATC_CTRS.c */
