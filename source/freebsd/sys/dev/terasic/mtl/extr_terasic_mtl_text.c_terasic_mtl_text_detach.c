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
struct terasic_mtl_softc {int /*<<< orphan*/ * mtl_text_cdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  TERASIC_MTL_LOCK_DESTROY (struct terasic_mtl_softc*) ; 
 int /*<<< orphan*/  destroy_dev (int /*<<< orphan*/ *) ; 

void
terasic_mtl_text_detach(struct terasic_mtl_softc *sc)
{

	if (sc->mtl_text_cdev != NULL) {
		destroy_dev(sc->mtl_text_cdev);
		TERASIC_MTL_LOCK_DESTROY(sc);
	}
}