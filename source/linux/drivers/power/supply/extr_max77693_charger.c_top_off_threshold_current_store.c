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
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  device_attr_store (struct device*,struct device_attribute*,char const*,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  max77693_set_top_off_threshold_current ; 

__attribute__((used)) static ssize_t top_off_threshold_current_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	return device_attr_store(dev, attr, buf, count,
			max77693_set_top_off_threshold_current);
}