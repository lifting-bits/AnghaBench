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
typedef  int ut16 ;
typedef  int /*<<< orphan*/  st8 ;
struct TYPE_3__ {int size; int /*<<< orphan*/  esil; int /*<<< orphan*/ * src; int /*<<< orphan*/  dst; int /*<<< orphan*/  type; } ;
typedef  TYPE_1__ RAnalOp ;
typedef  int /*<<< orphan*/  RAnal ;

/* Variables and functions */
 int /*<<< orphan*/  GET_TARGET_REG (int) ; 
 int /*<<< orphan*/  R_ANAL_OP_TYPE_MOV ; 
 int /*<<< orphan*/  anal_fill_ai_rg (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  anal_fill_im (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  r_strbuf_setf (int /*<<< orphan*/ *,char*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mov_imm_reg(RAnal* anal, RAnalOp* op, ut16 code) {
	op->type = R_ANAL_OP_TYPE_MOV;
	op->dst = anal_fill_ai_rg (anal, GET_TARGET_REG (code));
	op->src[0] = anal_fill_im (anal, (st8)(code & 0xFF));
	r_strbuf_setf (&op->esil, "0x%x,r%d,=,r%d,0x80,&,?{,0xFFFFFF00,r%d,|=,}", code & 0xFF, GET_TARGET_REG (code), GET_TARGET_REG (code), GET_TARGET_REG (code));
	return op->size;
}