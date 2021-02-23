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
typedef  int /*<<< orphan*/  uint16_t ;

/* Variables and functions */
 int BITS (int /*<<< orphan*/ ,int,int) ; 
 int FASTTRAP_T_COMMON ; 
 int FASTTRAP_T_INV ; 
 scalar_t__ REG_PC ; 
 scalar_t__ THUMB32_RM (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ THUMB32_RN (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ THUMB32_RT (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static
int thumb32_store_single(uint16_t instr1, uint16_t instr2)
{
	int op1 = BITS(instr1,5,0x7), op2 = BITS(instr2,6,0x3F);

	/* Do not support any use of the pc yet */
	if ((op1 == 0 || op1 == 1 || op1 == 2) && (op2 & 0x20) == 0) {
		/* str (register) uses RM */
		if (THUMB32_RM(instr1,instr2) == REG_PC)
			return FASTTRAP_T_INV;
	}

	if (THUMB32_RT(instr1,instr2) != REG_PC && THUMB32_RN(instr1,instr2) != REG_PC)
		return FASTTRAP_T_COMMON;

	return FASTTRAP_T_INV;
}