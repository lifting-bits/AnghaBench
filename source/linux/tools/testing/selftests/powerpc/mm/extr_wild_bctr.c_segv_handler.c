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
typedef  int /*<<< orphan*/  siginfo_t ;

/* Variables and functions */
 int /*<<< orphan*/  longjmp (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  save_regs (void*) ; 
 int /*<<< orphan*/  setjmp_env ; 

__attribute__((used)) static void segv_handler(int signum, siginfo_t *info, void *ctxt_v)
{
	save_regs(ctxt_v);
	longjmp(setjmp_env, 1);
}