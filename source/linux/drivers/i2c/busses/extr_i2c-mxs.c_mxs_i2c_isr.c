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
struct mxs_i2c_dev {scalar_t__ regs; int /*<<< orphan*/  cmd_err; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  EIO ; 
 int /*<<< orphan*/  ENXIO ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ MXS_I2C_CTRL1 ; 
 scalar_t__ MXS_I2C_CTRL1_CLR ; 
 int MXS_I2C_CTRL1_EARLY_TERM_IRQ ; 
 int MXS_I2C_CTRL1_MASTER_LOSS_IRQ ; 
 int MXS_I2C_CTRL1_NO_SLAVE_ACK_IRQ ; 
 int MXS_I2C_CTRL1_SLAVE_IRQ ; 
 int MXS_I2C_CTRL1_SLAVE_STOP_IRQ ; 
 int MXS_I2C_IRQ_MASK ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static irqreturn_t mxs_i2c_isr(int this_irq, void *dev_id)
{
	struct mxs_i2c_dev *i2c = dev_id;
	u32 stat = readl(i2c->regs + MXS_I2C_CTRL1) & MXS_I2C_IRQ_MASK;

	if (!stat)
		return IRQ_NONE;

	if (stat & MXS_I2C_CTRL1_NO_SLAVE_ACK_IRQ)
		i2c->cmd_err = -ENXIO;
	else if (stat & (MXS_I2C_CTRL1_EARLY_TERM_IRQ |
		    MXS_I2C_CTRL1_MASTER_LOSS_IRQ |
		    MXS_I2C_CTRL1_SLAVE_STOP_IRQ | MXS_I2C_CTRL1_SLAVE_IRQ))
		/* MXS_I2C_CTRL1_OVERSIZE_XFER_TERM_IRQ is only for slaves */
		i2c->cmd_err = -EIO;

	writel(stat, i2c->regs + MXS_I2C_CTRL1_CLR);

	return IRQ_HANDLED;
}