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
struct drm_mode_object {int /*<<< orphan*/  id; } ;
struct TYPE_2__ {int /*<<< orphan*/  crtc_names; } ;
struct drm_device {TYPE_1__ mode_config; } ;

/* Variables and functions */
 int /*<<< orphan*/  drm_gem_names_remove (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void drm_mode_object_put(struct drm_device *dev,
				struct drm_mode_object *object)
{

	drm_gem_names_remove(&dev->mode_config.crtc_names, object->id);
}