/*
   Copyright (c) 2014 Broadcom
   All Rights Reserved

    <:label-BRCM:2014:DUAL/GPL:standard
    
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

#ifndef _DATA_PATH_INIT_BASIC_
#define _DATA_PATH_INIT_BASIC_

#ifdef __cplusplus 
extern "C" {
#endif

#ifndef XRDP
#define XRDP
#endif

#define BBH_TX_COMMON_CONFIGURATION_DDRMBASEL_BASE_ADDRESS 0x82d9002c

/* includes */
#include "bdmf_data_types.h"
#include "rdp_common.h"

/* functions */
int data_path_init(dpi_params_t *dpi_params);
int data_path_init_basic(dpi_params_t *dpi_params);
void data_path_init_basic_update_fpm(dpi_params_t *dpi_params);

#ifdef __cplusplus 
}
#endif
#endif

