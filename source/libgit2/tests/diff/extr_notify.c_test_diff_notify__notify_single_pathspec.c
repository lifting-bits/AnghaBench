#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {char* member_0; char* member_1; } ;
typedef  TYPE_1__ notify_expected ;

/* Variables and functions */
 int /*<<< orphan*/  test_notify (char**,int,TYPE_1__*,int) ; 

void test_diff_notify__notify_single_pathspec(void)
{
	char *searched_pathspecs[] = {
		"*_deleted",
	};
	notify_expected expected_matched_pathspecs[] = {
		{ "file_deleted", "*_deleted" },
		{ "staged_changes_file_deleted", "*_deleted" },
		{ NULL, NULL }
	};

	test_notify(searched_pathspecs, 1, expected_matched_pathspecs, 2);
}