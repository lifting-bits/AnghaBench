#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  union ib_gid {int dummy; } ib_gid ;
typedef  int /*<<< orphan*/  u8 ;
struct sk_buff {int dummy; } ;
struct TYPE_9__ {int /*<<< orphan*/  tx_dropped; } ;
struct net_device {TYPE_4__ stats; } ;
struct ipoib_neigh {int /*<<< orphan*/  list; TYPE_5__* ah; } ;
struct TYPE_7__ {int /*<<< orphan*/  raw; } ;
struct TYPE_8__ {TYPE_2__ mgid; } ;
struct ipoib_mcast {TYPE_5__* ah; int /*<<< orphan*/  neigh_list; int /*<<< orphan*/  flags; int /*<<< orphan*/  pkt_queue; int /*<<< orphan*/  list; TYPE_3__ mcmember; } ;
struct ipoib_dev_priv {int /*<<< orphan*/  lock; int /*<<< orphan*/  multicast_list; TYPE_1__* broadcast; int /*<<< orphan*/  flags; } ;
struct TYPE_10__ {int /*<<< orphan*/  ref; } ;
struct TYPE_6__ {int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  IB_MULTICAST_QPN ; 
 int /*<<< orphan*/  IPOIB_FLAG_OPER_UP ; 
 scalar_t__ IPOIB_MAX_MCAST_QUEUE ; 
 int /*<<< orphan*/  IPOIB_MCAST_FLAG_ATTACHED ; 
 int /*<<< orphan*/  IPOIB_MCAST_FLAG_BUSY ; 
 int /*<<< orphan*/  IPOIB_MCAST_FLAG_SENDONLY ; 
 int /*<<< orphan*/  __ipoib_mcast_add (struct net_device*,struct ipoib_mcast*) ; 
 struct ipoib_mcast* __ipoib_mcast_find (struct net_device*,void*) ; 
 int /*<<< orphan*/  dev_kfree_skb_any (struct sk_buff*) ; 
 int /*<<< orphan*/  ipoib_dbg_mcast (struct ipoib_dev_priv*,char*,...) ; 
 struct ipoib_mcast* ipoib_mcast_alloc (struct net_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ipoib_mcast_sendonly_join (struct ipoib_mcast*) ; 
 struct ipoib_neigh* ipoib_neigh_alloc (int /*<<< orphan*/ *,struct net_device*) ; 
 struct ipoib_neigh* ipoib_neigh_get (struct net_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ipoib_neigh_put (struct ipoib_neigh*) ; 
 int /*<<< orphan*/  ipoib_send (struct net_device*,struct sk_buff*,TYPE_5__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ipoib_warn (struct ipoib_dev_priv*,char*) ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,void*,int) ; 
 struct ipoib_dev_priv* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ skb_queue_len (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  skb_queue_tail (int /*<<< orphan*/ *,struct sk_buff*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

void ipoib_mcast_send(struct net_device *dev, u8 *daddr, struct sk_buff *skb)
{
	struct ipoib_dev_priv *priv = netdev_priv(dev);
	struct ipoib_mcast *mcast;
	unsigned long flags;
	void *mgid = daddr + 4;

	spin_lock_irqsave(&priv->lock, flags);

	if (!test_bit(IPOIB_FLAG_OPER_UP, &priv->flags)		||
	    !priv->broadcast					||
	    !test_bit(IPOIB_MCAST_FLAG_ATTACHED, &priv->broadcast->flags)) {
		++dev->stats.tx_dropped;
		dev_kfree_skb_any(skb);
		goto unlock;
	}

	mcast = __ipoib_mcast_find(dev, mgid);
	if (!mcast) {
		/* Let's create a new send only group now */
		ipoib_dbg_mcast(priv, "setting up send only multicast group for %pI6\n",
				mgid);

		mcast = ipoib_mcast_alloc(dev, 0);
		if (!mcast) {
			ipoib_warn(priv, "unable to allocate memory for "
				   "multicast structure\n");
			++dev->stats.tx_dropped;
			dev_kfree_skb_any(skb);
			goto out;
		}

		set_bit(IPOIB_MCAST_FLAG_SENDONLY, &mcast->flags);
		memcpy(mcast->mcmember.mgid.raw, mgid, sizeof (union ib_gid));
		__ipoib_mcast_add(dev, mcast);
		list_add_tail(&mcast->list, &priv->multicast_list);
	}

	if (!mcast->ah) {
		if (skb_queue_len(&mcast->pkt_queue) < IPOIB_MAX_MCAST_QUEUE)
			skb_queue_tail(&mcast->pkt_queue, skb);
		else {
			++dev->stats.tx_dropped;
			dev_kfree_skb_any(skb);
		}

		if (test_bit(IPOIB_MCAST_FLAG_BUSY, &mcast->flags))
			ipoib_dbg_mcast(priv, "no address vector, "
					"but multicast join already started\n");
		else if (test_bit(IPOIB_MCAST_FLAG_SENDONLY, &mcast->flags))
			ipoib_mcast_sendonly_join(mcast);

		/*
		 * If lookup completes between here and out:, don't
		 * want to send packet twice.
		 */
		mcast = NULL;
	}

out:
	if (mcast && mcast->ah) {
		struct ipoib_neigh *neigh;

		spin_unlock_irqrestore(&priv->lock, flags);
		neigh = ipoib_neigh_get(dev, daddr);
		spin_lock_irqsave(&priv->lock, flags);
		if (!neigh) {
			neigh = ipoib_neigh_alloc(daddr, dev);
			if (neigh) {
				kref_get(&mcast->ah->ref);
				neigh->ah	= mcast->ah;
				list_add_tail(&neigh->list, &mcast->neigh_list);
			}
		}

		spin_unlock_irqrestore(&priv->lock, flags);
		ipoib_send(dev, skb, mcast->ah, IB_MULTICAST_QPN);
		if (neigh)
			ipoib_neigh_put(neigh);
		return;
	}

unlock:
	spin_unlock_irqrestore(&priv->lock, flags);
}