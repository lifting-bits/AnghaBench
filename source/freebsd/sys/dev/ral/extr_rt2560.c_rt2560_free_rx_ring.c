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
struct rt2560_softc {int dummy; } ;
struct rt2560_rx_ring {int count; int /*<<< orphan*/ * data_dmat; struct rt2560_rx_data* data; int /*<<< orphan*/ * desc_dmat; int /*<<< orphan*/ * desc_map; int /*<<< orphan*/ * desc; } ;
struct rt2560_rx_data {int /*<<< orphan*/ * map; int /*<<< orphan*/ * m; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUS_DMASYNC_POSTREAD ; 
 int /*<<< orphan*/  BUS_DMASYNC_POSTWRITE ; 
 int /*<<< orphan*/  M_DEVBUF ; 
 int /*<<< orphan*/  bus_dma_tag_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bus_dmamap_destroy (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bus_dmamap_sync (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bus_dmamap_unload (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bus_dmamem_free (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  free (struct rt2560_rx_data*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  m_freem (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
rt2560_free_rx_ring(struct rt2560_softc *sc, struct rt2560_rx_ring *ring)
{
	struct rt2560_rx_data *data;
	int i;

	if (ring->desc != NULL) {
		bus_dmamap_sync(ring->desc_dmat, ring->desc_map,
		    BUS_DMASYNC_POSTWRITE);
		bus_dmamap_unload(ring->desc_dmat, ring->desc_map);
		bus_dmamem_free(ring->desc_dmat, ring->desc, ring->desc_map);
	}

	if (ring->desc_dmat != NULL)
		bus_dma_tag_destroy(ring->desc_dmat);

	if (ring->data != NULL) {
		for (i = 0; i < ring->count; i++) {
			data = &ring->data[i];

			if (data->m != NULL) {
				bus_dmamap_sync(ring->data_dmat, data->map,
				    BUS_DMASYNC_POSTREAD);
				bus_dmamap_unload(ring->data_dmat, data->map);
				m_freem(data->m);
			}

			if (data->map != NULL)
				bus_dmamap_destroy(ring->data_dmat, data->map);
		}

		free(ring->data, M_DEVBUF);
	}

	if (ring->data_dmat != NULL)
		bus_dma_tag_destroy(ring->data_dmat);
}