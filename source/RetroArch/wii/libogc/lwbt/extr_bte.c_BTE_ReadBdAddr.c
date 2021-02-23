#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct bd_addr {int dummy; } ;
typedef  int /*<<< orphan*/  s32 ;
typedef  int /*<<< orphan*/  btecallback ;
struct TYPE_3__ {scalar_t__ hci_cmddone; struct bd_addr* usrdata; int /*<<< orphan*/  cb; } ;

/* Variables and functions */
 int /*<<< orphan*/  ERR_OK ; 
 int /*<<< orphan*/  _CPU_ISR_Disable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _CPU_ISR_Restore (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bte_read_bd_addr_complete ; 
 TYPE_1__ btstate ; 
 int /*<<< orphan*/  hci_arg (TYPE_1__*) ; 
 int /*<<< orphan*/  hci_cmd_complete (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hci_read_bd_addr () ; 

s32 BTE_ReadBdAddr(struct bd_addr *bdaddr, btecallback cb)
{
    u32 level;

    _CPU_ISR_Disable(level);
    btstate.cb = cb;
    btstate.usrdata = bdaddr;
    btstate.hci_cmddone = 0;
    hci_arg(&btstate);
    hci_cmd_complete(bte_read_bd_addr_complete);
    hci_read_bd_addr();
    _CPU_ISR_Restore(level);

    return ERR_OK;
}