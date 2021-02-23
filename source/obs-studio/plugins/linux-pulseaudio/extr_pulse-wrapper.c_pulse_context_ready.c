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
typedef  int int_fast32_t ;

/* Variables and functions */
 int /*<<< orphan*/  PA_CONTEXT_IS_GOOD (scalar_t__) ; 
 scalar_t__ PA_CONTEXT_READY ; 
 scalar_t__ pa_context_get_state (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pulse_context ; 
 int /*<<< orphan*/  pulse_lock () ; 
 int /*<<< orphan*/  pulse_unlock () ; 
 int /*<<< orphan*/  pulse_wait () ; 

__attribute__((used)) static int_fast32_t pulse_context_ready()
{
	pulse_lock();

	if (!PA_CONTEXT_IS_GOOD(pa_context_get_state(pulse_context))) {
		pulse_unlock();
		return -1;
	}

	while (pa_context_get_state(pulse_context) != PA_CONTEXT_READY)
		pulse_wait();

	pulse_unlock();
	return 0;
}