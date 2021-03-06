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
typedef  int volatile u32 ;

/* Variables and functions */
 scalar_t__ SNI_PCIT_INT_REG ; 
 unsigned int SNI_PCIT_INT_START ; 

__attribute__((used)) static void enable_pcit_irq(unsigned int irq)
{
	u32 mask = 1 << (irq - SNI_PCIT_INT_START + 24);

	*(volatile u32 *)SNI_PCIT_INT_REG |= mask;
}