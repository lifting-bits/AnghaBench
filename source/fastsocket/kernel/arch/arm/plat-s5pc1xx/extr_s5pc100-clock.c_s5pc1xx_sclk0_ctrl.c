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
 int /*<<< orphan*/  S5PC100_SCLKGATE0 ; 
 int s5pc1xx_clk_gate (int /*<<< orphan*/ ,struct clk*,int) ; 

int s5pc1xx_sclk0_ctrl(struct clk *clk, int enable)
{
	return s5pc1xx_clk_gate(S5PC100_SCLKGATE0, clk, enable);
}