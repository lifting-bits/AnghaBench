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
struct ceph_inode_info {int /*<<< orphan*/  i_release_count; int /*<<< orphan*/ * i_complete_seq; } ;

/* Variables and functions */
 scalar_t__ atomic64_read (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline bool __ceph_dir_is_complete(struct ceph_inode_info *ci)
{
	return atomic64_read(&ci->i_complete_seq[0]) ==
		atomic64_read(&ci->i_release_count);
}