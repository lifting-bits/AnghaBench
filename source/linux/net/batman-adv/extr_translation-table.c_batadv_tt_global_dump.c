#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct sk_buff {int len; } ;
struct netlink_callback {int* args; TYPE_2__* nlh; TYPE_4__* skb; } ;
struct net_device {int dummy; } ;
struct net {int dummy; } ;
struct hlist_head {int dummy; } ;
struct TYPE_5__ {struct batadv_hashtable* global_hash; } ;
struct batadv_priv {TYPE_1__ tt; } ;
struct batadv_hashtable {int size; struct hlist_head* table; } ;
struct batadv_hard_iface {scalar_t__ if_status; } ;
struct TYPE_8__ {int /*<<< orphan*/  sk; } ;
struct TYPE_7__ {int portid; } ;
struct TYPE_6__ {int /*<<< orphan*/  nlmsg_seq; } ;

/* Variables and functions */
 int /*<<< orphan*/  BATADV_ATTR_MESH_IFINDEX ; 
 scalar_t__ BATADV_IF_ACTIVE ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOENT ; 
 TYPE_3__ NETLINK_CB (TYPE_4__*) ; 
 int /*<<< orphan*/  batadv_hardif_put (struct batadv_hard_iface*) ; 
 int batadv_netlink_get_ifindex (TYPE_2__*,int /*<<< orphan*/ ) ; 
 struct batadv_hard_iface* batadv_primary_if_get_selected (struct batadv_priv*) ; 
 int /*<<< orphan*/  batadv_softif_is_valid (struct net_device*) ; 
 scalar_t__ batadv_tt_global_dump_bucket (struct sk_buff*,int,int /*<<< orphan*/ ,struct batadv_priv*,struct hlist_head*,int*,int*) ; 
 struct net_device* dev_get_by_index (struct net*,int) ; 
 int /*<<< orphan*/  dev_put (struct net_device*) ; 
 struct batadv_priv* netdev_priv (struct net_device*) ; 
 struct net* sock_net (int /*<<< orphan*/ ) ; 

int batadv_tt_global_dump(struct sk_buff *msg, struct netlink_callback *cb)
{
	struct net *net = sock_net(cb->skb->sk);
	struct net_device *soft_iface;
	struct batadv_priv *bat_priv;
	struct batadv_hard_iface *primary_if = NULL;
	struct batadv_hashtable *hash;
	struct hlist_head *head;
	int ret;
	int ifindex;
	int bucket = cb->args[0];
	int idx = cb->args[1];
	int sub = cb->args[2];
	int portid = NETLINK_CB(cb->skb).portid;

	ifindex = batadv_netlink_get_ifindex(cb->nlh, BATADV_ATTR_MESH_IFINDEX);
	if (!ifindex)
		return -EINVAL;

	soft_iface = dev_get_by_index(net, ifindex);
	if (!soft_iface || !batadv_softif_is_valid(soft_iface)) {
		ret = -ENODEV;
		goto out;
	}

	bat_priv = netdev_priv(soft_iface);

	primary_if = batadv_primary_if_get_selected(bat_priv);
	if (!primary_if || primary_if->if_status != BATADV_IF_ACTIVE) {
		ret = -ENOENT;
		goto out;
	}

	hash = bat_priv->tt.global_hash;

	while (bucket < hash->size) {
		head = &hash->table[bucket];

		if (batadv_tt_global_dump_bucket(msg, portid,
						 cb->nlh->nlmsg_seq, bat_priv,
						 head, &idx, &sub))
			break;

		bucket++;
	}

	ret = msg->len;

 out:
	if (primary_if)
		batadv_hardif_put(primary_if);
	if (soft_iface)
		dev_put(soft_iface);

	cb->args[0] = bucket;
	cb->args[1] = idx;
	cb->args[2] = sub;

	return ret;
}