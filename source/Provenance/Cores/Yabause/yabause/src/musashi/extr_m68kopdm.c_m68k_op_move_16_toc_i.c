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
 int /*<<< orphan*/  OPER_I_16 () ; 
 int /*<<< orphan*/  m68ki_set_ccr (int /*<<< orphan*/ ) ; 

void m68k_op_move_16_toc_i(void)
{
	m68ki_set_ccr(OPER_I_16());
}