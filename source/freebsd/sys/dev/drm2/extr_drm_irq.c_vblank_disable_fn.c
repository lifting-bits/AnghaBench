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
struct drm_device {int num_crtcs; int /*<<< orphan*/  vbl_lock; scalar_t__* vblank_enabled; int /*<<< orphan*/ * vblank_refcount; int /*<<< orphan*/  vblank_disable_allowed; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_DEBUG (char*,int) ; 
 scalar_t__ atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mtx_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mtx_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vblank_disable_and_save (struct drm_device*,int) ; 

__attribute__((used)) static void vblank_disable_fn(void *arg)
{
	struct drm_device *dev = (struct drm_device *)arg;
	int i;

	if (!dev->vblank_disable_allowed)
		return;

	for (i = 0; i < dev->num_crtcs; i++) {
		mtx_lock(&dev->vbl_lock);
		if (atomic_read(&dev->vblank_refcount[i]) == 0 &&
		    dev->vblank_enabled[i]) {
			DRM_DEBUG("disabling vblank on crtc %d\n", i);
			vblank_disable_and_save(dev, i);
		}
		mtx_unlock(&dev->vbl_lock);
	}
}