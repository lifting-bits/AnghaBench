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
typedef  int uint8_t ;
struct pirq {int reg; scalar_t__ active_count; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int PIRQ_DIS ; 
 int PIRQ_IRQ ; 
 int /*<<< orphan*/  assert (int) ; 
 unsigned int nitems (struct pirq*) ; 
 scalar_t__ pirq_valid_irq (int) ; 
 struct pirq* pirqs ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xh_vm_isa_assert_irq (int,int) ; 
 int /*<<< orphan*/  xh_vm_isa_deassert_irq (int,int) ; 

void
pirq_write(int pin, uint8_t val)
{
	struct pirq *pirq;

	assert((pin > 0) && (((unsigned) pin) <= nitems(pirqs)));
	pirq = &pirqs[pin - 1];
	pthread_mutex_lock(&pirq->lock);
	if (pirq->reg != (val & (PIRQ_DIS | PIRQ_IRQ))) {
		if (pirq->active_count != 0 && pirq_valid_irq(pirq->reg))
			xh_vm_isa_deassert_irq(pirq->reg & PIRQ_IRQ, -1);
		pirq->reg = val & (PIRQ_DIS | PIRQ_IRQ);
		if (pirq->active_count != 0 && pirq_valid_irq(pirq->reg))
			xh_vm_isa_assert_irq(pirq->reg & PIRQ_IRQ, -1);
	}
	pthread_mutex_unlock(&pirq->lock);
}