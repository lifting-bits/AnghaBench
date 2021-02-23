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
 unsigned int CFC_IOEND ; 
 unsigned int CFC_IOSTART ; 
 unsigned char* PORT2ADDR (unsigned int) ; 
 int /*<<< orphan*/  pcc_iowrite_byte (int /*<<< orphan*/ ,unsigned int,void*,int,unsigned long,int) ; 

void _outsb(unsigned int port, const void * addr, unsigned long count)
{
	const unsigned char *buf = addr;
	unsigned char *portp;

	if (port >= CFC_IOSTART && port <= CFC_IOEND)
		pcc_iowrite_byte(0, port, (void *)addr, sizeof(unsigned char),
			count, 1);
	else {
		portp = PORT2ADDR(port);
		while (count--)
			*(volatile unsigned char *)portp = *buf++;
	}
}