#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  sem; int /*<<< orphan*/  cnt; } ;
typedef  TYPE_1__ fastlock_t ;

/* Variables and functions */
 scalar_t__ atomic_fetch_add (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  sem_wait (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void fastlock_acquire(fastlock_t *lock)
{
	if (atomic_fetch_add(&lock->cnt, 1) > 0)
		sem_wait(&lock->sem);
}