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
struct renesas_usb3 {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  usb3_transition_to_default_state (struct renesas_usb3*,int) ; 

__attribute__((used)) static void usb3_irq_epc_int_1_linkup_success(struct renesas_usb3 *usb3)
{
	usb3_transition_to_default_state(usb3, true);
}