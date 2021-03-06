#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int bus_size_t ;
typedef  int /*<<< orphan*/  bus_dmamap_t ;
typedef  TYPE_1__* bus_dma_tag_t ;
struct TYPE_6__ {int ds_addr; int ds_len; } ;
typedef  TYPE_2__ bus_dma_segment_t ;
typedef  int bus_addr_t ;
struct TYPE_5__ {int boundary; int maxsegsz; int nsegments; } ;

/* Variables and functions */

__attribute__((used)) static int
_bus_dmamap_addseg(bus_dma_tag_t dmat, bus_dmamap_t map, bus_addr_t curaddr,
    bus_size_t sgsize, bus_dma_segment_t *segs, int *segp)
{
	bus_addr_t baddr, bmask;
	int seg;

	/*
	 * Make sure we don't cross any boundaries.
	 */
	bmask = ~(dmat->boundary - 1);
	if (dmat->boundary > 0) {
		baddr = (curaddr + dmat->boundary) & bmask;
		if (sgsize > (baddr - curaddr))
			sgsize = (baddr - curaddr);
	}
	/*
	 * Insert chunk into a segment, coalescing with
	 * the previous segment if possible.
	 */
	seg = *segp;
	if (seg >= 0 &&
	    curaddr == segs[seg].ds_addr + segs[seg].ds_len &&
	    (segs[seg].ds_len + sgsize) <= dmat->maxsegsz &&
	    (dmat->boundary == 0 ||
	     (segs[seg].ds_addr & bmask) == (curaddr & bmask))) {
		segs[seg].ds_len += sgsize;
	} else {
		if (++seg >= dmat->nsegments)
			return (0);
		segs[seg].ds_addr = curaddr;
		segs[seg].ds_len = sgsize;
	}
	*segp = seg;
	return (sgsize);
}