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
struct ocfs2_blockcheck_stats {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ocfs2_blockcheck_debug_remove (struct ocfs2_blockcheck_stats*) ; 

void ocfs2_blockcheck_stats_debugfs_remove(struct ocfs2_blockcheck_stats *stats)
{
	ocfs2_blockcheck_debug_remove(stats);
}