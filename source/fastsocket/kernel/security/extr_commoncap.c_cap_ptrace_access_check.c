#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct task_struct {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  cap_permitted; } ;
struct TYPE_3__ {int /*<<< orphan*/  cap_permitted; } ;

/* Variables and functions */
 int /*<<< orphan*/  CAP_SYS_PTRACE ; 
 int EPERM ; 
 TYPE_2__* __task_cred (struct task_struct*) ; 
 int /*<<< orphan*/  cap_issubset (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  capable (int /*<<< orphan*/ ) ; 
 TYPE_1__* current_cred () ; 
 int /*<<< orphan*/  rcu_read_lock () ; 
 int /*<<< orphan*/  rcu_read_unlock () ; 

int cap_ptrace_access_check(struct task_struct *child, unsigned int mode)
{
	int ret = 0;

	rcu_read_lock();
	if (!cap_issubset(__task_cred(child)->cap_permitted,
			  current_cred()->cap_permitted) &&
	    !capable(CAP_SYS_PTRACE))
		ret = -EPERM;
	rcu_read_unlock();
	return ret;
}