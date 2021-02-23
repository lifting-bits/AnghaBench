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
struct comedi_subdevice {int dummy; } ;
struct comedi_insn {int n; int /*<<< orphan*/  chanspec; } ;
struct comedi_device {int /*<<< orphan*/  iobase; } ;

/* Variables and functions */
 int C6X_encInput (int /*<<< orphan*/ ,int) ; 
 int CR_CHAN (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int c6xdigio_ei_insn_read(struct comedi_device *dev,
				 struct comedi_subdevice *s,
				 struct comedi_insn *insn, unsigned int *data)
{
	/*   printk("c6xdigio_ei__insn_read %x\n", insn->n); */
	int n;
	int chan = CR_CHAN(insn->chanspec);

	for (n = 0; n < insn->n; n++) {
		data[n] = (C6X_encInput(dev->iobase, chan) & 0xffffff);
	}

	return n;
}