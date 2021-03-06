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
struct TYPE_6__ {TYPE_1__* link; } ;
struct TYPE_5__ {int ifindex; } ;
typedef  TYPE_2__ DnsScope ;

/* Variables and functions */
 int /*<<< orphan*/  assert (TYPE_2__*) ; 

int dns_scope_ifindex(DnsScope *s) {
        assert(s);

        if (s->link)
                return s->link->ifindex;

        return 0;
}