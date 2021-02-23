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
 int /*<<< orphan*/  ia64_eoi () ; 
 int /*<<< orphan*/  irq_complete_move (unsigned int) ; 
 int /*<<< orphan*/  move_native_irq (unsigned int) ; 

__attribute__((used)) static void ia64_ack_msi_irq(unsigned int irq)
{
	irq_complete_move(irq);
	move_native_irq(irq);
	ia64_eoi();
}