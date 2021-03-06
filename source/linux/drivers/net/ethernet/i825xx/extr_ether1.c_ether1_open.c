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
struct net_device {int /*<<< orphan*/  irq; } ;

/* Variables and functions */
 int EAGAIN ; 
 scalar_t__ ether1_init_for_open (struct net_device*) ; 
 int /*<<< orphan*/  ether1_interrupt ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,struct net_device*) ; 
 int /*<<< orphan*/  netif_start_queue (struct net_device*) ; 
 scalar_t__ request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,struct net_device*) ; 

__attribute__((used)) static int
ether1_open (struct net_device *dev)
{
	if (request_irq(dev->irq, ether1_interrupt, 0, "ether1", dev))
		return -EAGAIN;

	if (ether1_init_for_open (dev)) {
		free_irq (dev->irq, dev);
		return -EAGAIN;
	}

	netif_start_queue(dev);

	return 0;
}