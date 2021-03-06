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
struct cpufreq_policy {int /*<<< orphan*/  cpu; } ;
struct TYPE_2__ {int /*<<< orphan*/  op_points; } ;

/* Variables and functions */
 int /*<<< orphan*/  centrino_model ; 
 int cpufreq_frequency_table_verify (struct cpufreq_policy*,int /*<<< orphan*/ ) ; 
 TYPE_1__* per_cpu (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int centrino_verify (struct cpufreq_policy *policy)
{
	return cpufreq_frequency_table_verify(policy,
			per_cpu(centrino_model, policy->cpu)->op_points);
}