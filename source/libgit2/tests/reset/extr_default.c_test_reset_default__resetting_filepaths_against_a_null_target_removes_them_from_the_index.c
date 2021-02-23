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
struct TYPE_4__ {char** strings; int count; } ;

/* Variables and functions */
 TYPE_1__ _pathspecs ; 
 int /*<<< orphan*/  _repo ; 
 int /*<<< orphan*/  assert_content_in_index (TYPE_1__*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_reset_default (int /*<<< orphan*/ ,int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  initialize (char*) ; 

void test_reset_default__resetting_filepaths_against_a_null_target_removes_them_from_the_index(void)
{
	char *paths[] = { "staged_changes", "staged_new_file" };

	initialize("status");

	_pathspecs.strings = paths;
	_pathspecs.count = 2;

	assert_content_in_index(&_pathspecs, true, NULL);

	cl_git_pass(git_reset_default(_repo, NULL, &_pathspecs));

	assert_content_in_index(&_pathspecs, false, NULL);
}