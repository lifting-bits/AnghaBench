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
struct net_device {int tx_queue_len; int /*<<< orphan*/  priv_flags; int /*<<< orphan*/  mtu; int /*<<< orphan*/  hard_header_len; int /*<<< orphan*/  type; int /*<<< orphan*/ * netdev_ops; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARPHRD_ATM ; 
 int /*<<< orphan*/  IFF_XMIT_DST_RELEASE ; 
 int /*<<< orphan*/  RFC1483LLC_LEN ; 
 int /*<<< orphan*/  RFC1626_MTU ; 
 int /*<<< orphan*/  clip_netdev_ops ; 

__attribute__((used)) static void clip_setup(struct net_device *dev)
{
	dev->netdev_ops = &clip_netdev_ops;
	dev->type = ARPHRD_ATM;
	dev->hard_header_len = RFC1483LLC_LEN;
	dev->mtu = RFC1626_MTU;
	dev->tx_queue_len = 100;	/* "normal" queue (packets) */
	/* When using a "real" qdisc, the qdisc determines the queue */
	/* length. tx_queue_len is only used for the default case, */
	/* without any more elaborate queuing. 100 is a reasonable */
	/* compromise between decent burst-tolerance and protection */
	/* against memory hogs. */
	dev->priv_flags &= ~IFF_XMIT_DST_RELEASE;
}