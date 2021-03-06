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
struct ena_eth_io_numa_node_cfg_reg {int numa_cfg; } ;

/* Variables and functions */
 int ENA_ETH_IO_NUMA_NODE_CFG_REG_NUMA_MASK ; 

__attribute__((used)) static inline void set_ena_eth_io_numa_node_cfg_reg_numa(struct ena_eth_io_numa_node_cfg_reg *p, uint32_t val)
{
	p->numa_cfg |= val & ENA_ETH_IO_NUMA_NODE_CFG_REG_NUMA_MASK;
}