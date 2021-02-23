#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_5__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {scalar_t__ spa_checkpoint_txg; int /*<<< orphan*/ * spa_vdev_removal; } ;
typedef  TYPE_1__ spa_t ;
typedef  int /*<<< orphan*/  dmu_tx_t ;
struct TYPE_7__ {TYPE_1__* dp_spa; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENOTSUP ; 
 int SET_ERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SPA_FEATURE_POOL_CHECKPOINT ; 
 int /*<<< orphan*/  ZFS_ERR_CHECKPOINT_EXISTS ; 
 int /*<<< orphan*/  ZFS_ERR_DEVRM_IN_PROGRESS ; 
 int /*<<< orphan*/  ZFS_ERR_DISCARDING_CHECKPOINT ; 
 int /*<<< orphan*/  ZFS_ERR_VDEV_TOO_BIG ; 
 TYPE_5__* dmu_tx_pool (int /*<<< orphan*/ *) ; 
 scalar_t__ spa_feature_is_active (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spa_feature_is_enabled (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spa_top_vdevs_spacemap_addressable (TYPE_1__*) ; 

__attribute__((used)) static int
spa_checkpoint_check(void *arg, dmu_tx_t *tx)
{
	spa_t *spa = dmu_tx_pool(tx)->dp_spa;

	if (!spa_feature_is_enabled(spa, SPA_FEATURE_POOL_CHECKPOINT))
		return (SET_ERROR(ENOTSUP));

	if (!spa_top_vdevs_spacemap_addressable(spa))
		return (SET_ERROR(ZFS_ERR_VDEV_TOO_BIG));

	if (spa->spa_vdev_removal != NULL)
		return (SET_ERROR(ZFS_ERR_DEVRM_IN_PROGRESS));

	if (spa->spa_checkpoint_txg != 0)
		return (SET_ERROR(ZFS_ERR_CHECKPOINT_EXISTS));

	if (spa_feature_is_active(spa, SPA_FEATURE_POOL_CHECKPOINT))
		return (SET_ERROR(ZFS_ERR_DISCARDING_CHECKPOINT));

	return (0);
}