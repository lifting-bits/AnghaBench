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
struct proc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MAC_PERFORM (int /*<<< orphan*/ ,struct proc*) ; 
 int /*<<< orphan*/  proc_notify_exit ; 

void
mac_proc_notify_exit(struct proc *proc)
{
	MAC_PERFORM(proc_notify_exit, proc);
}