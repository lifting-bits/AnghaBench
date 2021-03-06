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
typedef  int u16 ;
struct hinic_hwif {int dummy; } ;
struct hinic_api_cmd_chain {int /*<<< orphan*/  cell_size; int /*<<< orphan*/  chain_type; struct hinic_hwif* hwif; } ;

/* Variables and functions */
 int /*<<< orphan*/  AEQE_EN ; 
 int API_CMD_CELL_SIZE_VAL (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CELL_SIZE ; 
 int HINIC_API_CMD_CHAIN_CTRL_CLEAR (int,int /*<<< orphan*/ ) ; 
 int HINIC_API_CMD_CHAIN_CTRL_SET (int,int /*<<< orphan*/ ) ; 
 int HINIC_CSR_API_CMD_CHAIN_CTRL_ADDR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RESTART_WB_STAT ; 
 int XOR_CHK_ALL ; 
 int /*<<< orphan*/  XOR_CHK_EN ; 
 int /*<<< orphan*/  XOR_ERR ; 
 int hinic_hwif_read_reg (struct hinic_hwif*,int) ; 
 int /*<<< orphan*/  hinic_hwif_write_reg (struct hinic_hwif*,int,int) ; 

__attribute__((used)) static void api_cmd_ctrl_init(struct hinic_api_cmd_chain *chain)
{
	struct hinic_hwif *hwif = chain->hwif;
	u32 addr, ctrl;
	u16 cell_size;

	/* Read Modify Write */
	addr = HINIC_CSR_API_CMD_CHAIN_CTRL_ADDR(chain->chain_type);

	cell_size = API_CMD_CELL_SIZE_VAL(chain->cell_size);

	ctrl = hinic_hwif_read_reg(hwif, addr);

	ctrl =  HINIC_API_CMD_CHAIN_CTRL_CLEAR(ctrl, RESTART_WB_STAT) &
		HINIC_API_CMD_CHAIN_CTRL_CLEAR(ctrl, XOR_ERR)         &
		HINIC_API_CMD_CHAIN_CTRL_CLEAR(ctrl, AEQE_EN)         &
		HINIC_API_CMD_CHAIN_CTRL_CLEAR(ctrl, XOR_CHK_EN)      &
		HINIC_API_CMD_CHAIN_CTRL_CLEAR(ctrl, CELL_SIZE);

	ctrl |= HINIC_API_CMD_CHAIN_CTRL_SET(1, XOR_ERR)              |
		HINIC_API_CMD_CHAIN_CTRL_SET(XOR_CHK_ALL, XOR_CHK_EN) |
		HINIC_API_CMD_CHAIN_CTRL_SET(cell_size, CELL_SIZE);

	hinic_hwif_write_reg(hwif, addr, ctrl);
}