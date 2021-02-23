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
struct dtsec_regs {int /*<<< orphan*/  tctrl; } ;

/* Variables and functions */
 int DTSEC_TCTRL_GTS ; 
 int ioread32be (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  iowrite32be (int,int /*<<< orphan*/ *) ; 

void fman_dtsec_start_tx(struct dtsec_regs *regs)
{
	/* clear the graceful stop bit */
	iowrite32be(ioread32be(&regs->tctrl) & ~DTSEC_TCTRL_GTS, &regs->tctrl);
}