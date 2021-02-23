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
 int /*<<< orphan*/  clk_enable (int /*<<< orphan*/ ) ; 
 int clocked ; 
 scalar_t__ cpu_is_at91sam9261 () ; 
 int /*<<< orphan*/  fclk ; 
 int /*<<< orphan*/  hclk ; 
 int /*<<< orphan*/  iclk ; 

__attribute__((used)) static void at91_start_clock(void)
{
	if (cpu_is_at91sam9261())
		clk_enable(hclk);
	clk_enable(iclk);
	clk_enable(fclk);
	clocked = 1;
}