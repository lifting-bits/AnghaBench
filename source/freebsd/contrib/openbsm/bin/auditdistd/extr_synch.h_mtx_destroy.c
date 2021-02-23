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
typedef  int /*<<< orphan*/  pthread_mutex_t ;

/* Variables and functions */
 int /*<<< orphan*/  PJDLOG_ASSERT (int) ; 
 int pthread_mutex_destroy (int /*<<< orphan*/ *) ; 

__attribute__((used)) static __inline void
mtx_destroy(pthread_mutex_t *lock)
{
	int error;

	error = pthread_mutex_destroy(lock);
	PJDLOG_ASSERT(error == 0);
}