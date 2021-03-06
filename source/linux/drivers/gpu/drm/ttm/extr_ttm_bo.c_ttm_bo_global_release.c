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
struct ttm_bo_global {int /*<<< orphan*/  kobj; } ;

/* Variables and functions */
 int /*<<< orphan*/  kobject_del (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kobject_put (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (struct ttm_bo_global*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct ttm_bo_global ttm_bo_glob ; 
 scalar_t__ ttm_bo_glob_use_count ; 
 int /*<<< orphan*/  ttm_global_mutex ; 
 int /*<<< orphan*/  ttm_mem_glob ; 
 int /*<<< orphan*/  ttm_mem_global_release (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void ttm_bo_global_release(void)
{
	struct ttm_bo_global *glob = &ttm_bo_glob;

	mutex_lock(&ttm_global_mutex);
	if (--ttm_bo_glob_use_count > 0)
		goto out;

	kobject_del(&glob->kobj);
	kobject_put(&glob->kobj);
	ttm_mem_global_release(&ttm_mem_glob);
	memset(glob, 0, sizeof(*glob));
out:
	mutex_unlock(&ttm_global_mutex);
}