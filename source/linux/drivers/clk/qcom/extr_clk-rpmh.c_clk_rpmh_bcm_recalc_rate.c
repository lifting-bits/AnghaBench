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
struct clk_rpmh {unsigned long aggr_state; unsigned long unit; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 struct clk_rpmh* to_clk_rpmh (struct clk_hw*) ; 

__attribute__((used)) static unsigned long clk_rpmh_bcm_recalc_rate(struct clk_hw *hw,
					unsigned long prate)
{
	struct clk_rpmh *c = to_clk_rpmh(hw);

	return c->aggr_state * c->unit;
}