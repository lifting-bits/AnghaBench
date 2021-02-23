#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {void* bsh; void* bst; } ;
struct uart_softc {TYPE_2__ sc_bas; TYPE_3__* sc_sysdev; int /*<<< orphan*/ * sc_class; } ;
typedef  int /*<<< orphan*/  device_t ;
struct TYPE_4__ {void* bsh; void* bst; } ;
struct TYPE_6__ {TYPE_1__ bas; } ;

/* Variables and functions */
 int /*<<< orphan*/  MALTA_UART0ADR ; 
 void* MIPS_PHYS_TO_KSEG1 (int /*<<< orphan*/ ) ; 
 TYPE_3__* SLIST_FIRST (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bcopy (TYPE_1__*,TYPE_2__*,int) ; 
 struct uart_softc* device_get_softc (int /*<<< orphan*/ ) ; 
 void* mips_bus_space_generic ; 
 int uart_bus_probe (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uart_ns8250_class ; 
 int /*<<< orphan*/  uart_sysdevs ; 

__attribute__((used)) static int
uart_malta_probe(device_t dev)
{
	struct uart_softc *sc;

	sc = device_get_softc(dev);
	sc->sc_sysdev = SLIST_FIRST(&uart_sysdevs);
	sc->sc_class = &uart_ns8250_class;
	bcopy(&sc->sc_sysdev->bas, &sc->sc_bas, sizeof(sc->sc_bas));
	sc->sc_sysdev->bas.bst = mips_bus_space_generic;
	sc->sc_sysdev->bas.bsh = MIPS_PHYS_TO_KSEG1(MALTA_UART0ADR);
	sc->sc_bas.bst = mips_bus_space_generic;
	sc->sc_bas.bsh = MIPS_PHYS_TO_KSEG1(MALTA_UART0ADR);
	return(uart_bus_probe(dev, 0, 0, 0, 0, 0, 0));
}