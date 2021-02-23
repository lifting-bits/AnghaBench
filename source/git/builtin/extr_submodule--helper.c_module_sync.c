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
struct sync_cb {char const* prefix; int /*<<< orphan*/  flags; } ;
struct pathspec {int dummy; } ;
struct option {int dummy; } ;
struct module_list {int dummy; } ;

/* Variables and functions */
 struct module_list MODULE_LIST_INIT ; 
 char const* N_ (char*) ; 
 struct option OPT_BOOL (int /*<<< orphan*/ ,char*,int*,char const*) ; 
 struct option OPT_END () ; 
 int /*<<< orphan*/  OPT_QUIET ; 
 int /*<<< orphan*/  OPT_RECURSIVE ; 
 struct option OPT__QUIET (int*,char const*) ; 
 struct sync_cb SYNC_CB_INIT ; 
 int /*<<< orphan*/  for_each_listed_submodule (struct module_list*,int /*<<< orphan*/ ,struct sync_cb*) ; 
 scalar_t__ module_list_compute (int,char const**,char const*,struct pathspec*,struct module_list*) ; 
 int parse_options (int,char const**,char const*,struct option*,char const* const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sync_submodule_cb ; 

__attribute__((used)) static int module_sync(int argc, const char **argv, const char *prefix)
{
	struct sync_cb info = SYNC_CB_INIT;
	struct pathspec pathspec;
	struct module_list list = MODULE_LIST_INIT;
	int quiet = 0;
	int recursive = 0;

	struct option module_sync_options[] = {
		OPT__QUIET(&quiet, N_("Suppress output of synchronizing submodule url")),
		OPT_BOOL(0, "recursive", &recursive,
			N_("Recurse into nested submodules")),
		OPT_END()
	};

	const char *const git_submodule_helper_usage[] = {
		N_("git submodule--helper sync [--quiet] [--recursive] [<path>]"),
		NULL
	};

	argc = parse_options(argc, argv, prefix, module_sync_options,
			     git_submodule_helper_usage, 0);

	if (module_list_compute(argc, argv, prefix, &pathspec, &list) < 0)
		return 1;

	info.prefix = prefix;
	if (quiet)
		info.flags |= OPT_QUIET;
	if (recursive)
		info.flags |= OPT_RECURSIVE;

	for_each_listed_submodule(&list, sync_submodule_cb, &info);

	return 0;
}