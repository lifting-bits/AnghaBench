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
struct TYPE_3__ {int __mxcsr; int /*<<< orphan*/  __x87; } ;
typedef  TYPE_1__ fenv_t ;
typedef  int __uint32_t ;

/* Variables and functions */
 int FE_ALL_EXCEPT ; 
 int _SSE_EMASK_SHIFT ; 
 int /*<<< orphan*/  __fnclex () ; 
 int /*<<< orphan*/  __fnstenv (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  __ldmxcsr (int*) ; 
 int /*<<< orphan*/  __stmxcsr (int*) ; 

int
feholdexcept(fenv_t *envp)
{
	__uint32_t mxcsr;

	__stmxcsr(&mxcsr);
	__fnstenv(&envp->__x87);
	__fnclex();
	envp->__mxcsr = mxcsr;
	mxcsr &= ~FE_ALL_EXCEPT;
	mxcsr |= FE_ALL_EXCEPT << _SSE_EMASK_SHIFT;
	__ldmxcsr(&mxcsr);
	return (0);
}