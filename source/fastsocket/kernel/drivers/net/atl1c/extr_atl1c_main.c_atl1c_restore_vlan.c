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
struct pci_dev {int /*<<< orphan*/  dev; } ;
struct atl1c_adapter {int /*<<< orphan*/  vlgrp; int /*<<< orphan*/  netdev; struct pci_dev* pdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  atl1c_vlan_rx_register (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ netif_msg_pktdata (struct atl1c_adapter*) ; 

__attribute__((used)) static void atl1c_restore_vlan(struct atl1c_adapter *adapter)
{
	struct pci_dev *pdev = adapter->pdev;

	if (netif_msg_pktdata(adapter))
		dev_dbg(&pdev->dev, "atl1c_restore_vlan !");
	atl1c_vlan_rx_register(adapter->netdev, adapter->vlgrp);
}