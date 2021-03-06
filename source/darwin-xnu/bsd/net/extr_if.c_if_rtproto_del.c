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
struct radix_node_head {int /*<<< orphan*/  (* rnh_walktree ) (struct radix_node_head*,int /*<<< orphan*/ ,struct ifnet*) ;} ;
struct ifnet {int dummy; } ;

/* Variables and functions */
 int AF_MAX ; 
 int /*<<< orphan*/  if_rtdel ; 
 int /*<<< orphan*/  lck_mtx_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lck_mtx_unlock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rnh_lock ; 
 struct radix_node_head** rt_tables ; 
 int /*<<< orphan*/  stub1 (struct radix_node_head*,int /*<<< orphan*/ ,struct ifnet*) ; 

void
if_rtproto_del(struct ifnet *ifp, int protocol)
{
	struct radix_node_head  *rnh;

	if ((protocol <= AF_MAX) && (protocol >= 0) &&
		((rnh = rt_tables[protocol]) != NULL) && (ifp != NULL)) {
		lck_mtx_lock(rnh_lock);
		(void) rnh->rnh_walktree(rnh, if_rtdel, ifp);
		lck_mtx_unlock(rnh_lock);
	}
}