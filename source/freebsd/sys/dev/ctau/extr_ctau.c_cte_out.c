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
typedef  int port_t ;

/* Variables and functions */
 int E1DAT (int) ; 
 int /*<<< orphan*/  outb (int,unsigned char) ; 

void cte_out (port_t base, unsigned char reg, unsigned char val)
{
	outb (base, reg);
	outb (E1DAT (base & 0x3e0), val);
}