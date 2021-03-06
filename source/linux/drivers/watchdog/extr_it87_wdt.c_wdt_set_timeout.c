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
struct watchdog_device {unsigned int timeout; } ;

/* Variables and functions */
 unsigned int max_units ; 
 scalar_t__ watchdog_hw_running (struct watchdog_device*) ; 
 unsigned int wdt_round_time (unsigned int) ; 
 int wdt_update_timeout (unsigned int) ; 

__attribute__((used)) static int wdt_set_timeout(struct watchdog_device *wdd, unsigned int t)
{
	int ret = 0;

	if (t > max_units)
		t = wdt_round_time(t);

	wdd->timeout = t;

	if (watchdog_hw_running(wdd))
		ret = wdt_update_timeout(t);

	return ret;
}