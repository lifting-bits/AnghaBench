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

/* Variables and functions */
 int /*<<< orphan*/  PTHREAD_REQUIRE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cond ; 
 int /*<<< orphan*/  mutex ; 
 int /*<<< orphan*/  pthread_cond_broadcast (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_cond_wait (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int share ; 

__attribute__((used)) static void *
destroy_after_signal_threadfunc(void *arg)
{
	PTHREAD_REQUIRE(pthread_mutex_lock(&mutex));

	share = 1;
	PTHREAD_REQUIRE(pthread_cond_broadcast(&cond));
	PTHREAD_REQUIRE(pthread_cond_wait(&cond, &mutex));

	PTHREAD_REQUIRE(pthread_mutex_unlock(&mutex));

	return NULL;
}