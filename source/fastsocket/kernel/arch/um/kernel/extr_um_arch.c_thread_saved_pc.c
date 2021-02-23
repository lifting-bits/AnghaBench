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

/* Variables and functions */
 unsigned long os_process_pc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * userspace_pid ; 

unsigned long thread_saved_pc(struct task_struct *task)
{
	/* FIXME: Need to look up userspace_pid by cpu */
	return os_process_pc(userspace_pid[0]);
}