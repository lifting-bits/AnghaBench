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
struct resource {int dummy; } ;
typedef  int /*<<< orphan*/  device_t ;
typedef  scalar_t__ bus_space_handle_t ;
typedef  scalar_t__ bus_size_t ;

/* Variables and functions */
 int SYS_RES_IOPORT ; 
 int SYS_RES_IRQ ; 
 int SYS_RES_MEMORY ; 
 int /*<<< orphan*/  bus_space_unmap (int /*<<< orphan*/ *,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  intr_deactivate_irq (int /*<<< orphan*/ ,struct resource*) ; 
 int /*<<< orphan*/  memmap_bus ; 
 int rman_deactivate_resource (struct resource*) ; 
 scalar_t__ rman_get_bushandle (struct resource*) ; 
 scalar_t__ rman_get_size (struct resource*) ; 
 int /*<<< orphan*/  rman_set_bushandle (struct resource*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rman_set_virtual (struct resource*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
nexus_deactivate_resource(device_t bus, device_t child, int type, int rid,
    struct resource *r)
{
	bus_size_t psize;
	bus_space_handle_t vaddr;

	if (type == SYS_RES_MEMORY || type == SYS_RES_IOPORT) {
		psize = (bus_size_t)rman_get_size(r);
		vaddr = rman_get_bushandle(r);

		if (vaddr != 0) {
			bus_space_unmap(&memmap_bus, vaddr, psize);
			rman_set_virtual(r, NULL);
			rman_set_bushandle(r, 0);
		}
	} else if (type == SYS_RES_IRQ) {
		intr_deactivate_irq(child, r);
	}

	return (rman_deactivate_resource(r));
}