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
 int /*<<< orphan*/  buf ; 
 int /*<<< orphan*/  cfg ; 
 int /*<<< orphan*/  cl_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_s (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_mkfile (char*,char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_buf_cstr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_config_get_string_buf (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_config_open_ondisk (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_error_clear () ; 
 int /*<<< orphan*/ * git_error_last () ; 
 int /*<<< orphan*/  p_unlink (char*) ; 

void test_config_include__missing(void)
{
	cl_git_mkfile("including", "[include]\npath = nonexistentfile\n[foo]\nbar = baz");

	git_error_clear();
	cl_git_pass(git_config_open_ondisk(&cfg, "including"));
	cl_assert(git_error_last() == NULL);
	cl_git_pass(git_config_get_string_buf(&buf, cfg, "foo.bar"));
	cl_assert_equal_s("baz", git_buf_cstr(&buf));

	cl_git_pass(p_unlink("including"));
}