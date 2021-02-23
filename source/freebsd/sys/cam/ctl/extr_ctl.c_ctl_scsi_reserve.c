#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  union ctl_io {int dummy; } ctl_io ;
typedef  scalar_t__ uint32_t ;
struct TYPE_2__ {int /*<<< orphan*/  nexus; } ;
struct ctl_scsiio {TYPE_1__ io_hdr; } ;
struct ctl_lun {int flags; scalar_t__ res_idx; int /*<<< orphan*/  lun_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  CTL_DEBUG_PRINT (char*) ; 
 struct ctl_lun* CTL_LUN (struct ctl_scsiio*) ; 
 int CTL_LUN_PR_RESERVED ; 
 int CTL_LUN_RESERVED ; 
 int CTL_RETVAL_COMPLETE ; 
 int /*<<< orphan*/  ctl_done (union ctl_io*) ; 
 scalar_t__ ctl_get_initindex (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ctl_set_reservation_conflict (struct ctl_scsiio*) ; 
 int /*<<< orphan*/  ctl_set_success (struct ctl_scsiio*) ; 
 int /*<<< orphan*/  mtx_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mtx_unlock (int /*<<< orphan*/ *) ; 

int
ctl_scsi_reserve(struct ctl_scsiio *ctsio)
{
	struct ctl_lun *lun = CTL_LUN(ctsio);
	uint32_t residx;

	CTL_DEBUG_PRINT(("ctl_reserve\n"));

	residx = ctl_get_initindex(&ctsio->io_hdr.nexus);

	/*
	 * XXX KDM right now, we only support LUN reservation.  We don't
	 * support 3rd party reservations, or extent reservations, which
	 * might actually need the parameter list.  If we've gotten this
	 * far, we've got a LUN reservation.  Anything else got kicked out
	 * above.  So, according to SPC, ignore the length.
	 */

	mtx_lock(&lun->lun_lock);
	if ((lun->flags & CTL_LUN_RESERVED) && (lun->res_idx != residx)) {
		ctl_set_reservation_conflict(ctsio);
		goto bailout;
	}

	/* SPC-3 exceptions to SPC-2 RESERVE and RELEASE behavior. */
	if (lun->flags & CTL_LUN_PR_RESERVED) {
		ctl_set_success(ctsio);
		goto bailout;
	}

	lun->flags |= CTL_LUN_RESERVED;
	lun->res_idx = residx;
	ctl_set_success(ctsio);

bailout:
	mtx_unlock(&lun->lun_lock);
	ctl_done((union ctl_io *)ctsio);
	return (CTL_RETVAL_COMPLETE);
}