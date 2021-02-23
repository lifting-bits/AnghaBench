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
typedef  int /*<<< orphan*/  git_reference ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_HEAD_FILE ; 
 int /*<<< orphan*/  cl_assert_equal_oid (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  current_head_target ; 
 int /*<<< orphan*/  g_repo ; 
 int /*<<< orphan*/  git_reference_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_reference_resolve (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_target (int /*<<< orphan*/ *) ; 

void test_refs_read__master_then_head(void)
{
	/* lookup the master branch and then the HEAD */
	git_reference *reference, *master_ref, *resolved_ref;

	cl_git_pass(git_reference_lookup(&master_ref, g_repo, current_head_target));
	cl_git_pass(git_reference_lookup(&reference, g_repo, GIT_HEAD_FILE));

	cl_git_pass(git_reference_resolve(&resolved_ref, reference));
	cl_assert_equal_oid(git_reference_target(master_ref), git_reference_target(resolved_ref));

	git_reference_free(reference);
	git_reference_free(resolved_ref);
	git_reference_free(master_ref);
}