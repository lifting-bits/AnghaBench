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
typedef  int /*<<< orphan*/  vfs_context_t ;
struct mount {int dummy; } ;
typedef  int /*<<< orphan*/  kauth_cred_t ;

/* Variables and functions */
 int /*<<< orphan*/  MAC_CHECK (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct mount*,char const*) ; 
 int /*<<< orphan*/  mac_cred_check_enforce (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mac_vnode_enforce ; 
 int /*<<< orphan*/  mount_check_snapshot_delete ; 
 int /*<<< orphan*/  vfs_context_ucred (int /*<<< orphan*/ ) ; 

int
mac_mount_check_snapshot_delete(vfs_context_t ctx, struct mount *mp,
    const char *name)
{
	kauth_cred_t cred;
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
	/* 21167099 - only check if we allow write */
	if (!mac_vnode_enforce)
		return 0;
#endif
	cred = vfs_context_ucred(ctx);
	if (!mac_cred_check_enforce(cred))
		return (0);
	MAC_CHECK(mount_check_snapshot_delete, cred, mp, name);
	return (error);
}