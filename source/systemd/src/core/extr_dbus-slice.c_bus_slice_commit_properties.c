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
typedef  int /*<<< orphan*/  Unit ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  unit_invalidate_cgroup_members_masks (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  unit_realize_cgroup (int /*<<< orphan*/ *) ; 

int bus_slice_commit_properties(Unit *u) {
        assert(u);

        unit_invalidate_cgroup_members_masks(u);
        unit_realize_cgroup(u);

        return 0;
}