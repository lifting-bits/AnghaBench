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
struct i2c_client {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct adt7473_data {long* fan_min; int /*<<< orphan*/  lock; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  ADT7473_REG_FAN_MIN (size_t) ; 
 size_t EINVAL ; 
 long FAN_RPM_TO_PERIOD (long) ; 
 long SENSORS_LIMIT (long,int,int) ; 
 int /*<<< orphan*/  adt7473_write_word_data (struct i2c_client*,int /*<<< orphan*/ ,long) ; 
 struct adt7473_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ strict_strtol (char const*,int,long*) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static ssize_t set_fan_min(struct device *dev,
			   struct device_attribute *devattr,
			   const char *buf, size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct i2c_client *client = to_i2c_client(dev);
	struct adt7473_data *data = i2c_get_clientdata(client);
	long temp;

	if (strict_strtol(buf, 10, &temp) || !temp)
		return -EINVAL;

	temp = FAN_RPM_TO_PERIOD(temp);
	temp = SENSORS_LIMIT(temp, 1, 65534);

	mutex_lock(&data->lock);
	data->fan_min[attr->index] = temp;
	adt7473_write_word_data(client, ADT7473_REG_FAN_MIN(attr->index), temp);
	mutex_unlock(&data->lock);

	return count;
}