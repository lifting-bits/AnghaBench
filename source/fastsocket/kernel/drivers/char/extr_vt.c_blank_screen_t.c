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
 int HZ ; 
 int blank_timer_expired ; 
 int blankinterval ; 
 int /*<<< orphan*/  console_timer ; 
 int /*<<< orphan*/  console_work ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  keventd_up () ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  schedule_work (int /*<<< orphan*/ *) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static void blank_screen_t(unsigned long dummy)
{
	if (unlikely(!keventd_up())) {
		mod_timer(&console_timer, jiffies + (blankinterval * HZ));
		return;
	}
	blank_timer_expired = 1;
	schedule_work(&console_work);
}