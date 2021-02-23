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
typedef  int /*<<< orphan*/  git_revwalk ;
typedef  int /*<<< orphan*/  git_oid ;

/* Variables and functions */
 int GIT_ITEROVER ; 
 int /*<<< orphan*/  GIT_SORT_TOPOLOGICAL ; 
 int /*<<< orphan*/  _head_id ; 
 int /*<<< orphan*/  _repo ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int) ; 
 int /*<<< orphan*/  cl_assert_equal_oid (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * commit_ids ; 
 int /*<<< orphan*/  git_revwalk_add_hide_cb (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_revwalk_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_revwalk_new (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int git_revwalk_next (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_revwalk_push (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_revwalk_sorting (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hide_commit_use_payload_cb ; 

void test_revwalk_hidecb__test_payload(void)
{
	git_revwalk *walk;
	git_oid id;
	int i, error;

	cl_git_pass(git_revwalk_new(&walk, _repo));
	cl_git_pass(git_revwalk_push(walk, &_head_id));
	git_revwalk_sorting(walk, GIT_SORT_TOPOLOGICAL);

	/* Add hide callback, pass id of parent of initial commit as payload data */
	cl_git_pass(git_revwalk_add_hide_cb(walk, hide_commit_use_payload_cb, &commit_ids[5]));

	i = 0;
	while ((error = git_revwalk_next(&id, walk)) == 0) {
		cl_assert_equal_oid(&commit_ids[i], &id);
		i++;
	}

	/* walker should return four commits */
	cl_assert_equal_i(i, 4);
	cl_assert_equal_i(error, GIT_ITEROVER);

	git_revwalk_free(walk);
}