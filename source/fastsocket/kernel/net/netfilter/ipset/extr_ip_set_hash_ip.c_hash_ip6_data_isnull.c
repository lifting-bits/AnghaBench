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
struct TYPE_2__ {int /*<<< orphan*/  in6; } ;
struct hash_ip6_elem {TYPE_1__ ip; } ;

/* Variables and functions */
 int ipv6_addr_any (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline bool
hash_ip6_data_isnull(const struct hash_ip6_elem *elem)
{
	return ipv6_addr_any(&elem->ip.in6);
}