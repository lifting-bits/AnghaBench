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
typedef  int /*<<< orphan*/  ifnet_t ;
typedef  int /*<<< orphan*/  ifaddr_t ;
typedef  int /*<<< orphan*/  errno_t ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  M_NOWAIT ; 
 int /*<<< orphan*/  ifnet_get_address_list_family_internal (int /*<<< orphan*/ ,int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

errno_t
ifnet_get_inuse_address_list(ifnet_t interface, ifaddr_t **addresses)
{
	return (addresses == NULL ? EINVAL :
		ifnet_get_address_list_family_internal(interface, addresses,
		0, 0, M_NOWAIT, 1));
}