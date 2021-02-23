#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/  uc_sigmask; } ;
typedef  TYPE_1__ const ucontext_t ;
typedef  int /*<<< orphan*/  uc ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  SIGCANCEL ; 
 int /*<<< orphan*/  SIGDELSET (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SIGISMEMBER (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int __sys_setcontext (TYPE_1__ const*) ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  memcpy (TYPE_1__ const*,TYPE_1__ const*,int) ; 

int
__thr_setcontext(const ucontext_t *ucp)
{
	ucontext_t uc;

	if (ucp == NULL) {
		errno = EINVAL;
		return (-1);
	}
	if (!SIGISMEMBER(ucp->uc_sigmask, SIGCANCEL))
		return (__sys_setcontext(ucp));
	(void) memcpy(&uc, ucp, sizeof(uc));
	SIGDELSET(uc.uc_sigmask, SIGCANCEL);
	return (__sys_setcontext(&uc));
}