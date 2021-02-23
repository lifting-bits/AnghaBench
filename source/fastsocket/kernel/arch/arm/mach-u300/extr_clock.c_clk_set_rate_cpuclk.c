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
 int /*<<< orphan*/  clk_round_rate (struct clk*,unsigned long) ; 
 int /*<<< orphan*/  syscon_clk_rate_set_cpuclk (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int clk_set_rate_cpuclk(struct clk *clk, unsigned long rate)
{
	syscon_clk_rate_set_cpuclk(clk_round_rate(clk, rate));
	return 0;
}