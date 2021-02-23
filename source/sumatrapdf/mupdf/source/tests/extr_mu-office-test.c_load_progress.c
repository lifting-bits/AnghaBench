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
 int /*<<< orphan*/  ReleaseSemaphore (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int,int) ; 
 int /*<<< orphan*/  loaded ; 
 int /*<<< orphan*/  stderr ; 

__attribute__((used)) static void
load_progress(void *cookie, int pages_loaded, int complete)
{
	assert((intptr_t)cookie == 1234);

	fprintf(stderr, "load_progress: pages_loaded=%d complete=%d\n", pages_loaded, complete);

	if (complete)
		(void)ReleaseSemaphore(loaded, 1, NULL);
}