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
struct dvb_ca_private {TYPE_1__* slot_info; } ;
struct dvb_ca_en50221 {struct dvb_ca_private* private; } ;
struct TYPE_2__ {scalar_t__ slot_state; } ;

/* Variables and functions */
 scalar_t__ DVB_CA_SLOTSTATE_VALIDATE ; 
 scalar_t__ DVB_CA_SLOTSTATE_WAITREADY ; 
 int /*<<< orphan*/  dprintk (char*,int) ; 
 int /*<<< orphan*/  dvb_ca_en50221_thread_wakeup (struct dvb_ca_private*) ; 

void dvb_ca_en50221_camready_irq(struct dvb_ca_en50221 *pubca, int slot)
{
	struct dvb_ca_private *ca = pubca->private;

	dprintk("CAMREADY IRQ slot:%i\n", slot);

	if (ca->slot_info[slot].slot_state == DVB_CA_SLOTSTATE_WAITREADY) {
		ca->slot_info[slot].slot_state = DVB_CA_SLOTSTATE_VALIDATE;
		dvb_ca_en50221_thread_wakeup(ca);
	}
}