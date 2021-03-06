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
struct perf_env {int nr_cpus_avail; } ;

/* Variables and functions */
 int /*<<< orphan*/  perf_env__read_nr_cpus_avail (struct perf_env*) ; 

int perf_env__nr_cpus_avail(struct perf_env *env)
{
	return env && !perf_env__read_nr_cpus_avail(env) ? env->nr_cpus_avail : 0;
}