#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct comedi_subdevice {int dummy; } ;
struct comedi_insn {int n; } ;
struct comedi_device {int dummy; } ;
struct TYPE_4__ {TYPE_1__* mite; } ;
struct TYPE_3__ {scalar_t__ daq_io_addr; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ Falling_Edge_Detection_Enable (int) ; 
 unsigned int INSN_CONFIG_CHANGE_NOTIFY ; 
 scalar_t__ Rising_Edge_Detection_Enable (int) ; 
 TYPE_2__* devpriv ; 
 int /*<<< orphan*/  writeb (unsigned int,scalar_t__) ; 

__attribute__((used)) static int ni6527_intr_insn_config(struct comedi_device *dev,
				   struct comedi_subdevice *s,
				   struct comedi_insn *insn, unsigned int *data)
{
	if (insn->n < 1)
		return -EINVAL;
	if (data[0] != INSN_CONFIG_CHANGE_NOTIFY)
		return -EINVAL;

	writeb(data[1],
	       devpriv->mite->daq_io_addr + Rising_Edge_Detection_Enable(0));
	writeb(data[1] >> 8,
	       devpriv->mite->daq_io_addr + Rising_Edge_Detection_Enable(1));
	writeb(data[1] >> 16,
	       devpriv->mite->daq_io_addr + Rising_Edge_Detection_Enable(2));

	writeb(data[2],
	       devpriv->mite->daq_io_addr + Falling_Edge_Detection_Enable(0));
	writeb(data[2] >> 8,
	       devpriv->mite->daq_io_addr + Falling_Edge_Detection_Enable(1));
	writeb(data[2] >> 16,
	       devpriv->mite->daq_io_addr + Falling_Edge_Detection_Enable(2));

	return 2;
}