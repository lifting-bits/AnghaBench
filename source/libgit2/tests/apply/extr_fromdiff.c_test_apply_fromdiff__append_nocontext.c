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
struct TYPE_4__ {scalar_t__ context_lines; } ;
typedef  TYPE_1__ git_diff_options ;

/* Variables and functions */
 int /*<<< orphan*/  FILE_APPEND ; 
 int /*<<< orphan*/  FILE_ORIGINAL ; 
 TYPE_1__ GIT_DIFF_OPTIONS_INIT ; 
 int /*<<< orphan*/  PATCH_ORIGINAL_TO_APPEND_NOCONTEXT ; 
 int /*<<< orphan*/  apply_buf (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 

void test_apply_fromdiff__append_nocontext(void)
{
	git_diff_options diff_opts = GIT_DIFF_OPTIONS_INIT;
	diff_opts.context_lines = 0;

	cl_git_pass(apply_buf(
		FILE_ORIGINAL, "file.txt",
		FILE_APPEND, "file.txt",
		PATCH_ORIGINAL_TO_APPEND_NOCONTEXT, &diff_opts));
}