#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  member_0; } ;
struct TYPE_5__ {char* path; scalar_t__ mode; int /*<<< orphan*/  id; TYPE_1__ member_0; } ;
typedef  TYPE_2__ git_index_entry ;
typedef  scalar_t__ git_filemode_t ;

/* Variables and functions */
 scalar_t__ GIT_FILEMODE_TREE ; 
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  g_index ; 
 int /*<<< orphan*/  git_index_add (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,char const*) ; 

__attribute__((used)) static void test_add_entry(
	bool should_succeed, const char *idstr, git_filemode_t mode)
{
	git_index_entry entry = {{0}};

	cl_git_pass(git_oid_fromstr(&entry.id, idstr));

	entry.path = mode == GIT_FILEMODE_TREE ? "test_folder" : "test_file";
	entry.mode = mode;

	if (should_succeed)
		cl_git_pass(git_index_add(g_index, &entry));
	else
		cl_git_fail(git_index_add(g_index, &entry));
}