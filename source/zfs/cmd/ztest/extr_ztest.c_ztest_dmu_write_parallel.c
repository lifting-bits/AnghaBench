#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/  od_object; } ;
typedef  TYPE_1__ ztest_od_t ;
typedef  int /*<<< orphan*/  ztest_ds_t ;
typedef  unsigned long long uint64_t ;

/* Variables and functions */
 int /*<<< orphan*/  B_FALSE ; 
 int /*<<< orphan*/  DMU_OT_UINT64_OTHER ; 
 int /*<<< orphan*/  FTAG ; 
 int /*<<< orphan*/  ID_PARALLEL ; 
 unsigned long long SPA_MAXBLOCKSHIFT ; 
 int /*<<< orphan*/  UMEM_NOFAIL ; 
 int ZTEST_RANGE_LOCKS ; 
 TYPE_1__* umem_alloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  umem_free (TYPE_1__*,int) ; 
 int /*<<< orphan*/  ztest_io (int /*<<< orphan*/ *,int /*<<< orphan*/ ,unsigned long long) ; 
 scalar_t__ ztest_object_init (int /*<<< orphan*/ *,TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ztest_od_init (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 unsigned long long ztest_random (int) ; 

void
ztest_dmu_write_parallel(ztest_ds_t *zd, uint64_t id)
{
	ztest_od_t *od;

	od = umem_alloc(sizeof (ztest_od_t), UMEM_NOFAIL);
	uint64_t offset = (1ULL << (ztest_random(20) + 43)) +
	    (ztest_random(ZTEST_RANGE_LOCKS) << SPA_MAXBLOCKSHIFT);

	/*
	 * Have multiple threads write to large offsets in an object
	 * to verify that parallel writes to an object -- even to the
	 * same blocks within the object -- doesn't cause any trouble.
	 */
	ztest_od_init(od, ID_PARALLEL, FTAG, 0, DMU_OT_UINT64_OTHER, 0, 0, 0);

	if (ztest_object_init(zd, od, sizeof (ztest_od_t), B_FALSE) != 0)
		return;

	while (ztest_random(10) != 0)
		ztest_io(zd, od->od_object, offset);

	umem_free(od, sizeof (ztest_od_t));
}