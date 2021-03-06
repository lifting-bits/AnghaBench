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
 int /*<<< orphan*/  SIGPxcall ; 
 int /*<<< orphan*/  cpu_datap (int) ; 
 int /*<<< orphan*/  cpu_signal (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,void*) ; 

void
timer_call_nosync_cpu(int cpu, void (*fn)(void *), void *arg)
{
	/* XXX Needs error checking and retry */
	cpu_signal(cpu_datap(cpu), SIGPxcall, (void *) fn, arg);
}