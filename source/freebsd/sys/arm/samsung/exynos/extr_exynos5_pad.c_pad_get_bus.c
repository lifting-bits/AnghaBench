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
struct pad_softc {int /*<<< orphan*/  busdev; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 struct pad_softc* device_get_softc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static device_t
pad_get_bus(device_t dev)
{
	struct pad_softc *sc;

	sc = device_get_softc(dev);

	return (sc->busdev);
}