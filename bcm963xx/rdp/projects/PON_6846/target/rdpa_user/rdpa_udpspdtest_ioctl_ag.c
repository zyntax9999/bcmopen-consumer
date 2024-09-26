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
 * udpspdtest object ioctl functions implementation file.
 * This ioctl file is generated automatically. Do not edit!
 */
#include "rdpa_api.h"
#include "rdpa_user.h"
#include "rdpa_user_int.h"
#include "rdpa_udpspdtest_user_ioctl_ag.h"

static int rdpa_user_udpspdtest_drv(rdpa_ioctl_cmd_t *pa)
{
	BDMF_TRACE_DBG("inside rdpa_user_udpspdtest_drv\n");

	if (!(pa->drv = rdpa_udpspdtest_drv()))
	{
		BDMF_TRACE_DBG("rdpa_udpspdtest_drv failed\n");
	}

	return 0;
}

static int rdpa_user_udpspdtest_get(rdpa_ioctl_cmd_t *pa)
{
	BDMF_TRACE_DBG("inside rdpa_user_udpspdtest_drv\n");

	if ((pa->ret = rdpa_udpspdtest_get(&pa->mo)))
	{
		BDMF_TRACE_DBG("rdpa_udpspdtest_get failed ret: %d\n", pa->ret);
	}

	return 0;
}

