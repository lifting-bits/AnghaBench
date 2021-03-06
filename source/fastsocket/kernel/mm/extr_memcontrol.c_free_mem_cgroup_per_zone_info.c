#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/ * nodeinfo; } ;
struct mem_cgroup {TYPE_1__ info; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void free_mem_cgroup_per_zone_info(struct mem_cgroup *mem, int node)
{
	kfree(mem->info.nodeinfo[node]);
}