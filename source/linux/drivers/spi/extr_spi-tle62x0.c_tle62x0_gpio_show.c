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
struct tle62x0_state {int gpio_state; int /*<<< orphan*/  lock; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  PAGE_SIZE ; 
 struct tle62x0_state* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snprintf (char*,int /*<<< orphan*/ ,char*,int) ; 
 int to_gpio_num (struct device_attribute*) ; 

__attribute__((used)) static ssize_t tle62x0_gpio_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct tle62x0_state *st = dev_get_drvdata(dev);
	int gpio_num = to_gpio_num(attr);
	int value;

	mutex_lock(&st->lock);
	value = (st->gpio_state >> gpio_num) & 1;
	mutex_unlock(&st->lock);

	return snprintf(buf, PAGE_SIZE, "%d", value);
}