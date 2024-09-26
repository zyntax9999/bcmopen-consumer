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
 * dscp_to_pbit object ioctl functions implementation file.
 * This ioctl file is generated automatically. Do not edit!
 */
#include "rdpa_api.h"
#include "rdpa_user.h"
#include "rdpa_user_int.h"
#include "rdpa_dscp_to_pbit_user_ioctl_ag.h"

static int rdpa_user_dscp_to_pbit_drv(rdpa_ioctl_cmd_t *pa)
{
	BDMF_TRACE_DBG("inside rdpa_user_dscp_to_pbit_drv\n");

	if (!(pa->drv = rdpa_dscp_to_pbit_drv()))
	{
		BDMF_TRACE_DBG("rdpa_dscp_to_pbit_drv failed\n");
	}

	return 0;
}

static int rdpa_user_dscp_to_pbit_get(rdpa_ioctl_cmd_t *pa)
{
	BDMF_TRACE_DBG("inside rdpa_user_dscp_to_pbit_drv\n");

	if ((pa->ret = rdpa_dscp_to_pbit_get((bdmf_number)(long)pa->parm, &pa->mo)))
	{
		BDMF_TRACE_DBG("rdpa_dscp_to_pbit_get failed ret: %d\n", pa->ret);
	}

	return 0;
}

