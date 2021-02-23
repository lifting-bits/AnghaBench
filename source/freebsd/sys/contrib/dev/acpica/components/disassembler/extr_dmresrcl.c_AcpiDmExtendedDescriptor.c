#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  UINT32 ;
struct TYPE_6__ {int /*<<< orphan*/  TypeSpecific; int /*<<< orphan*/  Granularity; } ;
struct TYPE_7__ {TYPE_1__ ExtAddress64; } ;
typedef  TYPE_2__ AML_RESOURCE ;
typedef  int /*<<< orphan*/  ACPI_OP_WALK_INFO ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_RESOURCE_TYPE_EXTENDED_ADDRESS64 ; 
 int /*<<< orphan*/  AcpiDmAddressCommon (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiDmAddressFields (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiDmAddressFlags (TYPE_2__*) ; 
 int /*<<< orphan*/  AcpiDmDescriptorName () ; 
 int /*<<< orphan*/  AcpiDmDumpInteger64 (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  AcpiDmIndent (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiOsPrintf (char*) ; 

void
AcpiDmExtendedDescriptor (
    ACPI_OP_WALK_INFO       *Info,
    AML_RESOURCE            *Resource,
    UINT32                  Length,
    UINT32                  Level)
{

    /* Dump resource name and flags */

    AcpiDmAddressCommon (
        Resource, ACPI_RESOURCE_TYPE_EXTENDED_ADDRESS64, Level);

    /* Dump the 5 contiguous QWORD values */

    AcpiDmAddressFields (&Resource->ExtAddress64.Granularity, 64, Level);

    /* Extra field for this descriptor only */

    AcpiDmIndent (Level + 1);
    AcpiDmDumpInteger64 (Resource->ExtAddress64.TypeSpecific,
        "Type-Specific Attributes");

    /* Insert a descriptor name */

    AcpiDmIndent (Level + 1);
    AcpiDmDescriptorName ();

    /* Type-specific flags */

    AcpiDmAddressFlags (Resource);
    AcpiOsPrintf (")\n");
}