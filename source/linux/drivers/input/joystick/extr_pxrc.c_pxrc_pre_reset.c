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
struct usb_interface {int dummy; } ;
struct pxrc {int /*<<< orphan*/  urb; int /*<<< orphan*/  pm_mutex; } ;

/* Variables and functions */
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 struct pxrc* usb_get_intfdata (struct usb_interface*) ; 
 int /*<<< orphan*/  usb_kill_urb (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int pxrc_pre_reset(struct usb_interface *intf)
{
	struct pxrc *pxrc = usb_get_intfdata(intf);

	mutex_lock(&pxrc->pm_mutex);
	usb_kill_urb(pxrc->urb);
	return 0;
}