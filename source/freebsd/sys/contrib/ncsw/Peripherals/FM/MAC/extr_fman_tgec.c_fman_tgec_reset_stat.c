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
typedef  int uint32_t ;
struct tgec_regs {int /*<<< orphan*/  command_config; } ;

/* Variables and functions */
 int CMD_CFG_STAT_CLR ; 
 int ioread32be (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  iowrite32be (int,int /*<<< orphan*/ *) ; 

void fman_tgec_reset_stat(struct tgec_regs *regs)
{
	uint32_t tmp;

	tmp = ioread32be(&regs->command_config);

	tmp |= CMD_CFG_STAT_CLR;

	iowrite32be(tmp, &regs->command_config);

	while (ioread32be(&regs->command_config) & CMD_CFG_STAT_CLR) ;
}