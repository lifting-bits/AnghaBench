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
struct net_device_stats {int dummy; } ;
struct net_device {int dummy; } ;
struct ks_wlan_private {scalar_t__ dev_state; struct net_device_stats nstats; } ;

/* Variables and functions */
 scalar_t__ DEVICE_STATE_READY ; 
 struct ks_wlan_private* netdev_priv (struct net_device*) ; 

__attribute__((used)) static
struct net_device_stats *ks_wlan_get_stats(struct net_device *dev)
{
	struct ks_wlan_private *priv = netdev_priv(dev);

	if (priv->dev_state < DEVICE_STATE_READY)
		return NULL;	/* not finished initialize */

	return &priv->nstats;
}