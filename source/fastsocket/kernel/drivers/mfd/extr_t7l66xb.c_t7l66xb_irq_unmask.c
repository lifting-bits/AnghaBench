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
typedef  int u8 ;
struct t7l66xb {unsigned int irq_base; int /*<<< orphan*/  lock; scalar_t__ scr; } ;

/* Variables and functions */
 scalar_t__ SCR_IMR ; 
 struct t7l66xb* get_irq_chip_data (unsigned int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int tmio_ioread8 (scalar_t__) ; 
 int /*<<< orphan*/  tmio_iowrite8 (int,scalar_t__) ; 

__attribute__((used)) static void t7l66xb_irq_unmask(unsigned int irq)
{
	struct t7l66xb *t7l66xb = get_irq_chip_data(irq);
	unsigned long flags;
	u8 imr;

	spin_lock_irqsave(&t7l66xb->lock, flags);
	imr = tmio_ioread8(t7l66xb->scr + SCR_IMR);
	imr &= ~(1 << (irq - t7l66xb->irq_base));
	tmio_iowrite8(imr, t7l66xb->scr + SCR_IMR);
	spin_unlock_irqrestore(&t7l66xb->lock, flags);
}