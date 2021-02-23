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
struct isp_fc {int /*<<< orphan*/  simqfrozen; int /*<<< orphan*/ * sim; } ;
typedef  int /*<<< orphan*/  ispsoftc_t ;

/* Variables and functions */
 struct isp_fc* ISP_FC_PC (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ISP_LOGDEBUG0 ; 
 int /*<<< orphan*/  SIMQFRZ_LOOPDOWN ; 
 int /*<<< orphan*/  isp_prt (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  xpt_freeze_simq (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  xpt_hold_boot () ; 

__attribute__((used)) static void
isp_freeze_loopdown(ispsoftc_t *isp, int chan)
{
	struct isp_fc *fc = ISP_FC_PC(isp, chan);

	if (fc->sim == NULL)
		return;
	if (fc->simqfrozen == 0) {
		isp_prt(isp, ISP_LOGDEBUG0,
		    "Chan %d Freeze simq (loopdown)", chan);
		fc->simqfrozen = SIMQFRZ_LOOPDOWN;
		xpt_hold_boot();
		xpt_freeze_simq(fc->sim, 1);
	} else {
		isp_prt(isp, ISP_LOGDEBUG0,
		    "Chan %d Mark simq frozen (loopdown)", chan);
		fc->simqfrozen |= SIMQFRZ_LOOPDOWN;
	}
}