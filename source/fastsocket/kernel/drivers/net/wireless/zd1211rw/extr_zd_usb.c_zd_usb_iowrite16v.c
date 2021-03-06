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
struct zd_usb {int dummy; } ;
struct zd_ioreq16 {int dummy; } ;

/* Variables and functions */
 int zd_usb_iowrite16v_async (struct zd_usb*,struct zd_ioreq16 const*,unsigned int) ; 
 int zd_usb_iowrite16v_async_end (struct zd_usb*,int) ; 
 int /*<<< orphan*/  zd_usb_iowrite16v_async_start (struct zd_usb*) ; 

int zd_usb_iowrite16v(struct zd_usb *usb, const struct zd_ioreq16 *ioreqs,
			unsigned int count)
{
	int r;

	zd_usb_iowrite16v_async_start(usb);
	r = zd_usb_iowrite16v_async(usb, ioreqs, count);
	if (r) {
		zd_usb_iowrite16v_async_end(usb, 0);
		return r;
	}
	return zd_usb_iowrite16v_async_end(usb, 50 /* ms */);
}