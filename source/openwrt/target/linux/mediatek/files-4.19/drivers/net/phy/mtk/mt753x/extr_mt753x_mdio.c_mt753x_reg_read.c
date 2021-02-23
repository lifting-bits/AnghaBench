#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct gsw_mt753x {TYPE_1__* host_bus; int /*<<< orphan*/  smi_addr; } ;
struct TYPE_4__ {int (* read ) (TYPE_1__*,int /*<<< orphan*/ ,int) ;int /*<<< orphan*/  mdio_lock; int /*<<< orphan*/  (* write ) (TYPE_1__*,int /*<<< orphan*/ ,int,int) ;} ;

/* Variables and functions */
 int MT753X_REG_ADDR_M ; 
 int MT753X_REG_ADDR_S ; 
 int MT753X_REG_PAGE_ADDR_M ; 
 int MT753X_REG_PAGE_ADDR_S ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (TYPE_1__*,int /*<<< orphan*/ ,int,int) ; 
 int stub2 (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int stub3 (TYPE_1__*,int /*<<< orphan*/ ,int) ; 

u32 mt753x_reg_read(struct gsw_mt753x *gsw, u32 reg)
{
	u32 high, low;

	mutex_lock(&gsw->host_bus->mdio_lock);

	gsw->host_bus->write(gsw->host_bus, gsw->smi_addr, 0x1f,
		(reg & MT753X_REG_PAGE_ADDR_M) >> MT753X_REG_PAGE_ADDR_S);

	low = gsw->host_bus->read(gsw->host_bus, gsw->smi_addr,
		(reg & MT753X_REG_ADDR_M) >> MT753X_REG_ADDR_S);

	high = gsw->host_bus->read(gsw->host_bus, gsw->smi_addr, 0x10);

	mutex_unlock(&gsw->host_bus->mdio_lock);

	return (high << 16) | (low & 0xffff);
}