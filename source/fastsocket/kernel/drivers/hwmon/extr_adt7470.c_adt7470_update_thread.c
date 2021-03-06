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
struct adt7470_data {int /*<<< orphan*/  auto_update_stop; int /*<<< orphan*/  auto_update_interval; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  adt7470_read_temperatures (struct i2c_client*,struct adt7470_data*) ; 
 int /*<<< orphan*/  complete_all (int /*<<< orphan*/ *) ; 
 struct adt7470_data* i2c_get_clientdata (struct i2c_client*) ; 
 scalar_t__ kthread_should_stop () ; 
 int /*<<< orphan*/  msleep_interruptible (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int adt7470_update_thread(void *p)
{
	struct i2c_client *client = p;
	struct adt7470_data *data = i2c_get_clientdata(client);

	while (!kthread_should_stop()) {
		mutex_lock(&data->lock);
		adt7470_read_temperatures(client, data);
		mutex_unlock(&data->lock);
		if (kthread_should_stop())
			break;
		msleep_interruptible(data->auto_update_interval);
	}

	complete_all(&data->auto_update_stop);
	return 0;
}