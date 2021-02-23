#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {int /*<<< orphan*/  cn_handle; void* cn_needpost; scalar_t__ cn_zoned; } ;
typedef  TYPE_1__ prop_changenode_t ;
struct TYPE_9__ {int cl_prop; int cl_gflags; int /*<<< orphan*/  cl_mflags; int /*<<< orphan*/  cl_list; } ;
typedef  TYPE_2__ prop_changelist_t ;

/* Variables and functions */
 void* B_FALSE ; 
 int CL_GATHER_DONT_UNMOUNT ; 
 scalar_t__ GLOBAL_ZONEID ; 
 int /*<<< orphan*/  ZFS_IS_VOLUME (int /*<<< orphan*/ ) ; 
#define  ZFS_PROP_MOUNTPOINT 129 
#define  ZFS_PROP_SHARESMB 128 
 int /*<<< orphan*/  changelist_postfix (TYPE_2__*) ; 
 scalar_t__ getzoneid () ; 
 TYPE_1__* uu_list_first (int /*<<< orphan*/ ) ; 
 TYPE_1__* uu_list_next (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  zfs_unmount (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  zfs_unshare_smb (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

int
changelist_prefix(prop_changelist_t *clp)
{
	prop_changenode_t *cn;
	int ret = 0;

	if (clp->cl_prop != ZFS_PROP_MOUNTPOINT &&
	    clp->cl_prop != ZFS_PROP_SHARESMB)
		return (0);

	for (cn = uu_list_first(clp->cl_list); cn != NULL;
	    cn = uu_list_next(clp->cl_list, cn)) {

		/* if a previous loop failed, set the remaining to false */
		if (ret == -1) {
			cn->cn_needpost = B_FALSE;
			continue;
		}

		/*
		 * If we are in the global zone, but this dataset is exported
		 * to a local zone, do nothing.
		 */
		if (getzoneid() == GLOBAL_ZONEID && cn->cn_zoned)
			continue;

		if (!ZFS_IS_VOLUME(cn->cn_handle)) {
			/*
			 * Do the property specific processing.
			 */
			switch (clp->cl_prop) {
			case ZFS_PROP_MOUNTPOINT:
				if (clp->cl_gflags & CL_GATHER_DONT_UNMOUNT)
					break;
				if (zfs_unmount(cn->cn_handle, NULL,
				    clp->cl_mflags) != 0) {
					ret = -1;
					cn->cn_needpost = B_FALSE;
				}
				break;
			case ZFS_PROP_SHARESMB:
				(void) zfs_unshare_smb(cn->cn_handle, NULL);
				break;

			default:
				break;
			}
		}
	}

	if (ret == -1)
		(void) changelist_postfix(clp);

	return (ret);
}