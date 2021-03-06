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
struct nft_object_type {int /*<<< orphan*/  list; } ;

/* Variables and functions */
 int /*<<< orphan*/  NFNL_SUBSYS_NFTABLES ; 
 int /*<<< orphan*/  list_del_rcu (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nfnl_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nfnl_unlock (int /*<<< orphan*/ ) ; 

void nft_unregister_obj(struct nft_object_type *obj_type)
{
	nfnl_lock(NFNL_SUBSYS_NFTABLES);
	list_del_rcu(&obj_type->list);
	nfnl_unlock(NFNL_SUBSYS_NFTABLES);
}