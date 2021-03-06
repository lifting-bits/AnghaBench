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
typedef  size_t ssize_t ;

/* Variables and functions */
 size_t EINVAL ; 
 int sscanf (char const*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usbip_debug_flag ; 

__attribute__((used)) static ssize_t usbip_debug_store(struct device *dev,
				 struct device_attribute *attr, const char *buf,
				 size_t count)
{
	if (sscanf(buf, "%lx", &usbip_debug_flag) != 1)
		return -EINVAL;
	return count;
}