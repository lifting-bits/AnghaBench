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
typedef  int /*<<< orphan*/  u32 ;
struct fsi_priv {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DIFF_CTL ; 
 int /*<<< orphan*/  DOFF_CTL ; 
 int /*<<< orphan*/  FIFO_CLR ; 
 int /*<<< orphan*/  INT_ST ; 
 int /*<<< orphan*/  IRQ_HALF ; 
 int /*<<< orphan*/  fsi_irq_disable (struct fsi_priv*,int) ; 
 int /*<<< orphan*/  fsi_master_mask_set (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fsi_port_ab_io_bit (struct fsi_priv*,int) ; 
 int /*<<< orphan*/  fsi_reg_mask_set (struct fsi_priv*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fsi_reg_write (struct fsi_priv*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void fsi_irq_init(struct fsi_priv *fsi, int is_play)
{
	u32 data;
	u32 ctrl;

	data = fsi_port_ab_io_bit(fsi, is_play);
	ctrl = is_play ? DOFF_CTL : DIFF_CTL;

	/* set IMSK */
	fsi_irq_disable(fsi, is_play);

	/* set interrupt generation factor */
	fsi_reg_write(fsi, ctrl, IRQ_HALF);

	/* clear FIFO */
	fsi_reg_mask_set(fsi, ctrl, FIFO_CLR, FIFO_CLR);

	/* clear interrupt factor */
	fsi_master_mask_set(INT_ST, data, 0);
}