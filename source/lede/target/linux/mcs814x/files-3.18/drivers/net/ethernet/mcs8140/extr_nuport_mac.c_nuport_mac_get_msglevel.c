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
typedef  int /*<<< orphan*/  u32 ;
struct nuport_mac_priv {int /*<<< orphan*/  msg_level; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 struct nuport_mac_priv* netdev_priv (struct net_device*) ; 

__attribute__((used)) static u32 nuport_mac_get_msglevel(struct net_device *dev)
{
	struct nuport_mac_priv *priv = netdev_priv(dev);

	return priv->msg_level;
}