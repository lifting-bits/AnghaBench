#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint16_t ;
struct TYPE_7__ {int pc; int /*<<< orphan*/  cycles; } ;
typedef  TYPE_1__ sh2rec_block_t ;

/* Variables and functions */
 int INSTRUCTION_B (int /*<<< orphan*/ ) ; 
 int INSTRUCTION_C (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  R0 ; 
 int /*<<< orphan*/  R10 ; 
 int /*<<< orphan*/  R4 ; 
 int /*<<< orphan*/  R5 ; 
 int /*<<< orphan*/  R8 ; 
 int /*<<< orphan*/  R9 ; 
 int /*<<< orphan*/  R_PR ; 
 int /*<<< orphan*/  emitJSR (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  emitLDS (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  emitMOVLL4 (TYPE_1__*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  emitSTS (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void generateMOVWS(uint16_t inst, sh2rec_block_t *b) {
    int regn = INSTRUCTION_B(inst);
    int regm = INSTRUCTION_C(inst);

    emitMOVLL4(b, R9, 4, R0);       /* R0 <- MappedMemoryWriteWord */
    emitMOVLL4(b, R8, regm, R5);    /* R5 <- sh2[Rm] */
    emitSTS(b, R_PR, R10);          /* R10 <- PR */
    emitJSR(b, R0);                 /* Call MappedMemoryWriteWord */
    emitMOVLL4(b, R8, regn, R4);    /* R4 <- sh2[Rn] */
    emitLDS(b, R10, R_PR);          /* PR <- R10 */

    ++b->cycles;                    /* 1 Cycle */
    b->pc += 2;
}