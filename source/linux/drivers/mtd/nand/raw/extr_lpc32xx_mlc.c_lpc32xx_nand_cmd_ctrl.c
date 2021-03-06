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
struct nand_chip {int dummy; } ;
struct lpc32xx_nand_host {int /*<<< orphan*/  io_base; } ;

/* Variables and functions */
 int /*<<< orphan*/  MLC_ADDR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MLC_CMD (int /*<<< orphan*/ ) ; 
 unsigned int NAND_CLE ; 
 int NAND_CMD_NONE ; 
 struct lpc32xx_nand_host* nand_get_controller_data (struct nand_chip*) ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void lpc32xx_nand_cmd_ctrl(struct nand_chip *nand_chip, int cmd,
				  unsigned int ctrl)
{
	struct lpc32xx_nand_host *host = nand_get_controller_data(nand_chip);

	if (cmd != NAND_CMD_NONE) {
		if (ctrl & NAND_CLE)
			writel(cmd, MLC_CMD(host->io_base));
		else
			writel(cmd, MLC_ADDR(host->io_base));
	}
}