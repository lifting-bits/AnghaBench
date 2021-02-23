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
struct iwn_softc {int /*<<< orphan*/  sc_ic; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 struct iwn_softc* device_get_softc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ieee80211_resume_all (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pci_write_config (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int
iwn_resume(device_t dev)
{
	struct iwn_softc *sc = device_get_softc(dev);

	/* Clear device-specific "PCI retry timeout" register (41h). */
	pci_write_config(dev, 0x41, 0, 1);

	ieee80211_resume_all(&sc->sc_ic);
	return 0;
}