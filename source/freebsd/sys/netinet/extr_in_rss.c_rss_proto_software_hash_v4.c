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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  u_short ;
struct in_addr {int dummy; } ;

/* Variables and functions */
 int IPPROTO_TCP ; 
 int IPPROTO_UDP ; 
 int /*<<< orphan*/  M_HASHTYPE_RSS_IPV4 ; 
 int /*<<< orphan*/  M_HASHTYPE_RSS_TCP_IPV4 ; 
 int /*<<< orphan*/  M_HASHTYPE_RSS_UDP_IPV4 ; 
 int /*<<< orphan*/  RSS_DEBUG (char*) ; 
 int RSS_HASHTYPE_RSS_IPV4 ; 
 int RSS_HASHTYPE_RSS_TCP_IPV4 ; 
 int RSS_HASHTYPE_RSS_UDP_IPV4 ; 
 int rss_gethashconfig () ; 
 int /*<<< orphan*/  rss_hash_ip4_2tuple (struct in_addr,struct in_addr) ; 
 int /*<<< orphan*/  rss_hash_ip4_4tuple (struct in_addr,int /*<<< orphan*/ ,struct in_addr,int /*<<< orphan*/ ) ; 

int
rss_proto_software_hash_v4(struct in_addr s, struct in_addr d,
    u_short sp, u_short dp, int proto,
    uint32_t *hashval, uint32_t *hashtype)
{
	uint32_t hash;

	/*
	 * Next, choose the hash type depending upon the protocol
	 * identifier.
	 */
	if ((proto == IPPROTO_TCP) &&
	    (rss_gethashconfig() & RSS_HASHTYPE_RSS_TCP_IPV4)) {
		hash = rss_hash_ip4_4tuple(s, sp, d, dp);
		*hashval = hash;
		*hashtype = M_HASHTYPE_RSS_TCP_IPV4;
		return (0);
	} else if ((proto == IPPROTO_UDP) &&
	    (rss_gethashconfig() & RSS_HASHTYPE_RSS_UDP_IPV4)) {
		hash = rss_hash_ip4_4tuple(s, sp, d, dp);
		*hashval = hash;
		*hashtype = M_HASHTYPE_RSS_UDP_IPV4;
		return (0);
	} else if (rss_gethashconfig() & RSS_HASHTYPE_RSS_IPV4) {
		/* RSS doesn't hash on other protocols like SCTP; so 2-tuple */
		hash = rss_hash_ip4_2tuple(s, d);
		*hashval = hash;
		*hashtype = M_HASHTYPE_RSS_IPV4;
		return (0);
	}

	/* No configured available hashtypes! */
	RSS_DEBUG("no available hashtypes!\n");
	return (-1);
}