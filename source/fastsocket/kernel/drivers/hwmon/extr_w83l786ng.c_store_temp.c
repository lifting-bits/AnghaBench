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
struct w83l786ng_data {int /*<<< orphan*/  update_lock; int /*<<< orphan*/ ** temp; } ;
struct sensor_device_attribute_2 {int nr; int index; } ;
struct i2c_client {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  size_t ssize_t ;
typedef  int /*<<< orphan*/  s32 ;

/* Variables and functions */
 int /*<<< orphan*/  TEMP_TO_REG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ ** W83L786NG_REG_TEMP ; 
 struct w83l786ng_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  simple_strtol (char const*,int /*<<< orphan*/ *,int) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 
 struct sensor_device_attribute_2* to_sensor_dev_attr_2 (struct device_attribute*) ; 
 int /*<<< orphan*/  w83l786ng_write_value (struct i2c_client*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t
store_temp(struct device *dev, struct device_attribute *attr,
	   const char *buf, size_t count)
{
	struct sensor_device_attribute_2 *sensor_attr =
	    to_sensor_dev_attr_2(attr);
	int nr = sensor_attr->nr;
	int index = sensor_attr->index;
	struct i2c_client *client = to_i2c_client(dev);
	struct w83l786ng_data *data = i2c_get_clientdata(client);
	s32 val;

	val = simple_strtol(buf, NULL, 10);
	mutex_lock(&data->update_lock);
	data->temp[nr][index] = TEMP_TO_REG(val);
	w83l786ng_write_value(client, W83L786NG_REG_TEMP[nr][index],
			      data->temp[nr][index]);
	mutex_unlock(&data->update_lock);

        return count;
}