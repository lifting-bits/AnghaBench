#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
struct TYPE_6__ {TYPE_1__* network; } ;
struct TYPE_5__ {int /*<<< orphan*/  ipv6_accept_ra_route_table; scalar_t__ ipv6_accept_ra_route_table_set; } ;
typedef  TYPE_2__ Link ;

/* Variables and functions */
 int /*<<< orphan*/  link_get_vrf_table (TYPE_2__*) ; 

uint32_t link_get_ipv6_accept_ra_route_table(Link *link) {
        if (link->network->ipv6_accept_ra_route_table_set)
                return link->network->ipv6_accept_ra_route_table;
        return link_get_vrf_table(link);
}