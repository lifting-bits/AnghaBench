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
struct pcf_softc {scalar_t__ res_ioport; int pcf_flags; scalar_t__ res_irq; int /*<<< orphan*/  pcf_lock; int /*<<< orphan*/  rid_ioport; int /*<<< orphan*/  rid_irq; int /*<<< orphan*/ * iicbus; int /*<<< orphan*/  intr_cookie; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 struct pcf_softc* DEVTOSOFTC (int /*<<< orphan*/ ) ; 
 int ENXIO ; 
 int /*<<< orphan*/  IIC_FASTEST ; 
 int IIC_POLLED ; 
 int INTR_MPSAFE ; 
 int INTR_TYPE_NET ; 
 int /*<<< orphan*/  MTX_DEF ; 
 int /*<<< orphan*/  PCF_DEFAULT_ADDR ; 
 int /*<<< orphan*/  RF_ACTIVE ; 
 int /*<<< orphan*/  SYS_RES_IRQ ; 
 int /*<<< orphan*/  SYS_RES_MEMORY ; 
 void* bus_alloc_resource_any (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bus_generic_attach (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bus_release_resource (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 int bus_setup_intr (int /*<<< orphan*/ ,scalar_t__,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct pcf_softc*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * device_add_child (int /*<<< orphan*/ ,char*,int) ; 
 int device_get_flags (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_get_nameunit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_printf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  mtx_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mtx_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pcf_intr ; 
 int /*<<< orphan*/  pcf_rst_card (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
envctrl_attach(device_t dev)
{
	struct pcf_softc *sc;
	int rv = ENXIO;

	sc = DEVTOSOFTC(dev);
	mtx_init(&sc->pcf_lock, device_get_nameunit(dev), "pcf", MTX_DEF);

	/* IO port is mandatory */
	sc->res_ioport = bus_alloc_resource_any(dev, SYS_RES_MEMORY,
						&sc->rid_ioport, RF_ACTIVE);
	if (sc->res_ioport == 0) {
		device_printf(dev, "cannot reserve I/O port range\n");
		goto error;
	}

	sc->pcf_flags = device_get_flags(dev);

	if (!(sc->pcf_flags & IIC_POLLED)) {
		sc->res_irq = bus_alloc_resource_any(dev, SYS_RES_IRQ, &sc->rid_irq,
						     RF_ACTIVE);
		if (sc->res_irq == 0) {
			device_printf(dev, "can't reserve irq, polled mode.\n");
			sc->pcf_flags |= IIC_POLLED;
		}
	}

	/* reset the chip */
	pcf_rst_card(dev, IIC_FASTEST, PCF_DEFAULT_ADDR, NULL);

	rv = bus_setup_intr(dev, sc->res_irq,
			    INTR_TYPE_NET | INTR_MPSAFE /* | INTR_ENTROPY */,
			    NULL, pcf_intr, sc, &sc->intr_cookie);
	if (rv) {
		device_printf(dev, "could not setup IRQ\n");
		goto error;
	}

	if ((sc->iicbus = device_add_child(dev, "iicbus", -1)) == NULL)
		device_printf(dev, "could not allocate iicbus instance\n");

	/* probe and attach the iicbus */
	bus_generic_attach(dev);

	return (0);

error:
	if (sc->res_irq != 0) {
		bus_release_resource(dev, SYS_RES_IRQ, sc->rid_irq,
				     sc->res_irq);
	}
	if (sc->res_ioport != 0) {
		bus_release_resource(dev, SYS_RES_MEMORY, sc->rid_ioport,
				     sc->res_ioport);
	}
	mtx_destroy(&sc->pcf_lock);
	return (rv);
}