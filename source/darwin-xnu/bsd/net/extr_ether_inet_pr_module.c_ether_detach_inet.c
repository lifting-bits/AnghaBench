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
struct ifnet {int dummy; } ;
typedef  int /*<<< orphan*/  protocol_family_t ;

/* Variables and functions */
 int /*<<< orphan*/  ifnet_detach_protocol (struct ifnet*,int /*<<< orphan*/ ) ; 

void
ether_detach_inet(struct ifnet *ifp, protocol_family_t proto_family)
{
	(void) ifnet_detach_protocol(ifp, proto_family);
}