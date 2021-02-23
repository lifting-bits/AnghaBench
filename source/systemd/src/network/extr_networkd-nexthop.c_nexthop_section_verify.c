#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  gw; int /*<<< orphan*/  family; int /*<<< orphan*/  section; } ;
typedef  TYPE_1__ NextHop ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ in_addr_is_null (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ section_is_invalid (int /*<<< orphan*/ ) ; 

int nexthop_section_verify(NextHop *nh) {
        if (section_is_invalid(nh->section))
                return -EINVAL;

        if (in_addr_is_null(nh->family, &nh->gw) < 0)
                return -EINVAL;

        return 0;
}