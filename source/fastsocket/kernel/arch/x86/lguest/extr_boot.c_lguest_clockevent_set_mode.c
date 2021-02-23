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
struct clock_event_device {int dummy; } ;
typedef  enum clock_event_mode { ____Placeholder_clock_event_mode } clock_event_mode ;

/* Variables and functions */
 int /*<<< orphan*/  BUG () ; 
#define  CLOCK_EVT_MODE_ONESHOT 132 
#define  CLOCK_EVT_MODE_PERIODIC 131 
#define  CLOCK_EVT_MODE_RESUME 130 
#define  CLOCK_EVT_MODE_SHUTDOWN 129 
#define  CLOCK_EVT_MODE_UNUSED 128 
 int /*<<< orphan*/  LHCALL_SET_CLOCKEVENT ; 
 int /*<<< orphan*/  kvm_hypercall0 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void lguest_clockevent_set_mode(enum clock_event_mode mode,
                                      struct clock_event_device *evt)
{
	switch (mode) {
	case CLOCK_EVT_MODE_UNUSED:
	case CLOCK_EVT_MODE_SHUTDOWN:
		/* A 0 argument shuts the clock down. */
		kvm_hypercall0(LHCALL_SET_CLOCKEVENT);
		break;
	case CLOCK_EVT_MODE_ONESHOT:
		/* This is what we expect. */
		break;
	case CLOCK_EVT_MODE_PERIODIC:
		BUG();
	case CLOCK_EVT_MODE_RESUME:
		break;
	}
}