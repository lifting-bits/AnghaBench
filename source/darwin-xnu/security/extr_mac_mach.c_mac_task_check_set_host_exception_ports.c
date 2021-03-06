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
struct task {int dummy; } ;
struct proc {int dummy; } ;
typedef  int /*<<< orphan*/  kauth_cred_t ;

/* Variables and functions */
 int ESRCH ; 
 int EXC_TYPES_COUNT ; 
 int FIRST_EXCEPTION ; 
 int /*<<< orphan*/  MAC_CHECK (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  kauth_cred_proc_ref (struct proc*) ; 
 int /*<<< orphan*/  kauth_cred_unref (int /*<<< orphan*/ *) ; 
 struct proc* mac_task_get_proc (struct task*) ; 
 int /*<<< orphan*/  proc_check_set_host_exception_port ; 
 int /*<<< orphan*/  proc_rele (struct proc*) ; 

int
mac_task_check_set_host_exception_ports(struct task *task, unsigned int exception_mask)
{
	int error = 0;
	int exception;

	struct proc *p = mac_task_get_proc(task);
	if (p == NULL)
		return ESRCH;

	kauth_cred_t cred = kauth_cred_proc_ref(p);
	for (exception = FIRST_EXCEPTION; exception < EXC_TYPES_COUNT; exception++) {
		if (exception_mask & (1 << exception)) {
			MAC_CHECK(proc_check_set_host_exception_port, cred, exception);
			if (error)
				break;
		}
	}
	kauth_cred_unref(&cred);
	proc_rele(p);
	return (error);
}