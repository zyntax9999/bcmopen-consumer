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
#ifndef _RDPA_IPTV_USER_IOCTL_H_
#define _RDPA_IPTV_USER_IOCTL_H_

enum
{
	RDPA_IPTV_DRV,
	RDPA_IPTV_GET,
	RDPA_IPTV_LOOKUP_METHOD_GET,
	RDPA_IPTV_LOOKUP_METHOD_SET,
	RDPA_IPTV_MCAST_PREFIX_FILTER_GET,
	RDPA_IPTV_MCAST_PREFIX_FILTER_SET,
	RDPA_IPTV_LOOKUP_MISS_ACTION_GET,
	RDPA_IPTV_LOOKUP_MISS_ACTION_SET,
	RDPA_IPTV_IPTV_STAT_GET,
	RDPA_IPTV_IPTV_STAT_SET,
	RDPA_IPTV_CHANNEL_REQUEST_SET,
	RDPA_IPTV_CHANNEL_REQUEST_ADD,
	RDPA_IPTV_CHANNEL_REQUEST_DELETE,
	RDPA_IPTV_CHANNEL_GET,
	RDPA_IPTV_CHANNEL_GET_NEXT,
	RDPA_IPTV_CHANNEL_FIND,
	RDPA_IPTV_CHANNEL_PM_STATS_GET,
	RDPA_IPTV_CHANNEL_PM_STATS_GET_NEXT,
	RDPA_IPTV_FLUSH_SET,
};

#endif /* _RDPA_IPTV_USER_IOCTL_H_ */
