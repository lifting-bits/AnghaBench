#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int reg; } ;

/* Variables and functions */
 int PIRQ_IRQ ; 
 int /*<<< orphan*/  assert (int) ; 
 unsigned int nitems (TYPE_1__*) ; 
 TYPE_1__* pirqs ; 

int
pirq_irq(int pin)
{
	assert((pin > 0) && (((unsigned) pin) <= nitems(pirqs)));
	return (pirqs[pin - 1].reg & PIRQ_IRQ);
}