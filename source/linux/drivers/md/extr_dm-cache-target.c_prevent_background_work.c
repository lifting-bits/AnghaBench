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
struct cache {int /*<<< orphan*/  background_work_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  down_write (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lockdep_off () ; 
 int /*<<< orphan*/  lockdep_on () ; 

__attribute__((used)) static void prevent_background_work(struct cache *cache)
{
	lockdep_off();
	down_write(&cache->background_work_lock);
	lockdep_on();
}