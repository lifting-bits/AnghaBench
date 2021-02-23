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
typedef  int xfs_dir2_db_t ;
struct xfs_mount {int dummy; } ;

/* Variables and functions */
 int XFS_DIR2_FREE_FIRSTDB (struct xfs_mount*) ; 
 int XFS_DIR2_MAX_FREE_BESTS (struct xfs_mount*) ; 

__attribute__((used)) static inline xfs_dir2_db_t
xfs_dir2_db_to_fdb(struct xfs_mount *mp, xfs_dir2_db_t db)
{
	return (XFS_DIR2_FREE_FIRSTDB(mp) + (db) / XFS_DIR2_MAX_FREE_BESTS(mp));
}