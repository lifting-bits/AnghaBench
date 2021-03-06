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
struct clk {int enable_shift1; scalar_t__ enable_reg1; } ;

/* Variables and functions */
 int __raw_readl (scalar_t__) ; 
 int /*<<< orphan*/  __raw_writel (int,scalar_t__) ; 

__attribute__((used)) static inline void clk_reg_disable1(struct clk *clk)
{
	if (clk->enable_reg1)
		__raw_writel(__raw_readl(clk->enable_reg1) &
			     ~(1 << clk->enable_shift1), clk->enable_reg1);
}