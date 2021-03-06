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
 int /*<<< orphan*/  cpufreq_generic_init (struct cpufreq_policy*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pmac_cpu_freqs ; 
 int /*<<< orphan*/  transition_latency ; 

__attribute__((used)) static int pmac_cpufreq_cpu_init(struct cpufreq_policy *policy)
{
	cpufreq_generic_init(policy, pmac_cpu_freqs, transition_latency);
	return 0;
}