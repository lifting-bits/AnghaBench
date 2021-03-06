#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  union xfs_btree_rec {int dummy; } xfs_btree_rec ;
struct xfs_btree_cur {TYPE_1__* bc_ops; } ;
typedef  int __uint64_t ;
struct TYPE_2__ {int /*<<< orphan*/  (* trace_enter ) (struct xfs_btree_cur*,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int,int,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* trace_record ) (struct xfs_btree_cur*,union xfs_btree_rec*,int*,int*,int*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  XBT_ARGS ; 
 int /*<<< orphan*/  XFS_BTREE_KTRACE_ARGR ; 
 int /*<<< orphan*/  stub1 (struct xfs_btree_cur*,union xfs_btree_rec*,int*,int*,int*) ; 
 int /*<<< orphan*/  stub2 (struct xfs_btree_cur*,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int,int,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
xfs_btree_trace_argr(
	const char		*func,
	struct xfs_btree_cur	*cur,
	union xfs_btree_rec	*rec,
	int			line)
{
	__uint64_t		l0, l1, l2;

	cur->bc_ops->trace_record(cur, rec, &l0, &l1, &l2);
	cur->bc_ops->trace_enter(cur, func, XBT_ARGS, XFS_BTREE_KTRACE_ARGR,
			      line,
			      l0 >> 32, (int)l0,
			      l1 >> 32, (int)l1,
			      l2 >> 32, (int)l2,
			      0, 0, 0, 0, 0);
}