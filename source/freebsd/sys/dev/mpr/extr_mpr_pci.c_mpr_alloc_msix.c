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
struct mpr_softc {int /*<<< orphan*/  mpr_dev; } ;

/* Variables and functions */
 int pci_alloc_msix (int /*<<< orphan*/ ,int*) ; 

__attribute__((used)) static int
mpr_alloc_msix(struct mpr_softc *sc, int msgs)
{
	int error;

	error = pci_alloc_msix(sc->mpr_dev, &msgs);
	return (error);
}