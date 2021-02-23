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
 int /*<<< orphan*/  FILE_DELETE_AND_CHANGE ; 
 int /*<<< orphan*/  FILE_ORIGINAL ; 
 int /*<<< orphan*/  apply_buf (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  skip_change ; 

void test_apply_partial__delete_and_change_skip_change(void)
{
	cl_git_pass(apply_buf(
		FILE_ORIGINAL, "file.txt",
		FILE_DELETE_AND_CHANGE, "file.txt",
		FILE_DELETE_AND_CHANGE, NULL, skip_change, NULL));
}