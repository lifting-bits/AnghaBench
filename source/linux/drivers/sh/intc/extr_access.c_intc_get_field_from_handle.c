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
 unsigned int _INTC_SHIFT (unsigned int) ; 
 unsigned int _INTC_WIDTH (unsigned int) ; 

unsigned long intc_get_field_from_handle(unsigned int value, unsigned int handle)
{
	unsigned int width = _INTC_WIDTH(handle);
	unsigned int shift = _INTC_SHIFT(handle);
	unsigned int mask = ((1 << width) - 1) << shift;

	return (value & mask) >> shift;
}