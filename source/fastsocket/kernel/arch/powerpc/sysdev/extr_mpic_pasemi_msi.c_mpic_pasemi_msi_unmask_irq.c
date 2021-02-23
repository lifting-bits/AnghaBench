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
 int /*<<< orphan*/  mpic_unmask_irq (unsigned int) ; 
 int /*<<< orphan*/  pr_debug (char*,unsigned int) ; 
 int /*<<< orphan*/  unmask_msi_irq (unsigned int) ; 

__attribute__((used)) static void mpic_pasemi_msi_unmask_irq(unsigned int irq)
{
	pr_debug("mpic_pasemi_msi_unmask_irq %d\n", irq);
	mpic_unmask_irq(irq);
	unmask_msi_irq(irq);
}