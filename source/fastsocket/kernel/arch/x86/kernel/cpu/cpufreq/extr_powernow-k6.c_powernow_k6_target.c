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
struct cpufreq_policy {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/ * clock_ratio ; 
 scalar_t__ cpufreq_frequency_table_target (struct cpufreq_policy*,int /*<<< orphan*/ *,unsigned int,unsigned int,unsigned int*) ; 
 int /*<<< orphan*/  powernow_k6_set_state (unsigned int) ; 

__attribute__((used)) static int powernow_k6_target(struct cpufreq_policy *policy,
			       unsigned int target_freq,
			       unsigned int relation)
{
	unsigned int newstate = 0;

	if (cpufreq_frequency_table_target(policy, &clock_ratio[0],
				target_freq, relation, &newstate))
		return -EINVAL;

	powernow_k6_set_state(newstate);

	return 0;
}