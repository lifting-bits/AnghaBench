#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_5__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {char* parent_path; } ;
typedef  TYPE_1__ git_worktree ;
struct TYPE_7__ {int /*<<< orphan*/  repo; } ;

/* Variables and functions */
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 TYPE_5__ fixture ; 
 int /*<<< orphan*/  git__free (char*) ; 
 int /*<<< orphan*/  git_worktree_free (TYPE_1__*) ; 
 int /*<<< orphan*/  git_worktree_lookup (TYPE_1__**,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_worktree_validate (TYPE_1__*) ; 

void test_worktree_worktree__validate_invalid_parent(void)
{
	git_worktree *wt;

	cl_git_pass(git_worktree_lookup(&wt, fixture.repo, "testrepo-worktree"));
	git__free(wt->parent_path);
	wt->parent_path = "/path/to/invalid/parent";
	cl_git_fail(git_worktree_validate(wt));

	wt->parent_path = NULL;
	git_worktree_free(wt);
}