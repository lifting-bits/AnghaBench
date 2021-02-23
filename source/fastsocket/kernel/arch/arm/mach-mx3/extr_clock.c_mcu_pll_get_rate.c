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
 int /*<<< orphan*/  MXC_CCM_CCMR ; 
 unsigned long MXC_CCM_CCMR_MDS ; 
 unsigned long MXC_CCM_CCMR_MPE ; 
 int /*<<< orphan*/  MXC_CCM_MPCTL ; 
 unsigned long __raw_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ckih_clk ; 
 unsigned long clk_get_rate (int /*<<< orphan*/ *) ; 
 unsigned long mxc_decode_pll (unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pll_ref_get_rate () ; 

__attribute__((used)) static unsigned long mcu_pll_get_rate(struct clk *clk)
{
	unsigned long reg, ccmr;

	ccmr = __raw_readl(MXC_CCM_CCMR);

	if (!(ccmr & MXC_CCM_CCMR_MPE) || (ccmr & MXC_CCM_CCMR_MDS))
		return clk_get_rate(&ckih_clk);

	reg = __raw_readl(MXC_CCM_MPCTL);

	return mxc_decode_pll(reg, pll_ref_get_rate());
}