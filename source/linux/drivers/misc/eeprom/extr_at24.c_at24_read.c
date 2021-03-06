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
struct device {int dummy; } ;
struct at24_data {unsigned int byte_len; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int EINVAL ; 
 struct device* at24_base_client_dev (struct at24_data*) ; 
 int at24_regmap_read (struct at24_data*,char*,unsigned int,size_t) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int pm_runtime_get_sync (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put_noidle (struct device*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static int at24_read(void *priv, unsigned int off, void *val, size_t count)
{
	struct at24_data *at24;
	struct device *dev;
	char *buf = val;
	int ret;

	at24 = priv;
	dev = at24_base_client_dev(at24);

	if (unlikely(!count))
		return count;

	if (off + count > at24->byte_len)
		return -EINVAL;

	ret = pm_runtime_get_sync(dev);
	if (ret < 0) {
		pm_runtime_put_noidle(dev);
		return ret;
	}

	/*
	 * Read data from chip, protecting against concurrent updates
	 * from this host, but not from other I2C masters.
	 */
	mutex_lock(&at24->lock);

	while (count) {
		ret = at24_regmap_read(at24, buf, off, count);
		if (ret < 0) {
			mutex_unlock(&at24->lock);
			pm_runtime_put(dev);
			return ret;
		}
		buf += ret;
		off += ret;
		count -= ret;
	}

	mutex_unlock(&at24->lock);

	pm_runtime_put(dev);

	return 0;
}