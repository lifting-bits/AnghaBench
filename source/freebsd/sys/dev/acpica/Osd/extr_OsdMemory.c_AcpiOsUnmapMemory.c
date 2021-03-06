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
typedef  int /*<<< orphan*/  vm_offset_t ;
typedef  int /*<<< orphan*/  ACPI_SIZE ;

/* Variables and functions */
 int /*<<< orphan*/  pmap_unmapbios (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
AcpiOsUnmapMemory(void *LogicalAddress, ACPI_SIZE Length)
{
    pmap_unmapbios((vm_offset_t)LogicalAddress, Length);
}