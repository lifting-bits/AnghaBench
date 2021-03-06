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
struct drm_minor {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  NOUVEAU_DEBUGFS_ENTRIES ; 
 int /*<<< orphan*/  drm_debugfs_remove_files (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct drm_minor*) ; 
 int /*<<< orphan*/  nouveau_debugfs_list ; 

void
nouveau_debugfs_takedown(struct drm_minor *minor)
{
	drm_debugfs_remove_files(nouveau_debugfs_list, NOUVEAU_DEBUGFS_ENTRIES,
				 minor);
}