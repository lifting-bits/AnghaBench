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
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int vti_input (struct sk_buff*,int,int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static int vti_input_proto(struct sk_buff *skb, int nexthdr, __be32 spi,
			   int encap_type)
{
	return vti_input(skb, nexthdr, spi, encap_type, false);
}