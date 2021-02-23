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
struct TYPE_4__ {int /*<<< orphan*/  checkout_strategy; } ;
typedef  TYPE_1__ git_checkout_options ;

/* Variables and functions */
 int /*<<< orphan*/  ALL_CRLF_TEXT_AS_CRLF ; 
 int /*<<< orphan*/  ALL_CRLF_TEXT_RAW ; 
 int /*<<< orphan*/  ALL_LF_TEXT_AS_CRLF ; 
 int /*<<< orphan*/  ALL_LF_TEXT_RAW ; 
 int /*<<< orphan*/  GIT_CHECKOUT_FORCE ; 
 TYPE_1__ GIT_CHECKOUT_OPTIONS_INIT ; 
 scalar_t__ GIT_EOL_CRLF ; 
 scalar_t__ GIT_EOL_NATIVE ; 
 int /*<<< orphan*/  check_file_contents (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_mkfile (char*,char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_repo_set_bool (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  g_repo ; 
 int /*<<< orphan*/  git_checkout_head (int /*<<< orphan*/ ,TYPE_1__*) ; 

void test_checkout_crlf__autocrlf_false_text_auto_attr(void)
{
	git_checkout_options opts = GIT_CHECKOUT_OPTIONS_INIT;
	opts.checkout_strategy = GIT_CHECKOUT_FORCE;

	cl_git_mkfile("./crlf/.gitattributes", "* text=auto\n");

	cl_repo_set_bool(g_repo, "core.autocrlf", false);

	cl_git_pass(git_checkout_head(g_repo, &opts));

	if (GIT_EOL_NATIVE == GIT_EOL_CRLF) {
		check_file_contents("./crlf/all-lf", ALL_LF_TEXT_AS_CRLF);
		check_file_contents("./crlf/all-crlf", ALL_CRLF_TEXT_AS_CRLF);
	} else {
		check_file_contents("./crlf/all-lf", ALL_LF_TEXT_RAW);
		check_file_contents("./crlf/all-crlf", ALL_CRLF_TEXT_RAW);
	}
}