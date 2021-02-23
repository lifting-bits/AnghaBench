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
 int /*<<< orphan*/  IXP2000_T4_CLD ; 
 int heartbeat ; 
 int /*<<< orphan*/  ixp2000_reg_write (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wdt_lock ; 
 int wdt_tick_rate ; 

__attribute__((used)) static void wdt_keepalive(void)
{
	spin_lock(&wdt_lock);
	ixp2000_reg_write(IXP2000_T4_CLD, heartbeat * wdt_tick_rate);
	spin_unlock(&wdt_lock);
}