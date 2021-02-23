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
 unsigned int i8254_control_reg ; 
 int readb (void*) ; 
 int /*<<< orphan*/  writeb (unsigned int,void*) ; 

__attribute__((used)) static inline int i8254_mm_read(void *base_address, unsigned int regshift,
				unsigned int counter_number)
{
	unsigned int byte;
	int ret;

	if (counter_number > 2)
		return -1;

	/*  latch counter */
	byte = counter_number << 6;
	writeb(byte, base_address + (i8254_control_reg << regshift));

	/*  read lsb */
	ret = readb(base_address + (counter_number << regshift));
	/*  read msb */
	ret += readb(base_address + (counter_number << regshift)) << 8;

	return ret;
}