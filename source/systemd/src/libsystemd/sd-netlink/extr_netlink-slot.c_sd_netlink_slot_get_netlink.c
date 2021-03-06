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
struct TYPE_4__ {int /*<<< orphan*/ * netlink; } ;
typedef  TYPE_1__ sd_netlink_slot ;
typedef  int /*<<< orphan*/  sd_netlink ;

/* Variables and functions */
 int /*<<< orphan*/  assert_return (TYPE_1__*,int /*<<< orphan*/ *) ; 

sd_netlink *sd_netlink_slot_get_netlink(sd_netlink_slot *slot) {
        assert_return(slot, NULL);

        return slot->netlink;
}