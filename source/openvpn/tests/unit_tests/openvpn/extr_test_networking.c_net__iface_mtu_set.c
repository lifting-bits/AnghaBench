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

/* Variables and functions */
 char* iface ; 
 int net_iface_mtu_set (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  printf (char*,char*,int) ; 

__attribute__((used)) static int
net__iface_mtu_set(int mtu)
{
    printf("CMD: ip link set %s mtu %d\n", iface, mtu);

    return net_iface_mtu_set(NULL, iface, mtu);
}