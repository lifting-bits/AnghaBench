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
struct TYPE_6__ {int fpc; TYPE_1__* fprs; } ;
struct TYPE_7__ {TYPE_2__ fp_regs; } ;
struct TYPE_8__ {TYPE_3__ thread; } ;
struct TYPE_5__ {float f; int /*<<< orphan*/  d; } ;

/* Variables and functions */
 int /*<<< orphan*/  D ; 
 int /*<<< orphan*/  DA ; 
 int /*<<< orphan*/  DB ; 
 int /*<<< orphan*/  DR ; 
 int /*<<< orphan*/  FP_CONV (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FP_DECL_D (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FP_DECL_EX ; 
 int /*<<< orphan*/  FP_DECL_S (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FP_MUL_D (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FP_PACK_DP (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FP_UNPACK_SP (int /*<<< orphan*/ ,float*) ; 
 int /*<<< orphan*/  S ; 
 int /*<<< orphan*/  SA ; 
 int _fex ; 
 TYPE_4__* current ; 

__attribute__((used)) static int emu_mdeb (struct pt_regs *regs, int rx, float *val) {
        FP_DECL_S(SA); FP_DECL_D(DA); FP_DECL_D(DB); FP_DECL_D(DR);
	FP_DECL_EX;
        int mode;

	mode = current->thread.fp_regs.fpc & 3;
        FP_UNPACK_SP(SA, &current->thread.fp_regs.fprs[rx].f);
	FP_CONV (D, S, 2, 1, DA, SA);
        FP_UNPACK_SP(SA, val);
	FP_CONV (D, S, 2, 1, DB, SA);
        FP_MUL_D(DR, DA, DB);
	FP_PACK_DP(&current->thread.fp_regs.fprs[rx].d, DR);
        return _fex;
}