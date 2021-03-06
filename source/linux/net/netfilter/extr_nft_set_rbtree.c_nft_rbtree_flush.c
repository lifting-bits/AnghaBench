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
struct nft_set {int dummy; } ;
struct nft_rbtree_elem {int /*<<< orphan*/  ext; } ;
struct net {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  nft_is_active (struct net const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nft_set_elem_change_active (struct net const*,struct nft_set const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nft_set_elem_mark_busy (int /*<<< orphan*/ *) ; 

__attribute__((used)) static bool nft_rbtree_flush(const struct net *net,
			     const struct nft_set *set, void *priv)
{
	struct nft_rbtree_elem *rbe = priv;

	if (!nft_set_elem_mark_busy(&rbe->ext) ||
	    !nft_is_active(net, &rbe->ext)) {
		nft_set_elem_change_active(net, set, &rbe->ext);
		return true;
	}
	return false;
}