static int rdpa_user_dscp_to_pbit_table_get(rdpa_ioctl_cmd_t *pa)
{
	bdmf_number parm;

	BDMF_TRACE_DBG("inside dscp_to_pbit_user_table_get\n");

	if ((pa->ret = rdpa_dscp_to_pbit_table_get(pa->mo, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_dscp_to_pbit_table_get failed, ret:%d\n", pa->ret);
	}

	if (copy_to_user((void *)(long)pa->ptr, (void *)&parm, sizeof(bdmf_number)))
	{
		BDMF_TRACE_ERR("failed to copy to user\n");
		return -1;
	}

	return 0;
}

static int rdpa_user_dscp_to_pbit_table_set(rdpa_ioctl_cmd_t *pa)
{

	BDMF_TRACE_DBG("inside dscp_to_pbit_user_table_set\n");

	if ((pa->ret = rdpa_dscp_to_pbit_table_set(pa->mo, (bdmf_number)(long)pa->parm)))
	{
		BDMF_TRACE_DBG("rdpa_dscp_to_pbit_table_set failed, ret:%d\n", pa->ret);
	}

	return 0;
}

static int rdpa_user_dscp_to_pbit_qos_mapping_get(rdpa_ioctl_cmd_t *pa)
{
	bdmf_boolean parm;

	BDMF_TRACE_DBG("inside dscp_to_pbit_user_qos_mapping_get\n");

	if ((pa->ret = rdpa_dscp_to_pbit_qos_mapping_get(pa->mo, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_dscp_to_pbit_qos_mapping_get failed, ret:%d\n", pa->ret);
	}

	if (copy_to_user((void *)(long)pa->ptr, (void *)&parm, sizeof(bdmf_boolean)))
	{
		BDMF_TRACE_ERR("failed to copy to user\n");
		return -1;
	}

	return 0;
}

static int rdpa_user_dscp_to_pbit_qos_mapping_set(rdpa_ioctl_cmd_t *pa)
{

	BDMF_TRACE_DBG("inside dscp_to_pbit_user_qos_mapping_set\n");

	if ((pa->ret = rdpa_dscp_to_pbit_qos_mapping_set(pa->mo, (bdmf_boolean)(long)pa->parm)))
	{
		BDMF_TRACE_DBG("rdpa_dscp_to_pbit_qos_mapping_set failed, ret:%d\n", pa->ret);
	}

	return 0;
}

static int rdpa_user_dscp_to_pbit_dscp_map_get(rdpa_ioctl_cmd_t *pa)
{
	rdpa_pbit parm;

	BDMF_TRACE_DBG("inside dscp_to_pbit_user_dscp_map_get\n");

	if ((pa->ret = rdpa_dscp_to_pbit_dscp_map_get(pa->mo, pa->ai, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_dscp_to_pbit_dscp_map_get failed, ret:%d\n", pa->ret);
	}

	if (copy_to_user((void *)(long)pa->ptr, (void *)&parm, sizeof(rdpa_pbit)))
	{
		BDMF_TRACE_ERR("failed to copy to user\n");
		return -1;
	}

	return 0;
}

static int rdpa_user_dscp_to_pbit_dscp_map_set(rdpa_ioctl_cmd_t *pa)
{

	BDMF_TRACE_DBG("inside dscp_to_pbit_user_dscp_map_set\n");

	if ((pa->ret = rdpa_dscp_to_pbit_dscp_map_set(pa->mo, pa->ai, (rdpa_pbit)(long)pa->parm)))
	{
		BDMF_TRACE_DBG("rdpa_dscp_to_pbit_dscp_map_set failed, ret:%d\n", pa->ret);
	}

	return 0;
}

static int rdpa_user_dscp_to_pbit_dscp_pbit_dei_map_get(rdpa_ioctl_cmd_t *pa)
{
	rdpa_pbit_dei_t  parm;

	BDMF_TRACE_DBG("inside dscp_to_pbit_user_dscp_pbit_dei_map_get\n");

	if ((pa->ret = rdpa_dscp_to_pbit_dscp_pbit_dei_map_get(pa->mo, pa->ai, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_dscp_to_pbit_dscp_pbit_dei_map_get failed, ret:%d\n", pa->ret);
	}

	if (copy_to_user((void *)(long)pa->ptr, (void *)&parm, sizeof(rdpa_pbit_dei_t )))
	{
		BDMF_TRACE_ERR("failed to copy to user\n");
		return -1;
	}

	return 0;
}

static int rdpa_user_dscp_to_pbit_dscp_pbit_dei_map_set(rdpa_ioctl_cmd_t *pa)
{
	rdpa_pbit_dei_t  parm;

	BDMF_TRACE_DBG("inside dscp_to_pbit_user_dscp_pbit_dei_map_set\n");

	if (copy_from_user((void *)&parm, (void *)(long)pa->ptr, sizeof(rdpa_pbit_dei_t )))
	{
		BDMF_TRACE_ERR("failed to copy from user\n");
		return -1;
	}

	if ((pa->ret = rdpa_dscp_to_pbit_dscp_pbit_dei_map_set(pa->mo, pa->ai, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_dscp_to_pbit_dscp_pbit_dei_map_set failed, ret:%d\n", pa->ret);
	}

	return 0;
}

long rdpa_dscp_to_pbit_ag_ioctl(unsigned int op, rdpa_ioctl_cmd_t *pa)
{
	int ret;

	switch (op){
		case RDPA_DSCP_TO_PBIT_DRV:
			ret = rdpa_user_dscp_to_pbit_drv(pa);
			break;

		case RDPA_DSCP_TO_PBIT_GET:
			ret = rdpa_user_dscp_to_pbit_get(pa);
			break;

		case RDPA_DSCP_TO_PBIT_TABLE_GET:
			ret = rdpa_user_dscp_to_pbit_table_get(pa);
			break;

		case RDPA_DSCP_TO_PBIT_TABLE_SET:
			ret = rdpa_user_dscp_to_pbit_table_set(pa);
			break;

		case RDPA_DSCP_TO_PBIT_QOS_MAPPING_GET:
			ret = rdpa_user_dscp_to_pbit_qos_mapping_get(pa);
			break;

		case RDPA_DSCP_TO_PBIT_QOS_MAPPING_SET:
			ret = rdpa_user_dscp_to_pbit_qos_mapping_set(pa);
			break;

		case RDPA_DSCP_TO_PBIT_DSCP_MAP_GET:
			ret = rdpa_user_dscp_to_pbit_dscp_map_get(pa);
			break;

		case RDPA_DSCP_TO_PBIT_DSCP_MAP_SET:
			ret = rdpa_user_dscp_to_pbit_dscp_map_set(pa);
			break;

		case RDPA_DSCP_TO_PBIT_DSCP_PBIT_DEI_MAP_GET:
			ret = rdpa_user_dscp_to_pbit_dscp_pbit_dei_map_get(pa);
			break;

		case RDPA_DSCP_TO_PBIT_DSCP_PBIT_DEI_MAP_SET:
			ret = rdpa_user_dscp_to_pbit_dscp_pbit_dei_map_set(pa);
			break;

		default:
			BDMF_TRACE_ERR("no such ioctl cmd: %u\n", op);
			ret = EINVAL;
		}

	return ret;
}
