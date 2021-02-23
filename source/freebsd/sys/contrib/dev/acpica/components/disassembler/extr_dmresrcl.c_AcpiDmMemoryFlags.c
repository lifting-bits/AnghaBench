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
typedef  int /*<<< orphan*/  UINT8 ;

/* Variables and functions */
 size_t ACPI_EXTRACT_1BIT_FLAG (int /*<<< orphan*/ ,int) ; 
 size_t ACPI_EXTRACT_2BIT_FLAG (int /*<<< orphan*/ ,int) ; 
 size_t ACPI_GET_1BIT_FLAG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * AcpiGbl_ConsumeDecode ; 
 int /*<<< orphan*/ * AcpiGbl_DecDecode ; 
 int /*<<< orphan*/ * AcpiGbl_MaxDecode ; 
 int /*<<< orphan*/ * AcpiGbl_MemDecode ; 
 int /*<<< orphan*/ * AcpiGbl_MinDecode ; 
 int /*<<< orphan*/ * AcpiGbl_RwDecode ; 
 int /*<<< orphan*/  AcpiOsPrintf (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
AcpiDmMemoryFlags (
    UINT8                   Flags,
    UINT8                   SpecificFlags)
{

    AcpiOsPrintf ("%s, %s, %s, %s, %s, %s,",
        AcpiGbl_ConsumeDecode [ACPI_GET_1BIT_FLAG (Flags)],
        AcpiGbl_DecDecode [ACPI_EXTRACT_1BIT_FLAG (Flags, 1)],
        AcpiGbl_MinDecode [ACPI_EXTRACT_1BIT_FLAG (Flags, 2)],
        AcpiGbl_MaxDecode [ACPI_EXTRACT_1BIT_FLAG (Flags, 3)],
        AcpiGbl_MemDecode [ACPI_EXTRACT_2BIT_FLAG (SpecificFlags, 1)],
        AcpiGbl_RwDecode [ACPI_GET_1BIT_FLAG (SpecificFlags)]);
}