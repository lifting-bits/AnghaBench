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
struct agp_softc {int /*<<< orphan*/  as_devnode; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  destroy_dev (int /*<<< orphan*/ ) ; 
 struct agp_softc* device_get_softc (int /*<<< orphan*/ ) ; 

void
agp_free_cdev(device_t dev)
{
	struct agp_softc *sc = device_get_softc(dev);

	destroy_dev(sc->as_devnode);
}