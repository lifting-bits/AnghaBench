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
struct map_groups {int /*<<< orphan*/ * maps; } ;
struct map {size_t type; } ;

/* Variables and functions */
 int /*<<< orphan*/  maps__remove (int /*<<< orphan*/ *,struct map*) ; 

__attribute__((used)) static inline void map_groups__remove(struct map_groups *mg, struct map *map)
{
	maps__remove(&mg->maps[map->type], map);
}