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
 int /*<<< orphan*/  FEW_UTF8_CRLF_RAW ; 
 int /*<<< orphan*/  GIT_CHECKOUT_FORCE ; 
 TYPE_1__ GIT_CHECKOUT_OPTIONS_INIT ; 
 int /*<<< orphan*/  MANY_UTF8_CRLF_RAW ; 
 int /*<<< orphan*/  check_file_contents (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_repo_set_bool (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  g_repo ; 
 int /*<<< orphan*/  git_checkout_head (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  git_repository_set_head (int /*<<< orphan*/ ,char*) ; 

void test_checkout_crlf__detect_crlf_autocrlf_true_utf8(void)
{
	git_checkout_options opts = GIT_CHECKOUT_OPTIONS_INIT;
	opts.checkout_strategy = GIT_CHECKOUT_FORCE;

	cl_repo_set_bool(g_repo, "core.autocrlf", true);

	git_repository_set_head(g_repo, "refs/heads/master");
	git_checkout_head(g_repo, &opts);

	check_file_contents("./crlf/few-utf8-chars-lf", FEW_UTF8_CRLF_RAW);
	check_file_contents("./crlf/many-utf8-chars-lf", MANY_UTF8_CRLF_RAW);

	check_file_contents("./crlf/few-utf8-chars-crlf", FEW_UTF8_CRLF_RAW);
	check_file_contents("./crlf/many-utf8-chars-crlf", MANY_UTF8_CRLF_RAW);
}