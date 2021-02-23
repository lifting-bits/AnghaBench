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
struct timer_list {int /*<<< orphan*/  expires; int /*<<< orphan*/  callout; } ;

/* Variables and functions */
 int /*<<< orphan*/  callout_reset_on (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct timer_list*,int) ; 
 int /*<<< orphan*/  linux_timer_callback_wrapper ; 
 int /*<<< orphan*/  linux_timer_jiffies_until (int /*<<< orphan*/ ) ; 

void
add_timer_on(struct timer_list *timer, int cpu)
{

	callout_reset_on(&timer->callout,
	    linux_timer_jiffies_until(timer->expires),
	    &linux_timer_callback_wrapper, timer, cpu);
}