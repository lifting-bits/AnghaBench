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
typedef  int /*<<< orphan*/  git_tree ;
typedef  int /*<<< orphan*/  git_repository ;
typedef  int /*<<< orphan*/  git_reference ;
typedef  int /*<<< orphan*/  git_object ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_OBJECT_TREE ; 
 int /*<<< orphan*/  git_reference_free (int /*<<< orphan*/ *) ; 
 int git_reference_peel (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int git_repository_head (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int checkout_lookup_head_tree(git_tree **out, git_repository *repo)
{
	int error = 0;
	git_reference *ref = NULL;
	git_object *head;

	if (!(error = git_repository_head(&ref, repo)) &&
		!(error = git_reference_peel(&head, ref, GIT_OBJECT_TREE)))
		*out = (git_tree *)head;

	git_reference_free(ref);

	return error;
}