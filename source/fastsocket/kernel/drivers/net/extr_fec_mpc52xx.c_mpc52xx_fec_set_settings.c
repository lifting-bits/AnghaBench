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
struct net_device {int dummy; } ;
struct mpc52xx_fec_priv {int /*<<< orphan*/  phydev; } ;
struct ethtool_cmd {int dummy; } ;

/* Variables and functions */
 int ENODEV ; 
 struct mpc52xx_fec_priv* netdev_priv (struct net_device*) ; 
 int phy_ethtool_sset (int /*<<< orphan*/ ,struct ethtool_cmd*) ; 

__attribute__((used)) static int mpc52xx_fec_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
	struct mpc52xx_fec_priv *priv = netdev_priv(dev);

	if (!priv->phydev)
		return -ENODEV;

	return phy_ethtool_sset(priv->phydev, cmd);
}