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
struct sensor_device_attribute {size_t index; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct adt7473_data {int /*<<< orphan*/ * fan; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 scalar_t__ FAN_DATA_VALID (int /*<<< orphan*/ ) ; 
 int FAN_PERIOD_TO_RPM (int /*<<< orphan*/ ) ; 
 struct adt7473_data* adt7473_update_device (struct device*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,...) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static ssize_t show_fan(struct device *dev, struct device_attribute *devattr,
			char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct adt7473_data *data = adt7473_update_device(dev);

	if (FAN_DATA_VALID(data->fan[attr->index]))
		return sprintf(buf, "%d\n",
			       FAN_PERIOD_TO_RPM(data->fan[attr->index]));
	else
		return sprintf(buf, "0\n");
}