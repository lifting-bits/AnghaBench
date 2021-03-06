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
struct pqi_scsi_dev {scalar_t__ in_remove; } ;
struct pqi_ctrl_info {int /*<<< orphan*/  in_shutdown; } ;

/* Variables and functions */

__attribute__((used)) static inline bool pqi_device_in_remove(struct pqi_ctrl_info *ctrl_info,
					struct pqi_scsi_dev *device)
{
	return device->in_remove && !ctrl_info->in_shutdown;
}