#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct pt_regs {int dummy; } ;
struct TYPE_6__ {TYPE_1__* fprs; } ;
struct TYPE_7__ {TYPE_2__ fp_regs; } ;
struct TYPE_8__ {TYPE_3__ thread; } ;
struct TYPE_5__ {float f; } ;

/* Variables and functions */
 int /*<<< orphan*/  FP_CMP_S (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  FP_DECL_S (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FP_UNPACK_RAW_SP (int /*<<< orphan*/ ,float*) ; 
 int /*<<< orphan*/  SA ; 
 int /*<<< orphan*/  SB ; 
 TYPE_4__* current ; 
 int /*<<< orphan*/  emu_set_CC (struct pt_regs*,int) ; 

__attribute__((used)) static int emu_ceb (struct pt_regs *regs, int rx, float *val) {
        FP_DECL_S(SA); FP_DECL_S(SB);
        int IR;

        FP_UNPACK_RAW_SP(SA, &current->thread.fp_regs.fprs[rx].f);
        FP_UNPACK_RAW_SP(SB, val);
        FP_CMP_S(IR, SA, SB, 3);
        /*
         * IR == -1 if DA < DB, IR == 0 if DA == DB,
         * IR == 1 if DA > DB and IR == 3 if unorderded
         */
        emu_set_CC(regs, (IR == -1) ? 1 : (IR == 1) ? 2 : IR);
        return 0;
}