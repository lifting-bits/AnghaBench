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
typedef  int /*<<< orphan*/  usb_error_t ;
typedef  scalar_t__ uint8_t ;
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int uint32_t ;
struct xhci_trb {int /*<<< orphan*/  dwTrb3; scalar_t__ dwTrb2; int /*<<< orphan*/  qwTrb0; } ;
struct xhci_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DPRINTF (char*) ; 
 int XHCI_TRB_3_DCEP_BIT ; 
 int XHCI_TRB_3_SLOT_SET (scalar_t__) ; 
 int XHCI_TRB_3_TYPE_SET (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XHCI_TRB_TYPE_CONFIGURE_EP ; 
 int /*<<< orphan*/  htole32 (int) ; 
 int /*<<< orphan*/  htole64 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xhci_do_command (struct xhci_softc*,struct xhci_trb*,int) ; 

__attribute__((used)) static usb_error_t
xhci_cmd_configure_ep(struct xhci_softc *sc, uint64_t input_ctx,
    uint8_t deconfigure, uint8_t slot_id)
{
	struct xhci_trb trb;
	uint32_t temp;

	DPRINTF("\n");

	trb.qwTrb0 = htole64(input_ctx);
	trb.dwTrb2 = 0;
	temp = XHCI_TRB_3_TYPE_SET(XHCI_TRB_TYPE_CONFIGURE_EP) |
	    XHCI_TRB_3_SLOT_SET(slot_id);

	if (deconfigure)
		temp |= XHCI_TRB_3_DCEP_BIT;

	trb.dwTrb3 = htole32(temp);

	return (xhci_do_command(sc, &trb, 100 /* ms */));
}