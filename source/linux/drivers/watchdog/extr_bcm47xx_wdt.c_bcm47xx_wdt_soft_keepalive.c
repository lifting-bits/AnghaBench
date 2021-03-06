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
struct bcm47xx_wdt {int /*<<< orphan*/  soft_ticks; } ;

/* Variables and functions */
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct bcm47xx_wdt* bcm47xx_wdt_get (struct watchdog_device*) ; 

__attribute__((used)) static int bcm47xx_wdt_soft_keepalive(struct watchdog_device *wdd)
{
	struct bcm47xx_wdt *wdt = bcm47xx_wdt_get(wdd);

	atomic_set(&wdt->soft_ticks, wdd->timeout);

	return 0;
}