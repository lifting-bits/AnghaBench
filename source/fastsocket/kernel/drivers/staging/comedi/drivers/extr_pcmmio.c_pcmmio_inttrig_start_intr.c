#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct comedi_subdevice {TYPE_3__* async; } ;
struct comedi_device {int dummy; } ;
struct TYPE_5__ {int /*<<< orphan*/  spinlock; scalar_t__ active; } ;
struct TYPE_6__ {TYPE_1__ intr; } ;
struct TYPE_8__ {TYPE_2__ dio; } ;
struct TYPE_7__ {scalar_t__ inttrig; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  comedi_event (struct comedi_device*,struct comedi_subdevice*) ; 
 int pcmmio_start_intr (struct comedi_device*,struct comedi_subdevice*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 TYPE_4__* subpriv ; 

__attribute__((used)) static int
pcmmio_inttrig_start_intr(struct comedi_device *dev, struct comedi_subdevice *s,
			  unsigned int trignum)
{
	unsigned long flags;
	int event = 0;

	if (trignum != 0)
		return -EINVAL;

	spin_lock_irqsave(&subpriv->dio.intr.spinlock, flags);
	s->async->inttrig = 0;
	if (subpriv->dio.intr.active) {
		event = pcmmio_start_intr(dev, s);
	}
	spin_unlock_irqrestore(&subpriv->dio.intr.spinlock, flags);

	if (event) {
		comedi_event(dev, s);
	}

	return 1;
}