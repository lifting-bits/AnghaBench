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

/* Variables and functions */
 int netdev_has_upper_dev_all_rcu (struct net_device*,struct net_device*) ; 

__attribute__((used)) static inline bool rdma_is_upper_dev_rcu(struct net_device *dev,
					 struct net_device *upper)
{
	return netdev_has_upper_dev_all_rcu(dev, upper);
}