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
#ifndef RDPA_PLATFORM_H_
#define RDPA_PLATFORM_H_

#ifdef RDP_SIM
#define INTERRUPT_XRDP_QUEUE_0 0
#else
#include "bcm_OS_Deps.h"
#if !defined(INTERRUPT_ID_FPM) && defined(INTERRUPT_ID_XRDP_FPM)
#define INTERRUPT_ID_FPM INTERRUPT_ID_XRDP_FPM
#endif
#endif

#endif /* RDPA_PLATFORM_H_ */
