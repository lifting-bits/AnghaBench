#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ xfs_lsn_t ;
struct TYPE_3__ {scalar_t__ li_lsn; } ;
typedef  TYPE_1__ xfs_log_item_t ;
struct xfs_ail {int /*<<< orphan*/  xa_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 TYPE_1__* xfs_ail_min (struct xfs_ail*) ; 

xfs_lsn_t
xfs_ail_min_lsn(
	struct xfs_ail	*ailp)
{
	xfs_lsn_t	lsn;
	xfs_log_item_t	*lip;

	spin_lock(&ailp->xa_lock);
	lip = xfs_ail_min(ailp);
	if (lip == NULL) {
		lsn = (xfs_lsn_t)0;
	} else {
		lsn = lip->li_lsn;
	}
	spin_unlock(&ailp->xa_lock);

	return lsn;
}