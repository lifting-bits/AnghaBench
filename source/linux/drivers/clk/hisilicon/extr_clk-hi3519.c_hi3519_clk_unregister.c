#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct hi3519_crg_data {int /*<<< orphan*/  clk_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hi3519_fixed_rate_clks ; 
 int /*<<< orphan*/  hi3519_gate_clks ; 
 int /*<<< orphan*/  hi3519_mux_clks ; 
 int /*<<< orphan*/  hisi_clk_unregister_fixed_rate (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hisi_clk_unregister_gate (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hisi_clk_unregister_mux (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_clk_del_provider (int /*<<< orphan*/ ) ; 
 struct hi3519_crg_data* platform_get_drvdata (struct platform_device*) ; 

__attribute__((used)) static void hi3519_clk_unregister(struct platform_device *pdev)
{
	struct hi3519_crg_data *crg = platform_get_drvdata(pdev);

	of_clk_del_provider(pdev->dev.of_node);

	hisi_clk_unregister_gate(hi3519_gate_clks,
				ARRAY_SIZE(hi3519_mux_clks),
				crg->clk_data);
	hisi_clk_unregister_mux(hi3519_mux_clks,
				ARRAY_SIZE(hi3519_mux_clks),
				crg->clk_data);
	hisi_clk_unregister_fixed_rate(hi3519_fixed_rate_clks,
				ARRAY_SIZE(hi3519_fixed_rate_clks),
				crg->clk_data);
}