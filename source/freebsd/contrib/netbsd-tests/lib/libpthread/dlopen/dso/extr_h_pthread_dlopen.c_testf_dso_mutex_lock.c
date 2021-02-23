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
 int /*<<< orphan*/  ATF_REQUIRE (int) ; 
 scalar_t__ pthread_mutex_lock (int /*<<< orphan*/ *) ; 

int
testf_dso_mutex_lock(pthread_mutex_t *mtx)
{
	ATF_REQUIRE(mtx != NULL);
	ATF_REQUIRE(pthread_mutex_lock(mtx) == 0);

	return 0xcafe;
}