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
struct ata_pci_controller {int (* ch_suspend ) (int /*<<< orphan*/ ) ;} ;
struct ata_channel {int /*<<< orphan*/  attached; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int ata_suspend (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_get_parent (int /*<<< orphan*/ ) ; 
 void* device_get_softc (int /*<<< orphan*/ ) ; 
 int stub1 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
ata_pcichannel_suspend(device_t dev)
{
    struct ata_pci_controller *ctlr = device_get_softc(device_get_parent(dev));
    struct ata_channel *ch = device_get_softc(dev);
    int error;

    if (!ch->attached)
	return (0);

    if ((error = ata_suspend(dev)))
	return (error);

    if (ctlr->ch_suspend != NULL && (error = ctlr->ch_suspend(dev)))
	return (error);

    return (0);
}