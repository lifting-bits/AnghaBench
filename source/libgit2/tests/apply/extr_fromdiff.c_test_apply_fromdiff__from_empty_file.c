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
 int /*<<< orphan*/  FILE_ORIGINAL ; 
 int /*<<< orphan*/  PATCH_EMPTY_FILE_TO_ORIGINAL ; 
 int /*<<< orphan*/  apply_buf (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 

void test_apply_fromdiff__from_empty_file(void)
{
	cl_git_pass(apply_buf(
		"", NULL,
		FILE_ORIGINAL, "file.txt",
		PATCH_EMPTY_FILE_TO_ORIGINAL, NULL));
}