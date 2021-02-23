#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct acpi_softc {int /*<<< orphan*/  acpi_sysctl_tree; int /*<<< orphan*/  acpi_sysctl_ctx; } ;
typedef  int /*<<< orphan*/  device_t ;
struct TYPE_2__ {int /*<<< orphan*/  SciInterrupt; } ;

/* Variables and functions */
 scalar_t__ ACPI_INTR_PIC ; 
 TYPE_1__ AcpiGbl_FADT ; 
 int /*<<< orphan*/  BUS_CONFIG_INTR (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CTLFLAG_RW ; 
 int /*<<< orphan*/  INTR_POLARITY_LOW ; 
 int /*<<< orphan*/  INTR_TRIGGER_LEVEL ; 
 int /*<<< orphan*/  OID_AUTO ; 
 int /*<<< orphan*/  SYSCTL_ADD_UINT (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  SYSCTL_CHILDREN (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_SetIntrModel (scalar_t__) ; 
 int /*<<< orphan*/  acpi_apm_init (struct acpi_softc*) ; 
 int /*<<< orphan*/  acpi_install_wakeup_handler (struct acpi_softc*) ; 
 int /*<<< orphan*/  acpi_reset_video ; 
 struct acpi_softc* device_get_softc (int /*<<< orphan*/ ) ; 
 scalar_t__ intr_model ; 

int
acpi_machdep_init(device_t dev)
{
	struct acpi_softc *sc;

	sc = device_get_softc(dev);

	acpi_apm_init(sc);
	acpi_install_wakeup_handler(sc);

	if (intr_model == ACPI_INTR_PIC)
		BUS_CONFIG_INTR(dev, AcpiGbl_FADT.SciInterrupt,
		    INTR_TRIGGER_LEVEL, INTR_POLARITY_LOW);
	else
		acpi_SetIntrModel(intr_model);

	SYSCTL_ADD_UINT(&sc->acpi_sysctl_ctx,
	    SYSCTL_CHILDREN(sc->acpi_sysctl_tree), OID_AUTO,
	    "reset_video", CTLFLAG_RW, &acpi_reset_video, 0,
	    "Call the VESA reset BIOS vector on the resume path");

	return (0);
}