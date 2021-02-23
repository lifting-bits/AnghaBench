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
struct scsi_device {int dummy; } ;

/* Variables and functions */
 int EOPNOTSUPP ; 
 int iscsi_change_queue_depth (struct scsi_device*,int,int) ; 
 int /*<<< orphan*/  ql4xqfulltracking ; 

__attribute__((used)) static int qla4xxx_change_queue_depth(struct scsi_device *sdev, int qdepth,
				      int reason)
{
	if (!ql4xqfulltracking)
		return -EOPNOTSUPP;

	return iscsi_change_queue_depth(sdev, qdepth, reason);
}