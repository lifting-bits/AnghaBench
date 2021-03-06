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
struct drm_global_item {scalar_t__ refcount; int /*<<< orphan*/ * object; int /*<<< orphan*/  mutex; } ;

/* Variables and functions */
 int DRM_GLOBAL_NUM ; 
 struct drm_global_item* glob ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 

void drm_global_init(void)
{
	int i;

	for (i = 0; i < DRM_GLOBAL_NUM; ++i) {
		struct drm_global_item *item = &glob[i];
		mutex_init(&item->mutex);
		item->object = NULL;
		item->refcount = 0;
	}
}