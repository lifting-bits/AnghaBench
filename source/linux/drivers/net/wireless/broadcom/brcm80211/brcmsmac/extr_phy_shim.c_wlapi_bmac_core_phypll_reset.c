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
struct phy_shim_info {int /*<<< orphan*/  wlc_hw; } ;

/* Variables and functions */
 int /*<<< orphan*/  brcms_b_core_phypll_reset (int /*<<< orphan*/ ) ; 

void wlapi_bmac_core_phypll_reset(struct phy_shim_info *physhim)
{
	brcms_b_core_phypll_reset(physhim->wlc_hw);
}