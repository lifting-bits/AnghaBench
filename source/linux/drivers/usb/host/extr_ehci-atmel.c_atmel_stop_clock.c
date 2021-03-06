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
struct atmel_ehci_priv {int clocked; int /*<<< orphan*/  uclk; int /*<<< orphan*/  iclk; } ;

/* Variables and functions */
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void atmel_stop_clock(struct atmel_ehci_priv *atmel_ehci)
{
	if (!atmel_ehci->clocked)
		return;

	clk_disable_unprepare(atmel_ehci->iclk);
	clk_disable_unprepare(atmel_ehci->uclk);
	atmel_ehci->clocked = false;
}