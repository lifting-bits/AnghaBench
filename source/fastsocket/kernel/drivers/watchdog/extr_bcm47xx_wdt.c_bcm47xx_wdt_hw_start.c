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
 int /*<<< orphan*/  ssb_bcm47xx ; 
 int /*<<< orphan*/  ssb_watchdog_timer_set (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static inline void bcm47xx_wdt_hw_start(void)
{
	/* this is 2,5s on 100Mhz clock  and 2s on 133 Mhz */
	ssb_watchdog_timer_set(&ssb_bcm47xx, 0xfffffff);
}