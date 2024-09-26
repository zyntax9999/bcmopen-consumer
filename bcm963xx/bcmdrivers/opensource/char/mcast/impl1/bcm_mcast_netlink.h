/*
*    Copyright (c) 2015 Broadcom Corporation
*    All Rights Reserved
*
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

#ifndef _BCM_MCAST_NETLINK_H_
#define _BCM_MCAST_NETLINK_H_

struct sk_buff *bcm_mcast_netlink_alloc_skb(int len, int proto);
int bcm_mcast_netlink_send_skb(struct sk_buff *skb, int msg_type);
void bcm_mcast_netlink_send_igmp_purge_entry(bcm_mcast_ifdata *pif,
                                             t_igmp_grp_entry *igmp_entry, 
                                             t_igmp_rep_entry *rep_entry);
void bcm_mcast_netlink_send_query_trigger(int rep_ifi);
void bcm_mcast_notify_event(int event, int proto, void *grp_entry, void *rep_entry);

__init int bcm_mcast_netlink_init(void);
void bcm_mcast_netlink_deinit(void);

#endif /* _BCM_MCAST_NETLINK_H_ */