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
struct TYPE_4__ {int /*<<< orphan*/  password; int /*<<< orphan*/  username; int /*<<< orphan*/  path; int /*<<< orphan*/  port; int /*<<< orphan*/  host; int /*<<< orphan*/  scheme; } ;

/* Variables and functions */
 int /*<<< orphan*/  cl_assert_equal_s (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 TYPE_1__ conndata ; 
 int /*<<< orphan*/  git_net_url_parse (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  gitno_connection_data_handle_redirect (TYPE_1__*,char*,char*) ; 

void test_network_redirect__redirect_encoded_username_password(void)
{
	cl_git_pass(git_net_url_parse(&conndata,
				"https://user%2fname:pass%40word%zyx%v@example.com/foo/bar/baz"));
	cl_git_pass(gitno_connection_data_handle_redirect(&conndata,
				"https://user%2fname:pass%40word%zyx%v@example.com/foo/bar/baz", "bar/baz"));
	cl_assert_equal_s(conndata.scheme, "https");
	cl_assert_equal_s(conndata.host, "example.com");
	cl_assert_equal_s(conndata.port, "443");
	cl_assert_equal_s(conndata.path, "/foo/");
	cl_assert_equal_s(conndata.username, "user/name");
	cl_assert_equal_s(conndata.password, "pass@word%zyx%v");
}