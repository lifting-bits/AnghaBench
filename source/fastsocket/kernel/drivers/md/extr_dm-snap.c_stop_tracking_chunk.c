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
struct dm_snapshot {int /*<<< orphan*/  tracked_chunk_pool; int /*<<< orphan*/  tracked_chunk_lock; } ;
struct dm_snap_tracked_chunk {int /*<<< orphan*/  node; } ;

/* Variables and functions */
 int /*<<< orphan*/  hlist_del (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mempool_free (struct dm_snap_tracked_chunk*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void stop_tracking_chunk(struct dm_snapshot *s,
				struct dm_snap_tracked_chunk *c)
{
	unsigned long flags;

	spin_lock_irqsave(&s->tracked_chunk_lock, flags);
	hlist_del(&c->node);
	spin_unlock_irqrestore(&s->tracked_chunk_lock, flags);

	mempool_free(c, s->tracked_chunk_pool);
}