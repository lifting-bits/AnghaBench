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
struct comedi_subdevice {int /*<<< orphan*/  state; } ;
struct comedi_insn {int n; } ;
struct comedi_device {scalar_t__ mmio; } ;

/* Variables and functions */
 scalar_t__ DIO_DATA_60XX_REG ; 
 scalar_t__ comedi_dio_update_state (struct comedi_subdevice*,unsigned int*) ; 
 unsigned int readb (scalar_t__) ; 
 int /*<<< orphan*/  writeb (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static int dio_60xx_wbits(struct comedi_device *dev,
			  struct comedi_subdevice *s,
			  struct comedi_insn *insn,
			  unsigned int *data)
{
	if (comedi_dio_update_state(s, data))
		writeb(s->state, dev->mmio + DIO_DATA_60XX_REG);

	data[1] = readb(dev->mmio + DIO_DATA_60XX_REG);

	return insn->n;
}