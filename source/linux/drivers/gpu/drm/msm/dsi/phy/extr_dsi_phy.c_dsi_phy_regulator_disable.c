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
struct regulator_bulk_data {int /*<<< orphan*/  consumer; } ;
struct msm_dsi_phy {TYPE_1__* cfg; struct regulator_bulk_data* supplies; } ;
struct dsi_reg_entry {scalar_t__ disable_load; } ;
struct TYPE_4__ {int num; struct dsi_reg_entry* regs; } ;
struct TYPE_3__ {TYPE_2__ reg_cfg; } ;

/* Variables and functions */
 int /*<<< orphan*/  DBG (char*) ; 
 int /*<<< orphan*/  regulator_bulk_disable (int,struct regulator_bulk_data*) ; 
 int /*<<< orphan*/  regulator_set_load (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void dsi_phy_regulator_disable(struct msm_dsi_phy *phy)
{
	struct regulator_bulk_data *s = phy->supplies;
	const struct dsi_reg_entry *regs = phy->cfg->reg_cfg.regs;
	int num = phy->cfg->reg_cfg.num;
	int i;

	DBG("");
	for (i = num - 1; i >= 0; i--)
		if (regs[i].disable_load >= 0)
			regulator_set_load(s[i].consumer, regs[i].disable_load);

	regulator_bulk_disable(num, s);
}