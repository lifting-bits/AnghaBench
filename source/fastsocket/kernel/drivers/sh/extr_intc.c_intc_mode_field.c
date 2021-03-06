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
 int _INTC_WIDTH (unsigned long) ; 

__attribute__((used)) static void intc_mode_field(unsigned long addr,
			    unsigned long handle,
			    void (*fn)(unsigned long,
				       unsigned long,
				       unsigned long),
			    unsigned int irq)
{
	fn(addr, handle, ((1 << _INTC_WIDTH(handle)) - 1));
}