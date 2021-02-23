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
struct platform_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  omap2evm_panel ; 
 int /*<<< orphan*/  omapfb_register_panel (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int omap2evm_panel_probe(struct platform_device *pdev)
{
	omapfb_register_panel(&omap2evm_panel);
	return 0;
}