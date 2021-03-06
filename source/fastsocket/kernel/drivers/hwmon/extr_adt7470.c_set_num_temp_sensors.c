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
struct i2c_client {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct adt7470_data {long num_temp_sensors; int /*<<< orphan*/  lock; scalar_t__ temperatures_probed; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 size_t EINVAL ; 
 long SENSORS_LIMIT (long,int,int) ; 
 struct adt7470_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ strict_strtol (char const*,int,long*) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 

__attribute__((used)) static ssize_t set_num_temp_sensors(struct device *dev,
				    struct device_attribute *devattr,
				    const char *buf,
				    size_t count)
{
	struct i2c_client *client = to_i2c_client(dev);
	struct adt7470_data *data = i2c_get_clientdata(client);
	long temp;

	if (strict_strtol(buf, 10, &temp))
		return -EINVAL;

	temp = SENSORS_LIMIT(temp, -1, 10);

	mutex_lock(&data->lock);
	data->num_temp_sensors = temp;
	if (temp < 0)
		data->temperatures_probed = 0;
	mutex_unlock(&data->lock);

	return count;
}