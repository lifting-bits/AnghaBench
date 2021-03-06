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
struct drm_master {int /*<<< orphan*/  refcount; } ;

/* Variables and functions */
 int /*<<< orphan*/  drm_master_destroy (struct drm_master*) ; 
 scalar_t__ refcount_release (int /*<<< orphan*/ *) ; 

void drm_master_put(struct drm_master **master)
{
	if (refcount_release(&(*master)->refcount))
		drm_master_destroy(*master);
	*master = NULL;
}