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
struct pcmcia_device {scalar_t__ dev_node; struct net_device* priv; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  pcmcia_disable_device (struct pcmcia_device*) ; 
 int /*<<< orphan*/  unregister_netdev (struct net_device*) ; 

__attribute__((used)) static void wl3501_release(struct pcmcia_device *link)
{
	struct net_device *dev = link->priv;

	/* Unlink the device chain */
	if (link->dev_node)
		unregister_netdev(dev);

	pcmcia_disable_device(link);
}