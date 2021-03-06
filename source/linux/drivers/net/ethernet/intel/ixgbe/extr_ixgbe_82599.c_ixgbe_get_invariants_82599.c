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
struct ixgbe_mac_info {int /*<<< orphan*/  max_msix_vectors; int /*<<< orphan*/  max_tx_queues; int /*<<< orphan*/  max_rx_queues; int /*<<< orphan*/  rx_pb_size; int /*<<< orphan*/  num_rar_entries; int /*<<< orphan*/  vft_size; int /*<<< orphan*/  mcft_size; } ;
struct ixgbe_hw {struct ixgbe_mac_info mac; } ;
typedef  int /*<<< orphan*/  s32 ;

/* Variables and functions */
 int /*<<< orphan*/  IXGBE_82599_MAX_RX_QUEUES ; 
 int /*<<< orphan*/  IXGBE_82599_MAX_TX_QUEUES ; 
 int /*<<< orphan*/  IXGBE_82599_MC_TBL_SIZE ; 
 int /*<<< orphan*/  IXGBE_82599_RAR_ENTRIES ; 
 int /*<<< orphan*/  IXGBE_82599_RX_PB_SIZE ; 
 int /*<<< orphan*/  IXGBE_82599_VFT_TBL_SIZE ; 
 int /*<<< orphan*/  ixgbe_get_pcie_msix_count_generic (struct ixgbe_hw*) ; 
 int /*<<< orphan*/  ixgbe_init_mac_link_ops_82599 (struct ixgbe_hw*) ; 

__attribute__((used)) static s32 ixgbe_get_invariants_82599(struct ixgbe_hw *hw)
{
	struct ixgbe_mac_info *mac = &hw->mac;

	ixgbe_init_mac_link_ops_82599(hw);

	mac->mcft_size = IXGBE_82599_MC_TBL_SIZE;
	mac->vft_size = IXGBE_82599_VFT_TBL_SIZE;
	mac->num_rar_entries = IXGBE_82599_RAR_ENTRIES;
	mac->rx_pb_size = IXGBE_82599_RX_PB_SIZE;
	mac->max_rx_queues = IXGBE_82599_MAX_RX_QUEUES;
	mac->max_tx_queues = IXGBE_82599_MAX_TX_QUEUES;
	mac->max_msix_vectors = ixgbe_get_pcie_msix_count_generic(hw);

	return 0;
}