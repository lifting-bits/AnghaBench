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
struct sockaddr {int dummy; } ;
struct ifaddr {int dummy; } ;

/* Variables and functions */
 struct ifaddr* ifa_ifwithaddr_scoped_locked (struct sockaddr const*,unsigned int) ; 
 int /*<<< orphan*/  ifnet_head_done () ; 
 int /*<<< orphan*/  ifnet_head_lock_shared () ; 

struct ifaddr *
ifa_ifwithaddr_scoped(const struct sockaddr *addr, unsigned int ifscope)
{
	struct ifaddr *result = NULL;

	ifnet_head_lock_shared();

	result = ifa_ifwithaddr_scoped_locked(addr, ifscope);

	ifnet_head_done();

	return (result);
}