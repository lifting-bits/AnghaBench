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
struct opts {scalar_t__ argc; } ;
typedef  int /*<<< orphan*/  git_repository ;

/* Variables and functions */
 int /*<<< orphan*/  check_lg2 (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_stash_pop (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  usage (char*) ; 

__attribute__((used)) static int cmd_pop(git_repository *repo, struct opts *opts)
{
	if (opts->argc)
		usage("pop does not accept any parameters");

	check_lg2(git_stash_pop(repo, 0, NULL),
		  "Unable to pop stash", NULL);

	printf("Dropped refs/stash@{0}\n");

	return 0;
}