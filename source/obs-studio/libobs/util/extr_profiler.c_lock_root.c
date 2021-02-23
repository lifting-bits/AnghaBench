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
 int /*<<< orphan*/  enabled ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  root_mutex ; 
 int thread_enabled ; 

__attribute__((used)) static bool lock_root(void)
{
	pthread_mutex_lock(&root_mutex);
	if (!enabled) {
		pthread_mutex_unlock(&root_mutex);
		thread_enabled = false;
		return false;
	}

	return true;
}