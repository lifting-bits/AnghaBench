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
typedef  scalar_t__ uint32_t ;
typedef  int mach_msg_type_number_t ;
typedef  scalar_t__ mach_exception_data_type_t ;
typedef  int /*<<< orphan*/  instr ;
typedef  int /*<<< orphan*/  exception_type_t ;
typedef  int /*<<< orphan*/  arm_saved_state_t ;

/* Variables and functions */
 int /*<<< orphan*/  COPYIN (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  ESR_EC_MSR_TRAP ; 
 scalar_t__ EXC_ARM_UNDEFINED ; 
 int /*<<< orphan*/  EXC_BAD_INSTRUCTION ; 
 scalar_t__ PSR64_IS_KERNEL (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  exception_triage (int /*<<< orphan*/ ,scalar_t__*,int) ; 
 int /*<<< orphan*/  get_saved_state_cpsr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  get_saved_state_pc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  is_saved_state64 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  panic (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
handle_msr_trap(arm_saved_state_t *state, uint32_t iss)
{
	exception_type_t           exception = EXC_BAD_INSTRUCTION;
	mach_exception_data_type_t codes[2] = {EXC_ARM_UNDEFINED};
	mach_msg_type_number_t     numcodes = 2;
	uint32_t                   instr = 0;

	(void)iss;

	if (!is_saved_state64(state)) {
		panic("MSR/MRS trap (EC 0x%x) from 32-bit state\n", ESR_EC_MSR_TRAP);
	}

	if (PSR64_IS_KERNEL(get_saved_state_cpsr(state))) {
		panic("MSR/MRS trap (EC 0x%x) from kernel\n", ESR_EC_MSR_TRAP);
	}

	COPYIN(get_saved_state_pc(state), (char *)&instr, sizeof(instr));
	codes[1] = instr;

	exception_triage(exception, codes, numcodes);
}