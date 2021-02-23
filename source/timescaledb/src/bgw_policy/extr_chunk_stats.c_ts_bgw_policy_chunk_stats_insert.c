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
typedef  int /*<<< orphan*/  Relation ;
typedef  int /*<<< orphan*/  Catalog ;
typedef  int /*<<< orphan*/  BgwPolicyChunkStats ;

/* Variables and functions */
 int /*<<< orphan*/  BGW_POLICY_CHUNK_STATS ; 
 int /*<<< orphan*/  RowExclusiveLock ; 
 int /*<<< orphan*/  catalog_get_table_id (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  heap_close (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  heap_open (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ts_bgw_policy_chunk_stats_insert_with_relation (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * ts_catalog_get () ; 

void
ts_bgw_policy_chunk_stats_insert(BgwPolicyChunkStats *chunk_stats)
{
	Catalog *catalog = ts_catalog_get();
	Relation rel =
		heap_open(catalog_get_table_id(catalog, BGW_POLICY_CHUNK_STATS), RowExclusiveLock);

	ts_bgw_policy_chunk_stats_insert_with_relation(rel, chunk_stats);
	heap_close(rel, RowExclusiveLock);
}