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
struct hash_net4_telem {int /*<<< orphan*/  timeout; int /*<<< orphan*/  cidr; int /*<<< orphan*/  ip; } ;
struct hash_net4_elem {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  IPSET_ATTR_CIDR ; 
 int /*<<< orphan*/  IPSET_ATTR_IP ; 
 int /*<<< orphan*/  IPSET_ATTR_TIMEOUT ; 
 int /*<<< orphan*/  NLA_PUT_IPADDR4 (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NLA_PUT_NET32 (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NLA_PUT_U8 (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  htonl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ip_set_timeout_get (int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool
hash_net4_data_tlist(struct sk_buff *skb, const struct hash_net4_elem *data)
{
	const struct hash_net4_telem *tdata =
		(const struct hash_net4_telem *)data;

	NLA_PUT_IPADDR4(skb, IPSET_ATTR_IP, tdata->ip);
	NLA_PUT_U8(skb, IPSET_ATTR_CIDR, tdata->cidr);
	NLA_PUT_NET32(skb, IPSET_ATTR_TIMEOUT,
		      htonl(ip_set_timeout_get(tdata->timeout)));

	return 0;

nla_put_failure:
	return 1;
}