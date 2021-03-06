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
struct ib_uverbs_device {TYPE_1__* ib_dev; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
struct TYPE_2__ {int uverbs_abi_ver; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENODEV ; 
 struct ib_uverbs_device* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 

__attribute__((used)) static ssize_t show_dev_abi_version(struct device *device,
				    struct device_attribute *attr, char *buf)
{
	struct ib_uverbs_device *dev = dev_get_drvdata(device);

	if (!dev)
		return -ENODEV;

	return sprintf(buf, "%d\n", dev->ib_dev->uverbs_abi_ver);
}