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
typedef  int fenv_t ;

/* Variables and functions */
 int _ROUND_MASK ; 
 int /*<<< orphan*/  vmrs_fpscr (int) ; 
 int /*<<< orphan*/  vmsr_fpscr (int) ; 

inline int
fesetround(int __round)
{
	fenv_t __fpsr;

	vmrs_fpscr(__fpsr);
	__fpsr &= ~(_ROUND_MASK);
	__fpsr |= __round;
	vmsr_fpscr(__fpsr);
	return (0);
}