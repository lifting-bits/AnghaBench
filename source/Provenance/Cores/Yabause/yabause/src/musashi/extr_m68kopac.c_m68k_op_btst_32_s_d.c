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
 int DY ; 
 int FLAG_Z ; 
 int OPER_I_8 () ; 

void m68k_op_btst_32_s_d(void)
{
	FLAG_Z = DY & (1 << (OPER_I_8() & 0x1f));
}