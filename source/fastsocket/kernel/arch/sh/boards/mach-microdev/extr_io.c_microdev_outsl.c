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
 scalar_t__ PORT2ADDR (unsigned long) ; 

void microdev_outsl(unsigned long port, const void *buffer, unsigned long count)
{
	volatile unsigned long *port_addr;
	const unsigned int *buf = buffer;

	port_addr = (volatile unsigned long *)PORT2ADDR(port);

	while (count--)
		*port_addr = *buf++;
}