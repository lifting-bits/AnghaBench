#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_diff ;
struct TYPE_4__ {int /*<<< orphan*/  flags; } ;
typedef  TYPE_1__ git_apply_options ;

/* Variables and functions */
 int /*<<< orphan*/  DIFF_MODIFY_TWO_FILES_BINARY ; 
 int /*<<< orphan*/  GIT_APPLY_CHECK ; 
 int /*<<< orphan*/  GIT_APPLY_LOCATION_INDEX ; 
 TYPE_1__ GIT_APPLY_OPTIONS_INIT ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_apply (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  git_diff_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_diff_from_buffer (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  repo ; 
 int /*<<< orphan*/  strlen (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  validate_index_unchanged (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  validate_workdir_unchanged (int /*<<< orphan*/ ) ; 

void test_apply_check__binary(void)
{
   git_diff *diff;
   git_apply_options opts = GIT_APPLY_OPTIONS_INIT;

   opts.flags |= GIT_APPLY_CHECK;
   cl_git_pass(git_diff_from_buffer(&diff,
       DIFF_MODIFY_TWO_FILES_BINARY,
       strlen(DIFF_MODIFY_TWO_FILES_BINARY)));
   cl_git_pass(git_apply(repo, diff, GIT_APPLY_LOCATION_INDEX, &opts));

   validate_index_unchanged(repo);
   validate_workdir_unchanged(repo);

   git_diff_free(diff);
}