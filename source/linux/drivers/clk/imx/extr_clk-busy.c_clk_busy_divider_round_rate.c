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
struct clk_hw {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  hw; } ;
struct clk_busy_divider {TYPE_2__ div; TYPE_1__* div_ops; } ;
struct TYPE_3__ {long (* round_rate ) (int /*<<< orphan*/ *,unsigned long,unsigned long*) ;} ;

/* Variables and functions */
 long stub1 (int /*<<< orphan*/ *,unsigned long,unsigned long*) ; 
 struct clk_busy_divider* to_clk_busy_divider (struct clk_hw*) ; 

__attribute__((used)) static long clk_busy_divider_round_rate(struct clk_hw *hw, unsigned long rate,
					unsigned long *prate)
{
	struct clk_busy_divider *busy = to_clk_busy_divider(hw);

	return busy->div_ops->round_rate(&busy->div.hw, rate, prate);
}