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
struct ath10k {int dummy; } ;

/* Variables and functions */
 scalar_t__ PCIE_INTR_CAUSE_ADDRESS ; 
 int PCIE_INTR_CE_MASK_ALL ; 
 int PCIE_INTR_FIRMWARE_MASK ; 
 scalar_t__ SOC_CORE_BASE_ADDRESS ; 
 int ath10k_pci_read32 (struct ath10k*,scalar_t__) ; 

bool ath10k_pci_irq_pending(struct ath10k *ar)
{
	u32 cause;

	/* Check if the shared legacy irq is for us */
	cause = ath10k_pci_read32(ar, SOC_CORE_BASE_ADDRESS +
				  PCIE_INTR_CAUSE_ADDRESS);
	if (cause & (PCIE_INTR_FIRMWARE_MASK | PCIE_INTR_CE_MASK_ALL))
		return true;

	return false;
}