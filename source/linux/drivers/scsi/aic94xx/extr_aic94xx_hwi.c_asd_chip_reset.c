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
struct asd_ha_struct {int /*<<< orphan*/  pcidev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASD_DPRINTK (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  asd_chip_hardrst (struct asd_ha_struct*) ; 
 int /*<<< orphan*/  pci_name (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void asd_chip_reset(struct asd_ha_struct *asd_ha)
{
	ASD_DPRINTK("chip reset for %s\n", pci_name(asd_ha->pcidev));
	asd_chip_hardrst(asd_ha);
}