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
struct intel_runtime_pm {int dummy; } ;
typedef  int depot_stack_handle_t ;

/* Variables and functions */

__attribute__((used)) static depot_stack_handle_t
track_intel_runtime_pm_wakeref(struct intel_runtime_pm *rpm)
{
	return -1;
}