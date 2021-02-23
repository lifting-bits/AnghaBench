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
typedef  int /*<<< orphan*/  git_buf ;
typedef  int /*<<< orphan*/  git_annotated_commit ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_BUF_INIT ; 
 int /*<<< orphan*/  GIT_RESET_HARD ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_annotated_commit_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_annotated_commit_from_revspec (int /*<<< orphan*/ **,int /*<<< orphan*/ ,char*) ; 
 char const* git_buf_cstr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_buf_dispose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_buf_printf (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_object_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_object_id (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_oid_tostr_s (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_reset (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reset_from_annotated (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_revparse_single (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  reflog_check (int /*<<< orphan*/ ,char*,int,char*,char const*) ; 
 int /*<<< orphan*/  repo ; 
 int /*<<< orphan*/  target ; 

void test_reset_hard__reflog_is_correct(void)
{
	git_buf buf = GIT_BUF_INIT;
	git_annotated_commit *annotated;
	const char *exp_msg = "commit: Add a file which name should appear before the "
		"\"subdir/\" folder while being dealt with by the treewalker";

	reflog_check(repo, "HEAD", 3, "emeric.fermas@gmail.com", exp_msg);
	reflog_check(repo, "refs/heads/master", 3, "emeric.fermas@gmail.com", exp_msg);

	/* Branch not moving, no reflog entry */
	cl_git_pass(git_revparse_single(&target, repo, "HEAD^{commit}"));
	cl_git_pass(git_reset(repo, target, GIT_RESET_HARD, NULL));
	reflog_check(repo, "HEAD", 3, "emeric.fermas@gmail.com", exp_msg);
	reflog_check(repo, "refs/heads/master", 3, "emeric.fermas@gmail.com", exp_msg);

	git_object_free(target);

	/* Moved branch, expect id in message */
	cl_git_pass(git_revparse_single(&target, repo, "HEAD~^{commit}"));
	cl_git_pass(git_buf_printf(&buf, "reset: moving to %s", git_oid_tostr_s(git_object_id(target))));
	cl_git_pass(git_reset(repo, target, GIT_RESET_HARD, NULL));
	reflog_check(repo, "HEAD", 4, NULL, git_buf_cstr(&buf));
	reflog_check(repo, "refs/heads/master", 4, NULL, git_buf_cstr(&buf));

	git_buf_dispose(&buf);

	/* Moved branch, expect revspec in message */
	exp_msg = "reset: moving to HEAD~^{commit}";
	cl_git_pass(git_annotated_commit_from_revspec(&annotated, repo, "HEAD~^{commit}"));
	cl_git_pass(git_reset_from_annotated(repo, annotated, GIT_RESET_HARD, NULL));
	reflog_check(repo, "HEAD", 5, NULL, exp_msg);
	reflog_check(repo, "refs/heads/master", 5, NULL, exp_msg);

	git_annotated_commit_free(annotated);

}