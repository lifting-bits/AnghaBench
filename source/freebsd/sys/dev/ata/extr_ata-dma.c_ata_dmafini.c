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
struct TYPE_2__ {int /*<<< orphan*/ * dmatag; int /*<<< orphan*/ * work_tag; int /*<<< orphan*/ * work; scalar_t__ work_bus; int /*<<< orphan*/  work_map; } ;
struct ata_channel {TYPE_1__ dma; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  bus_dma_tag_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bus_dmamap_unload (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bus_dmamem_free (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct ata_channel* device_get_softc (int /*<<< orphan*/ ) ; 

void 
ata_dmafini(device_t dev)
{
    struct ata_channel *ch = device_get_softc(dev);

    if (ch->dma.work_bus) {
	bus_dmamap_unload(ch->dma.work_tag, ch->dma.work_map);
	bus_dmamem_free(ch->dma.work_tag, ch->dma.work, ch->dma.work_map);
	ch->dma.work_bus = 0;
	ch->dma.work = NULL;
    }
    if (ch->dma.work_tag) {
	bus_dma_tag_destroy(ch->dma.work_tag);
	ch->dma.work_tag = NULL;
    }
    if (ch->dma.dmatag) {
	bus_dma_tag_destroy(ch->dma.dmatag);
	ch->dma.dmatag = NULL;
    }
}