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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  size_t uint16_t ;
struct libusb20_transfer {size_t maxFrames; int /*<<< orphan*/ * pLength; int /*<<< orphan*/ * ppBuffer; } ;

/* Variables and functions */
 int /*<<< orphan*/  libusb20_pass_ptr (void*) ; 

void
libusb20_tr_setup_isoc(struct libusb20_transfer *xfer, void *pBuf, uint32_t length, uint16_t frIndex)
{
	if (frIndex >= xfer->maxFrames) {
		/* should not happen */
		return;
	}
	xfer->ppBuffer[frIndex] = libusb20_pass_ptr(pBuf);
	xfer->pLength[frIndex] = length;
	return;
}