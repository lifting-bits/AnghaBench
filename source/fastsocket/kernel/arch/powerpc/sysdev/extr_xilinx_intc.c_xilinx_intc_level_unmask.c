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
 int XINTC_IAR ; 
 int XINTC_SIE ; 
 void* get_irq_chip_data (unsigned int) ; 
 int /*<<< orphan*/  out_be32 (void*,int) ; 
 int /*<<< orphan*/  pr_debug (char*,int) ; 
 int virq_to_hw (unsigned int) ; 

__attribute__((used)) static void xilinx_intc_level_unmask(unsigned int virq)
{
	int irq = virq_to_hw(virq);
	void * regs = get_irq_chip_data(virq);
	pr_debug("unmask: %d\n", irq);
	out_be32(regs + XINTC_SIE, 1 << irq);

	/* ack level irqs because they can't be acked during
	 * ack function since the handle_level_irq function
	 * acks the irq before calling the inerrupt handler
	 */
	out_be32(regs + XINTC_IAR, 1 << irq);
}