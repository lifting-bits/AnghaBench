#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ztest_ds_t ;
struct TYPE_12__ {int /*<<< orphan*/  vdev_guid; } ;
typedef  TYPE_1__ vdev_t ;
typedef  int /*<<< orphan*/  uint64_t ;
struct TYPE_13__ {int /*<<< orphan*/ * spa_vdev_removal; } ;
typedef  TYPE_2__ spa_t ;

/* Variables and functions */
 scalar_t__ B_FALSE ; 
 scalar_t__ B_TRUE ; 
 int /*<<< orphan*/  FTAG ; 
 int /*<<< orphan*/  POOL_SCAN_SCRUB ; 
 int /*<<< orphan*/  RW_READER ; 
 int /*<<< orphan*/  SCL_VDEV ; 
 scalar_t__ dsl_scan_scrubbing (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_enter (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_exit (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spa_config_enter (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spa_config_exit (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spa_get_dsl (TYPE_2__*) ; 
 int spa_scan (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int spa_vdev_remove (TYPE_2__*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  txg_wait_synced (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_1__* vdev_lookup_top (TYPE_2__*,int /*<<< orphan*/ ) ; 
 scalar_t__ ztest_device_removal_active ; 
 int /*<<< orphan*/  ztest_random_vdev_top (TYPE_2__*,scalar_t__) ; 
 TYPE_2__* ztest_spa ; 
 int /*<<< orphan*/  ztest_vdev_lock ; 

void
ztest_device_removal(ztest_ds_t *zd, uint64_t id)
{
	spa_t *spa = ztest_spa;
	vdev_t *vd;
	uint64_t guid;
	int error;

	mutex_enter(&ztest_vdev_lock);

	if (ztest_device_removal_active) {
		mutex_exit(&ztest_vdev_lock);
		return;
	}

	/*
	 * Remove a random top-level vdev and wait for removal to finish.
	 */
	spa_config_enter(spa, SCL_VDEV, FTAG, RW_READER);
	vd = vdev_lookup_top(spa, ztest_random_vdev_top(spa, B_FALSE));
	guid = vd->vdev_guid;
	spa_config_exit(spa, SCL_VDEV, FTAG);

	error = spa_vdev_remove(spa, guid, B_FALSE);
	if (error == 0) {
		ztest_device_removal_active = B_TRUE;
		mutex_exit(&ztest_vdev_lock);

		while (spa->spa_vdev_removal != NULL)
			txg_wait_synced(spa_get_dsl(spa), 0);
	} else {
		mutex_exit(&ztest_vdev_lock);
		return;
	}

	/*
	 * The pool needs to be scrubbed after completing device removal.
	 * Failure to do so may result in checksum errors due to the
	 * strategy employed by ztest_fault_inject() when selecting which
	 * offset are redundant and can be damaged.
	 */
	error = spa_scan(spa, POOL_SCAN_SCRUB);
	if (error == 0) {
		while (dsl_scan_scrubbing(spa_get_dsl(spa)))
			txg_wait_synced(spa_get_dsl(spa), 0);
	}

	mutex_enter(&ztest_vdev_lock);
	ztest_device_removal_active = B_FALSE;
	mutex_exit(&ztest_vdev_lock);
}