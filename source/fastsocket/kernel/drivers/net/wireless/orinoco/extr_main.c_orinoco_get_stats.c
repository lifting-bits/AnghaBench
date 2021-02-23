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
struct orinoco_private {struct net_device_stats stats; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 struct orinoco_private* ndev_priv (struct net_device*) ; 

struct net_device_stats *orinoco_get_stats(struct net_device *dev)
{
	struct orinoco_private *priv = ndev_priv(dev);

	return &priv->stats;
}