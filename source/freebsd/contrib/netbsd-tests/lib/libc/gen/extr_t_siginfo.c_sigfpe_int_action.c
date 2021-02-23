#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ucontext_t ;
struct TYPE_4__ {int /*<<< orphan*/  si_errno; int /*<<< orphan*/  si_code; int /*<<< orphan*/  si_signo; } ;
typedef  TYPE_1__ siginfo_t ;

/* Variables and functions */
 int /*<<< orphan*/  ATF_REQUIRE_EQ (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FPE_INTDIV ; 
 int /*<<< orphan*/  SIGFPE ; 
 int /*<<< orphan*/  atf_tc_expect_pass () ; 
 int /*<<< orphan*/  atf_tc_fail (char*) ; 
 int /*<<< orphan*/  intdiv_signalled ; 
 int /*<<< orphan*/  sig_debug (int,TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sigfpe_int_env ; 
 int /*<<< orphan*/  siglongjmp (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void
sigfpe_int_action(int signo, siginfo_t *info, void *ptr)
{

	sig_debug(signo, info, (ucontext_t *)ptr);

	if (intdiv_signalled++ != 0)
		atf_tc_fail("INTDIV handler called more than once");

	ATF_REQUIRE_EQ(info->si_signo, SIGFPE);
	ATF_REQUIRE_EQ(info->si_code, FPE_INTDIV);
	atf_tc_expect_pass();
	ATF_REQUIRE_EQ(info->si_errno, 0);

	siglongjmp(sigfpe_int_env, 1);
}