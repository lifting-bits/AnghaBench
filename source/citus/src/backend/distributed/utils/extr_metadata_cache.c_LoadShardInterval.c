#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint64 ;
struct TYPE_5__ {int isDistributedTable; size_t shardIntervalArrayLength; int /*<<< orphan*/ ** sortedShardIntervalArray; } ;
struct TYPE_4__ {size_t shardIndex; TYPE_2__* tableEntry; } ;
typedef  int /*<<< orphan*/  ShardInterval ;
typedef  TYPE_1__ ShardCacheEntry ;
typedef  TYPE_2__ DistTableCacheEntry ;

/* Variables and functions */
 int /*<<< orphan*/  Assert (int) ; 
 int /*<<< orphan*/  CopyShardInterval (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 TYPE_1__* LookupShardCacheEntry (int /*<<< orphan*/ ) ; 
 scalar_t__ palloc0 (int) ; 

ShardInterval *
LoadShardInterval(uint64 shardId)
{
	ShardInterval *shardInterval = NULL;
	ShardInterval *sourceShardInterval = NULL;
	ShardCacheEntry *shardEntry = NULL;
	DistTableCacheEntry *tableEntry = NULL;

	shardEntry = LookupShardCacheEntry(shardId);

	tableEntry = shardEntry->tableEntry;

	Assert(tableEntry->isDistributedTable);

	/* the offset better be in a valid range */
	Assert(shardEntry->shardIndex < tableEntry->shardIntervalArrayLength);

	sourceShardInterval = tableEntry->sortedShardIntervalArray[shardEntry->shardIndex];

	/* copy value to return */
	shardInterval = (ShardInterval *) palloc0(sizeof(ShardInterval));
	CopyShardInterval(sourceShardInterval, shardInterval);

	return shardInterval;
}