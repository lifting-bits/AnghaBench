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
typedef  scalar_t__ u16 ;
struct ipath_devdata {int /*<<< orphan*/  ipath_lmc; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ IPATH_MULTICAST_LID_BASE ; 
 struct ipath_devdata* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  ipath_dev_err (struct ipath_devdata*,char*,scalar_t__) ; 
 int ipath_parse_ushort (char const*,scalar_t__*) ; 
 int /*<<< orphan*/  ipath_set_lid (struct ipath_devdata*,scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t store_lid(struct device *dev,
			 struct device_attribute *attr,
			  const char *buf,
			  size_t count)
{
	struct ipath_devdata *dd = dev_get_drvdata(dev);
	u16 lid = 0;
	int ret;

	ret = ipath_parse_ushort(buf, &lid);
	if (ret < 0)
		goto invalid;

	if (lid == 0 || lid >= IPATH_MULTICAST_LID_BASE) {
		ret = -EINVAL;
		goto invalid;
	}

	ipath_set_lid(dd, lid, dd->ipath_lmc);

	goto bail;
invalid:
	ipath_dev_err(dd, "attempt to set invalid LID 0x%x\n", lid);
bail:
	return ret;
}