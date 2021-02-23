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
typedef  scalar_t__ uint ;

/* Variables and functions */
 int /*<<< orphan*/  CFLAG_ADD_32 (scalar_t__,scalar_t__,scalar_t__) ; 
 scalar_t__ DY ; 
 int /*<<< orphan*/  FLAG_C ; 
 int /*<<< orphan*/  FLAG_N ; 
 int /*<<< orphan*/  FLAG_V ; 
 int /*<<< orphan*/  FLAG_X ; 
 scalar_t__ FLAG_Z ; 
 scalar_t__ MASK_OUT_ABOVE_32 (scalar_t__) ; 
 int /*<<< orphan*/  NFLAG_32 (scalar_t__) ; 
 scalar_t__ OPER_I_32 () ; 
 int /*<<< orphan*/  VFLAG_ADD_32 (scalar_t__,scalar_t__,scalar_t__) ; 

void m68k_op_addi_32_d(void)
{
	uint* r_dst = &DY;
	uint src = OPER_I_32();
	uint dst = *r_dst;
	uint res = src + dst;

	FLAG_N = NFLAG_32(res);
	FLAG_V = VFLAG_ADD_32(src, dst, res);
	FLAG_X = FLAG_C = CFLAG_ADD_32(src, dst, res);
	FLAG_Z = MASK_OUT_ABOVE_32(res);

	*r_dst = FLAG_Z;
}