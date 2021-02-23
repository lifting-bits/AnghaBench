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
typedef  int /*<<< orphan*/  u32 ;
struct lm93_data {int prochot_override; int /*<<< orphan*/  update_lock; } ;
struct i2c_client {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  LM93_REG_PROCHOT_OVERRIDE ; 
 int SENSORS_LIMIT (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct lm93_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  lm93_write_byte (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  simple_strtoul (char const*,int /*<<< orphan*/ *,int) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 

__attribute__((used)) static ssize_t store_prochot_override_duty_cycle(struct device *dev,
						struct device_attribute *attr,
						const char *buf, size_t count)
{
	struct i2c_client *client = to_i2c_client(dev);
	struct lm93_data *data = i2c_get_clientdata(client);
	u32 val = simple_strtoul(buf, NULL, 10);

	mutex_lock(&data->update_lock);
	data->prochot_override = (data->prochot_override & 0xf0) |
					SENSORS_LIMIT(val, 0, 15);
	lm93_write_byte(client, LM93_REG_PROCHOT_OVERRIDE,
			data->prochot_override);
	mutex_unlock(&data->update_lock);
	return count;
}