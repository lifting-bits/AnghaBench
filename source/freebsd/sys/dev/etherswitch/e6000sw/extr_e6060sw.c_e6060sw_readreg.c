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
 int MDIO_READREG (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  device_get_parent (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
e6060sw_readreg(device_t dev, int addr)
{
	int devaddr, regaddr;

	devaddr = (addr >> 5) & 0x1f;
	regaddr = addr & 0x1f;

	return MDIO_READREG(device_get_parent(dev), devaddr, regaddr);
}