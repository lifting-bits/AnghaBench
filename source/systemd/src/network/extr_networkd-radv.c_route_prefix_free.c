#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int /*<<< orphan*/  radv_route_prefix; scalar_t__ section; TYPE_1__* network; } ;
struct TYPE_6__ {scalar_t__ n_static_route_prefixes; int /*<<< orphan*/  route_prefixes_by_section; int /*<<< orphan*/  static_route_prefixes; } ;
typedef  TYPE_2__ RoutePrefix ;

/* Variables and functions */
 int /*<<< orphan*/  LIST_REMOVE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  free (TYPE_2__*) ; 
 int /*<<< orphan*/  hashmap_remove (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  network_config_section_free (scalar_t__) ; 
 int /*<<< orphan*/  route_prefixes ; 
 int /*<<< orphan*/  sd_radv_route_prefix_unref (int /*<<< orphan*/ ) ; 

void route_prefix_free(RoutePrefix *prefix) {
        if (!prefix)
                return;

        if (prefix->network) {
                LIST_REMOVE(route_prefixes, prefix->network->static_route_prefixes, prefix);
                assert(prefix->network->n_static_route_prefixes > 0);
                prefix->network->n_static_route_prefixes--;

                if (prefix->section)
                        hashmap_remove(prefix->network->route_prefixes_by_section,
                                       prefix->section);
        }

        network_config_section_free(prefix->section);
        sd_radv_route_prefix_unref(prefix->radv_route_prefix);

        free(prefix);
}