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



/* This is an automated file. Do not edit its contents. */


#include "rdd_ag_us_tm.h"

int rdd_ag_us_tm_scheduling_queue_descriptor_get(uint32_t _entry, rdd_scheduling_queue_descriptor_t *scheduling_queue_descriptor)
{
    if(!scheduling_queue_descriptor || _entry >= RDD_US_TM_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_SCHEDULING_QUEUE_DESCRIPTOR_BLOCK_TYPE_READ_G(scheduling_queue_descriptor->block_type, RDD_US_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);
    RDD_SCHEDULING_QUEUE_DESCRIPTOR_BBH_QUEUE_INDEX_READ_G(scheduling_queue_descriptor->bbh_queue_index, RDD_US_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);
    RDD_SCHEDULING_QUEUE_DESCRIPTOR_SCHEDULER_INDEX_READ_G(scheduling_queue_descriptor->scheduler_index, RDD_US_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);
    RDD_SCHEDULING_QUEUE_DESCRIPTOR_QUEUE_BIT_MASK_READ_G(scheduling_queue_descriptor->queue_bit_mask, RDD_US_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_scheduling_queue_descriptor_set(uint32_t _entry, rdd_scheduling_queue_descriptor_t *scheduling_queue_descriptor)
{
    if(!scheduling_queue_descriptor || _entry >= RDD_US_TM_SCHEDULING_QUEUE_TABLE_SIZE || scheduling_queue_descriptor->bbh_queue_index >= 64 || scheduling_queue_descriptor->scheduler_index >= 128)
          return BDMF_ERR_PARM;

    RDD_SCHEDULING_QUEUE_DESCRIPTOR_BLOCK_TYPE_WRITE_G(scheduling_queue_descriptor->block_type, RDD_US_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);
    RDD_SCHEDULING_QUEUE_DESCRIPTOR_BBH_QUEUE_INDEX_WRITE_G(scheduling_queue_descriptor->bbh_queue_index, RDD_US_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);
    RDD_SCHEDULING_QUEUE_DESCRIPTOR_SCHEDULER_INDEX_WRITE_G(scheduling_queue_descriptor->scheduler_index, RDD_US_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);
    RDD_SCHEDULING_QUEUE_DESCRIPTOR_QUEUE_BIT_MASK_WRITE_G(scheduling_queue_descriptor->queue_bit_mask, RDD_US_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_scheduling_queue_table_enable_set(uint32_t _entry, bdmf_boolean enable)
{
    if(_entry >= RDD_US_TM_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_SCHEDULING_QUEUE_DESCRIPTOR_ENABLE_WRITE_G(enable, RDD_US_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_scheduling_queue_table_enable_get(uint32_t _entry, bdmf_boolean *enable)
{
    if(_entry >= RDD_US_TM_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_SCHEDULING_QUEUE_DESCRIPTOR_ENABLE_READ_G(*enable, RDD_US_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_scheduling_queue_table_rate_limit_enable_set(uint32_t _entry, bdmf_boolean rate_limit_enable)
{
    if(_entry >= RDD_US_TM_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_SCHEDULING_QUEUE_DESCRIPTOR_RATE_LIMIT_ENABLE_WRITE_G(rate_limit_enable, RDD_US_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_scheduling_queue_table_rate_limit_enable_get(uint32_t _entry, bdmf_boolean *rate_limit_enable)
{
    if(_entry >= RDD_US_TM_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_SCHEDULING_QUEUE_DESCRIPTOR_RATE_LIMIT_ENABLE_READ_G(*rate_limit_enable, RDD_US_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_scheduling_queue_table_rate_limiter_index_set(uint32_t _entry, uint8_t rate_limiter_index)
{
    if(_entry >= RDD_US_TM_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_SCHEDULING_QUEUE_DESCRIPTOR_RATE_LIMITER_INDEX_WRITE_G(rate_limiter_index, RDD_US_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_scheduling_queue_table_rate_limiter_index_get(uint32_t _entry, uint8_t *rate_limiter_index)
{
    if(_entry >= RDD_US_TM_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_SCHEDULING_QUEUE_DESCRIPTOR_RATE_LIMITER_INDEX_READ_G(*rate_limiter_index, RDD_US_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_scheduling_queue_table_quantum_number_set(uint32_t _entry, uint8_t quantum_number)
{
    if(_entry >= RDD_US_TM_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_SCHEDULING_QUEUE_DESCRIPTOR_QUANTUM_NUMBER_WRITE_G(quantum_number, RDD_US_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_scheduling_queue_table_quantum_number_get(uint32_t _entry, uint8_t *quantum_number)
{
    if(_entry >= RDD_US_TM_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_SCHEDULING_QUEUE_DESCRIPTOR_QUANTUM_NUMBER_READ_G(*quantum_number, RDD_US_TM_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_scheduling_flush_vector_set(uint32_t _entry, uint32_t bits)
{
    if(_entry >= RDD_US_TM_SCHEDULING_FLUSH_VECTOR_SIZE)
          return BDMF_ERR_PARM;

    RDD_BYTES_4_BITS_WRITE_G(bits, RDD_US_TM_SCHEDULING_FLUSH_VECTOR_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_scheduling_flush_vector_get(uint32_t _entry, uint32_t *bits)
{
    if(_entry >= RDD_US_TM_SCHEDULING_FLUSH_VECTOR_SIZE)
          return BDMF_ERR_PARM;

    RDD_BYTES_4_BITS_READ_G(*bits, RDD_US_TM_SCHEDULING_FLUSH_VECTOR_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_wan_0_bb_destination_table_set(uint16_t bits)
{
    RDD_BYTES_2_BITS_WRITE_G(bits, RDD_US_TM_WAN_0_BB_DESTINATION_TABLE_ADDRESS_ARR, 0);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_wan_0_bb_destination_table_get(uint16_t *bits)
{
    RDD_BYTES_2_BITS_READ_G(*bits, RDD_US_TM_WAN_0_BB_DESTINATION_TABLE_ADDRESS_ARR, 0);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_scheduling_global_flush_cfg_set(uint8_t bits)
{
    RDD_BYTE_1_BITS_WRITE_G(bits, RDD_US_TM_SCHEDULING_GLOBAL_FLUSH_CFG_ADDRESS_ARR, 0);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_scheduling_global_flush_cfg_get(uint8_t *bits)
{
    RDD_BYTE_1_BITS_READ_G(*bits, RDD_US_TM_SCHEDULING_GLOBAL_FLUSH_CFG_ADDRESS_ARR, 0);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_bbh_tx_us_wan_0_fifo_bytes_threshold_set(uint16_t bits)
{
    RDD_BYTES_2_BITS_WRITE_G(bits, RDD_BBH_TX_US_WAN_0_FIFO_BYTES_THRESHOLD_ADDRESS_ARR, 0);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_bbh_tx_us_wan_0_fifo_bytes_threshold_get(uint16_t *bits)
{
    RDD_BYTES_2_BITS_READ_G(*bits, RDD_BBH_TX_US_WAN_0_FIFO_BYTES_THRESHOLD_ADDRESS_ARR, 0);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_flush_aggregation_task_disable_set(uint8_t bits)
{
    RDD_BYTE_1_BITS_WRITE_G(bits, RDD_US_TM_FLUSH_AGGREGATION_TASK_DISABLE_ADDRESS_ARR, 0);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_flush_aggregation_task_disable_get(uint8_t *bits)
{
    RDD_BYTE_1_BITS_READ_G(*bits, RDD_US_TM_FLUSH_AGGREGATION_TASK_DISABLE_ADDRESS_ARR, 0);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_wan_0_bbh_tx_fifo_size_set(uint8_t bits)
{
    RDD_BYTE_1_BITS_WRITE_G(bits, RDD_WAN_0_BBH_TX_FIFO_SIZE_ADDRESS_ARR, 0);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_wan_0_bbh_tx_fifo_size_get(uint8_t *bits)
{
    RDD_BYTE_1_BITS_READ_G(*bits, RDD_WAN_0_BBH_TX_FIFO_SIZE_ADDRESS_ARR, 0);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_first_queue_mapping_set(uint8_t bits)
{
    RDD_BYTE_1_BITS_WRITE_G(bits, RDD_US_TM_FIRST_QUEUE_MAPPING_ADDRESS_ARR, 0);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_first_queue_mapping_get(uint8_t *bits)
{
    RDD_BYTE_1_BITS_READ_G(*bits, RDD_US_TM_FIRST_QUEUE_MAPPING_ADDRESS_ARR, 0);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_tx_octets_counters_table_packets_set(uint32_t _entry, uint32_t packets)
{
    if(_entry >= RDD_US_TM_TX_OCTETS_COUNTERS_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_PACKETS_AND_BYTES_PACKETS_WRITE_G(packets, RDD_US_TM_TX_OCTETS_COUNTERS_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_tx_octets_counters_table_packets_get(uint32_t _entry, uint32_t *packets)
{
    if(_entry >= RDD_US_TM_TX_OCTETS_COUNTERS_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_PACKETS_AND_BYTES_PACKETS_READ_G(*packets, RDD_US_TM_TX_OCTETS_COUNTERS_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_tx_octets_counters_table_bytes_set(uint32_t _entry, uint32_t bytes)
{
    if(_entry >= RDD_US_TM_TX_OCTETS_COUNTERS_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_PACKETS_AND_BYTES_BYTES_WRITE_G(bytes, RDD_US_TM_TX_OCTETS_COUNTERS_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_tx_octets_counters_table_bytes_get(uint32_t _entry, uint32_t *bytes)
{
    if(_entry >= RDD_US_TM_TX_OCTETS_COUNTERS_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_PACKETS_AND_BYTES_BYTES_READ_G(*bytes, RDD_US_TM_TX_OCTETS_COUNTERS_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_basic_scheduler_table_us_quantum_number_set(uint32_t _entry, uint8_t quantum_number)
{
    if(_entry >= RDD_BASIC_SCHEDULER_TABLE_US_SIZE)
         return BDMF_ERR_PARM;

    RDD_BASIC_SCHEDULER_DESCRIPTOR_QUANTUM_NUMBER_WRITE_G(quantum_number, RDD_BASIC_SCHEDULER_TABLE_US_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_basic_scheduler_table_us_quantum_number_get(uint32_t _entry, uint8_t *quantum_number)
{
    if(_entry >= RDD_BASIC_SCHEDULER_TABLE_US_SIZE)
         return BDMF_ERR_PARM;

    RDD_BASIC_SCHEDULER_DESCRIPTOR_QUANTUM_NUMBER_READ_G(*quantum_number, RDD_BASIC_SCHEDULER_TABLE_US_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_complex_scheduler_rl_cfg_get(uint32_t _entry, rdd_complex_scheduler_rl_cfg_t *complex_scheduler_rl_cfg)
{
    if(!complex_scheduler_rl_cfg || _entry >= RDD_COMPLEX_SCHEDULER_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_IS_POSITIVE_BUDGET_READ_G(complex_scheduler_rl_cfg->is_positive_budget, RDD_COMPLEX_SCHEDULER_TABLE_ADDRESS_ARR, _entry);
    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_RATE_LIMITER_INDEX_READ_G(complex_scheduler_rl_cfg->rate_limiter_index, RDD_COMPLEX_SCHEDULER_TABLE_ADDRESS_ARR, _entry);
    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_RATE_LIMIT_ENABLE_READ_G(complex_scheduler_rl_cfg->rate_limit_enable, RDD_COMPLEX_SCHEDULER_TABLE_ADDRESS_ARR, _entry);
    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DEFICIT_COUNTER_READ_G(complex_scheduler_rl_cfg->deficit_counter, RDD_COMPLEX_SCHEDULER_TABLE_ADDRESS_ARR, _entry);
    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_QUANTUM_NUMBER_READ_G(complex_scheduler_rl_cfg->quantum_number, RDD_COMPLEX_SCHEDULER_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_complex_scheduler_rl_cfg_set(uint32_t _entry, rdd_complex_scheduler_rl_cfg_t *complex_scheduler_rl_cfg)
{
    if(!complex_scheduler_rl_cfg || _entry >= RDD_COMPLEX_SCHEDULER_TABLE_SIZE || complex_scheduler_rl_cfg->rate_limiter_index >= 128)
          return BDMF_ERR_PARM;

    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_IS_POSITIVE_BUDGET_WRITE_G(complex_scheduler_rl_cfg->is_positive_budget, RDD_COMPLEX_SCHEDULER_TABLE_ADDRESS_ARR, _entry);
    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_RATE_LIMITER_INDEX_WRITE_G(complex_scheduler_rl_cfg->rate_limiter_index, RDD_COMPLEX_SCHEDULER_TABLE_ADDRESS_ARR, _entry);
    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_RATE_LIMIT_ENABLE_WRITE_G(complex_scheduler_rl_cfg->rate_limit_enable, RDD_COMPLEX_SCHEDULER_TABLE_ADDRESS_ARR, _entry);
    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DEFICIT_COUNTER_WRITE_G(complex_scheduler_rl_cfg->deficit_counter, RDD_COMPLEX_SCHEDULER_TABLE_ADDRESS_ARR, _entry);
    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_QUANTUM_NUMBER_WRITE_G(complex_scheduler_rl_cfg->quantum_number, RDD_COMPLEX_SCHEDULER_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_complex_scheduler_table_dwrr_offset_pir_set(uint32_t _entry, uint8_t dwrr_offset_pir)
{
    if(_entry >= RDD_COMPLEX_SCHEDULER_TABLE_SIZE || dwrr_offset_pir >= 8)
          return BDMF_ERR_PARM;

    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DWRR_OFFSET_PIR_WRITE_G(dwrr_offset_pir, RDD_COMPLEX_SCHEDULER_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_complex_scheduler_table_dwrr_offset_pir_get(uint32_t _entry, uint8_t *dwrr_offset_pir)
{
    if(_entry >= RDD_COMPLEX_SCHEDULER_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DWRR_OFFSET_PIR_READ_G(*dwrr_offset_pir, RDD_COMPLEX_SCHEDULER_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_complex_scheduler_table_dwrr_offset_sir_set(uint32_t _entry, uint8_t dwrr_offset_sir)
{
    if(_entry >= RDD_COMPLEX_SCHEDULER_TABLE_SIZE || dwrr_offset_sir >= 8)
          return BDMF_ERR_PARM;

    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DWRR_OFFSET_SIR_WRITE_G(dwrr_offset_sir, RDD_COMPLEX_SCHEDULER_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_complex_scheduler_table_dwrr_offset_sir_get(uint32_t _entry, uint8_t *dwrr_offset_sir)
{
    if(_entry >= RDD_COMPLEX_SCHEDULER_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DWRR_OFFSET_SIR_READ_G(*dwrr_offset_sir, RDD_COMPLEX_SCHEDULER_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_complex_scheduler_table_slot_budget_bit_vector_0_set(uint32_t _entry, uint32_t slot_budget_bit_vector_0)
{
    if(_entry >= RDD_COMPLEX_SCHEDULER_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_SLOT_BUDGET_BIT_VECTOR_0_WRITE_G(slot_budget_bit_vector_0, RDD_COMPLEX_SCHEDULER_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_complex_scheduler_table_slot_budget_bit_vector_0_get(uint32_t _entry, uint32_t *slot_budget_bit_vector_0)
{
    if(_entry >= RDD_COMPLEX_SCHEDULER_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_SLOT_BUDGET_BIT_VECTOR_0_READ_G(*slot_budget_bit_vector_0, RDD_COMPLEX_SCHEDULER_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_complex_scheduler_table_quantum_number_set(uint32_t _entry, uint8_t quantum_number)
{
    if(_entry >= RDD_COMPLEX_SCHEDULER_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_QUANTUM_NUMBER_WRITE_G(quantum_number, RDD_COMPLEX_SCHEDULER_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_us_tm_complex_scheduler_table_quantum_number_get(uint32_t _entry, uint8_t *quantum_number)
{
    if(_entry >= RDD_COMPLEX_SCHEDULER_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_QUANTUM_NUMBER_READ_G(*quantum_number, RDD_COMPLEX_SCHEDULER_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

