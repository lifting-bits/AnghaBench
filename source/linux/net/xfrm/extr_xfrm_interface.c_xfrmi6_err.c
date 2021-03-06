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
typedef  int /*<<< orphan*/  xfrm_address_t ;
typedef  scalar_t__ u8 ;
struct xfrm_state {int dummy; } ;
struct xfrm_if {int dummy; } ;
struct sk_buff {TYPE_1__* dev; int /*<<< orphan*/  mark; scalar_t__ data; } ;
struct net {int dummy; } ;
struct ipv6hdr {int nexthdr; int /*<<< orphan*/  daddr; } ;
struct ip_esp_hdr {int /*<<< orphan*/  spi; } ;
struct ip_comp_hdr {int /*<<< orphan*/  cpi; } ;
struct ip_auth_hdr {int /*<<< orphan*/  spi; } ;
struct inet6_skb_parm {int dummy; } ;
typedef  int /*<<< orphan*/  __be32 ;
struct TYPE_2__ {int /*<<< orphan*/  ifindex; } ;

/* Variables and functions */
 int /*<<< orphan*/  AF_INET6 ; 
 scalar_t__ ICMPV6_PKT_TOOBIG ; 
#define  IPPROTO_AH 130 
#define  IPPROTO_COMP 129 
#define  IPPROTO_ESP 128 
 scalar_t__ NDISC_REDIRECT ; 
 struct net* dev_net (TYPE_1__*) ; 
 int /*<<< orphan*/  htonl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ip6_redirect (struct sk_buff*,struct net*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ip6_update_pmtu (struct sk_buff*,struct net*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ntohs (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sock_net_uid (struct net*,int /*<<< orphan*/ *) ; 
 struct xfrm_state* xfrm_state_lookup (struct net*,int /*<<< orphan*/ ,int /*<<< orphan*/  const*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xfrm_state_put (struct xfrm_state*) ; 
 struct xfrm_if* xfrmi_lookup (struct net*,struct xfrm_state*) ; 

__attribute__((used)) static int xfrmi6_err(struct sk_buff *skb, struct inet6_skb_parm *opt,
		    u8 type, u8 code, int offset, __be32 info)
{
	const struct ipv6hdr *iph = (const struct ipv6hdr *)skb->data;
	struct net *net = dev_net(skb->dev);
	int protocol = iph->nexthdr;
	struct ip_comp_hdr *ipch;
	struct ip_esp_hdr *esph;
	struct ip_auth_hdr *ah;
	struct xfrm_state *x;
	struct xfrm_if *xi;
	__be32 spi;

	switch (protocol) {
	case IPPROTO_ESP:
		esph = (struct ip_esp_hdr *)(skb->data + offset);
		spi = esph->spi;
		break;
	case IPPROTO_AH:
		ah = (struct ip_auth_hdr *)(skb->data + offset);
		spi = ah->spi;
		break;
	case IPPROTO_COMP:
		ipch = (struct ip_comp_hdr *)(skb->data + offset);
		spi = htonl(ntohs(ipch->cpi));
		break;
	default:
		return 0;
	}

	if (type != ICMPV6_PKT_TOOBIG &&
	    type != NDISC_REDIRECT)
		return 0;

	x = xfrm_state_lookup(net, skb->mark, (const xfrm_address_t *)&iph->daddr,
			      spi, protocol, AF_INET6);
	if (!x)
		return 0;

	xi = xfrmi_lookup(net, x);
	if (!xi) {
		xfrm_state_put(x);
		return -1;
	}

	if (type == NDISC_REDIRECT)
		ip6_redirect(skb, net, skb->dev->ifindex, 0,
			     sock_net_uid(net, NULL));
	else
		ip6_update_pmtu(skb, net, info, 0, 0, sock_net_uid(net, NULL));
	xfrm_state_put(x);

	return 0;
}