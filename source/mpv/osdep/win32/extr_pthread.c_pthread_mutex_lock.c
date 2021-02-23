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
struct TYPE_4__ {int /*<<< orphan*/  srw; int /*<<< orphan*/  cs; } ;
struct TYPE_5__ {TYPE_1__ lock; scalar_t__ use_cs; } ;
typedef  TYPE_2__ pthread_mutex_t ;

/* Variables and functions */
 int /*<<< orphan*/  AcquireSRWLockExclusive (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  EnterCriticalSection (int /*<<< orphan*/ *) ; 

int pthread_mutex_lock(pthread_mutex_t *mutex)
{
    if (mutex->use_cs) {
        EnterCriticalSection(&mutex->lock.cs);
    } else {
        AcquireSRWLockExclusive(&mutex->lock.srw);
    }
    return 0;
}