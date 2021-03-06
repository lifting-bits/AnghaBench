#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct ixgbe_ring_feature {int offset; int indices; } ;
struct ixgbe_hw {int dummy; } ;
struct ixgbe_adapter {int flags; TYPE_2__** rx_ring; TYPE_1__* netdev; struct ixgbe_hw hw; struct ixgbe_ring_feature* ring_feature; } ;
struct TYPE_4__ {int reg_idx; } ;
struct TYPE_3__ {int features; } ;

/* Variables and functions */
 int ETH_P_FCOE ; 
 int ETH_P_FIP ; 
 int FC_FCOE_VER ; 
 int /*<<< orphan*/  IXGBE_ETQF (int /*<<< orphan*/ ) ; 
 int IXGBE_ETQF_FCOE ; 
 int IXGBE_ETQF_FILTER_EN ; 
 int /*<<< orphan*/  IXGBE_ETQF_FILTER_FCOE ; 
 int /*<<< orphan*/  IXGBE_ETQF_FILTER_FIP ; 
 int IXGBE_ETQF_POOL_ENABLE ; 
 int IXGBE_ETQF_POOL_SHIFT ; 
 int /*<<< orphan*/  IXGBE_ETQS (int /*<<< orphan*/ ) ; 
 int IXGBE_ETQS_QUEUE_EN ; 
 int IXGBE_ETQS_RX_QUEUE_SHIFT ; 
 int /*<<< orphan*/  IXGBE_FCRECTL ; 
 int IXGBE_FCRECTL_ENA ; 
 int /*<<< orphan*/  IXGBE_FCRETA (int) ; 
 int IXGBE_FCRETA_ENTRY_MASK ; 
 int IXGBE_FCRETA_SIZE ; 
 int /*<<< orphan*/  IXGBE_FCRXCTRL ; 
 int IXGBE_FCRXCTRL_FCCRCBO ; 
 int IXGBE_FCRXCTRL_FCOEVER_SHIFT ; 
 int IXGBE_FLAG_FCOE_ENABLED ; 
 int IXGBE_FLAG_SRIOV_ENABLED ; 
 int /*<<< orphan*/  IXGBE_WRITE_REG (struct ixgbe_hw*,int /*<<< orphan*/ ,int) ; 
 int NETIF_F_FCOE_CRC ; 
 size_t RING_F_FCOE ; 
 int VMDQ_P (int /*<<< orphan*/ ) ; 

void ixgbe_configure_fcoe(struct ixgbe_adapter *adapter)
{
	struct ixgbe_ring_feature *fcoe = &adapter->ring_feature[RING_F_FCOE];
	struct ixgbe_hw *hw = &adapter->hw;
	int i, fcoe_q, fcoe_i;
	u32 etqf;

	/* Minimal functionality for FCoE requires at least CRC offloads */
	if (!(adapter->netdev->features & NETIF_F_FCOE_CRC))
		return;

	/* Enable L2 EtherType filter for FCoE, needed for FCoE CRC and DDP */
	etqf = ETH_P_FCOE | IXGBE_ETQF_FCOE | IXGBE_ETQF_FILTER_EN;
	if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED) {
		etqf |= IXGBE_ETQF_POOL_ENABLE;
		etqf |= VMDQ_P(0) << IXGBE_ETQF_POOL_SHIFT;
	}
	IXGBE_WRITE_REG(hw, IXGBE_ETQF(IXGBE_ETQF_FILTER_FCOE), etqf);
	IXGBE_WRITE_REG(hw, IXGBE_ETQS(IXGBE_ETQF_FILTER_FCOE), 0);

	/* leave registers un-configured if FCoE is disabled */
	if (!(adapter->flags & IXGBE_FLAG_FCOE_ENABLED))
		return;

	/* Use one or more Rx queues for FCoE by redirection table */
	for (i = 0; i < IXGBE_FCRETA_SIZE; i++) {
		fcoe_i = fcoe->offset + (i % fcoe->indices);
		fcoe_i &= IXGBE_FCRETA_ENTRY_MASK;
		fcoe_q = adapter->rx_ring[fcoe_i]->reg_idx;
		IXGBE_WRITE_REG(hw, IXGBE_FCRETA(i), fcoe_q);
	}
	IXGBE_WRITE_REG(hw, IXGBE_FCRECTL, IXGBE_FCRECTL_ENA);

	/* Enable L2 EtherType filter for FIP */
	etqf = ETH_P_FIP | IXGBE_ETQF_FILTER_EN;
	if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED) {
		etqf |= IXGBE_ETQF_POOL_ENABLE;
		etqf |= VMDQ_P(0) << IXGBE_ETQF_POOL_SHIFT;
	}
	IXGBE_WRITE_REG(hw, IXGBE_ETQF(IXGBE_ETQF_FILTER_FIP), etqf);

	/* Send FIP frames to the first FCoE queue */
	fcoe_q = adapter->rx_ring[fcoe->offset]->reg_idx;
	IXGBE_WRITE_REG(hw, IXGBE_ETQS(IXGBE_ETQF_FILTER_FIP),
			IXGBE_ETQS_QUEUE_EN |
			(fcoe_q << IXGBE_ETQS_RX_QUEUE_SHIFT));

	/* Configure FCoE Rx control */
	IXGBE_WRITE_REG(hw, IXGBE_FCRXCTRL,
			IXGBE_FCRXCTRL_FCCRCBO |
			(FC_FCOE_VER << IXGBE_FCRXCTRL_FCOEVER_SHIFT));
}