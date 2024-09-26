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


#ifndef _RDD_RUNNER_DEFS_AUTO_H_
#define _RDD_RUNNER_DEFS_AUTO_H_

#ifdef XRDP_CFE
/* DDR */
/* PSRAM */
/* IMAGE_0 */
#define IMAGE_0_BASIC_RATE_LIMITER_TABLE_DS_ADDRESS 0x0000
#define IMAGE_0_BASIC_RATE_LIMITER_TABLE_DS_BYTE_SIZE 0x0800
#define IMAGE_0_BASIC_RATE_LIMITER_TABLE_DS_LOG2_BYTE_SIZE 0x000b
#define RDD_IMAGE_0_BASIC_RATE_LIMITER_TABLE_DS_SIZE     128
#define RDD_IMAGE_0_BASIC_RATE_LIMITER_TABLE_DS_LOG2_SIZE     7
#define IMAGE_0_DS_TM_SCHEDULING_QUEUE_TABLE_ADDRESS 0x0800
#define IMAGE_0_DS_TM_SCHEDULING_QUEUE_TABLE_BYTE_SIZE 0x0500
#define IMAGE_0_DS_TM_SCHEDULING_QUEUE_TABLE_LOG2_BYTE_SIZE 0x000b
#define RDD_IMAGE_0_DS_TM_SCHEDULING_QUEUE_TABLE_SIZE     160
#define RDD_IMAGE_0_DS_TM_SCHEDULING_QUEUE_TABLE_LOG2_SIZE     8
#define IMAGE_0_DS_TM_BBH_TX_EGRESS_COUNTER_TABLE_ADDRESS 0x0d00
#define IMAGE_0_DS_TM_BBH_TX_EGRESS_COUNTER_TABLE_BYTE_SIZE 0x0040
#define IMAGE_0_DS_TM_BBH_TX_EGRESS_COUNTER_TABLE_LOG2_BYTE_SIZE 0x0006
#define RDD_IMAGE_0_DS_TM_BBH_TX_EGRESS_COUNTER_TABLE_SIZE     8
#define RDD_IMAGE_0_DS_TM_BBH_TX_EGRESS_COUNTER_TABLE_LOG2_SIZE     3
#define IMAGE_0_REGISTERS_BUFFER_ADDRESS 0x0d40
#define IMAGE_0_REGISTERS_BUFFER_BYTE_SIZE 0x0080
#define IMAGE_0_REGISTERS_BUFFER_LOG2_BYTE_SIZE 0x0007
#define RDD_IMAGE_0_REGISTERS_BUFFER_SIZE     32
#define RDD_IMAGE_0_REGISTERS_BUFFER_LOG2_SIZE     5
#define IMAGE_0_DS_TM_TM_ACTION_PTR_TABLE_ADDRESS 0x0dc0
#define IMAGE_0_DS_TM_TM_ACTION_PTR_TABLE_BYTE_SIZE 0x0022
#define IMAGE_0_DS_TM_TM_ACTION_PTR_TABLE_LOG2_BYTE_SIZE 0x0006
#define RDD_IMAGE_0_DS_TM_TM_ACTION_PTR_TABLE_SIZE     17
#define RDD_IMAGE_0_DS_TM_TM_ACTION_PTR_TABLE_LOG2_SIZE     5
#define IMAGE_0_BUDGET_ALLOCATION_TIMER_VALUE_ADDRESS 0x0de2
#define IMAGE_0_BUDGET_ALLOCATION_TIMER_VALUE_BYTE_SIZE 0x0002
#define IMAGE_0_BUDGET_ALLOCATION_TIMER_VALUE_LOG2_BYTE_SIZE 0x0001
#define IMAGE_0_DS_TM_BB_DESTINATION_TABLE_ADDRESS 0x0de4
#define IMAGE_0_DS_TM_BB_DESTINATION_TABLE_BYTE_SIZE 0x0002
#define IMAGE_0_DS_TM_BB_DESTINATION_TABLE_LOG2_BYTE_SIZE 0x0001
#define IMAGE_0_SCHEDULING_FLUSH_GLOBAL_CFG_ADDRESS 0x0de6
#define IMAGE_0_SCHEDULING_FLUSH_GLOBAL_CFG_BYTE_SIZE 0x0001
#define IMAGE_0_SCHEDULING_FLUSH_GLOBAL_CFG_LOG2_BYTE_SIZE 0x0001
#define IMAGE_0_DS_TM_SCHEDULING_GLOBAL_FLUSH_CFG_ADDRESS 0x0de7
#define IMAGE_0_DS_TM_SCHEDULING_GLOBAL_FLUSH_CFG_BYTE_SIZE 0x0001
#define IMAGE_0_DS_TM_SCHEDULING_GLOBAL_FLUSH_CFG_LOG2_BYTE_SIZE 0x0001
#define IMAGE_0_DS_TM_BBH_TX_QUEUE_ID_TABLE_ADDRESS 0x0de8
#define IMAGE_0_DS_TM_BBH_TX_QUEUE_ID_TABLE_BYTE_SIZE 0x0008
#define IMAGE_0_DS_TM_BBH_TX_QUEUE_ID_TABLE_LOG2_BYTE_SIZE 0x0003
#define RDD_IMAGE_0_DS_TM_BBH_TX_QUEUE_ID_TABLE_SIZE     2
#define RDD_IMAGE_0_DS_TM_BBH_TX_QUEUE_ID_TABLE_LOG2_SIZE     1
#define IMAGE_0_FPM_GLOBAL_CFG_ADDRESS 0x0df0
#define IMAGE_0_FPM_GLOBAL_CFG_BYTE_SIZE 0x000c
#define IMAGE_0_FPM_GLOBAL_CFG_LOG2_BYTE_SIZE 0x0004
#define IMAGE_0_TASK_IDX_ADDRESS 0x0dfc
#define IMAGE_0_TASK_IDX_BYTE_SIZE 0x0004
#define IMAGE_0_TASK_IDX_LOG2_BYTE_SIZE 0x0002
#define IMAGE_0_BASIC_SCHEDULER_TABLE_DS_ADDRESS 0x0e00
#define IMAGE_0_BASIC_SCHEDULER_TABLE_DS_BYTE_SIZE 0x0200
#define IMAGE_0_BASIC_SCHEDULER_TABLE_DS_LOG2_BYTE_SIZE 0x0009
#define RDD_IMAGE_0_BASIC_SCHEDULER_TABLE_DS_SIZE     32
#define RDD_IMAGE_0_BASIC_SCHEDULER_TABLE_DS_LOG2_SIZE     5
#define IMAGE_0_DS_TM_PD_FIFO_TABLE_ADDRESS 0x1000
#define IMAGE_0_DS_TM_PD_FIFO_TABLE_BYTE_SIZE 0x0500
#define IMAGE_0_DS_TM_PD_FIFO_TABLE_LOG2_BYTE_SIZE 0x000b
#define RDD_IMAGE_0_DS_TM_PD_FIFO_TABLE_SIZE     80
#define RDD_IMAGE_0_DS_TM_PD_FIFO_TABLE_LOG2_SIZE     7
#define IMAGE_0_UPDATE_FIFO_TABLE_ADDRESS 0x1500
#define IMAGE_0_UPDATE_FIFO_TABLE_BYTE_SIZE 0x0020
#define IMAGE_0_UPDATE_FIFO_TABLE_LOG2_BYTE_SIZE 0x0005
#define RDD_IMAGE_0_UPDATE_FIFO_TABLE_SIZE     8
#define RDD_IMAGE_0_UPDATE_FIFO_TABLE_LOG2_SIZE     3
#define IMAGE_0_RUNNER_GLOBAL_REGISTERS_INIT_ADDRESS 0x1520
#define IMAGE_0_RUNNER_GLOBAL_REGISTERS_INIT_BYTE_SIZE 0x0020
#define IMAGE_0_RUNNER_GLOBAL_REGISTERS_INIT_LOG2_BYTE_SIZE 0x0005
#define RDD_IMAGE_0_RUNNER_GLOBAL_REGISTERS_INIT_SIZE     8
#define RDD_IMAGE_0_RUNNER_GLOBAL_REGISTERS_INIT_LOG2_SIZE     3
#define IMAGE_0_DS_TM_SCHEDULING_AGGREGATION_CONTEXT_VECTOR_ADDRESS 0x1540
#define IMAGE_0_DS_TM_SCHEDULING_AGGREGATION_CONTEXT_VECTOR_BYTE_SIZE 0x0014
#define IMAGE_0_DS_TM_SCHEDULING_AGGREGATION_CONTEXT_VECTOR_LOG2_BYTE_SIZE 0x0005
#define RDD_IMAGE_0_DS_TM_SCHEDULING_AGGREGATION_CONTEXT_VECTOR_SIZE     5
#define RDD_IMAGE_0_DS_TM_SCHEDULING_AGGREGATION_CONTEXT_VECTOR_LOG2_SIZE     3
#define IMAGE_0_SRAM_DUMMY_STORE_ADDRESS 0x1554
#define IMAGE_0_SRAM_DUMMY_STORE_BYTE_SIZE 0x0001
#define IMAGE_0_SRAM_DUMMY_STORE_LOG2_BYTE_SIZE 0x0001
#define IMAGE_0_DS_TM_FIRST_QUEUE_MAPPING_ADDRESS 0x1555
#define IMAGE_0_DS_TM_FIRST_QUEUE_MAPPING_BYTE_SIZE 0x0001
#define IMAGE_0_DS_TM_FIRST_QUEUE_MAPPING_LOG2_BYTE_SIZE 0x0001
#define IMAGE_0_DS_TM_TM_FLOW_CNTR_TABLE_ADDRESS 0x1558
#define IMAGE_0_DS_TM_TM_FLOW_CNTR_TABLE_BYTE_SIZE 0x0005
#define IMAGE_0_DS_TM_TM_FLOW_CNTR_TABLE_LOG2_BYTE_SIZE 0x0003
#define RDD_IMAGE_0_DS_TM_TM_FLOW_CNTR_TABLE_SIZE     5
#define RDD_IMAGE_0_DS_TM_TM_FLOW_CNTR_TABLE_LOG2_SIZE     3
#define IMAGE_0_DS_TM_SCHEDULING_FLUSH_VECTOR_ADDRESS 0x1560
#define IMAGE_0_DS_TM_SCHEDULING_FLUSH_VECTOR_BYTE_SIZE 0x0014
#define IMAGE_0_DS_TM_SCHEDULING_FLUSH_VECTOR_LOG2_BYTE_SIZE 0x0005
#define RDD_IMAGE_0_DS_TM_SCHEDULING_FLUSH_VECTOR_SIZE     5
#define RDD_IMAGE_0_DS_TM_SCHEDULING_FLUSH_VECTOR_LOG2_SIZE     3
#define IMAGE_0_DS_TM_SCHEDULING_QUEUE_AGING_VECTOR_ADDRESS 0x1580
#define IMAGE_0_DS_TM_SCHEDULING_QUEUE_AGING_VECTOR_BYTE_SIZE 0x0014
#define IMAGE_0_DS_TM_SCHEDULING_QUEUE_AGING_VECTOR_LOG2_BYTE_SIZE 0x0005
#define RDD_IMAGE_0_DS_TM_SCHEDULING_QUEUE_AGING_VECTOR_SIZE     5
#define RDD_IMAGE_0_DS_TM_SCHEDULING_QUEUE_AGING_VECTOR_LOG2_SIZE     3
#define IMAGE_0_RATE_LIMITER_VALID_TABLE_DS_ADDRESS 0x15a0
#define IMAGE_0_RATE_LIMITER_VALID_TABLE_DS_BYTE_SIZE 0x0010
#define IMAGE_0_RATE_LIMITER_VALID_TABLE_DS_LOG2_BYTE_SIZE 0x0004
#define RDD_IMAGE_0_RATE_LIMITER_VALID_TABLE_DS_SIZE     4
#define RDD_IMAGE_0_RATE_LIMITER_VALID_TABLE_DS_LOG2_SIZE     2
#define IMAGE_0_DS_TM_BBH_QUEUE_TABLE_ADDRESS 0x1600
#define IMAGE_0_DS_TM_BBH_QUEUE_TABLE_BYTE_SIZE 0x0020
#define IMAGE_0_DS_TM_BBH_QUEUE_TABLE_LOG2_BYTE_SIZE 0x0005
#define RDD_IMAGE_0_DS_TM_BBH_QUEUE_TABLE_SIZE     8
#define RDD_IMAGE_0_DS_TM_BBH_QUEUE_TABLE_LOG2_SIZE     3
#define IMAGE_0_COMPLEX_SCHEDULER_TABLE_ADDRESS 0x1800
#define IMAGE_0_COMPLEX_SCHEDULER_TABLE_BYTE_SIZE 0x0400
#define IMAGE_0_COMPLEX_SCHEDULER_TABLE_LOG2_BYTE_SIZE 0x000a
#define RDD_IMAGE_0_COMPLEX_SCHEDULER_TABLE_SIZE     16
#define RDD_IMAGE_0_COMPLEX_SCHEDULER_TABLE_LOG2_SIZE     4
#define IMAGE_0_RUNNER_PROFILING_TRACE_BUFFER_ADDRESS 0x1c00
#define IMAGE_0_RUNNER_PROFILING_TRACE_BUFFER_BYTE_SIZE 0x0200
#define IMAGE_0_RUNNER_PROFILING_TRACE_BUFFER_LOG2_BYTE_SIZE 0x0009
#define RDD_IMAGE_0_RUNNER_PROFILING_TRACE_BUFFER_SIZE     128
#define RDD_IMAGE_0_RUNNER_PROFILING_TRACE_BUFFER_LOG2_SIZE     7
/* IMAGE_1 */
#define IMAGE_1_CPU_RECYCLE_SRAM_PD_FIFO_ADDRESS 0x0000
#define IMAGE_1_CPU_RECYCLE_SRAM_PD_FIFO_BYTE_SIZE 0x0100
#define IMAGE_1_CPU_RECYCLE_SRAM_PD_FIFO_LOG2_BYTE_SIZE 0x0008
#define RDD_IMAGE_1_CPU_RECYCLE_SRAM_PD_FIFO_SIZE     16
#define RDD_IMAGE_1_CPU_RECYCLE_SRAM_PD_FIFO_LOG2_SIZE     4
#define IMAGE_1_CPU_RX_COPY_PD_FIFO_TABLE_ADDRESS 0x0100
#define IMAGE_1_CPU_RX_COPY_PD_FIFO_TABLE_BYTE_SIZE 0x0040
#define IMAGE_1_CPU_RX_COPY_PD_FIFO_TABLE_LOG2_BYTE_SIZE 0x0006
#define RDD_IMAGE_1_CPU_RX_COPY_PD_FIFO_TABLE_SIZE     4
#define RDD_IMAGE_1_CPU_RX_COPY_PD_FIFO_TABLE_LOG2_SIZE     2
#define IMAGE_1_DIRECT_PROCESSING_PD_TABLE_ADDRESS 0x0140
#define IMAGE_1_DIRECT_PROCESSING_PD_TABLE_BYTE_SIZE 0x0020
#define IMAGE_1_DIRECT_PROCESSING_PD_TABLE_LOG2_BYTE_SIZE 0x0005
#define RDD_IMAGE_1_DIRECT_PROCESSING_PD_TABLE_SIZE     2
#define RDD_IMAGE_1_DIRECT_PROCESSING_PD_TABLE_LOG2_SIZE     1
#define IMAGE_1_RUNNER_GLOBAL_REGISTERS_INIT_ADDRESS 0x0160
#define IMAGE_1_RUNNER_GLOBAL_REGISTERS_INIT_BYTE_SIZE 0x0020
#define IMAGE_1_RUNNER_GLOBAL_REGISTERS_INIT_LOG2_BYTE_SIZE 0x0005
#define RDD_IMAGE_1_RUNNER_GLOBAL_REGISTERS_INIT_SIZE     8
#define RDD_IMAGE_1_RUNNER_GLOBAL_REGISTERS_INIT_LOG2_SIZE     3
#define IMAGE_1_DS_CPU_RX_METER_TABLE_ADDRESS 0x0180
#define IMAGE_1_DS_CPU_RX_METER_TABLE_BYTE_SIZE 0x0080
#define IMAGE_1_DS_CPU_RX_METER_TABLE_LOG2_BYTE_SIZE 0x0007
#define RDD_IMAGE_1_DS_CPU_RX_METER_TABLE_SIZE     16
#define RDD_IMAGE_1_DS_CPU_RX_METER_TABLE_LOG2_SIZE     4
#define IMAGE_1_CPU_RING_INTERRUPT_COUNTER_TABLE_ADDRESS 0x0200
#define IMAGE_1_CPU_RING_INTERRUPT_COUNTER_TABLE_BYTE_SIZE 0x0090
#define IMAGE_1_CPU_RING_INTERRUPT_COUNTER_TABLE_LOG2_BYTE_SIZE 0x0008
#define RDD_IMAGE_1_CPU_RING_INTERRUPT_COUNTER_TABLE_SIZE     18
#define RDD_IMAGE_1_CPU_RING_INTERRUPT_COUNTER_TABLE_LOG2_SIZE     5
#define IMAGE_1_SCRATCH_ADDRESS 0x0290
#define IMAGE_1_SCRATCH_BYTE_SIZE 0x0020
#define IMAGE_1_SCRATCH_LOG2_BYTE_SIZE 0x0005
#define RDD_IMAGE_1_SCRATCH_SIZE     8
#define RDD_IMAGE_1_SCRATCH_LOG2_SIZE     3
#define IMAGE_1_CPU_RECYCLE_INTERRUPT_COALESCING_TABLE_ADDRESS 0x02b0
#define IMAGE_1_CPU_RECYCLE_INTERRUPT_COALESCING_TABLE_BYTE_SIZE 0x0010
#define IMAGE_1_CPU_RECYCLE_INTERRUPT_COALESCING_TABLE_LOG2_BYTE_SIZE 0x0004
#define IMAGE_1_DS_CPU_REASON_TO_METER_TABLE_ADDRESS 0x02c0
#define IMAGE_1_DS_CPU_REASON_TO_METER_TABLE_BYTE_SIZE 0x0040
#define IMAGE_1_DS_CPU_REASON_TO_METER_TABLE_LOG2_BYTE_SIZE 0x0006
#define RDD_IMAGE_1_DS_CPU_REASON_TO_METER_TABLE_SIZE     64
#define RDD_IMAGE_1_DS_CPU_REASON_TO_METER_TABLE_LOG2_SIZE     6
#define IMAGE_1_US_CPU_RX_METER_TABLE_ADDRESS 0x0300
#define IMAGE_1_US_CPU_RX_METER_TABLE_BYTE_SIZE 0x0080
#define IMAGE_1_US_CPU_RX_METER_TABLE_LOG2_BYTE_SIZE 0x0007
#define RDD_IMAGE_1_US_CPU_RX_METER_TABLE_SIZE     16
#define RDD_IMAGE_1_US_CPU_RX_METER_TABLE_LOG2_SIZE     4
#define IMAGE_1_CPU_REASON_AND_VPORT_TO_METER_TABLE_ADDRESS 0x0380
#define IMAGE_1_CPU_REASON_AND_VPORT_TO_METER_TABLE_BYTE_SIZE 0x0078
#define IMAGE_1_CPU_REASON_AND_VPORT_TO_METER_TABLE_LOG2_BYTE_SIZE 0x0007
#define RDD_IMAGE_1_CPU_REASON_AND_VPORT_TO_METER_TABLE_SIZE     120
#define RDD_IMAGE_1_CPU_REASON_AND_VPORT_TO_METER_TABLE_LOG2_SIZE     7
#define IMAGE_1_CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_ADDRESS 0x03f8
#define IMAGE_1_CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_BYTE_SIZE 0x0008
#define IMAGE_1_CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_LOG2_BYTE_SIZE 0x0003
#define IMAGE_1_CPU_RX_SCRATCHPAD_ADDRESS 0x0400
#define IMAGE_1_CPU_RX_SCRATCHPAD_BYTE_SIZE 0x0200
#define IMAGE_1_CPU_RX_SCRATCHPAD_LOG2_BYTE_SIZE 0x0009
#define RDD_IMAGE_1_CPU_RX_SCRATCHPAD_SIZE     64
#define RDD_IMAGE_1_CPU_RX_SCRATCHPAD_LOG2_SIZE     6
#define IMAGE_1_US_CPU_REASON_TO_METER_TABLE_ADDRESS 0x0600
#define IMAGE_1_US_CPU_REASON_TO_METER_TABLE_BYTE_SIZE 0x0040
#define IMAGE_1_US_CPU_REASON_TO_METER_TABLE_LOG2_BYTE_SIZE 0x0006
#define RDD_IMAGE_1_US_CPU_REASON_TO_METER_TABLE_SIZE     64
#define RDD_IMAGE_1_US_CPU_REASON_TO_METER_TABLE_LOG2_SIZE     6
#define IMAGE_1_REGISTERS_BUFFER_ADDRESS 0x0640
#define IMAGE_1_REGISTERS_BUFFER_BYTE_SIZE 0x0080
#define IMAGE_1_REGISTERS_BUFFER_LOG2_BYTE_SIZE 0x0007
#define RDD_IMAGE_1_REGISTERS_BUFFER_SIZE     32
#define RDD_IMAGE_1_REGISTERS_BUFFER_LOG2_SIZE     5
#define IMAGE_1_UPDATE_FIFO_TABLE_ADDRESS 0x06c0
#define IMAGE_1_UPDATE_FIFO_TABLE_BYTE_SIZE 0x0020
#define IMAGE_1_UPDATE_FIFO_TABLE_LOG2_BYTE_SIZE 0x0005
#define RDD_IMAGE_1_UPDATE_FIFO_TABLE_SIZE     8
#define RDD_IMAGE_1_UPDATE_FIFO_TABLE_LOG2_SIZE     3
#define IMAGE_1_CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD_ADDRESS 0x06e0
#define IMAGE_1_CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD_BYTE_SIZE 0x0010
#define IMAGE_1_CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD_LOG2_BYTE_SIZE 0x0004
#define RDD_IMAGE_1_CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD_SIZE     4
#define RDD_IMAGE_1_CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD_LOG2_SIZE     2
#define IMAGE_1_CPU_RX_COPY_DISPATCHER_CREDIT_TABLE_ADDRESS 0x06f0
#define IMAGE_1_CPU_RX_COPY_DISPATCHER_CREDIT_TABLE_BYTE_SIZE 0x000c
#define IMAGE_1_CPU_RX_COPY_DISPATCHER_CREDIT_TABLE_LOG2_BYTE_SIZE 0x0004
#define RDD_IMAGE_1_CPU_RX_COPY_DISPATCHER_CREDIT_TABLE_SIZE     3
#define RDD_IMAGE_1_CPU_RX_COPY_DISPATCHER_CREDIT_TABLE_LOG2_SIZE     2
#define IMAGE_1_CPU_RX_INTERRUPT_SCRATCH_ADDRESS 0x06fc
#define IMAGE_1_CPU_RX_INTERRUPT_SCRATCH_BYTE_SIZE 0x0004
#define IMAGE_1_CPU_RX_INTERRUPT_SCRATCH_LOG2_BYTE_SIZE 0x0002
#define IMAGE_1_CPU_VPORT_TO_METER_TABLE_ADDRESS 0x0700
#define IMAGE_1_CPU_VPORT_TO_METER_TABLE_BYTE_SIZE 0x0028
#define IMAGE_1_CPU_VPORT_TO_METER_TABLE_LOG2_BYTE_SIZE 0x0006
#define RDD_IMAGE_1_CPU_VPORT_TO_METER_TABLE_SIZE     40
#define RDD_IMAGE_1_CPU_VPORT_TO_METER_TABLE_LOG2_SIZE     6
#define IMAGE_1_CPU_RX_INTERRUPT_ID_DDR_ADDR_ADDRESS 0x0728
#define IMAGE_1_CPU_RX_INTERRUPT_ID_DDR_ADDR_BYTE_SIZE 0x0008
#define IMAGE_1_CPU_RX_INTERRUPT_ID_DDR_ADDR_LOG2_BYTE_SIZE 0x0003
#define IMAGE_1_CPU_RECYCLE_RING_DESCRIPTOR_TABLE_ADDRESS 0x0730
#define IMAGE_1_CPU_RECYCLE_RING_DESCRIPTOR_TABLE_BYTE_SIZE 0x0010
#define IMAGE_1_CPU_RECYCLE_RING_DESCRIPTOR_TABLE_LOG2_BYTE_SIZE 0x0004
#define IMAGE_1_CPU_RX_COPY_UPDATE_FIFO_TABLE_ADDRESS 0x0740
#define IMAGE_1_CPU_RX_COPY_UPDATE_FIFO_TABLE_BYTE_SIZE 0x0020
#define IMAGE_1_CPU_RX_COPY_UPDATE_FIFO_TABLE_LOG2_BYTE_SIZE 0x0005
#define RDD_IMAGE_1_CPU_RX_COPY_UPDATE_FIFO_TABLE_SIZE     8
#define RDD_IMAGE_1_CPU_RX_COPY_UPDATE_FIFO_TABLE_LOG2_SIZE     3
#define IMAGE_1_CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_ADDRESS 0x0760
#define IMAGE_1_CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_BYTE_SIZE 0x0010
#define IMAGE_1_CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_LOG2_BYTE_SIZE 0x0004
#define RDD_IMAGE_1_CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_SIZE     2
#define RDD_IMAGE_1_CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_LOG2_SIZE     1
#define IMAGE_1_CPU_INTERRUPT_COALESCING_TABLE_ADDRESS 0x0770
#define IMAGE_1_CPU_INTERRUPT_COALESCING_TABLE_BYTE_SIZE 0x0010
#define IMAGE_1_CPU_INTERRUPT_COALESCING_TABLE_LOG2_BYTE_SIZE 0x0004
#define IMAGE_1_PD_FIFO_TABLE_ADDRESS 0x0780
#define IMAGE_1_PD_FIFO_TABLE_BYTE_SIZE 0x0020
#define IMAGE_1_PD_FIFO_TABLE_LOG2_BYTE_SIZE 0x0005
#define RDD_IMAGE_1_PD_FIFO_TABLE_SIZE     2
#define RDD_IMAGE_1_PD_FIFO_TABLE_LOG2_SIZE     1
#define IMAGE_1_CPU_REASON_TO_TC_ADDRESS 0x07a0
#define IMAGE_1_CPU_REASON_TO_TC_BYTE_SIZE 0x0040
#define IMAGE_1_CPU_REASON_TO_TC_LOG2_BYTE_SIZE 0x0006
#define RDD_IMAGE_1_CPU_REASON_TO_TC_SIZE     64
#define RDD_IMAGE_1_CPU_REASON_TO_TC_LOG2_SIZE     6
#define IMAGE_1_CPU_FEED_RING_DESCRIPTOR_TABLE_ADDRESS 0x07e0
#define IMAGE_1_CPU_FEED_RING_DESCRIPTOR_TABLE_BYTE_SIZE 0x0010
#define IMAGE_1_CPU_FEED_RING_DESCRIPTOR_TABLE_LOG2_BYTE_SIZE 0x0004
#define IMAGE_1_CPU_RX_LOCAL_SCRATCH_ADDRESS 0x07f0
#define IMAGE_1_CPU_RX_LOCAL_SCRATCH_BYTE_SIZE 0x0010
#define IMAGE_1_CPU_RX_LOCAL_SCRATCH_LOG2_BYTE_SIZE 0x0004
#define RDD_IMAGE_1_CPU_RX_LOCAL_SCRATCH_SIZE     2
#define RDD_IMAGE_1_CPU_RX_LOCAL_SCRATCH_LOG2_SIZE     1
#define IMAGE_1_RX_FLOW_TABLE_ADDRESS 0x0800
#define IMAGE_1_RX_FLOW_TABLE_BYTE_SIZE 0x0280
#define IMAGE_1_RX_FLOW_TABLE_LOG2_BYTE_SIZE 0x000a
#define RDD_IMAGE_1_RX_FLOW_TABLE_SIZE     320
#define RDD_IMAGE_1_RX_FLOW_TABLE_LOG2_SIZE     9
#define IMAGE_1_TC_TO_CPU_RXQ_ADDRESS 0x0a80
#define IMAGE_1_TC_TO_CPU_RXQ_BYTE_SIZE 0x0040
#define IMAGE_1_TC_TO_CPU_RXQ_LOG2_BYTE_SIZE 0x0006
#define RDD_IMAGE_1_TC_TO_CPU_RXQ_SIZE     64
#define RDD_IMAGE_1_TC_TO_CPU_RXQ_LOG2_SIZE     6
#define IMAGE_1_EXC_TC_TO_CPU_RXQ_ADDRESS 0x0ac0
#define IMAGE_1_EXC_TC_TO_CPU_RXQ_BYTE_SIZE 0x0040
#define IMAGE_1_EXC_TC_TO_CPU_RXQ_LOG2_BYTE_SIZE 0x0006
#define RDD_IMAGE_1_EXC_TC_TO_CPU_RXQ_SIZE     64
#define RDD_IMAGE_1_EXC_TC_TO_CPU_RXQ_LOG2_SIZE     6
#define IMAGE_1_VPORT_TO_CPU_OBJ_ADDRESS 0x0b00
#define IMAGE_1_VPORT_TO_CPU_OBJ_BYTE_SIZE 0x0028
#define IMAGE_1_VPORT_TO_CPU_OBJ_LOG2_BYTE_SIZE 0x0006
#define RDD_IMAGE_1_VPORT_TO_CPU_OBJ_SIZE     40
#define RDD_IMAGE_1_VPORT_TO_CPU_OBJ_LOG2_SIZE     6
#define IMAGE_1_CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE_ADDRESS 0x0b28
#define IMAGE_1_CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE_BYTE_SIZE 0x0008
#define IMAGE_1_CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE_LOG2_BYTE_SIZE 0x0003
#define IMAGE_1_FPM_GLOBAL_CFG_ADDRESS 0x0b30
#define IMAGE_1_FPM_GLOBAL_CFG_BYTE_SIZE 0x000c
#define IMAGE_1_FPM_GLOBAL_CFG_LOG2_BYTE_SIZE 0x0004
#define IMAGE_1_TASK_IDX_ADDRESS 0x0b3c
#define IMAGE_1_TASK_IDX_BYTE_SIZE 0x0004
#define IMAGE_1_TASK_IDX_LOG2_BYTE_SIZE 0x0002
#define IMAGE_1_CPU_RX_COPY_LOCAL_SCRATCH_ADDRESS 0x0b40
#define IMAGE_1_CPU_RX_COPY_LOCAL_SCRATCH_BYTE_SIZE 0x0008
#define IMAGE_1_CPU_RX_COPY_LOCAL_SCRATCH_LOG2_BYTE_SIZE 0x0003
#define IMAGE_1_DIRECT_PROCESSING_EPON_CONTROL_SCRATCH_ADDRESS 0x0b48
#define IMAGE_1_DIRECT_PROCESSING_EPON_CONTROL_SCRATCH_BYTE_SIZE 0x0001
#define IMAGE_1_DIRECT_PROCESSING_EPON_CONTROL_SCRATCH_LOG2_BYTE_SIZE 0x0001
#define IMAGE_1_SRAM_DUMMY_STORE_ADDRESS 0x0b49
#define IMAGE_1_SRAM_DUMMY_STORE_BYTE_SIZE 0x0001
#define IMAGE_1_SRAM_DUMMY_STORE_LOG2_BYTE_SIZE 0x0001
#define IMAGE_1_CPU_FEED_RING_INTERRUPT_COUNTER_MAX_ADDRESS 0x0b4a
#define IMAGE_1_CPU_FEED_RING_INTERRUPT_COUNTER_MAX_BYTE_SIZE 0x0002
#define IMAGE_1_CPU_FEED_RING_INTERRUPT_COUNTER_MAX_LOG2_BYTE_SIZE 0x0001
#define IMAGE_1_CPU_FEED_RING_INTERRUPT_THRESHOLD_ADDRESS 0x0b4c
#define IMAGE_1_CPU_FEED_RING_INTERRUPT_THRESHOLD_BYTE_SIZE 0x0002
#define IMAGE_1_CPU_FEED_RING_INTERRUPT_THRESHOLD_LOG2_BYTE_SIZE 0x0001
#define IMAGE_1_CPU_FEED_RING_INTERRUPT_COUNTER_ADDRESS 0x0b4e
#define IMAGE_1_CPU_FEED_RING_INTERRUPT_COUNTER_BYTE_SIZE 0x0002
#define IMAGE_1_CPU_FEED_RING_INTERRUPT_COUNTER_LOG2_BYTE_SIZE 0x0001
#define IMAGE_1_MAC_TYPE_ADDRESS 0x0b50
#define IMAGE_1_MAC_TYPE_BYTE_SIZE 0x0001
#define IMAGE_1_MAC_TYPE_LOG2_BYTE_SIZE 0x0001
#define IMAGE_1_CPU_RECYCLE_INTERRUPT_SCRATCH_ADDRESS 0x0b80
#define IMAGE_1_CPU_RECYCLE_INTERRUPT_SCRATCH_BYTE_SIZE 0x0008
#define IMAGE_1_CPU_RECYCLE_INTERRUPT_SCRATCH_LOG2_BYTE_SIZE 0x0003
#define RDD_IMAGE_1_CPU_RECYCLE_INTERRUPT_SCRATCH_SIZE     2
#define RDD_IMAGE_1_CPU_RECYCLE_INTERRUPT_SCRATCH_LOG2_SIZE     1
#define IMAGE_1_RUNNER_PROFILING_TRACE_BUFFER_ADDRESS 0x0c00
#define IMAGE_1_RUNNER_PROFILING_TRACE_BUFFER_BYTE_SIZE 0x0200
#define IMAGE_1_RUNNER_PROFILING_TRACE_BUFFER_LOG2_BYTE_SIZE 0x0009
#define RDD_IMAGE_1_RUNNER_PROFILING_TRACE_BUFFER_SIZE     128
#define RDD_IMAGE_1_RUNNER_PROFILING_TRACE_BUFFER_LOG2_SIZE     7
#define IMAGE_1_CPU_RECYCLE_SHADOW_RD_IDX_ADDRESS 0x0e00
#define IMAGE_1_CPU_RECYCLE_SHADOW_RD_IDX_BYTE_SIZE 0x0002
#define IMAGE_1_CPU_RECYCLE_SHADOW_RD_IDX_LOG2_BYTE_SIZE 0x0001
#define IMAGE_1_CPU_RECYCLE_SHADOW_WR_IDX_ADDRESS 0x0e80
#define IMAGE_1_CPU_RECYCLE_SHADOW_WR_IDX_BYTE_SIZE 0x0002
#define IMAGE_1_CPU_RECYCLE_SHADOW_WR_IDX_LOG2_BYTE_SIZE 0x0001
#define IMAGE_1_CPU_RING_DESCRIPTORS_TABLE_ADDRESS 0x3000
#define IMAGE_1_CPU_RING_DESCRIPTORS_TABLE_BYTE_SIZE 0x0100
#define IMAGE_1_CPU_RING_DESCRIPTORS_TABLE_LOG2_BYTE_SIZE 0x0008
#define RDD_IMAGE_1_CPU_RING_DESCRIPTORS_TABLE_SIZE     16
#define RDD_IMAGE_1_CPU_RING_DESCRIPTORS_TABLE_LOG2_SIZE     4
/* IMAGE_2 */
#define IMAGE_2_CPU_TX_SCRATCHPAD_ADDRESS 0x0000
#define IMAGE_2_CPU_TX_SCRATCHPAD_BYTE_SIZE 0x0400
#define IMAGE_2_CPU_TX_SCRATCHPAD_LOG2_BYTE_SIZE 0x000a
#define RDD_IMAGE_2_CPU_TX_SCRATCHPAD_SIZE     128
#define RDD_IMAGE_2_CPU_TX_SCRATCHPAD_LOG2_SIZE     7
#define IMAGE_2_RUNNER_PROFILING_TRACE_BUFFER_ADDRESS 0x0400
#define IMAGE_2_RUNNER_PROFILING_TRACE_BUFFER_BYTE_SIZE 0x0200
#define IMAGE_2_RUNNER_PROFILING_TRACE_BUFFER_LOG2_BYTE_SIZE 0x0009
#define RDD_IMAGE_2_RUNNER_PROFILING_TRACE_BUFFER_SIZE     128
#define RDD_IMAGE_2_RUNNER_PROFILING_TRACE_BUFFER_LOG2_SIZE     7
#define IMAGE_2_TX_FLOW_TABLE_ADDRESS 0x0600
#define IMAGE_2_TX_FLOW_TABLE_BYTE_SIZE 0x0140
#define IMAGE_2_TX_FLOW_TABLE_LOG2_BYTE_SIZE 0x0009
#define RDD_IMAGE_2_TX_FLOW_TABLE_SIZE     320
#define RDD_IMAGE_2_TX_FLOW_TABLE_LOG2_SIZE     9
#define IMAGE_2_QUEUE_THRESHOLD_VECTOR_ADDRESS 0x0740
#define IMAGE_2_QUEUE_THRESHOLD_VECTOR_BYTE_SIZE 0x0024
#define IMAGE_2_QUEUE_THRESHOLD_VECTOR_LOG2_BYTE_SIZE 0x0006
#define RDD_IMAGE_2_QUEUE_THRESHOLD_VECTOR_SIZE     9
#define RDD_IMAGE_2_QUEUE_THRESHOLD_VECTOR_LOG2_SIZE     4
#define IMAGE_2_TASK_IDX_ADDRESS 0x0764
#define IMAGE_2_TASK_IDX_BYTE_SIZE 0x0004
#define IMAGE_2_TASK_IDX_LOG2_BYTE_SIZE 0x0002
#define IMAGE_2_CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_ADDRESS 0x0768
#define IMAGE_2_CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_BYTE_SIZE 0x0008
#define IMAGE_2_CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_LOG2_BYTE_SIZE 0x0003
#define IMAGE_2_CPU_TX_FPM_POOL_NUMBER_MAPPING_TABLE_ADDRESS 0x0770
#define IMAGE_2_CPU_TX_FPM_POOL_NUMBER_MAPPING_TABLE_BYTE_SIZE 0x0010
#define IMAGE_2_CPU_TX_FPM_POOL_NUMBER_MAPPING_TABLE_LOG2_BYTE_SIZE 0x0004
#define RDD_IMAGE_2_CPU_TX_FPM_POOL_NUMBER_MAPPING_TABLE_SIZE     16
#define RDD_IMAGE_2_CPU_TX_FPM_POOL_NUMBER_MAPPING_TABLE_LOG2_SIZE     4
#define IMAGE_2_CPU_TX_RING_TABLE_ADDRESS 0x0780
#define IMAGE_2_CPU_TX_RING_TABLE_BYTE_SIZE 0x0080
#define IMAGE_2_CPU_TX_RING_TABLE_LOG2_BYTE_SIZE 0x0007
#define RDD_IMAGE_2_CPU_TX_RING_TABLE_SIZE     8
#define RDD_IMAGE_2_CPU_TX_RING_TABLE_LOG2_SIZE     3
#define IMAGE_2_CPU_RECYCLE_SRAM_PD_FIFO_ADDRESS 0x0800
#define IMAGE_2_CPU_RECYCLE_SRAM_PD_FIFO_BYTE_SIZE 0x0100
#define IMAGE_2_CPU_RECYCLE_SRAM_PD_FIFO_LOG2_BYTE_SIZE 0x0008
#define RDD_IMAGE_2_CPU_RECYCLE_SRAM_PD_FIFO_SIZE     16
#define RDD_IMAGE_2_CPU_RECYCLE_SRAM_PD_FIFO_LOG2_SIZE     4
#define IMAGE_2_REGISTERS_BUFFER_ADDRESS 0x0900
#define IMAGE_2_REGISTERS_BUFFER_BYTE_SIZE 0x0080
#define IMAGE_2_REGISTERS_BUFFER_LOG2_BYTE_SIZE 0x0007
#define RDD_IMAGE_2_REGISTERS_BUFFER_SIZE     32
#define RDD_IMAGE_2_REGISTERS_BUFFER_LOG2_SIZE     5
#define IMAGE_2_RUNNER_GLOBAL_REGISTERS_INIT_ADDRESS 0x0980
#define IMAGE_2_RUNNER_GLOBAL_REGISTERS_INIT_BYTE_SIZE 0x0020
#define IMAGE_2_RUNNER_GLOBAL_REGISTERS_INIT_LOG2_BYTE_SIZE 0x0005
#define RDD_IMAGE_2_RUNNER_GLOBAL_REGISTERS_INIT_SIZE     8
#define RDD_IMAGE_2_RUNNER_GLOBAL_REGISTERS_INIT_LOG2_SIZE     3
#define IMAGE_2_FPM_REPLY_ADDRESS 0x09a0
#define IMAGE_2_FPM_REPLY_BYTE_SIZE 0x0010
#define IMAGE_2_FPM_REPLY_LOG2_BYTE_SIZE 0x0004
#define RDD_IMAGE_2_FPM_REPLY_SIZE     2
#define RDD_IMAGE_2_FPM_REPLY_LOG2_SIZE     1
#define IMAGE_2_CPU_RECYCLE_INTERRUPT_COALESCING_TABLE_ADDRESS 0x09b0
#define IMAGE_2_CPU_RECYCLE_INTERRUPT_COALESCING_TABLE_BYTE_SIZE 0x0010
#define IMAGE_2_CPU_RECYCLE_INTERRUPT_COALESCING_TABLE_LOG2_BYTE_SIZE 0x0004
#define IMAGE_2_CPU_TX_EGRESS_UPDATE_FIFO_TABLE_ADDRESS 0x09c0
#define IMAGE_2_CPU_TX_EGRESS_UPDATE_FIFO_TABLE_BYTE_SIZE 0x0020
#define IMAGE_2_CPU_TX_EGRESS_UPDATE_FIFO_TABLE_LOG2_BYTE_SIZE 0x0005
#define RDD_IMAGE_2_CPU_TX_EGRESS_UPDATE_FIFO_TABLE_SIZE     8
#define RDD_IMAGE_2_CPU_TX_EGRESS_UPDATE_FIFO_TABLE_LOG2_SIZE     3
#define IMAGE_2_CPU_TX_EGRESS_DISPATCHER_CREDIT_TABLE_ADDRESS 0x09e0
#define IMAGE_2_CPU_TX_EGRESS_DISPATCHER_CREDIT_TABLE_BYTE_SIZE 0x000c
#define IMAGE_2_CPU_TX_EGRESS_DISPATCHER_CREDIT_TABLE_LOG2_BYTE_SIZE 0x0004
#define RDD_IMAGE_2_CPU_TX_EGRESS_DISPATCHER_CREDIT_TABLE_SIZE     3
#define RDD_IMAGE_2_CPU_TX_EGRESS_DISPATCHER_CREDIT_TABLE_LOG2_SIZE     2
#define IMAGE_2_CORE_ID_TABLE_ADDRESS 0x09ec
#define IMAGE_2_CORE_ID_TABLE_BYTE_SIZE 0x0001
#define IMAGE_2_CORE_ID_TABLE_LOG2_BYTE_SIZE 0x0001
#define IMAGE_2_SRAM_DUMMY_STORE_ADDRESS 0x09ed
#define IMAGE_2_SRAM_DUMMY_STORE_BYTE_SIZE 0x0001
#define IMAGE_2_SRAM_DUMMY_STORE_LOG2_BYTE_SIZE 0x0001
#define IMAGE_2_CPU_TX_INGRESS_DISPATCHER_CREDIT_TABLE_ADDRESS 0x09f0
#define IMAGE_2_CPU_TX_INGRESS_DISPATCHER_CREDIT_TABLE_BYTE_SIZE 0x000c
#define IMAGE_2_CPU_TX_INGRESS_DISPATCHER_CREDIT_TABLE_LOG2_BYTE_SIZE 0x0004
#define RDD_IMAGE_2_CPU_TX_INGRESS_DISPATCHER_CREDIT_TABLE_SIZE     3
#define RDD_IMAGE_2_CPU_TX_INGRESS_DISPATCHER_CREDIT_TABLE_LOG2_SIZE     2
#define IMAGE_2_CPU_TX_INGRESS_UPDATE_FIFO_TABLE_ADDRESS 0x0a00
#define IMAGE_2_CPU_TX_INGRESS_UPDATE_FIFO_TABLE_BYTE_SIZE 0x0020
#define IMAGE_2_CPU_TX_INGRESS_UPDATE_FIFO_TABLE_LOG2_BYTE_SIZE 0x0005
#define RDD_IMAGE_2_CPU_TX_INGRESS_UPDATE_FIFO_TABLE_SIZE     8
#define RDD_IMAGE_2_CPU_TX_INGRESS_UPDATE_FIFO_TABLE_LOG2_SIZE     3
#define IMAGE_2_CPU_RECYCLE_RING_DESCRIPTOR_TABLE_ADDRESS 0x0a20
#define IMAGE_2_CPU_RECYCLE_RING_DESCRIPTOR_TABLE_BYTE_SIZE 0x0010
#define IMAGE_2_CPU_RECYCLE_RING_DESCRIPTOR_TABLE_LOG2_BYTE_SIZE 0x0004
#define IMAGE_2_CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_ADDRESS 0x0a30
#define IMAGE_2_CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_BYTE_SIZE 0x0010
#define IMAGE_2_CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_LOG2_BYTE_SIZE 0x0004
#define RDD_IMAGE_2_CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_SIZE     2
#define RDD_IMAGE_2_CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_LOG2_SIZE     1
#define IMAGE_2_CPU_TX_EGRESS_PD_FIFO_TABLE_ADDRESS 0x0a40
#define IMAGE_2_CPU_TX_EGRESS_PD_FIFO_TABLE_BYTE_SIZE 0x0020
#define IMAGE_2_CPU_TX_EGRESS_PD_FIFO_TABLE_LOG2_BYTE_SIZE 0x0005
#define RDD_IMAGE_2_CPU_TX_EGRESS_PD_FIFO_TABLE_SIZE     2
#define RDD_IMAGE_2_CPU_TX_EGRESS_PD_FIFO_TABLE_LOG2_SIZE     1
#define IMAGE_2_CPU_RX_INTERRUPT_ID_DDR_ADDR_ADDRESS 0x0a60
#define IMAGE_2_CPU_RX_INTERRUPT_ID_DDR_ADDR_BYTE_SIZE 0x0008
#define IMAGE_2_CPU_RX_INTERRUPT_ID_DDR_ADDR_LOG2_BYTE_SIZE 0x0003
#define IMAGE_2_CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE_ADDRESS 0x0a68
#define IMAGE_2_CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE_BYTE_SIZE 0x0008
#define IMAGE_2_CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE_LOG2_BYTE_SIZE 0x0003
#define IMAGE_2_FPM_GLOBAL_CFG_ADDRESS 0x0a70
#define IMAGE_2_FPM_GLOBAL_CFG_BYTE_SIZE 0x000c
#define IMAGE_2_FPM_GLOBAL_CFG_LOG2_BYTE_SIZE 0x0004
#define IMAGE_2_CPU_TX_INGRESS_PD_FIFO_TABLE_ADDRESS 0x0a80
#define IMAGE_2_CPU_TX_INGRESS_PD_FIFO_TABLE_BYTE_SIZE 0x0020
#define IMAGE_2_CPU_TX_INGRESS_PD_FIFO_TABLE_LOG2_BYTE_SIZE 0x0005
#define RDD_IMAGE_2_CPU_TX_INGRESS_PD_FIFO_TABLE_SIZE     2
#define RDD_IMAGE_2_CPU_TX_INGRESS_PD_FIFO_TABLE_LOG2_SIZE     1
#define IMAGE_2_CPU_RECYCLE_INTERRUPT_SCRATCH_ADDRESS 0x0b00
#define IMAGE_2_CPU_RECYCLE_INTERRUPT_SCRATCH_BYTE_SIZE 0x0008
#define IMAGE_2_CPU_RECYCLE_INTERRUPT_SCRATCH_LOG2_BYTE_SIZE 0x0003
#define RDD_IMAGE_2_CPU_RECYCLE_INTERRUPT_SCRATCH_SIZE     2
#define RDD_IMAGE_2_CPU_RECYCLE_INTERRUPT_SCRATCH_LOG2_SIZE     1
#define IMAGE_2_CPU_RECYCLE_SHADOW_RD_IDX_ADDRESS 0x0b80
#define IMAGE_2_CPU_RECYCLE_SHADOW_RD_IDX_BYTE_SIZE 0x0002
#define IMAGE_2_CPU_RECYCLE_SHADOW_RD_IDX_LOG2_BYTE_SIZE 0x0001
#define IMAGE_2_CPU_RECYCLE_SHADOW_WR_IDX_ADDRESS 0x0c00
#define IMAGE_2_CPU_RECYCLE_SHADOW_WR_IDX_BYTE_SIZE 0x0002
#define IMAGE_2_CPU_RECYCLE_SHADOW_WR_IDX_LOG2_BYTE_SIZE 0x0001
#endif
#endif /* _RDD_RUNNER_DEFS_AUTO_H_ */
