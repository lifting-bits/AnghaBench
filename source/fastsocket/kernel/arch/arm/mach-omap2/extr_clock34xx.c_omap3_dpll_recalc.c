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
struct clk {int dummy; } ;

/* Variables and functions */
 unsigned long omap2_get_dpll_rate (struct clk*) ; 

__attribute__((used)) static unsigned long omap3_dpll_recalc(struct clk *clk)
{
	return omap2_get_dpll_rate(clk);
}