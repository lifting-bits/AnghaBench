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

/* Variables and functions */
 int ide_pci_register_driver (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  scc_pci_driver ; 

__attribute__((used)) static int scc_ide_init(void)
{
	return ide_pci_register_driver(&scc_pci_driver);
}