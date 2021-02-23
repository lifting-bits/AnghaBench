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
typedef  int /*<<< orphan*/  zio_t ;
typedef  scalar_t__ uint64_t ;
typedef  int /*<<< orphan*/  spa_t ;
typedef  enum zio_stage { ____Placeholder_zio_stage } zio_stage ;
typedef  enum zio_flag { ____Placeholder_zio_flag } zio_flag ;
typedef  int /*<<< orphan*/  blkptr_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 scalar_t__ BP_GET_DEDUP (int /*<<< orphan*/  const*) ; 
 scalar_t__ BP_IS_EMBEDDED (int /*<<< orphan*/  const*) ; 
 scalar_t__ BP_IS_GANG (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  BP_IS_HOLE (int /*<<< orphan*/  const*) ; 
 int ZIO_FLAG_DONT_QUEUE ; 
 int ZIO_FREE_PIPELINE ; 
 int /*<<< orphan*/  ZIO_PRIORITY_NOW ; 
 int ZIO_STAGE_ISSUE_ASYNC ; 
 int /*<<< orphan*/  ZIO_STAGE_OPEN ; 
 int ZIO_STAGE_VDEV_IO_ASSESS ; 
 int ZIO_STAGE_VDEV_IO_START ; 
 int /*<<< orphan*/  ZIO_TYPE_FREE ; 
 int /*<<< orphan*/  arc_freed (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  dsl_scan_freed (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  metaslab_check_free (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 scalar_t__ spa_sync_pass (int /*<<< orphan*/ *) ; 
 scalar_t__ spa_syncing_txg (int /*<<< orphan*/ *) ; 
 scalar_t__ zfs_sync_pass_deferred_free ; 
 scalar_t__ zfs_trim_enabled ; 
 int /*<<< orphan*/ * zio_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/  const*,int /*<<< orphan*/ *,scalar_t__,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * zio_null (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

zio_t *
zio_free_sync(zio_t *pio, spa_t *spa, uint64_t txg, const blkptr_t *bp,
    uint64_t size, enum zio_flag flags)
{
	zio_t *zio;
	enum zio_stage stage = ZIO_FREE_PIPELINE;

	ASSERT(!BP_IS_HOLE(bp));
	ASSERT(spa_syncing_txg(spa) == txg);
	ASSERT(spa_sync_pass(spa) < zfs_sync_pass_deferred_free);

	if (BP_IS_EMBEDDED(bp))
		return (zio_null(pio, spa, NULL, NULL, NULL, 0));

	metaslab_check_free(spa, bp);
	arc_freed(spa, bp);
	dsl_scan_freed(spa, bp);

	if (zfs_trim_enabled)
		stage |= ZIO_STAGE_ISSUE_ASYNC | ZIO_STAGE_VDEV_IO_START |
		    ZIO_STAGE_VDEV_IO_ASSESS;
	/*
	 * GANG and DEDUP blocks can induce a read (for the gang block header,
	 * or the DDT), so issue them asynchronously so that this thread is
	 * not tied up.
	 */
	else if (BP_IS_GANG(bp) || BP_GET_DEDUP(bp))
		stage |= ZIO_STAGE_ISSUE_ASYNC;

	flags |= ZIO_FLAG_DONT_QUEUE;

	zio = zio_create(pio, spa, txg, bp, NULL, size,
	    size, NULL, NULL, ZIO_TYPE_FREE, ZIO_PRIORITY_NOW,
	    flags, NULL, 0, NULL, ZIO_STAGE_OPEN, stage);

	return (zio);
}