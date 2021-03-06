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
struct comedi_device {scalar_t__ irq; scalar_t__ iobase; int /*<<< orphan*/  minor; } ;

/* Variables and functions */
 int /*<<< orphan*/  DAS800_SIZE ; 
 int /*<<< orphan*/  free_irq (scalar_t__,struct comedi_device*) ; 
 int /*<<< orphan*/  printk (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  release_region (scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int das800_detach(struct comedi_device *dev)
{
	printk("comedi%d: das800: remove\n", dev->minor);

	/* only free stuff if it has been allocated by _attach */
	if (dev->iobase)
		release_region(dev->iobase, DAS800_SIZE);
	if (dev->irq)
		free_irq(dev->irq, dev);
	return 0;
}