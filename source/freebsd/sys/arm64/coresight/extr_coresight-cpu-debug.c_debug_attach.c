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
struct debug_softc {int /*<<< orphan*/  pdata; int /*<<< orphan*/  res; } ;
struct coresight_desc {int /*<<< orphan*/  dev_type; int /*<<< orphan*/  dev; int /*<<< orphan*/  pdata; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  CORESIGHT_CPU_DEBUG ; 
 int ENXIO ; 
 scalar_t__ bus_alloc_resources (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  coresight_get_platform_data (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  coresight_register (struct coresight_desc*) ; 
 int /*<<< orphan*/  debug_spec ; 
 struct debug_softc* device_get_softc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_printf (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static int
debug_attach(device_t dev)
{
	struct coresight_desc desc;
	struct debug_softc *sc;

	sc = device_get_softc(dev);

	if (bus_alloc_resources(dev, debug_spec, &sc->res) != 0) {
		device_printf(dev, "cannot allocate resources for device\n");
		return (ENXIO);
	}

	sc->pdata = coresight_get_platform_data(dev);
	desc.pdata = sc->pdata;
	desc.dev = dev;
	desc.dev_type = CORESIGHT_CPU_DEBUG;
	coresight_register(&desc);

	return (0);
}