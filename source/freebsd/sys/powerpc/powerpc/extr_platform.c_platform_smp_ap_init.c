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

/* Variables and functions */
 int /*<<< orphan*/  PLATFORM_SMP_AP_INIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  plat_obj ; 

void
platform_smp_ap_init()
{
	PLATFORM_SMP_AP_INIT(plat_obj);
}