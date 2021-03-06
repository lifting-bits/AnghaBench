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
struct TYPE_2__ {int ctx_valid; } ;

/* Variables and functions */
 int /*<<< orphan*/  CONTROL ; 
 int /*<<< orphan*/  DSSDBG (char*) ; 
 int OMAP_DISPLAY_TYPE_SDI ; 
 int /*<<< orphan*/  OMAP_DSS_CHANNEL_LCD ; 
 int /*<<< orphan*/  PLL_CONTROL ; 
 int /*<<< orphan*/  SDI_CONTROL ; 
 int /*<<< orphan*/  SR (int /*<<< orphan*/ ) ; 
 TYPE_1__ dss ; 
 int dss_feat_get_supported_displays (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void dss_save_context(void)
{
	DSSDBG("dss_save_context\n");

	SR(CONTROL);

	if (dss_feat_get_supported_displays(OMAP_DSS_CHANNEL_LCD) &
			OMAP_DISPLAY_TYPE_SDI) {
		SR(SDI_CONTROL);
		SR(PLL_CONTROL);
	}

	dss.ctx_valid = true;

	DSSDBG("context saved\n");
}