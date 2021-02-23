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
typedef  scalar_t__ uint64_t ;

/* Variables and functions */
 int /*<<< orphan*/  _clock_delay_until_deadline (scalar_t__,scalar_t__) ; 
 scalar_t__ mach_absolute_time () ; 

void
clock_delay_until(
	uint64_t		deadline)
{
	uint64_t		now = mach_absolute_time();

	if (now >= deadline)
		return;

	_clock_delay_until_deadline(deadline - now, deadline);
}