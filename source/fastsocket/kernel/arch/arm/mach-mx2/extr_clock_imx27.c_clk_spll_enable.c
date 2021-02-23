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
 int /*<<< orphan*/  CCM_CSCR ; 
 unsigned long CCM_CSCR_SPEN ; 
 int /*<<< orphan*/  CCM_SPCTL1 ; 
 unsigned long CCM_SPCTL1_LF ; 
 unsigned long __raw_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writel (unsigned long,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int clk_spll_enable(struct clk *clk)
{
	unsigned long reg;

	reg = __raw_readl(CCM_CSCR);
	reg |= CCM_CSCR_SPEN;
	__raw_writel(reg, CCM_CSCR);

	while (!(__raw_readl(CCM_SPCTL1) & CCM_SPCTL1_LF));

	return 0;
}