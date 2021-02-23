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
struct vtmmio_softc {int /*<<< orphan*/ * platform; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  VIRTIO_MMIO_POLL (int /*<<< orphan*/ *) ; 
 struct vtmmio_softc* device_get_softc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
vtmmio_poll(device_t dev)
{
	struct vtmmio_softc *sc;

	sc = device_get_softc(dev);

	if (sc->platform != NULL)
		VIRTIO_MMIO_POLL(sc->platform);
}