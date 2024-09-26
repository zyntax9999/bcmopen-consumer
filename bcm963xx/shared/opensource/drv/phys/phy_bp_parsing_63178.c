/*
   Copyright (c) 2015 Broadcom Corporation
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

/*
 *  Created on: Nov 2016
 *      Author: steven.hsieh@broadcom.com
 */

#include "phy_drv.h"
#include "mac_drv.h"
#include "mac_drv_sf2.h"
#include "phy_bp_parsing.h"
#include "boardparms.h"

static bus_type_t bp_parse_bus_type(const EMAC_PORT_INFO *port_info)
{
    return BUS_TYPE_DSL_ETHSW;
}

void bp_parse_phy_driver(const EMAC_PORT_INFO *port_info, phy_drv_t *phy_drv)
{
    bus_type_t bus_type;

    if ((bus_type = bp_parse_bus_type(port_info)) != BUS_TYPE_UNKNOWN)
        phy_drv->bus_drv = bus_drv_get(bus_type);

}

phy_type_t bp_parse_phy_type(const EMAC_PORT_INFO *port_info)
{
    phy_type_t phy_type = PHY_TYPE_UNKNOWN;
    uint32_t phy_id;
    uint32_t intf;

    phy_id = port_info->phy_id;

    intf = phy_id & MAC_IFACE;

    // no phy connection
    if (IsMacToMac(phy_id)) 
        return PHY_TYPE_MAC2MAC;
    if (phy_id == BP_PHY_ID_NOT_SPECIFIED) return PHY_TYPE_UNKNOWN;

    switch (intf)
    {
        case MAC_IF_RGMII_1P8V:
        case MAC_IF_RGMII_3P3V:
        case MAC_IF_INVALID:    /* treat as GMII as default, if not specified */
        case MAC_IF_GMII:
            phy_type = PHY_TYPE_SF2_GPHY;
            break;
    }

    return phy_type;
}

void *bp_parse_phy_priv(const EMAC_PORT_INFO *port_info)
{
    void *priv = 0;

    return priv;
}

mac_type_t bp_parse_mac_type(const ETHERNET_MAC_INFO *emac_info, uint32_t port)
{
    if (port < 9) return MAC_TYPE_SF2;

    return MAC_TYPE_UNKNOWN;
}

void *bp_parse_mac_priv(const ETHERNET_MAC_INFO *emac_info, uint32_t port)
{
    return (void *) 0;
}

void bp_parse_phy_ext(const EMAC_PORT_INFO *port_info, phy_dev_t *phy_dev)
{
    EMAC_PORT_INFO ext_info;
    phy_dev_t *phy_ext_dev;
    
    if (port_info->phy_id_ext > 0)
    {
        memcpy(&ext_info, port_info, sizeof(ext_info));
        ext_info.phy_id = port_info->phy_id_ext;
        ext_info.phy_id_ext = 0;
        if ( (phy_ext_dev = bp_parse_phy_dev(&ext_info)) == NULL)
        {
            printk("Failed to create cascaded phy devices\n");
            return;
        }
        phy_dev->cascade_next = phy_ext_dev;
        phy_ext_dev->cascade_prev = phy_dev;
    }
}

uint32_t bp_parse_phy_addr(const EMAC_PORT_INFO *port_info)
{
    uint32_t meta_id = port_info->phy_id;
    
    // for mac2mac, use port number as address
    if (IsMacToMac(meta_id))
    {
        meta_id &= ~BP_PHY_ID_NOT_SPECIFIED;
        meta_id |= port_info->switch_port;
    }
    return meta_id;
}
