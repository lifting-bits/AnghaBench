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
struct platform_device {int dummy; } ;
struct net_device {int dummy; } ;
struct ag71xx {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ag71xx_debugfs_exit (struct ag71xx*) ; 
 int /*<<< orphan*/  ag71xx_phy_disconnect (struct ag71xx*) ; 
 struct ag71xx* netdev_priv (struct net_device*) ; 
 struct net_device* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  unregister_netdev (struct net_device*) ; 

__attribute__((used)) static int ag71xx_remove(struct platform_device *pdev)
{
	struct net_device *dev = platform_get_drvdata(pdev);
	struct ag71xx *ag;

	if (!dev)
		return 0;

	ag = netdev_priv(dev);
	ag71xx_debugfs_exit(ag);
	ag71xx_phy_disconnect(ag);
	unregister_netdev(dev);
	platform_set_drvdata(pdev, NULL);
	return 0;
}