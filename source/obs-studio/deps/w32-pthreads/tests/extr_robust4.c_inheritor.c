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
 scalar_t__ EOWNERDEAD ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  lockCount ; 
 int /*<<< orphan*/ * mutex ; 
 scalar_t__ pthread_mutex_consistent (int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_mutex_unlock (int /*<<< orphan*/ *) ; 

void * inheritor(void * arg)
{
  int* o = (int*)arg;

  assert(pthread_mutex_lock(&mutex[o[0]]) == EOWNERDEAD);
  lockCount++;
  assert(pthread_mutex_lock(&mutex[o[1]]) == EOWNERDEAD);
  lockCount++;
  assert(pthread_mutex_lock(&mutex[o[2]]) == EOWNERDEAD);
  lockCount++;
  assert(pthread_mutex_consistent(&mutex[o[2]]) == 0);
  assert(pthread_mutex_consistent(&mutex[o[1]]) == 0);
  assert(pthread_mutex_consistent(&mutex[o[0]]) == 0);
  assert(pthread_mutex_unlock(&mutex[o[2]]) == 0);
  assert(pthread_mutex_unlock(&mutex[o[1]]) == 0);
  assert(pthread_mutex_unlock(&mutex[o[0]]) == 0);

  return 0;
}