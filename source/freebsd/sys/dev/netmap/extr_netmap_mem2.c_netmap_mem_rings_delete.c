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
struct netmap_mem_d {TYPE_1__* ops; } ;
struct netmap_adapter {struct netmap_mem_d* nm_mem; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* nmd_rings_delete ) (struct netmap_adapter*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  NMA_LOCK (struct netmap_mem_d*) ; 
 int /*<<< orphan*/  NMA_UNLOCK (struct netmap_mem_d*) ; 
 int /*<<< orphan*/  stub1 (struct netmap_adapter*) ; 

void
netmap_mem_rings_delete(struct netmap_adapter *na)
{
	struct netmap_mem_d *nmd = na->nm_mem;

	NMA_LOCK(nmd);
	nmd->ops->nmd_rings_delete(na);
	NMA_UNLOCK(nmd);
}