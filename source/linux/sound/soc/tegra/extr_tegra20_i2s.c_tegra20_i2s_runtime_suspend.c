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
struct tegra20_i2s {int /*<<< orphan*/  clk_i2s; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 struct tegra20_i2s* dev_get_drvdata (struct device*) ; 

__attribute__((used)) static int tegra20_i2s_runtime_suspend(struct device *dev)
{
	struct tegra20_i2s *i2s = dev_get_drvdata(dev);

	clk_disable_unprepare(i2s->clk_i2s);

	return 0;
}