#ifndef RUNNER_B_CODE_ADDRESSES
#define RUNNER_B_CODE_ADDRESSES

#define runner_b_start_task_initialization_task		(0x14)
#define runner_b_initialization_task		(0x14)
#define runner_b_start_task_timer_scheduler_set		(0x34A8)
#define runner_b_timer_scheduler_set		(0x34A8)
#define runner_b_start_task_cpu_rx_wakeup_request		(0x12D8)
#define runner_b_cpu_rx_wakeup_request		(0x12D8)
#define runner_b_start_task_rx_buffer_copy_wakeup_request		(0x2B54)
#define runner_b_rx_buffer_copy_wakeup_request		(0x2B54)
#define runner_b_start_task_cpu_tx_wakeup_request		(0x2DD8)
#define runner_b_cpu_tx_wakeup_request		(0x2DD8)
#define runner_b_start_task_policer_budget_allocator_1st_wakeup_request		(0x39F4)
#define runner_b_policer_budget_allocator_1st_wakeup_request		(0x39F4)
#define runner_b_start_task_rate_control_budget_allocator_1st_wakeup_request		(0x2348)
#define runner_b_rate_control_budget_allocator_1st_wakeup_request		(0x2348)
#define runner_b_start_task_wan_interworking_enqueue_wakeup_request		(0x208)
#define runner_b_wan_interworking_enqueue_wakeup_request		(0x208)
#define runner_b_start_task_wan_tx_wakeup_request		(0x54C)
#define runner_b_wan_tx_wakeup_request		(0x54C)
#define runner_b_start_task_debug_routine		(0x120)
#define runner_b_debug_routine		(0x120)
#define runner_b_start_task_timer_7_1st_wakeup_request		(0x36B0)
#define runner_b_timer_7_1st_wakeup_request		(0x36B0)
#define runner_b_start_task_free_skb_index_wakeup_request		(0x363C)
#define runner_b_free_skb_index_wakeup_request		(0x363C)
#define runner_b_ingress_classification_key_src_ip		(0xE10)
#define runner_b_ingress_classification_key_dst_ip		(0xE54)
#define runner_b_ingress_classification_key_ipv6_flow_label		(0xE98)
#define runner_b_ingress_classification_key_generic_rule_1		(0xEBC)
#define runner_b_ingress_classification_key_generic_rule_2		(0xEC4)
#define runner_b_ingress_classification_key_outer_tpid		(0xF30)
#define runner_b_ingress_classification_key_inner_tpid		(0xF3C)
#define runner_b_ingress_classification_key_src_port		(0xF58)
#define runner_b_ingress_classification_key_dst_port		(0xF78)
#define runner_b_ingress_classification_key_outer_vlan		(0xF98)
#define runner_b_ingress_classification_key_inner_vlan		(0xFB0)
#define runner_b_ingress_classification_key_dst_mac		(0xFCC)
#define runner_b_ingress_classification_key_src_mac		(0xFD4)
#define runner_b_ingress_classification_key_ether_type		(0xFFC)
#define runner_b_ingress_classification_key_ip_protocol		(0x1010)
#define runner_b_ingress_classification_key_dscp		(0x1034)
#define runner_b_ingress_classification_key_ssid		(0x1050)
#define runner_b_ingress_classification_key_ingress_port		(0x1068)
#define runner_b_ingress_classification_key_outer_pbits		(0x1078)
#define runner_b_ingress_classification_key_inner_pbits		(0x1090)
#define runner_b_ingress_classification_key_number_of_vlans		(0x10AC)
#define runner_b_ingress_classification_key_layer3_protocol		(0x10BC)
#define runner_b_spdsvc_timer_wakeup_request		(0x3414)
#define runner_b_cpu_rx_meter_budget_allocate		(0x3528)
#define runner_b_upstream_rate_limiter_budget_allocate		(0x3574)
#define runner_b_schedule_free_skb_index		(0x3620)
#define runner_b_pps_rate_limiter_timer_wakeup_request		(0x3714)

#endif
