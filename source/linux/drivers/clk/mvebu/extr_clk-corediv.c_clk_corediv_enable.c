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
typedef  int u32 ;
struct clk_hw {int dummy; } ;
struct clk_corediv_soc_desc {int enable_bit_offset; } ;
struct clk_corediv_desc {int /*<<< orphan*/  fieldbit; } ;
struct clk_corediv {int /*<<< orphan*/  lock; int /*<<< orphan*/  reg; struct clk_corediv_desc* desc; struct clk_corediv_soc_desc* soc_desc; } ;

/* Variables and functions */
 int BIT (int /*<<< orphan*/ ) ; 
 int readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 struct clk_corediv* to_corediv_clk (struct clk_hw*) ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int clk_corediv_enable(struct clk_hw *hwclk)
{
	struct clk_corediv *corediv = to_corediv_clk(hwclk);
	const struct clk_corediv_soc_desc *soc_desc = corediv->soc_desc;
	const struct clk_corediv_desc *desc = corediv->desc;
	unsigned long flags = 0;
	u32 reg;

	spin_lock_irqsave(&corediv->lock, flags);

	reg = readl(corediv->reg);
	reg |= (BIT(desc->fieldbit) << soc_desc->enable_bit_offset);
	writel(reg, corediv->reg);

	spin_unlock_irqrestore(&corediv->lock, flags);

	return 0;
}