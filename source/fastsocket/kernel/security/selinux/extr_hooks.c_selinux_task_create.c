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

/* Variables and functions */
 int /*<<< orphan*/  PROCESS__FORK ; 
 int /*<<< orphan*/  current ; 
 int current_has_perm (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int selinux_task_create(unsigned long clone_flags)
{
	return current_has_perm(current, PROCESS__FORK);
}