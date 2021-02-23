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
struct ucc_geth_private {int /*<<< orphan*/  phydev; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 struct ucc_geth_private* netdev_priv (struct net_device*) ; 
 int phy_start_aneg (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int uec_nway_reset(struct net_device *netdev)
{
	struct ucc_geth_private *ugeth = netdev_priv(netdev);

	return phy_start_aneg(ugeth->phydev);
}