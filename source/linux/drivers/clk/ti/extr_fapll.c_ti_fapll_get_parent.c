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
typedef  int u8 ;
struct fapll_data {int dummy; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 scalar_t__ ti_fapll_clock_is_bypass (struct fapll_data*) ; 
 struct fapll_data* to_fapll (struct clk_hw*) ; 

__attribute__((used)) static u8 ti_fapll_get_parent(struct clk_hw *hw)
{
	struct fapll_data *fd = to_fapll(hw);

	if (ti_fapll_clock_is_bypass(fd))
		return 1;

	return 0;
}