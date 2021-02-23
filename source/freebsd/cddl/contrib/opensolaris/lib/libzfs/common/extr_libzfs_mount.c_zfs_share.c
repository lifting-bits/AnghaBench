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
typedef  int /*<<< orphan*/  zfs_handle_t ;

/* Variables and functions */
 int /*<<< orphan*/  ZFS_IS_VOLUME (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  share_all_proto ; 
 int zfs_share_proto (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

int
zfs_share(zfs_handle_t *zhp)
{
	assert(!ZFS_IS_VOLUME(zhp));
	return (zfs_share_proto(zhp, share_all_proto));
}