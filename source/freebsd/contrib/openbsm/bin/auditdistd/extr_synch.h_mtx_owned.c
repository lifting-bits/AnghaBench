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
 scalar_t__ pthread_mutex_isowned_np (int /*<<< orphan*/ *) ; 

__attribute__((used)) static __inline bool
mtx_owned(pthread_mutex_t *lock)
{

	return (pthread_mutex_isowned_np(lock) != 0);
}