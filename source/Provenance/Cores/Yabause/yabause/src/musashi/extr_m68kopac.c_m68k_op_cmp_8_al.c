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
typedef  void* uint ;

/* Variables and functions */
 int /*<<< orphan*/  CFLAG_8 (void*) ; 
 void* DX ; 
 int /*<<< orphan*/  FLAG_C ; 
 int /*<<< orphan*/  FLAG_N ; 
 int /*<<< orphan*/  FLAG_V ; 
 void* FLAG_Z ; 
 void* MASK_OUT_ABOVE_8 (void*) ; 
 int /*<<< orphan*/  NFLAG_8 (void*) ; 
 void* OPER_AL_8 () ; 
 int /*<<< orphan*/  VFLAG_SUB_8 (void*,void*,void*) ; 

void m68k_op_cmp_8_al(void)
{
	uint src = OPER_AL_8();
	uint dst = MASK_OUT_ABOVE_8(DX);
	uint res = dst - src;

	FLAG_N = NFLAG_8(res);
	FLAG_Z = MASK_OUT_ABOVE_8(res);
	FLAG_V = VFLAG_SUB_8(src, dst, res);
	FLAG_C = CFLAG_8(res);
}