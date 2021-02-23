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
typedef  int uint8_t ;
struct device {int dummy; } ;
struct adp5520_bl {int /*<<< orphan*/  lock; int /*<<< orphan*/  master; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int adp5520_read (int /*<<< orphan*/ ,int,int*) ; 
 struct adp5520_bl* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 

__attribute__((used)) static ssize_t adp5520_show(struct device *dev, char *buf, int reg)
{
	struct adp5520_bl *data = dev_get_drvdata(dev);
	int error;
	uint8_t reg_val;

	mutex_lock(&data->lock);
	error = adp5520_read(data->master, reg, &reg_val);
	mutex_unlock(&data->lock);

	return sprintf(buf, "%u\n", reg_val);
}