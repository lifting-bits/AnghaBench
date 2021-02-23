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
typedef  TYPE_1__* vm_map_t ;
struct TYPE_4__ {int /*<<< orphan*/  lock; int /*<<< orphan*/  system_mtx; scalar_t__ system_map; } ;

/* Variables and functions */
 int /*<<< orphan*/  VM_MAP_UNLOCK_CONSISTENT (TYPE_1__*) ; 
 int /*<<< orphan*/  mtx_unlock_flags_ (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char const*,int) ; 
 int /*<<< orphan*/  sx_xunlock_ (int /*<<< orphan*/ *,char const*,int) ; 
 int /*<<< orphan*/  vm_map_process_deferred () ; 

void
_vm_map_unlock(vm_map_t map, const char *file, int line)
{

	VM_MAP_UNLOCK_CONSISTENT(map);
	if (map->system_map)
		mtx_unlock_flags_(&map->system_mtx, 0, file, line);
	else {
		sx_xunlock_(&map->lock, file, line);
		vm_map_process_deferred();
	}
}