static int rdpa_user_udpspdtest_cfg_get(rdpa_ioctl_cmd_t *pa)
{
	rdpa_udpspdtest_cfg_t  parm;

	BDMF_TRACE_DBG("inside udpspdtest_user_cfg_get\n");

	if ((pa->ret = rdpa_udpspdtest_cfg_get(pa->mo, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_udpspdtest_cfg_get failed, ret:%d\n", pa->ret);
	}

	if (copy_to_user((void *)(long)pa->ptr, (void *)&parm, sizeof(rdpa_udpspdtest_cfg_t )))
	{
		BDMF_TRACE_ERR("failed to copy to user\n");
		return -1;
	}

	return 0;
}

static int rdpa_user_udpspdtest_cfg_set(rdpa_ioctl_cmd_t *pa)
{
	rdpa_udpspdtest_cfg_t  parm;

	BDMF_TRACE_DBG("inside udpspdtest_user_cfg_set\n");

	if (copy_from_user((void *)&parm, (void *)(long)pa->ptr, sizeof(rdpa_udpspdtest_cfg_t )))
	{
		BDMF_TRACE_ERR("failed to copy from user\n");
		return -1;
	}

	if ((pa->ret = rdpa_udpspdtest_cfg_set(pa->mo, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_udpspdtest_cfg_set failed, ret:%d\n", pa->ret);
	}

	return 0;
}

static int rdpa_user_udpspdtest_stream_stat_get(rdpa_ioctl_cmd_t *pa)
{
	rdpa_udpspdtest_stat_t  parm;

	BDMF_TRACE_DBG("inside udpspdtest_user_stream_stat_get\n");

	if ((pa->ret = rdpa_udpspdtest_stream_stat_get(pa->mo, pa->ai, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_udpspdtest_stream_stat_get failed, ret:%d\n", pa->ret);
	}

	if (copy_to_user((void *)(long)pa->ptr, (void *)&parm, sizeof(rdpa_udpspdtest_stat_t )))
	{
		BDMF_TRACE_ERR("failed to copy to user\n");
		return -1;
	}

	return 0;
}

static int rdpa_user_udpspdtest_rx_params_get(rdpa_ioctl_cmd_t *pa)
{
	rdpa_udpspdtest_rx_params_t  parm;

	BDMF_TRACE_DBG("inside udpspdtest_user_rx_params_get\n");

	if ((pa->ret = rdpa_udpspdtest_rx_params_get(pa->mo, pa->ai, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_udpspdtest_rx_params_get failed, ret:%d\n", pa->ret);
	}

	if (copy_to_user((void *)(long)pa->ptr, (void *)&parm, sizeof(rdpa_udpspdtest_rx_params_t )))
	{
		BDMF_TRACE_ERR("failed to copy to user\n");
		return -1;
	}

	return 0;
}

static int rdpa_user_udpspdtest_rx_params_set(rdpa_ioctl_cmd_t *pa)
{
	rdpa_udpspdtest_rx_params_t  parm;

	BDMF_TRACE_DBG("inside udpspdtest_user_rx_params_set\n");

	if (copy_from_user((void *)&parm, (void *)(long)pa->ptr, sizeof(rdpa_udpspdtest_rx_params_t )))
	{
		BDMF_TRACE_ERR("failed to copy from user\n");
		return -1;
	}

	if ((pa->ret = rdpa_udpspdtest_rx_params_set(pa->mo, pa->ai, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_udpspdtest_rx_params_set failed, ret:%d\n", pa->ret);
	}

	return 0;
}

static int rdpa_user_udpspdtest_rx_start_set(rdpa_ioctl_cmd_t *pa)
{

	BDMF_TRACE_DBG("inside udpspdtest_user_rx_start_set\n");

	if ((pa->ret = rdpa_udpspdtest_rx_start_set(pa->mo, (bdmf_number)(long)pa->parm)))
	{
		BDMF_TRACE_DBG("rdpa_udpspdtest_rx_start_set failed, ret:%d\n", pa->ret);
	}

	return 0;
}

static int rdpa_user_udpspdtest_rx_stop_set(rdpa_ioctl_cmd_t *pa)
{

	BDMF_TRACE_DBG("inside udpspdtest_user_rx_stop_set\n");

	if ((pa->ret = rdpa_udpspdtest_rx_stop_set(pa->mo, (bdmf_number)(long)pa->parm)))
	{
		BDMF_TRACE_DBG("rdpa_udpspdtest_rx_stop_set failed, ret:%d\n", pa->ret);
	}

	return 0;
}

static int rdpa_user_udpspdtest_tx_params_get(rdpa_ioctl_cmd_t *pa)
{
	rdpa_udpspdtest_tx_params_t  parm;

	BDMF_TRACE_DBG("inside udpspdtest_user_tx_params_get\n");

	if ((pa->ret = rdpa_udpspdtest_tx_params_get(pa->mo, pa->ai, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_udpspdtest_tx_params_get failed, ret:%d\n", pa->ret);
	}

	if (copy_to_user((void *)(long)pa->ptr, (void *)&parm, sizeof(rdpa_udpspdtest_tx_params_t )))
	{
		BDMF_TRACE_ERR("failed to copy to user\n");
		return -1;
	}

	return 0;
}

static int rdpa_user_udpspdtest_tx_params_set(rdpa_ioctl_cmd_t *pa)
{
	rdpa_udpspdtest_tx_params_t  parm;

	BDMF_TRACE_DBG("inside udpspdtest_user_tx_params_set\n");

	if (copy_from_user((void *)&parm, (void *)(long)pa->ptr, sizeof(rdpa_udpspdtest_tx_params_t )))
	{
		BDMF_TRACE_ERR("failed to copy from user\n");
		return -1;
	}

	if ((pa->ret = rdpa_udpspdtest_tx_params_set(pa->mo, pa->ai, &parm)))
	{
		BDMF_TRACE_DBG("rdpa_udpspdtest_tx_params_set failed, ret:%d\n", pa->ret);
	}

	return 0;
}

static int rdpa_user_udpspdtest_tx_start_set(rdpa_ioctl_cmd_t *pa)
{

	BDMF_TRACE_DBG("inside udpspdtest_user_tx_start_set\n");

	if ((pa->ret = rdpa_udpspdtest_tx_start_set(pa->mo, (bdmf_number)(long)pa->parm)))
	{
		BDMF_TRACE_DBG("rdpa_udpspdtest_tx_start_set failed, ret:%d\n", pa->ret);
	}

	return 0;
}

static int rdpa_user_udpspdtest_tx_stop_set(rdpa_ioctl_cmd_t *pa)
{

	BDMF_TRACE_DBG("inside udpspdtest_user_tx_stop_set\n");

	if ((pa->ret = rdpa_udpspdtest_tx_stop_set(pa->mo, (bdmf_number)(long)pa->parm)))
	{
		BDMF_TRACE_DBG("rdpa_udpspdtest_tx_stop_set failed, ret:%d\n", pa->ret);
	}

	return 0;
}

long rdpa_udpspdtest_ag_ioctl(unsigned int op, rdpa_ioctl_cmd_t *pa)
{
	int ret;

	switch (op){
		case RDPA_UDPSPDTEST_DRV:
			ret = rdpa_user_udpspdtest_drv(pa);
			break;

		case RDPA_UDPSPDTEST_GET:
			ret = rdpa_user_udpspdtest_get(pa);
			break;

		case RDPA_UDPSPDTEST_CFG_GET:
			ret = rdpa_user_udpspdtest_cfg_get(pa);
			break;

		case RDPA_UDPSPDTEST_CFG_SET:
			ret = rdpa_user_udpspdtest_cfg_set(pa);
			break;

		case RDPA_UDPSPDTEST_STREAM_STAT_GET:
			ret = rdpa_user_udpspdtest_stream_stat_get(pa);
			break;

		case RDPA_UDPSPDTEST_RX_PARAMS_GET:
			ret = rdpa_user_udpspdtest_rx_params_get(pa);
			break;

		case RDPA_UDPSPDTEST_RX_PARAMS_SET:
			ret = rdpa_user_udpspdtest_rx_params_set(pa);
			break;

		case RDPA_UDPSPDTEST_RX_START_SET:
			ret = rdpa_user_udpspdtest_rx_start_set(pa);
			break;

		case RDPA_UDPSPDTEST_RX_STOP_SET:
			ret = rdpa_user_udpspdtest_rx_stop_set(pa);
			break;

		case RDPA_UDPSPDTEST_TX_PARAMS_GET:
			ret = rdpa_user_udpspdtest_tx_params_get(pa);
			break;

		case RDPA_UDPSPDTEST_TX_PARAMS_SET:
			ret = rdpa_user_udpspdtest_tx_params_set(pa);
			break;

		case RDPA_UDPSPDTEST_TX_START_SET:
			ret = rdpa_user_udpspdtest_tx_start_set(pa);
			break;

		case RDPA_UDPSPDTEST_TX_STOP_SET:
			ret = rdpa_user_udpspdtest_tx_stop_set(pa);
			break;

		default:
			BDMF_TRACE_ERR("no such ioctl cmd: %u\n", op);
			ret = EINVAL;
		}

	return ret;
}
