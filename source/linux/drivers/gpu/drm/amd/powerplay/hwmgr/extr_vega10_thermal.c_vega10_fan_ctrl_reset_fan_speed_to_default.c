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
struct TYPE_3__ {scalar_t__ bNoFan; } ;
struct TYPE_4__ {TYPE_1__ fanInfo; } ;
struct pp_hwmgr {TYPE_2__ thermal_controller; } ;

/* Variables and functions */
 int /*<<< orphan*/  PHM_PlatformCaps_MicrocodeFanControl ; 
 scalar_t__ PP_CAP (int /*<<< orphan*/ ) ; 
 int vega10_fan_ctrl_set_default_mode (struct pp_hwmgr*) ; 
 int vega10_fan_ctrl_start_smc_fan_control (struct pp_hwmgr*) ; 

int vega10_fan_ctrl_reset_fan_speed_to_default(struct pp_hwmgr *hwmgr)
{
	if (hwmgr->thermal_controller.fanInfo.bNoFan)
		return 0;

	if (PP_CAP(PHM_PlatformCaps_MicrocodeFanControl))
		return vega10_fan_ctrl_start_smc_fan_control(hwmgr);
	else
		return vega10_fan_ctrl_set_default_mode(hwmgr);
}