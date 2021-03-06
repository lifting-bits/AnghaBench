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
typedef  enum GA_REG { ____Placeholder_GA_REG } GA_REG ;

/* Variables and functions */
 int sscape_read_unsafe (unsigned int,int) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int sscape_wait_dma_unsafe(unsigned io_base, enum GA_REG reg, unsigned timeout)
{
	while (!(sscape_read_unsafe(io_base, reg) & 0x01) && (timeout != 0)) {
		udelay(100);
		--timeout;
	} /* while */

	return (sscape_read_unsafe(io_base, reg) & 0x01);
}