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
struct watchdog_device {int /*<<< orphan*/  timeout; } ;

/* Variables and functions */
 int /*<<< orphan*/  __booke_wdt_enable ; 
 int /*<<< orphan*/  on_each_cpu (int /*<<< orphan*/ ,struct watchdog_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_debug (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int booke_wdt_start(struct watchdog_device *wdog)
{
	on_each_cpu(__booke_wdt_enable, wdog, 0);
	pr_debug("watchdog enabled (timeout = %u sec)\n", wdog->timeout);

	return 0;
}