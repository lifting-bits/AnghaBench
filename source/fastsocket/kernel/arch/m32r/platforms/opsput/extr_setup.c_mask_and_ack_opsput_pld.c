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
 int /*<<< orphan*/  disable_opsput_pld_irq (unsigned int) ; 

__attribute__((used)) static void mask_and_ack_opsput_pld(unsigned int irq)
{
	disable_opsput_pld_irq(irq);
//	mask_and_ack_opsput(M32R_IRQ_INT1);
}