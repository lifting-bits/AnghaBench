#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
union nf_inet_addr {int /*<<< orphan*/  ip; } ;
struct sk_buff {int dummy; } ;
typedef  int /*<<< orphan*/  __be16 ;
struct TYPE_5__ {int /*<<< orphan*/  network; } ;
struct TYPE_6__ {TYPE_1__ iPAddress; } ;
struct TYPE_7__ {TYPE_2__ unicastAddress; } ;
typedef  TYPE_3__ H245_TransportAddress ;

/* Variables and functions */
 int set_addr (struct sk_buff*,unsigned char**,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int set_h245_addr(struct sk_buff *skb,
			 unsigned char **data, int dataoff,
			 H245_TransportAddress *taddr,
			 union nf_inet_addr *addr, __be16 port)
{
	return set_addr(skb, data, dataoff,
			taddr->unicastAddress.iPAddress.network,
			addr->ip, port);
}