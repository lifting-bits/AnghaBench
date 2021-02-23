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
typedef  int u8 ;
typedef  int u32 ;
struct lm93_data {int /*<<< orphan*/  update_lock; } ;
struct i2c_client {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  size_t ssize_t ;
struct TYPE_2__ {int index; } ;

/* Variables and functions */
 int /*<<< orphan*/  LM93_PWM_CTL4 ; 
 int /*<<< orphan*/  LM93_REG_PWM_CTL (int,int /*<<< orphan*/ ) ; 
 struct lm93_data* i2c_get_clientdata (struct i2c_client*) ; 
 int lm93_read_byte (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lm93_write_fan_smart_tach (struct i2c_client*,struct lm93_data*,int,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int simple_strtoul (char const*,int /*<<< orphan*/ *,int) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 
 TYPE_1__* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static ssize_t store_fan_smart_tach(struct device *dev,
					struct device_attribute *attr,
					const char *buf, size_t count)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct i2c_client *client = to_i2c_client(dev);
	struct lm93_data *data = i2c_get_clientdata(client);
	u32 val = simple_strtoul(buf, NULL, 10);

	mutex_lock(&data->update_lock);
	/* sanity test, ignore the write otherwise */
	if (0 <= val && val <= 2) {
		/* can't enable if pwm freq is 22.5KHz */
		if (val) {
			u8 ctl4 = lm93_read_byte(client,
				LM93_REG_PWM_CTL(val-1,LM93_PWM_CTL4));
			if ((ctl4 & 0x07) == 0)
				val = 0;
		}
		lm93_write_fan_smart_tach(client, data, nr, val);
	}
	mutex_unlock(&data->update_lock);
	return count;
}