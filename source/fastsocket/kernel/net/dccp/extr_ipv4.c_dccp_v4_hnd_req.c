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
struct sock {scalar_t__ sk_state; } ;
struct sk_buff {int dummy; } ;
struct request_sock {int dummy; } ;
struct iphdr {int /*<<< orphan*/  daddr; int /*<<< orphan*/  saddr; } ;
struct dccp_hdr {int /*<<< orphan*/  dccph_dport; int /*<<< orphan*/  dccph_sport; } ;

/* Variables and functions */
 scalar_t__ DCCP_TIME_WAIT ; 
 int /*<<< orphan*/  bh_lock_sock (struct sock*) ; 
 struct sock* dccp_check_req (struct sock*,struct sk_buff*,struct request_sock*,struct request_sock**) ; 
 int /*<<< orphan*/  dccp_hashinfo ; 
 struct dccp_hdr* dccp_hdr (struct sk_buff*) ; 
 struct request_sock* inet_csk_search_req (struct sock*,struct request_sock***,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  inet_iif (struct sk_buff*) ; 
 struct sock* inet_lookup_established (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  inet_twsk (struct sock*) ; 
 int /*<<< orphan*/  inet_twsk_put (int /*<<< orphan*/ ) ; 
 struct iphdr* ip_hdr (struct sk_buff*) ; 
 int /*<<< orphan*/  sock_net (struct sock*) ; 

__attribute__((used)) static struct sock *dccp_v4_hnd_req(struct sock *sk, struct sk_buff *skb)
{
	const struct dccp_hdr *dh = dccp_hdr(skb);
	const struct iphdr *iph = ip_hdr(skb);
	struct sock *nsk;
	struct request_sock **prev;
	/* Find possible connection requests. */
	struct request_sock *req = inet_csk_search_req(sk, &prev,
						       dh->dccph_sport,
						       iph->saddr, iph->daddr);
	if (req != NULL)
		return dccp_check_req(sk, skb, req, prev);

	nsk = inet_lookup_established(sock_net(sk), &dccp_hashinfo,
				      iph->saddr, dh->dccph_sport,
				      iph->daddr, dh->dccph_dport,
				      inet_iif(skb));
	if (nsk != NULL) {
		if (nsk->sk_state != DCCP_TIME_WAIT) {
			bh_lock_sock(nsk);
			return nsk;
		}
		inet_twsk_put(inet_twsk(nsk));
		return NULL;
	}

	return sk;
}