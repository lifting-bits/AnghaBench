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
typedef  int /*<<< orphan*/  cpu_data_t ;

/* Variables and functions */
 int /*<<< orphan*/  mt_cpu_run (int /*<<< orphan*/ *) ; 

void
mt_cpu_up(cpu_data_t *cpu)
{
	mt_cpu_run(cpu);
}