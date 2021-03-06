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
 int /*<<< orphan*/  i8259A_auto_eoi ; 
 int /*<<< orphan*/  init_8259A (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_trigger ; 
 int /*<<< orphan*/  restore_ELCR (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void i8259A_resume(void)
{
	init_8259A(i8259A_auto_eoi);
	restore_ELCR(irq_trigger);
}