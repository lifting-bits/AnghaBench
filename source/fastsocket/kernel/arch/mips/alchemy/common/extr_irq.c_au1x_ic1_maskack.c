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
 unsigned int AU1000_INTC1_INT_BASE ; 
 int /*<<< orphan*/  IC1_FALLINGCLR ; 
 int /*<<< orphan*/  IC1_MASKCLR ; 
 int /*<<< orphan*/  IC1_RISINGCLR ; 
 int /*<<< orphan*/  IC1_WAKECLR ; 
 int /*<<< orphan*/  au_sync () ; 
 int /*<<< orphan*/  au_writel (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void au1x_ic1_maskack(unsigned int irq_nr)
{
	unsigned int bit = irq_nr - AU1000_INTC1_INT_BASE;

	au_writel(1 << bit, IC1_WAKECLR);
	au_writel(1 << bit, IC1_MASKCLR);
	au_writel(1 << bit, IC1_RISINGCLR);
	au_writel(1 << bit, IC1_FALLINGCLR);
	au_sync();
}