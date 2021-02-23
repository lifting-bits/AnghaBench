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
 int /*<<< orphan*/  assert_is_ignored (int,char*) ; 
 int /*<<< orphan*/  cl_git_rewritefile (char*,char*) ; 

void test_ignore_path__negative_prefix_rule(void)
{
	cl_git_rewritefile("attr/.gitignore", "ff*\n!f\n");
	assert_is_ignored(true, "fff");
	assert_is_ignored(true, "ff");
	assert_is_ignored(false, "f");
}