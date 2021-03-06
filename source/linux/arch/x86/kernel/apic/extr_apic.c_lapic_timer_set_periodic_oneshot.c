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
struct clock_event_device {int features; } ;

/* Variables and functions */
 int CLOCK_EVT_FEAT_DUMMY ; 
 int /*<<< orphan*/  __setup_APIC_LVTT (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  lapic_timer_period ; 

__attribute__((used)) static inline int
lapic_timer_set_periodic_oneshot(struct clock_event_device *evt, bool oneshot)
{
	/* Lapic used as dummy for broadcast ? */
	if (evt->features & CLOCK_EVT_FEAT_DUMMY)
		return 0;

	__setup_APIC_LVTT(lapic_timer_period, oneshot, 1);
	return 0;
}