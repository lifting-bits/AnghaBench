#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct thread {int /*<<< orphan*/  td_siglist; int /*<<< orphan*/  td_sigmask; struct proc* td_proc; } ;
struct proc {TYPE_1__* p_sigacts; int /*<<< orphan*/  p_siglist; } ;
typedef  int /*<<< orphan*/  sigset_t ;
struct TYPE_2__ {int /*<<< orphan*/  ps_mtx; int /*<<< orphan*/  ps_sigignore; } ;

/* Variables and functions */
 int EINTR ; 
 int /*<<< orphan*/  PROC_LOCK (struct proc*) ; 
 int /*<<< orphan*/  PROC_UNLOCK (struct proc*) ; 
 scalar_t__ SIGNOTEMPTY (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SIGSETNAND (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SIGSETOR (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ SMB_SIGMASK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtx_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mtx_unlock (int /*<<< orphan*/ *) ; 

int
smb_td_intr(struct thread *td)
{
	struct proc *p;
	sigset_t tmpset;

	if (td == NULL)
		return 0;

	p = td->td_proc;
	PROC_LOCK(p);
	tmpset = p->p_siglist;
	SIGSETOR(tmpset, td->td_siglist);
	SIGSETNAND(tmpset, td->td_sigmask);
	mtx_lock(&p->p_sigacts->ps_mtx);
	SIGSETNAND(tmpset, p->p_sigacts->ps_sigignore);
	mtx_unlock(&p->p_sigacts->ps_mtx);
	if (SIGNOTEMPTY(td->td_siglist) && SMB_SIGMASK(tmpset)) {
		PROC_UNLOCK(p);
                return EINTR;
	}
	PROC_UNLOCK(p);
	return 0;
}