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
struct scsi_device {int queue_depth; } ;

/* Variables and functions */
 int EOPNOTSUPP ; 
#define  SCSI_QDEPTH_DEFAULT 130 
#define  SCSI_QDEPTH_QFULL 129 
#define  SCSI_QDEPTH_RAMP_UP 128 
 int /*<<< orphan*/  qla2x00_adjust_sdev_qdepth_up (struct scsi_device*,int) ; 
 int /*<<< orphan*/  qla2x00_handle_queue_full (struct scsi_device*,int) ; 
 int /*<<< orphan*/  scsi_adjust_queue_depth (struct scsi_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  scsi_get_tag_type (struct scsi_device*) ; 

__attribute__((used)) static int
qla2x00_change_queue_depth(struct scsi_device *sdev, int qdepth, int reason)
{
	switch (reason) {
	case SCSI_QDEPTH_DEFAULT:
		scsi_adjust_queue_depth(sdev, scsi_get_tag_type(sdev), qdepth);
		break;
	case SCSI_QDEPTH_QFULL:
		qla2x00_handle_queue_full(sdev, qdepth);
		break;
	case SCSI_QDEPTH_RAMP_UP:
		qla2x00_adjust_sdev_qdepth_up(sdev, qdepth);
		break;
	default:
		return -EOPNOTSUPP;
	}

	return sdev->queue_depth;
}