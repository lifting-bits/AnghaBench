#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct ixgbe_adapter {int flags; int /*<<< orphan*/  state; TYPE_1__* netdev; } ;
struct TYPE_2__ {int /*<<< orphan*/  trans_start; } ;

/* Variables and functions */
 int IXGBE_FLAG_SRIOV_ENABLED ; 
 int /*<<< orphan*/  WARN_ON (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __IXGBE_RESETTING ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  in_interrupt () ; 
 int /*<<< orphan*/  ixgbe_down (struct ixgbe_adapter*) ; 
 int /*<<< orphan*/  ixgbe_up (struct ixgbe_adapter*) ; 
 int /*<<< orphan*/  jiffies ; 
 int /*<<< orphan*/  msleep (int) ; 
 scalar_t__ test_and_set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

void ixgbe_reinit_locked(struct ixgbe_adapter *adapter)
{
	WARN_ON(in_interrupt());
	/* put off any impending NetWatchDogTimeout */
	adapter->netdev->trans_start = jiffies;

	while (test_and_set_bit(__IXGBE_RESETTING, &adapter->state))
		usleep_range(1000, 2000);
	ixgbe_down(adapter);
	/*
	 * If SR-IOV enabled then wait a bit before bringing the adapter
	 * back up to give the VFs time to respond to the reset.  The
	 * two second wait is based upon the watchdog timer cycle in
	 * the VF driver.
	 */
	if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED)
		msleep(2000);
	ixgbe_up(adapter);
	clear_bit(__IXGBE_RESETTING, &adapter->state);
}