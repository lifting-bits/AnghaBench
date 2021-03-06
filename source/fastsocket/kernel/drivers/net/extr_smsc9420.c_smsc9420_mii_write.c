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
typedef  int u32 ;
typedef  scalar_t__ u16 ;
struct smsc9420_pdata {int /*<<< orphan*/  phy_lock; } ;
struct mii_bus {scalar_t__ priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRV ; 
 int EIO ; 
 int /*<<< orphan*/  MII_ACCESS ; 
 int MII_ACCESS_MII_BUSY_ ; 
 int MII_ACCESS_MII_WRITE_ ; 
 int /*<<< orphan*/  MII_DATA ; 
 int smsc9420_reg_read (struct smsc9420_pdata*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  smsc9420_reg_write (struct smsc9420_pdata*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  smsc_warn (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int smsc9420_mii_write(struct mii_bus *bus, int phyaddr, int regidx,
			   u16 val)
{
	struct smsc9420_pdata *pd = (struct smsc9420_pdata *)bus->priv;
	unsigned long flags;
	u32 addr;
	int i, reg = -EIO;

	spin_lock_irqsave(&pd->phy_lock, flags);

	/* confirm MII not busy */
	if ((smsc9420_reg_read(pd, MII_ACCESS) & MII_ACCESS_MII_BUSY_)) {
		smsc_warn(DRV, "MII is busy???");
		goto out;
	}

	/* put the data to write in the MAC */
	smsc9420_reg_write(pd, MII_DATA, (u32)val);

	/* set the address, index & direction (write to PHY) */
	addr = ((phyaddr & 0x1F) << 11) | ((regidx & 0x1F) << 6) |
		MII_ACCESS_MII_WRITE_;
	smsc9420_reg_write(pd, MII_ACCESS, addr);

	/* wait for write to complete with 50us timeout */
	for (i = 0; i < 5; i++) {
		if (!(smsc9420_reg_read(pd, MII_ACCESS) &
			MII_ACCESS_MII_BUSY_)) {
			reg = 0;
			goto out;
		}
		udelay(10);
	}

	smsc_warn(DRV, "MII busy timeout!");

out:
	spin_unlock_irqrestore(&pd->phy_lock, flags);
	return reg;
}