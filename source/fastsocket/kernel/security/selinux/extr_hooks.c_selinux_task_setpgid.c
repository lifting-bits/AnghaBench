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
struct task_struct {int dummy; } ;
typedef  int /*<<< orphan*/  pid_t ;

/* Variables and functions */
 int /*<<< orphan*/  PROCESS__SETPGID ; 
 int current_has_perm (struct task_struct*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int selinux_task_setpgid(struct task_struct *p, pid_t pgid)
{
	return current_has_perm(p, PROCESS__SETPGID);
}