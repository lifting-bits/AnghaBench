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

/* Variables and functions */
 int /*<<< orphan*/  tick_check_nohz (int) ; 
 int /*<<< orphan*/  tick_check_oneshot_broadcast (int) ; 

void tick_check_idle(int cpu)
{
	tick_check_oneshot_broadcast(cpu);
	tick_check_nohz(cpu);
}