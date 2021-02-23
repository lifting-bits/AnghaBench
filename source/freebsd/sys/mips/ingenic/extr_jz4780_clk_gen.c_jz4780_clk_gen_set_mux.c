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
typedef  int uint32_t ;
struct jz4780_clk_gen_sc {TYPE_2__* clk_descr; } ;
struct clknode {int dummy; } ;
struct TYPE_3__ {unsigned int mux_bits; int mux_shift; int /*<<< orphan*/  mux_reg; int /*<<< orphan*/  mux_map; } ;
struct TYPE_4__ {int clk_type; TYPE_1__ clk_mux; } ;

/* Variables and functions */
 int /*<<< orphan*/  CLK_LOCK (struct jz4780_clk_gen_sc*) ; 
 int CLK_MASK_MUX ; 
 int CLK_RD_4 (struct jz4780_clk_gen_sc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CLK_UNLOCK (struct jz4780_clk_gen_sc*) ; 
 int /*<<< orphan*/  CLK_WR_4 (struct jz4780_clk_gen_sc*,int /*<<< orphan*/ ,int) ; 
 int EINVAL ; 
 struct jz4780_clk_gen_sc* clknode_get_softc (struct clknode*) ; 
 int mux_to_reg (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
jz4780_clk_gen_set_mux(struct clknode *clk, int src)
{
	struct jz4780_clk_gen_sc *sc;
	uint32_t reg, msk;

	sc = clknode_get_softc(clk);

	/* Only mux nodes are capable of being reparented */
	if (!(sc->clk_descr->clk_type & CLK_MASK_MUX))
		return (src ? EINVAL : 0);

	msk = (1u << sc->clk_descr->clk_mux.mux_bits) - 1;
	src = mux_to_reg(src & msk, sc->clk_descr->clk_mux.mux_map);

	CLK_LOCK(sc);
	reg = CLK_RD_4(sc, sc->clk_descr->clk_mux.mux_reg);
	reg &= ~(msk << sc->clk_descr->clk_mux.mux_shift);
	reg |=  (src << sc->clk_descr->clk_mux.mux_shift);
	CLK_WR_4(sc, sc->clk_descr->clk_mux.mux_reg, reg);
	CLK_UNLOCK(sc);

	return (0);
}