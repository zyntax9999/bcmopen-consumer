// <:copyright-BRCM:2013:DUAL/GPL:standard
// 
//    Copyright (c) 2013 Broadcom 
//    All Rights Reserved
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License, version 2, as published by
// the Free Software Foundation (the "GPL").
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// 
// A copy of the GPL is available at http://www.broadcom.com/licenses/GPLv2.php, or by
// writing to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
// Boston, MA 02111-1307, USA.
// 
// :>
/*
 * rdpa user ioctl define header file.
 * This header file is generated automatically. Do not edit!
 */
#ifndef _RDPA_VLAN_USER_IOCTL_H_
#define _RDPA_VLAN_USER_IOCTL_H_

enum
{
	RDPA_VLAN_DRV,
	RDPA_VLAN_GET,
	RDPA_VLAN_NAME_GET,
	RDPA_VLAN_NAME_SET,
	RDPA_VLAN_VID_ENABLE_GET,
	RDPA_VLAN_VID_ENABLE_SET,
	RDPA_VLAN_INGRESS_FILTER_GET,
	RDPA_VLAN_INGRESS_FILTER_SET,
	RDPA_VLAN_INGRESS_FILTER_GET_NEXT,
	RDPA_VLAN_MAC_LOOKUP_CFG_GET,
	RDPA_VLAN_MAC_LOOKUP_CFG_SET,
	RDPA_VLAN_PROTOCOL_FILTERS_GET,
	RDPA_VLAN_PROTOCOL_FILTERS_SET,
	RDPA_VLAN_DISCARD_PRTY_GET,
	RDPA_VLAN_DISCARD_PRTY_SET,
	RDPA_VLAN_OPTIONS_GET,
	RDPA_VLAN_OPTIONS_SET,
	RDPA_VLAN_IS_DEFAULT_GET,
	RDPA_VLAN_IS_DEFAULT_SET,
	RDPA_VLAN_STAT_GET,
	RDPA_VLAN_STAT_SET,
};

#endif /* _RDPA_VLAN_USER_IOCTL_H_ */
