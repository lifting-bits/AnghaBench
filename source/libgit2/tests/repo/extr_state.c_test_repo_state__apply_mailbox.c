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
 int /*<<< orphan*/  GIT_REBASE_APPLY_APPLYING_FILE ; 
 int /*<<< orphan*/  GIT_REPOSITORY_STATE_APPLY_MAILBOX ; 
 int /*<<< orphan*/  GIT_REPOSITORY_STATE_NONE ; 
 int /*<<< orphan*/  _repo ; 
 int /*<<< orphan*/  assert_repo_state (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_state_cleanup (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  setup_simple_state (int /*<<< orphan*/ ) ; 

void test_repo_state__apply_mailbox(void)
{
	setup_simple_state(GIT_REBASE_APPLY_APPLYING_FILE);
	assert_repo_state(GIT_REPOSITORY_STATE_APPLY_MAILBOX);
	cl_git_pass(git_repository_state_cleanup(_repo));
	assert_repo_state(GIT_REPOSITORY_STATE_NONE);
}