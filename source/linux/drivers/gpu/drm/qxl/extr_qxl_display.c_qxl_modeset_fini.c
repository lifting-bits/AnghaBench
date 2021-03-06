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
struct qxl_device {int /*<<< orphan*/  ddev; } ;

/* Variables and functions */
 int /*<<< orphan*/  drm_mode_config_cleanup (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  qxl_destroy_monitors_object (struct qxl_device*) ; 

void qxl_modeset_fini(struct qxl_device *qdev)
{
	qxl_destroy_monitors_object(qdev);
	drm_mode_config_cleanup(&qdev->ddev);
}