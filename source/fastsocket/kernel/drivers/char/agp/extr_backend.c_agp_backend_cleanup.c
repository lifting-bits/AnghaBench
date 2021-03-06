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
struct agp_bridge_data {TYPE_1__* driver; int /*<<< orphan*/  scratch_page_dma; int /*<<< orphan*/  scratch_page_page; int /*<<< orphan*/ * key_list; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* agp_destroy_page ) (void*,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* agp_unmap_page ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;scalar_t__ needs_scratch_page; int /*<<< orphan*/  (* free_gatt_table ) (struct agp_bridge_data*) ;int /*<<< orphan*/  (* cleanup ) () ;} ;

/* Variables and functions */
 int /*<<< orphan*/  AGP_PAGE_DESTROY_FREE ; 
 int /*<<< orphan*/  AGP_PAGE_DESTROY_UNMAP ; 
 void* page_address (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 () ; 
 int /*<<< orphan*/  stub2 (struct agp_bridge_data*) ; 
 int /*<<< orphan*/  stub3 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub5 (void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vfree (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void agp_backend_cleanup(struct agp_bridge_data *bridge)
{
	if (bridge->driver->cleanup)
		bridge->driver->cleanup();
	if (bridge->driver->free_gatt_table)
		bridge->driver->free_gatt_table(bridge);

	vfree(bridge->key_list);
	bridge->key_list = NULL;

	if (bridge->driver->agp_destroy_page &&
	    bridge->driver->needs_scratch_page) {
		void *va = page_address(bridge->scratch_page_page);

		if (bridge->driver->agp_unmap_page)
			bridge->driver->agp_unmap_page(bridge->scratch_page_page,
						       bridge->scratch_page_dma);

		bridge->driver->agp_destroy_page(va, AGP_PAGE_DESTROY_UNMAP);
		bridge->driver->agp_destroy_page(va, AGP_PAGE_DESTROY_FREE);
	}
}