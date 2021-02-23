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
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  cpufreq_settings_changed (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void 
cpufreq_startup_task(void *ctx, int pending)
{

	cpufreq_settings_changed((device_t)ctx);
}