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
struct sk_buff {int dummy; } ;
struct net_device {int flags; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int IFF_NOARP ; 
 struct sk_buff* arp_create (int,int,int /*<<< orphan*/ ,struct net_device*,int /*<<< orphan*/ ,unsigned char const*,unsigned char const*,unsigned char const*) ; 
 int /*<<< orphan*/  arp_xmit (struct sk_buff*) ; 

void arp_send(int type, int ptype, __be32 dest_ip,
	      struct net_device *dev, __be32 src_ip,
	      const unsigned char *dest_hw, const unsigned char *src_hw,
	      const unsigned char *target_hw)
{
	struct sk_buff *skb;

	/*
	 *	No arp on this interface.
	 */

	if (dev->flags&IFF_NOARP)
		return;

	skb = arp_create(type, ptype, dest_ip, dev, src_ip,
			 dest_hw, src_hw, target_hw);
	if (skb == NULL) {
		return;
	}

	arp_xmit(skb);
}