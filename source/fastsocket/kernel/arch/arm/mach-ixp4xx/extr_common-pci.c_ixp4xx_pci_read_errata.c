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
typedef  void* u32 ;

/* Variables and functions */
 void** PCI_NP_AD ; 
 void** PCI_NP_CBE ; 
 void** PCI_NP_RDATA ; 
 scalar_t__ check_master_abort () ; 
 int /*<<< orphan*/  ixp4xx_pci_lock ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

int ixp4xx_pci_read_errata(u32 addr, u32 cmd, u32* data)
{
	unsigned long flags;
	int retval = 0;
	int i;

	spin_lock_irqsave(&ixp4xx_pci_lock, flags);

	*PCI_NP_AD = addr;

	/* 
	 * PCI workaround  - only works if NP PCI space reads have 
	 * no side effects!!! Read 8 times. last one will be good.
	 */
	for (i = 0; i < 8; i++) {
		*PCI_NP_CBE = cmd;
		*data = *PCI_NP_RDATA;
		*data = *PCI_NP_RDATA;
	}

	if(check_master_abort())
		retval = 1;

	spin_unlock_irqrestore(&ixp4xx_pci_lock, flags);
	return retval;
}