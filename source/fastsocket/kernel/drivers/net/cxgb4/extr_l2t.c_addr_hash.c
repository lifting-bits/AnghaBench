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
typedef  int /*<<< orphan*/  u32 ;

/* Variables and functions */
 unsigned int arp_hash (int /*<<< orphan*/  const*,int) ; 
 unsigned int ipv6_hash (int /*<<< orphan*/  const*,int) ; 

__attribute__((used)) static unsigned int addr_hash(const u32 *addr, int addr_len, int ifindex)
{
	return addr_len == 4 ? arp_hash(addr, ifindex) :
			       ipv6_hash(addr, ifindex);
}