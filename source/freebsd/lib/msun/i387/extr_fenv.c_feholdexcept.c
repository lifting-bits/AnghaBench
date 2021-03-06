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
typedef  int /*<<< orphan*/  fenv_t ;
typedef  int __uint32_t ;

/* Variables and functions */
 int FE_ALL_EXCEPT ; 
 int _SSE_EMASK_SHIFT ; 
 scalar_t__ __HAS_SSE () ; 
 int /*<<< orphan*/  __fnclex () ; 
 int /*<<< orphan*/  __fnstenv (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  __ldmxcsr (int*) ; 
 int /*<<< orphan*/  __set_mxcsr (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  __stmxcsr (int*) ; 

int
feholdexcept(fenv_t *envp)
{
	__uint32_t mxcsr;

	__fnstenv(envp);
	__fnclex();
	if (__HAS_SSE()) {
		__stmxcsr(&mxcsr);
		__set_mxcsr(*envp, mxcsr);
		mxcsr &= ~FE_ALL_EXCEPT;
		mxcsr |= FE_ALL_EXCEPT << _SSE_EMASK_SHIFT;
		__ldmxcsr(&mxcsr);
	}
	return (0);
}