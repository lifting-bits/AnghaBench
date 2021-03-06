#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int uint32_t ;
struct ena_eth_io_rx_cdesc_base {int status; } ;

/* Variables and functions */
 int ENA_ETH_IO_RX_CDESC_BASE_SRC_VLAN_CNT_MASK ; 
 int ENA_ETH_IO_RX_CDESC_BASE_SRC_VLAN_CNT_SHIFT ; 

__attribute__((used)) static inline void set_ena_eth_io_rx_cdesc_base_src_vlan_cnt(struct ena_eth_io_rx_cdesc_base *p, uint32_t val)
{
	p->status |= (val << ENA_ETH_IO_RX_CDESC_BASE_SRC_VLAN_CNT_SHIFT) & ENA_ETH_IO_RX_CDESC_BASE_SRC_VLAN_CNT_MASK;
}