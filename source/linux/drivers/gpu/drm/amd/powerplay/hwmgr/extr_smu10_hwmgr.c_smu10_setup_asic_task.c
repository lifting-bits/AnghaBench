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
 int smu10_init_power_gate_state (struct pp_hwmgr*) ; 

__attribute__((used)) static int smu10_setup_asic_task(struct pp_hwmgr *hwmgr)
{
	return smu10_init_power_gate_state(hwmgr);
}