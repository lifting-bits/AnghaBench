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
typedef  int /*<<< orphan*/  uint32_t ;
struct TYPE_2__ {scalar_t__ vfebase; } ;

/* Variables and functions */
 scalar_t__ VFE_BUS_ENC_CBCR_WR_PM_STATS_1 ; 
 TYPE_1__* ctrl ; 
 int /*<<< orphan*/  readl (scalar_t__) ; 

__attribute__((used)) static uint32_t vfe_read_pm_status_in_raw_capture(void)
{
	return readl(ctrl->vfebase + VFE_BUS_ENC_CBCR_WR_PM_STATS_1);
}