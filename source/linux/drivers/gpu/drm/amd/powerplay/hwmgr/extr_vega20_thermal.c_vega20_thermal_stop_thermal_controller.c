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
struct pp_hwmgr {int dummy; } ;

/* Variables and functions */
 int vega20_thermal_disable_alert (struct pp_hwmgr*) ; 

int vega20_thermal_stop_thermal_controller(struct pp_hwmgr *hwmgr)
{
	int result = vega20_thermal_disable_alert(hwmgr);

	return result;
}