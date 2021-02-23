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
typedef  int /*<<< orphan*/  TimestampTz ;
typedef  int /*<<< orphan*/  TimeoutId ;

/* Variables and functions */
 int /*<<< orphan*/  GetCurrentTimestamp () ; 
 int /*<<< orphan*/  TimestampTzPlusMilliseconds (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  disable_alarm () ; 
 int /*<<< orphan*/  enable_timeout (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  schedule_alarm (int /*<<< orphan*/ ) ; 

void
enable_timeout_after(TimeoutId id, int delay_ms)
{
	TimestampTz now;
	TimestampTz fin_time;

	/* Disable timeout interrupts for safety. */
	disable_alarm();

	/* Queue the timeout at the appropriate time. */
	now = GetCurrentTimestamp();
	fin_time = TimestampTzPlusMilliseconds(now, delay_ms);
	enable_timeout(id, now, fin_time);

	/* Set the timer interrupt. */
	schedule_alarm(now);
}