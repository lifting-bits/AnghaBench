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
struct pevent {int dummy; } ;
struct func_map {char const* func; } ;

/* Variables and functions */
 struct func_map* find_func (struct pevent*,unsigned long long) ; 

const char *pevent_find_function(struct pevent *pevent, unsigned long long addr)
{
	struct func_map *map;

	map = find_func(pevent, addr);
	if (!map)
		return NULL;

	return map->func;
}