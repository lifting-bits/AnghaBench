#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  timer; } ;
struct net_bridge {TYPE_1__ gc_work; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  br_timer_value (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int /*<<< orphan*/ ) ; 
 struct net_bridge* to_bridge (struct device*) ; 

__attribute__((used)) static ssize_t gc_timer_show(struct device *d, struct device_attribute *attr,
			     char *buf)
{
	struct net_bridge *br = to_bridge(d);
	return sprintf(buf, "%ld\n", br_timer_value(&br->gc_work.timer));
}