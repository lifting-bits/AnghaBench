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
struct libusb20_transfer {int is_draining; scalar_t__ is_pending; int /*<<< orphan*/  is_opened; } ;

/* Variables and functions */
 int /*<<< orphan*/  libusb20_tr_stop (struct libusb20_transfer*) ; 

void
libusb20_tr_drain(struct libusb20_transfer *xfer)
{
	if (!xfer->is_opened) {
		/* transfer is not opened */
		return;
	}
	/* make sure that we are cancelling */
	libusb20_tr_stop(xfer);

	if (xfer->is_pending) {
		xfer->is_draining = 1;
	}
	return;
}