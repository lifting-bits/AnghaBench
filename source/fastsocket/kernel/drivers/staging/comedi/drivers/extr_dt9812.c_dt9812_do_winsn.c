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
typedef  int u8 ;
struct comedi_subdevice {int dummy; } ;
struct comedi_insn {int n; int chanspec; } ;
struct comedi_device {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  slot; } ;

/* Variables and functions */
 TYPE_1__* devpriv ; 
 int /*<<< orphan*/  dt9812_digital_out (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dt9812_digital_out_shadow (int /*<<< orphan*/ ,int*) ; 

__attribute__((used)) static int dt9812_do_winsn(struct comedi_device *dev,
			   struct comedi_subdevice *s, struct comedi_insn *insn,
			   unsigned int *data)
{
	int n;
	u8 bits = 0;

	dt9812_digital_out_shadow(devpriv->slot, &bits);
	for (n = 0; n < insn->n; n++) {
		u8 mask = 1 << insn->chanspec;

		bits &= ~mask;
		if (data[n])
			bits |= mask;
	}
	dt9812_digital_out(devpriv->slot, bits);
	return n;
}