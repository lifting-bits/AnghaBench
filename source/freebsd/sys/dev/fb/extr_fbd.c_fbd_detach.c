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
struct fbd_softc {int /*<<< orphan*/  sc_info; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 struct fbd_softc* device_get_softc (int /*<<< orphan*/ ) ; 
 int fbd_unregister (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
fbd_detach(device_t dev)
{
	struct fbd_softc *sc;
	int err;

	sc = device_get_softc(dev);

	err = fbd_unregister(sc->sc_info);

	return (err);
}