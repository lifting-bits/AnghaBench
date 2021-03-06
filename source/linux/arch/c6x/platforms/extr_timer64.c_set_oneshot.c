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

/* Variables and functions */
 int /*<<< orphan*/  TIMER64_MODE_ONE_SHOT ; 
 int /*<<< orphan*/  timer64_enable () ; 
 int /*<<< orphan*/  timer64_mode ; 

__attribute__((used)) static int set_oneshot(struct clock_event_device *evt)
{
	timer64_enable();
	timer64_mode = TIMER64_MODE_ONE_SHOT;
	return 0;
}