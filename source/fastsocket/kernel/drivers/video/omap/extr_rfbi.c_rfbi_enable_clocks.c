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
struct TYPE_2__ {int /*<<< orphan*/  dss_ick; int /*<<< orphan*/  dss1_fck; } ;

/* Variables and functions */
 int /*<<< orphan*/  clk_disable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_enable (int /*<<< orphan*/ ) ; 
 TYPE_1__ rfbi ; 

__attribute__((used)) static void rfbi_enable_clocks(int enable)
{
	if (enable) {
		clk_enable(rfbi.dss_ick);
		clk_enable(rfbi.dss1_fck);
	} else {
		clk_disable(rfbi.dss1_fck);
		clk_disable(rfbi.dss_ick);
	}
}