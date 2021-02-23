#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  manager; scalar_t__ link; } ;
typedef  int /*<<< orphan*/  DnssecMode ;
typedef  TYPE_1__ DnsServer ;

/* Variables and functions */
 int /*<<< orphan*/  assert (TYPE_1__*) ; 
 int /*<<< orphan*/  link_get_dnssec_mode (scalar_t__) ; 
 int /*<<< orphan*/  manager_get_dnssec_mode (int /*<<< orphan*/ ) ; 

DnssecMode dns_server_get_dnssec_mode(DnsServer *s) {
        assert(s);

        if (s->link)
                return link_get_dnssec_mode(s->link);

        return manager_get_dnssec_mode(s->manager);
}