#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int ut8 ;
typedef  scalar_t__ ut64 ;
struct TYPE_3__ {int /*<<< orphan*/  type; int /*<<< orphan*/  jump; scalar_t__ size; scalar_t__ fail; } ;
typedef  TYPE_1__ RAnalOp ;
typedef  int /*<<< orphan*/  RAnal ;

/* Variables and functions */
 int /*<<< orphan*/  R_ANAL_OP_TYPE_CJMP ; 
 int /*<<< orphan*/  R_ANAL_OP_TYPE_MOV ; 
 int /*<<< orphan*/  xtensa_imm6s (scalar_t__,int const*) ; 

__attribute__((used)) static void xtensa_st2n_op (RAnal *anal, RAnalOp *op, ut64 addr, const ut8 *buf) {
	if (buf[0] & 0x80) {
		op->type = R_ANAL_OP_TYPE_CJMP;
		op->fail = addr + op->size;
		op->jump = xtensa_imm6s (addr, buf);
	} else {
		op->type = R_ANAL_OP_TYPE_MOV;
	}
}