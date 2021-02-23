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
struct tc35815_local {int /*<<< orphan*/  phy_dev; } ;
struct net_device {int dummy; } ;
struct ifreq {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int /*<<< orphan*/  if_mii (struct ifreq*) ; 
 struct tc35815_local* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_running (struct net_device*) ; 
 int phy_mii_ioctl (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int tc35815_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
	struct tc35815_local *lp = netdev_priv(dev);

	if (!netif_running(dev))
		return -EINVAL;
	if (!lp->phy_dev)
		return -ENODEV;
	return phy_mii_ioctl(lp->phy_dev, if_mii(rq), cmd);
}