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
typedef  int /*<<< orphan*/  uid_t ;
typedef  scalar_t__ gid_t ;
struct TYPE_4__ {int /*<<< orphan*/  gid_refs; } ;
typedef  TYPE_1__ Manager ;

/* Variables and functions */
 int /*<<< orphan*/  clean_ipc_by_gid ; 
 int /*<<< orphan*/  manager_unref_uid_internal (TYPE_1__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

void manager_unref_gid(Manager *m, gid_t gid, bool destroy_now) {
        manager_unref_uid_internal(m, &m->gid_refs, (uid_t) gid, destroy_now, clean_ipc_by_gid);
}