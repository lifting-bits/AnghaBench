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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
struct pci_vtcon_softc {scalar_t__ vsc_config; } ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,void*,int) ; 

__attribute__((used)) static int
pci_vtcon_cfgread(void *vsc, int offset, int size, uint32_t *retval)
{
	struct pci_vtcon_softc *sc = vsc;
	void *ptr;

	ptr = (uint8_t *)sc->vsc_config + offset;
	memcpy(retval, ptr, size);
	return (0);
}