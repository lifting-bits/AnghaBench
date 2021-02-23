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
struct cpufreq_policy {int dummy; } ;
typedef  size_t ssize_t ;
struct TYPE_2__ {unsigned int sampling_down_factor; } ;

/* Variables and functions */
 size_t EINVAL ; 
 unsigned int MAX_SAMPLING_DOWN_FACTOR ; 
 int /*<<< orphan*/  dbs_mutex ; 
 TYPE_1__ dbs_tuners_ins ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sscanf (char const*,char*,unsigned int*) ; 

__attribute__((used)) static ssize_t store_sampling_down_factor(struct cpufreq_policy *unused,
		const char *buf, size_t count)
{
	unsigned int input;
	int ret;
	ret = sscanf(buf, "%u", &input);

	if (ret != 1 || input > MAX_SAMPLING_DOWN_FACTOR || input < 1)
		return -EINVAL;

	mutex_lock(&dbs_mutex);
	dbs_tuners_ins.sampling_down_factor = input;
	mutex_unlock(&dbs_mutex);

	return count;
}