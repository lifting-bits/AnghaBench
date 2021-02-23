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
struct dr_helper {int thread_valid; int /*<<< orphan*/  thread_lock; int /*<<< orphan*/  thread; } ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int pthread_equal (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_self () ; 

void dr_helper_release_thread(struct dr_helper *dr)
{
    pthread_mutex_lock(&dr->thread_lock);
    // Fails on API user errors.
    assert(dr->thread_valid);
    assert(pthread_equal(dr->thread, pthread_self()));
    dr->thread_valid = false;
    pthread_mutex_unlock(&dr->thread_lock);
}