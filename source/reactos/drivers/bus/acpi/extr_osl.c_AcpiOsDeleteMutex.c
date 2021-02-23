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
typedef  int /*<<< orphan*/  ACPI_MUTEX ;

/* Variables and functions */
 int /*<<< orphan*/  DPRINT1 (char*) ; 
 int /*<<< orphan*/  ExFreePoolWithTag (int /*<<< orphan*/ ,char) ; 

void
AcpiOsDeleteMutex(
    ACPI_MUTEX Handle)
{
    if (!Handle)
    {
        DPRINT1("Bad parameter\n");
        return;
    }

    ExFreePoolWithTag(Handle, 'LpcA');
}