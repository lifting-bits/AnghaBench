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
typedef  int /*<<< orphan*/  sd_netlink ;

/* Variables and functions */
 int /*<<< orphan*/  NETLINK_GENERIC ; 
 int netlink_open_family (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 

int sd_genl_socket_open(sd_netlink **ret) {
        return netlink_open_family(ret, NETLINK_GENERIC);
}