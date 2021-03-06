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
struct TYPE_2__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_1__ dev; } ;
struct mfd_cell {size_t id; } ;
struct asic3 {int /*<<< orphan*/ * clocks; int /*<<< orphan*/  gpio; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASIC3_GPIO (int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  C ; 
 int /*<<< orphan*/  asic3_clk_disable (struct asic3*,int /*<<< orphan*/ *) ; 
 scalar_t__ asic3_gpio_get (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 size_t* clock_ledn ; 
 struct asic3* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct mfd_cell* mfd_get_cell (struct platform_device*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int asic3_leds_suspend(struct platform_device *pdev)
{
	const struct mfd_cell *cell = mfd_get_cell(pdev);
	struct asic3 *asic = dev_get_drvdata(pdev->dev.parent);

	while (asic3_gpio_get(&asic->gpio, ASIC3_GPIO(C, cell->id)) != 0)
		usleep_range(1000, 5000);

	asic3_clk_disable(asic, &asic->clocks[clock_ledn[cell->id]]);

	return 0;
}