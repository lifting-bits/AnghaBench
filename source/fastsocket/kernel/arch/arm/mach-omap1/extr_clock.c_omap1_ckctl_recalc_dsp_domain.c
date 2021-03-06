#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct clk {int rate_offset; TYPE_1__* parent; } ;
struct TYPE_4__ {int /*<<< orphan*/  clk; } ;
struct TYPE_3__ {int rate; } ;

/* Variables and functions */
 int /*<<< orphan*/  DSP_CKCTL ; 
 int __raw_readw (int /*<<< orphan*/ ) ; 
 TYPE_2__ api_ck ; 
 int /*<<< orphan*/  omap1_clk_disable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  omap1_clk_enable (int /*<<< orphan*/ *) ; 

__attribute__((used)) static unsigned long omap1_ckctl_recalc_dsp_domain(struct clk *clk)
{
	int dsor;

	/* Calculate divisor encoded as 2-bit exponent
	 *
	 * The clock control bits are in DSP domain,
	 * so api_ck is needed for access.
	 * Note that DSP_CKCTL virt addr = phys addr, so
	 * we must use __raw_readw() instead of omap_readw().
	 */
	omap1_clk_enable(&api_ck.clk);
	dsor = 1 << (3 & (__raw_readw(DSP_CKCTL) >> clk->rate_offset));
	omap1_clk_disable(&api_ck.clk);

	return clk->parent->rate / dsor;
}