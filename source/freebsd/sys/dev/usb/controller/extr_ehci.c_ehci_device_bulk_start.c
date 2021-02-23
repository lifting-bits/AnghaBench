#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct usb_xfer {TYPE_1__* xroot; } ;
struct TYPE_6__ {int sc_flags; int /*<<< orphan*/  sc_async_p_last; } ;
typedef  TYPE_2__ ehci_softc_t ;
struct TYPE_5__ {int /*<<< orphan*/  bus; } ;

/* Variables and functions */
 TYPE_2__* EHCI_BUS2SC (int /*<<< orphan*/ ) ; 
 int EHCI_SCFLG_IAADBUG ; 
 int /*<<< orphan*/  ehci_doorbell_async (TYPE_2__*) ; 
 int /*<<< orphan*/  ehci_setup_standard_chain (struct usb_xfer*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ehci_transfer_intr_enqueue (struct usb_xfer*) ; 

__attribute__((used)) static void
ehci_device_bulk_start(struct usb_xfer *xfer)
{
	ehci_softc_t *sc = EHCI_BUS2SC(xfer->xroot->bus);

	/* setup TD's and QH */
	ehci_setup_standard_chain(xfer, &sc->sc_async_p_last);

	/* put transfer on interrupt queue */
	ehci_transfer_intr_enqueue(xfer);

	/* 
	 * XXX Certain nVidia chipsets choke when using the IAAD
	 * feature too frequently.
	 */
	if (sc->sc_flags & EHCI_SCFLG_IAADBUG)
		return;

	ehci_doorbell_async(sc);
}