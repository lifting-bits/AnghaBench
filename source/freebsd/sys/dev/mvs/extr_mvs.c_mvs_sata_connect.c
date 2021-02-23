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
typedef  int u_int32_t ;
struct mvs_channel {int /*<<< orphan*/  r_mem; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int ATA_INL (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ATA_OUTL (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  DELAY (int) ; 
 int /*<<< orphan*/  SATA_SE ; 
 int /*<<< orphan*/  SATA_SS ; 
 int SATA_SS_DET_MASK ; 
 int SATA_SS_DET_NO_DEVICE ; 
 int SATA_SS_DET_PHY_OFFLINE ; 
 int SATA_SS_DET_PHY_ONLINE ; 
 int SATA_SS_IPM_ACTIVE ; 
 int SATA_SS_IPM_MASK ; 
 int SATA_SS_SPD_MASK ; 
 int SATA_SS_SPD_NO_SPEED ; 
 scalar_t__ bootverbose ; 
 int /*<<< orphan*/  device_printf (int /*<<< orphan*/ ,char*,int,...) ; 

__attribute__((used)) static int
mvs_sata_connect(struct mvs_channel *ch)
{
	u_int32_t status;
	int timeout, found = 0;

	/* Wait up to 100ms for "connect well" */
	for (timeout = 0; timeout < 1000 ; timeout++) {
		status = ATA_INL(ch->r_mem, SATA_SS);
		if ((status & SATA_SS_DET_MASK) != SATA_SS_DET_NO_DEVICE)
			found = 1;
		if (((status & SATA_SS_DET_MASK) == SATA_SS_DET_PHY_ONLINE) &&
		    ((status & SATA_SS_SPD_MASK) != SATA_SS_SPD_NO_SPEED) &&
		    ((status & SATA_SS_IPM_MASK) == SATA_SS_IPM_ACTIVE))
			break;
		if ((status & SATA_SS_DET_MASK) == SATA_SS_DET_PHY_OFFLINE) {
			if (bootverbose) {
				device_printf(ch->dev, "SATA offline status=%08x\n",
				    status);
			}
			return (0);
		}
		if (found == 0 && timeout >= 100)
			break;
		DELAY(100);
	}
	if (timeout >= 1000 || !found) {
		if (bootverbose) {
			device_printf(ch->dev,
			    "SATA connect timeout time=%dus status=%08x\n",
			    timeout * 100, status);
		}
		return (0);
	}
	if (bootverbose) {
		device_printf(ch->dev, "SATA connect time=%dus status=%08x\n",
		    timeout * 100, status);
	}
	/* Clear SATA error register */
	ATA_OUTL(ch->r_mem, SATA_SE, 0xffffffff);
	return (1);
}