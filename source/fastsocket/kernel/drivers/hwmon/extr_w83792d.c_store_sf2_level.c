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
typedef  int u8 ;
typedef  int u32 ;
struct w83792d_data {int** sf2_levels; int /*<<< orphan*/  update_lock; } ;
struct sensor_device_attribute_2 {int nr; int index; } ;
struct i2c_client {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 int SENSORS_LIMIT (int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ ** W83792D_REG_LEVELS ; 
 struct w83792d_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int simple_strtoul (char const*,int /*<<< orphan*/ *,int) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 
 struct sensor_device_attribute_2* to_sensor_dev_attr_2 (struct device_attribute*) ; 
 int w83792d_read_value (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  w83792d_write_value (struct i2c_client*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static ssize_t
store_sf2_level(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	struct sensor_device_attribute_2 *sensor_attr = to_sensor_dev_attr_2(attr);
	int nr = sensor_attr->nr;
	int index = sensor_attr->index - 1;
	struct i2c_client *client = to_i2c_client(dev);
	struct w83792d_data *data = i2c_get_clientdata(client);
	u32 val;
	u8 mask_tmp=0, level_tmp=0;

	val = simple_strtoul(buf, NULL, 10);
	mutex_lock(&data->update_lock);
	data->sf2_levels[index][nr] = SENSORS_LIMIT((val * 15) / 100, 0, 15);
	mask_tmp = w83792d_read_value(client, W83792D_REG_LEVELS[index][nr])
		& ((nr==3) ? 0xf0 : 0x0f);
	if (nr==3) {
		level_tmp = data->sf2_levels[index][nr];
	} else {
		level_tmp = data->sf2_levels[index][nr] << 4;
	}
	w83792d_write_value(client, W83792D_REG_LEVELS[index][nr], level_tmp | mask_tmp);
	mutex_unlock(&data->update_lock);

	return count;
}