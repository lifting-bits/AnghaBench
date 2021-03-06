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
struct pool {int /*<<< orphan*/  pmd; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ PM_WRITE ; 
 int dm_pool_commit_metadata (int /*<<< orphan*/ ) ; 
 scalar_t__ get_pool_mode (struct pool*) ; 
 int /*<<< orphan*/  metadata_operation_failed (struct pool*,char*,int) ; 

__attribute__((used)) static int commit(struct pool *pool)
{
	int r;

	if (get_pool_mode(pool) != PM_WRITE)
		return -EINVAL;

	r = dm_pool_commit_metadata(pool->pmd);
	if (r)
		metadata_operation_failed(pool, "dm_pool_commit_metadata", r);

	return r;
}