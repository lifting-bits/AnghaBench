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
 int /*<<< orphan*/  CPU_TYPE ; 
 scalar_t__ CPU_TYPE_IS_EC020_PLUS (int /*<<< orphan*/ ) ; 
 scalar_t__ MASK_OUT_ABOVE_32 (scalar_t__) ; 
 scalar_t__ OPER_I_32 () ; 
 scalar_t__* REG_A ; 
 int /*<<< orphan*/  m68ki_exception_illegal () ; 
 int /*<<< orphan*/  m68ki_write_32 (scalar_t__,scalar_t__) ; 

void m68k_op_link_32_a7(void)
{
	if(CPU_TYPE_IS_EC020_PLUS(CPU_TYPE))
	{
		REG_A[7] -= 4;
		m68ki_write_32(REG_A[7], REG_A[7]);
		REG_A[7] = MASK_OUT_ABOVE_32(REG_A[7] + OPER_I_32());
		return;
	}
	m68ki_exception_illegal();
}