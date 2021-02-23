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
typedef  int /*<<< orphan*/  u_int32_t ;
struct ata_pci_controller {int dummy; } ;
struct ata_channel {int unit; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  ATA_IDX_ADDR ; 
 int /*<<< orphan*/  ATA_IDX_DATA ; 
 int /*<<< orphan*/  ATA_IDX_INL (struct ata_channel*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ATA_IDX_OUTL (struct ata_channel*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ATA_INTEL_LOCK (struct ata_pci_controller*) ; 
 int /*<<< orphan*/  ATA_INTEL_UNLOCK (struct ata_pci_controller*) ; 
#define  ATA_SCONTROL 130 
#define  ATA_SERROR 129 
#define  ATA_SSTATUS 128 
 int EINVAL ; 
 int /*<<< orphan*/  device_get_parent (int /*<<< orphan*/ ) ; 
 void* device_get_softc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
ata_intel_sata_sidpr_read(device_t dev, int port, int reg, u_int32_t *result)
{
	struct ata_pci_controller *ctlr;
	struct ata_channel *ch;
	device_t parent;

	parent = device_get_parent(dev);
	ctlr = device_get_softc(parent);
	ch = device_get_softc(dev);
	port = (port == 1) ? 1 : 0;
	switch (reg) {
	case ATA_SSTATUS:
	    reg = 0;
	    break;
	case ATA_SCONTROL:
	    reg = 1;
	    break;
	case ATA_SERROR:
	    reg = 2;
	    break;
	default:
	    return (EINVAL);
	}
	ATA_INTEL_LOCK(ctlr);
	ATA_IDX_OUTL(ch, ATA_IDX_ADDR, ((ch->unit * 2 + port) << 8) + reg);
	*result = ATA_IDX_INL(ch, ATA_IDX_DATA);
	ATA_INTEL_UNLOCK(ctlr);
	return (0);
}