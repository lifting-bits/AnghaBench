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
 int /*<<< orphan*/  remove_proc_entry (char*,int /*<<< orphan*/ *) ; 

void
xfs_qm_cleanup_procfs(void)
{
	remove_proc_entry("fs/xfs/xqm", NULL);
	remove_proc_entry("fs/xfs/xqmstat", NULL);
}