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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  Q68State ;

/* Variables and functions */
 scalar_t__ EA_ADDRESS_REG ; 
 scalar_t__ EA_DATA_REG ; 
 scalar_t__ EA_MODE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  JIT_EMIT_ADD_CYCLES (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  JIT_EMIT_GET_OP2_IMMEDIATE (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  JIT_EMIT_SBCD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SIZE_B ; 
 int /*<<< orphan*/  current_entry ; 
 int /*<<< orphan*/  ea_get (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int*,int) ; 
 int /*<<< orphan*/  ea_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int op_ill (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int opNBCD(Q68State *state, uint32_t opcode)
{
    if (EA_MODE(opcode) == EA_ADDRESS_REG) {  // Address registers not allowed
        return op_ill(state, opcode);
    }

    int cycles;
    ea_get(state, opcode, SIZE_B, 1, &cycles, 1);
    if (cycles < 0) {
        return 1;
    }

    /* Treat it as something like SBCD <ea>,#0 for simplicity */
    JIT_EMIT_GET_OP2_IMMEDIATE(current_entry, 0);
    JIT_EMIT_SBCD(current_entry);

    ea_set(state, opcode, SIZE_B);
    JIT_EMIT_ADD_CYCLES(current_entry,
                        (EA_MODE(opcode) == EA_DATA_REG ? 6 : 8) + cycles);
    return 0;
}