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
typedef  int /*<<< orphan*/  int32 ;
typedef  int /*<<< orphan*/  float64 ;

/* Variables and functions */
 int /*<<< orphan*/  __fpu_getreg64 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __fpu_setreg (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  emul_trap (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  insn_int32_to_float64 ; 

float64
syst_int32_to_float64(int32 a)
{

	__fpu_setreg(0, a);
	emul_trap(&insn_int32_to_float64, 0x3UL);
	return (__fpu_getreg64(0));
}