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
struct timer_of {int dummy; } ;
struct clock_event_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  rda_ostimer_stop (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  timer_of_base (struct timer_of*) ; 
 struct timer_of* to_timer_of (struct clock_event_device*) ; 

__attribute__((used)) static int rda_ostimer_set_state_oneshot(struct clock_event_device *evt)
{
	struct timer_of *to = to_timer_of(evt);

	rda_ostimer_stop(timer_of_base(to));

	return 0;
}