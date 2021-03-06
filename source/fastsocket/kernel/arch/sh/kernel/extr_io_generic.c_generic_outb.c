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
typedef  int /*<<< orphan*/  u8 ;

/* Variables and functions */
 int /*<<< orphan*/  __ioport_map (unsigned long,int) ; 
 int /*<<< orphan*/  __raw_writeb (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void generic_outb(u8 b, unsigned long port)
{
	__raw_writeb(b, __ioport_map(port, 1));
}