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
 int /*<<< orphan*/  scsi_internal_device_block (struct scsi_device*) ; 

__attribute__((used)) static void
mptsas_block_io_sdev(struct scsi_device *sdev, void *data)
{
	scsi_internal_device_block(sdev);
}