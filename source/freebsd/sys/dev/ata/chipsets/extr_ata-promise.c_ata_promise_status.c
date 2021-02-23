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
struct ata_pci_controller {int /*<<< orphan*/  r_res1; } ;
struct ata_channel {scalar_t__ unit; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int ATA_INL (int /*<<< orphan*/ ,int) ; 
 int ata_pci_status (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_get_parent (int /*<<< orphan*/ ) ; 
 void* device_get_softc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
ata_promise_status(device_t dev)
{
    struct ata_pci_controller *ctlr = device_get_softc(device_get_parent(dev));
    struct ata_channel *ch = device_get_softc(dev);

    if (ATA_INL(ctlr->r_res1, 0x1c) & (ch->unit ? 0x00004000 : 0x00000400)) {
	return ata_pci_status(dev);
    }
    return 0;
}