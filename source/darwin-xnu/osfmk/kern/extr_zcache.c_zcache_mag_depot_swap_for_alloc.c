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
struct zone_cache {size_t zcc_depot_index; int /*<<< orphan*/ * zcc_depot_list; } ;
struct zcc_per_cpu_cache {int /*<<< orphan*/  current; } ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int zcache_depot_available (struct zone_cache*) ; 
 int /*<<< orphan*/  zcache_swap_magazines (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

void zcache_mag_depot_swap_for_alloc(struct zone_cache *zcache, struct zcc_per_cpu_cache *cache)
{
	/* Loads a full magazine from which we can allocate */
	assert(zcache_depot_available(zcache));
	assert(zcache->zcc_depot_index > 0);
	zcache->zcc_depot_index --;
	zcache_swap_magazines(&cache->current, &zcache->zcc_depot_list[zcache->zcc_depot_index]);
}