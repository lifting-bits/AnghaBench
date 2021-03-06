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
struct switchdev_obj {int flags; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT_RTNL () ; 
 int SWITCHDEV_F_DEFER ; 
 int switchdev_port_obj_del_defer (struct net_device*,struct switchdev_obj const*) ; 
 int switchdev_port_obj_del_now (struct net_device*,struct switchdev_obj const*) ; 

int switchdev_port_obj_del(struct net_device *dev,
			   const struct switchdev_obj *obj)
{
	if (obj->flags & SWITCHDEV_F_DEFER)
		return switchdev_port_obj_del_defer(dev, obj);
	ASSERT_RTNL();
	return switchdev_port_obj_del_now(dev, obj);
}