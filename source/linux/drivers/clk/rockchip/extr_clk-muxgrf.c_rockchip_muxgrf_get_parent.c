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
typedef  unsigned int u8 ;
struct rockchip_muxgrf_clock {unsigned int shift; int /*<<< orphan*/  reg; int /*<<< orphan*/  regmap; scalar_t__ width; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 unsigned int GENMASK (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 struct rockchip_muxgrf_clock* to_muxgrf_clock (struct clk_hw*) ; 

__attribute__((used)) static u8 rockchip_muxgrf_get_parent(struct clk_hw *hw)
{
	struct rockchip_muxgrf_clock *mux = to_muxgrf_clock(hw);
	unsigned int mask = GENMASK(mux->width - 1, 0);
	unsigned int val;

	regmap_read(mux->regmap, mux->reg, &val);

	val >>= mux->shift;
	val &= mask;

	return val;
}