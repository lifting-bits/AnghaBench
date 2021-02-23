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
struct usb_gadget {int dummy; } ;
struct at91_udc {int vbus; scalar_t__ driver; } ;

/* Variables and functions */
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  pullup (struct at91_udc*,int) ; 
 struct at91_udc* to_udc (struct usb_gadget*) ; 

__attribute__((used)) static int at91_vbus_session(struct usb_gadget *gadget, int is_active)
{
	struct at91_udc	*udc = to_udc(gadget);
	unsigned long	flags;

	// VDBG("vbus %s\n", is_active ? "on" : "off");
	local_irq_save(flags);
	udc->vbus = (is_active != 0);
	if (udc->driver)
		pullup(udc, is_active);
	else
		pullup(udc, 0);
	local_irq_restore(flags);
	return 0;
}