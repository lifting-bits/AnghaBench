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
struct fpm_scoreboard_proc_s {scalar_t__ lock; } ;

/* Variables and functions */

void fpm_scoreboard_proc_release(struct fpm_scoreboard_proc_s *proc) /* {{{ */
{
	if (!proc) {
		return;
	}

	proc->lock = 0;
}