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
struct panel_info {int /*<<< orphan*/  height_mm; int /*<<< orphan*/  width_mm; } ;
struct drm_device {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  TMD_PANEL_HEIGHT ; 
 int /*<<< orphan*/  TMD_PANEL_WIDTH ; 

__attribute__((used)) static int tmd_vid_get_panel_info(struct drm_device *dev,
				int pipe,
				struct panel_info *pi)
{
	if (!dev || !pi)
		return -EINVAL;

	pi->width_mm = TMD_PANEL_WIDTH;
	pi->height_mm = TMD_PANEL_HEIGHT;

	return 0;
}