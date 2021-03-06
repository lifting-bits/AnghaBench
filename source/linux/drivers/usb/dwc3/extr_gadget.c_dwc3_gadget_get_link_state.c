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
struct dwc3 {int /*<<< orphan*/  regs; } ;

/* Variables and functions */
 int /*<<< orphan*/  DWC3_DSTS ; 
 int DWC3_DSTS_USBLNKST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dwc3_readl (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int dwc3_gadget_get_link_state(struct dwc3 *dwc)
{
	u32		reg;

	reg = dwc3_readl(dwc->regs, DWC3_DSTS);

	return DWC3_DSTS_USBLNKST(reg);
}