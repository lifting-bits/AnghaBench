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
typedef  int u32 ;
struct nuport_mac_priv {int dummy; } ;
struct net_device {int dummy; } ;
struct mii_bus {struct net_device* priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  MII_ADDR_REG ; 
 int MII_ADDR_SHIFT ; 
 int MII_BUSY ; 
 int /*<<< orphan*/  MII_DATA_REG ; 
 int MII_REG_SHIFT ; 
 struct nuport_mac_priv* netdev_priv (struct net_device*) ; 
 int nuport_mac_mii_busy_wait (struct nuport_mac_priv*) ; 
 int nuport_mac_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nuport_mac_writel (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int nuport_mac_mii_read(struct mii_bus *bus,
				int mii_id, int regnum)
{
	struct net_device *dev = bus->priv;
	struct nuport_mac_priv *priv = netdev_priv(dev);
	int ret;
	u32 val = 0;

	ret = nuport_mac_mii_busy_wait(priv);
	if (ret)
		return ret;

	val |= (mii_id << MII_ADDR_SHIFT) | (regnum << MII_REG_SHIFT) | MII_BUSY;
	nuport_mac_writel(val, MII_ADDR_REG);
	ret = nuport_mac_mii_busy_wait(priv);
	if (ret)
		return ret;

	return nuport_mac_readl(MII_DATA_REG);
}