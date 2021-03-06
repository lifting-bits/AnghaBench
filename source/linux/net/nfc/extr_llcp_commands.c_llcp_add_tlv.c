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
typedef  int /*<<< orphan*/  u8 ;
struct sk_buff {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  skb_put_data (struct sk_buff*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct sk_buff *llcp_add_tlv(struct sk_buff *pdu, u8 *tlv,
				    u8 tlv_length)
{
	/* XXX Add an skb length check */

	if (tlv == NULL)
		return NULL;

	skb_put_data(pdu, tlv, tlv_length);

	return pdu;
}