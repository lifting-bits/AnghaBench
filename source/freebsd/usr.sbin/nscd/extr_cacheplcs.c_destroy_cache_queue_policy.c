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
struct cache_queue_policy_item_ {int dummy; } ;
struct cache_queue_policy_ {int /*<<< orphan*/  head; } ;
struct cache_policy_item_ {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  TAILQ_EMPTY (int /*<<< orphan*/ *) ; 
 struct cache_queue_policy_item_* TAILQ_FIRST (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TAILQ_REMOVE (int /*<<< orphan*/ *,struct cache_queue_policy_item_*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRACE_IN (void (*) (struct cache_queue_policy_*)) ; 
 int /*<<< orphan*/  TRACE_OUT (void (*) (struct cache_queue_policy_*)) ; 
 int /*<<< orphan*/  cache_queue_policy_destroy_item (struct cache_policy_item_*) ; 
 int /*<<< orphan*/  entries ; 
 int /*<<< orphan*/  free (struct cache_queue_policy_*) ; 

__attribute__((used)) static void
destroy_cache_queue_policy(struct cache_queue_policy_ *queue_policy)
{
	struct cache_queue_policy_item_	*queue_item;

	TRACE_IN(destroy_cache_queue_policy);
	while (!TAILQ_EMPTY(&queue_policy->head)) {
		queue_item = TAILQ_FIRST(&queue_policy->head);
		TAILQ_REMOVE(&queue_policy->head, queue_item, entries);
		cache_queue_policy_destroy_item(
			(struct cache_policy_item_ *)queue_item);
	}
	free(queue_policy);
	TRACE_OUT(destroy_cache_queue_policy);
}