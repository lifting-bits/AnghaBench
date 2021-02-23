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
 int /*<<< orphan*/ * _repo ; 
 int /*<<< orphan*/  cl_fixture_cleanup (char const*) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void cleanup_repository(void *path)
{
	git_repository_free(_repo);
	_repo = NULL;

	cl_fixture_cleanup((const char *)path);
}