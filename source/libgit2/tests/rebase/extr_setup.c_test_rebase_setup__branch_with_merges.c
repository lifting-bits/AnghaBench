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
typedef  int /*<<< orphan*/  git_rebase ;
typedef  int /*<<< orphan*/  git_oid ;
typedef  int /*<<< orphan*/  git_object ;
typedef  int /*<<< orphan*/  git_commit ;
typedef  int /*<<< orphan*/  git_annotated_commit ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_OBJECT_COMMIT ; 
 int /*<<< orphan*/  GIT_REPOSITORY_STATE_NONE ; 
 int /*<<< orphan*/  GIT_REPOSITORY_STATE_REBASE_MERGE ; 
 int /*<<< orphan*/  cl_assert_equal_file (char*,int,char*) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_oid (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_annotated_commit_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_annotated_commit_from_ref (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_commit_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_commit_id (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_rebase_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_rebase_init (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_reference_peel (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_head (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_state (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  repo ; 

void test_rebase_setup__branch_with_merges(void)
{
	git_rebase *rebase;
	git_reference *branch_ref, *upstream_ref;
	git_annotated_commit *branch_head, *upstream_head;
	git_reference *head;
	git_commit *head_commit;
	git_oid head_id;

	cl_assert_equal_i(GIT_REPOSITORY_STATE_NONE, git_repository_state(repo));

	cl_git_pass(git_reference_lookup(&branch_ref, repo, "refs/heads/veal"));
	cl_git_pass(git_reference_lookup(&upstream_ref, repo, "refs/heads/master"));

	cl_git_pass(git_annotated_commit_from_ref(&branch_head, repo, branch_ref));
	cl_git_pass(git_annotated_commit_from_ref(&upstream_head, repo, upstream_ref));

	cl_git_pass(git_rebase_init(&rebase, repo, branch_head, upstream_head, NULL, NULL));

	cl_assert_equal_i(GIT_REPOSITORY_STATE_REBASE_MERGE, git_repository_state(repo));

	git_oid_fromstr(&head_id, "efad0b11c47cb2f0220cbd6f5b0f93bb99064b00");
	cl_git_pass(git_repository_head(&head, repo));
	cl_git_pass(git_reference_peel((git_object **)&head_commit, head, GIT_OBJECT_COMMIT));
	cl_assert_equal_oid(&head_id, git_commit_id(head_commit));

	cl_assert_equal_file("f87d14a4a236582a0278a916340a793714256864\n", 41, "rebase/.git/ORIG_HEAD");

	cl_assert_equal_file("4bed71df7017283cac61bbf726197ad6a5a18b84\n", 41, "rebase/.git/rebase-merge/cmt.1");
	cl_assert_equal_file("2aa3ce842094e08ebac152b3d6d5b0fff39f9c6e\n", 41, "rebase/.git/rebase-merge/cmt.2");
	cl_assert_equal_file("3e8989b5a16d5258c935d998ef0e6bb139cc4757\n", 41, "rebase/.git/rebase-merge/cmt.3");
	cl_assert_equal_file("4cacc6f6e740a5bc64faa33e04b8ef0733d8a127\n", 41, "rebase/.git/rebase-merge/cmt.4");
	cl_assert_equal_file("f87d14a4a236582a0278a916340a793714256864\n", 41, "rebase/.git/rebase-merge/cmt.5");
	cl_assert_equal_file("5\n", 2, "rebase/.git/rebase-merge/end");
	cl_assert_equal_file("efad0b11c47cb2f0220cbd6f5b0f93bb99064b00\n", 41, "rebase/.git/rebase-merge/onto");
	cl_assert_equal_file("master\n", 7, "rebase/.git/rebase-merge/onto_name");
	cl_assert_equal_file("f87d14a4a236582a0278a916340a793714256864\n", 41, "rebase/.git/rebase-merge/orig-head");

	git_commit_free(head_commit);
	git_reference_free(head);
	git_annotated_commit_free(branch_head);
	git_annotated_commit_free(upstream_head);
	git_reference_free(branch_ref);
	git_reference_free(upstream_ref);
	git_rebase_free(rebase);
}