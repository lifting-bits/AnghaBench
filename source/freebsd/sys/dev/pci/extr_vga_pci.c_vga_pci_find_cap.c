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
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int pci_find_cap (int /*<<< orphan*/ ,int,int*) ; 

__attribute__((used)) static int
vga_pci_find_cap(device_t dev, device_t child, int capability,
    int *capreg)
{

	return (pci_find_cap(dev, capability, capreg));
}