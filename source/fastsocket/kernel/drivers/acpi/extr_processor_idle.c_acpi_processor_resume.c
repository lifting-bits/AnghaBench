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
struct acpi_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  acpi_idle_bm_rld_restore () ; 
 scalar_t__ acpi_idle_suspend ; 

int acpi_processor_resume(struct acpi_device * device)
{
	if (acpi_idle_suspend == 0)
		return 0;

	acpi_idle_bm_rld_restore();
	acpi_idle_suspend = 0;
	return 0;
}