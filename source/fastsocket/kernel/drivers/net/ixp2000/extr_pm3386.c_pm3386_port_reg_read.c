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
typedef  int /*<<< orphan*/  u16 ;

/* Variables and functions */
 int /*<<< orphan*/  pm3386_reg_read (int,int) ; 

__attribute__((used)) static u16 pm3386_port_reg_read(int port, int _reg, int spacing)
{
	int reg;

	reg = _reg;
	if (port & 1)
		reg += spacing;

	return pm3386_reg_read(port >> 1, reg);
}