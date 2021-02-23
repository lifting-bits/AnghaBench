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
 int /*<<< orphan*/  PA_IMASK ; 
 unsigned char ctrl_inb (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ctrl_outb (unsigned char,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void enable_landisk_irq(unsigned int irq)
{
	unsigned char value = (0x01 << (irq - 5));

	ctrl_outb(ctrl_inb(PA_IMASK) | value, PA_IMASK);
}