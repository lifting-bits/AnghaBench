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
typedef  int /*<<< orphan*/  u_long ;
typedef  int /*<<< orphan*/  float128 ;
typedef  int /*<<< orphan*/  flag ;

/* Variables and functions */
 int /*<<< orphan*/  __fpu_setreg128 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  emul_trap (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  insn_float128_cmpe ; 

flag syst_float128_eq_signaling(float128 a, float128 b)
{
	u_long r;

	__fpu_setreg128(0, a);
	__fpu_setreg128(4, b);
	emul_trap(&insn_float128_cmpe, 0x0UL);
	__asm __volatile("mov 0,%0; move %%fcc0,1,%0" : "=r" (r));
	return (r);
}