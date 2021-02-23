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
typedef  scalar_t__ pid_t_ ;
struct TYPE_4__ {TYPE_1__* parent; } ;
struct TYPE_3__ {scalar_t__ pid; } ;

/* Variables and functions */
 int /*<<< orphan*/  STRACE (char*) ; 
 TYPE_2__* current ; 
 int /*<<< orphan*/  lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pids_lock ; 
 int /*<<< orphan*/  unlock (int /*<<< orphan*/ *) ; 

pid_t_ sys_getppid() {
    STRACE("getppid()");
    pid_t_ ppid;
    lock(&pids_lock);
    if (current->parent != NULL)
        ppid = current->parent->pid;
    else
        ppid = 0;
    unlock(&pids_lock);
    return ppid;
}