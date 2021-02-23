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
struct hdac_irq {int irq_rid; int /*<<< orphan*/ * irq_res; int /*<<< orphan*/ * irq_handle; } ;
struct hdac_softc {int /*<<< orphan*/  dev; struct hdac_irq irq; } ;

/* Variables and functions */
 int /*<<< orphan*/  SYS_RES_IRQ ; 
 int /*<<< orphan*/  bus_release_resource (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bus_teardown_intr (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pci_release_msi (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
hdac_irq_free(struct hdac_softc *sc)
{
	struct hdac_irq *irq;

	irq = &sc->irq;
	if (irq->irq_res != NULL && irq->irq_handle != NULL)
		bus_teardown_intr(sc->dev, irq->irq_res, irq->irq_handle);
	if (irq->irq_res != NULL)
		bus_release_resource(sc->dev, SYS_RES_IRQ, irq->irq_rid,
		    irq->irq_res);
	if (irq->irq_rid == 0x1)
		pci_release_msi(sc->dev);
	irq->irq_handle = NULL;
	irq->irq_res = NULL;
	irq->irq_rid = 0x0;
}