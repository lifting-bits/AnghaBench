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
struct net_device {int features; } ;

/* Variables and functions */
 int NETIF_F_SG ; 

__attribute__((used)) static bool xennet_can_sg(struct net_device *dev)
{
	return dev->features & NETIF_F_SG;
}