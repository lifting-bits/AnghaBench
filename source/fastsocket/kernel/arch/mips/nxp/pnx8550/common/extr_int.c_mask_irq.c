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

/* Variables and functions */
 unsigned int PNX8550_INT_CP0_MAX ; 
 unsigned int PNX8550_INT_CP0_MIN ; 
 unsigned int PNX8550_INT_GIC_MAX ; 
 unsigned int PNX8550_INT_GIC_MIN ; 
 unsigned int PNX8550_INT_TIMER_MAX ; 
 unsigned int PNX8550_INT_TIMER_MIN ; 
 int /*<<< orphan*/  mask_gic_int (unsigned int) ; 
 int /*<<< orphan*/  modify_cp0_intmask (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printk (char*,unsigned int) ; 

__attribute__((used)) static inline void mask_irq(unsigned int irq_nr)
{
	if ((PNX8550_INT_CP0_MIN <= irq_nr) && (irq_nr <= PNX8550_INT_CP0_MAX)) {
		modify_cp0_intmask(1 << irq_nr, 0);
	} else if ((PNX8550_INT_GIC_MIN <= irq_nr) &&
		(irq_nr <= PNX8550_INT_GIC_MAX)) {
		mask_gic_int(irq_nr - PNX8550_INT_GIC_MIN);
	} else if ((PNX8550_INT_TIMER_MIN <= irq_nr) &&
		(irq_nr <= PNX8550_INT_TIMER_MAX)) {
		modify_cp0_intmask(1 << 7, 0);
	} else {
		printk("mask_irq: irq %d doesn't exist!\n", irq_nr);
	}
}