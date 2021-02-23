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
 unsigned int LAN_IOEND ; 
 unsigned int LAN_IOSTART ; 
 unsigned int M32R_PCC_IOEND0 ; 
 unsigned int M32R_PCC_IOSTART0 ; 
 unsigned short* PORT2ADDR (unsigned int) ; 
 unsigned short* PORT2ADDR_NE (unsigned int) ; 
 unsigned short* __port2addr_ata (unsigned int) ; 
 int /*<<< orphan*/  pcc_iowrite_word (int,unsigned int,void*,int,unsigned long,int) ; 

void _outsw(unsigned int port, const void * addr, unsigned long count)
{
	const unsigned short *buf = addr;
	unsigned short *portp;

	if (port >= LAN_IOSTART && port < LAN_IOEND) {
		portp = PORT2ADDR_NE(port);
		while (count--)
			*(volatile unsigned short *)portp = *buf++;
#if defined(CONFIG_IDE) && !defined(CONFIG_M32R_CFC)
	} else if ((port >= 0x1f0 && port <=0x1f7) || port == 0x3f6) {
		portp = __port2addr_ata(port);
		while (count--)
			*(volatile unsigned short *)portp = *buf++;
#endif
#if defined(CONFIG_PCMCIA) && defined(CONFIG_M32R_CFC)
	} else if (port >= M32R_PCC_IOSTART0 && port <= M32R_PCC_IOEND0) {
		pcc_iowrite_word(9, port, (void *)addr, sizeof(unsigned short),
				 count, 1);
#endif
	} else {
		portp = PORT2ADDR(port);
		while (count--)
			*(volatile unsigned short *)portp = *buf++;
	}
}