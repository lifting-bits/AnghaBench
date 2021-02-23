#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {TYPE_1__* DebugInfo; } ;
struct NBNameCache {int /*<<< orphan*/  heap; scalar_t__ head; TYPE_2__ cs; } ;
struct TYPE_3__ {scalar_t__* Spare; } ;

/* Variables and functions */
 int /*<<< orphan*/  DeleteCriticalSection (TYPE_2__*) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct NBNameCache*) ; 
 int /*<<< orphan*/  NBNameCacheUnlinkNode (struct NBNameCache*,scalar_t__*) ; 

void NBNameCacheDestroy(struct NBNameCache *cache)
{
    if (cache)
    {
        cache->cs.DebugInfo->Spare[0] = 0;
        DeleteCriticalSection(&cache->cs);
        while (cache->head)
            NBNameCacheUnlinkNode(cache, &cache->head);
        HeapFree(cache->heap, 0, cache);
    }
}