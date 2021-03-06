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
struct scsi_cmnd {int /*<<< orphan*/  allowed; } ;
struct ata_queued_cmd {int /*<<< orphan*/  err_mask; struct scsi_cmnd* scsicmd; } ;

/* Variables and functions */
 int /*<<< orphan*/  __ata_eh_qc_complete (struct ata_queued_cmd*) ; 

void ata_eh_qc_retry(struct ata_queued_cmd *qc)
{
	struct scsi_cmnd *scmd = qc->scsicmd;
	if (!qc->err_mask)
		scmd->allowed++;
	__ata_eh_qc_complete(qc);
}