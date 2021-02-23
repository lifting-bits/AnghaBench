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
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  entrycount ; 
 int /*<<< orphan*/  g_reflog ; 
 int /*<<< orphan*/  g_repo ; 
 int /*<<< orphan*/  git_reflog_entrycount (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_reflog_read (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 

void test_refs_reflog_drop__initialize(void)
{
	g_repo = cl_git_sandbox_init("testrepo.git");

	git_reflog_read(&g_reflog, g_repo, "HEAD");
	entrycount = git_reflog_entrycount(g_reflog);
}