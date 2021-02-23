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
 int mv_read_ge_smi (int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static int
mge_mdio_readreg(device_t dev, int phy, int reg)
{
	int ret;

	ret = mv_read_ge_smi(dev, phy, reg);

	return (ret);
}