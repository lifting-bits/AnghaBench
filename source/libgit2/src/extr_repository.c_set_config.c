#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  _config; } ;
typedef  TYPE_1__ git_repository ;
typedef  int /*<<< orphan*/  git_config ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_REFCOUNT_INC (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GIT_REFCOUNT_OWN (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/ * git__swap (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_config_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository__configmap_lookup_cache_clear (TYPE_1__*) ; 

__attribute__((used)) static void set_config(git_repository *repo, git_config *config)
{
	if (config) {
		GIT_REFCOUNT_OWN(config, repo);
		GIT_REFCOUNT_INC(config);
	}

	if ((config = git__swap(repo->_config, config)) != NULL) {
		GIT_REFCOUNT_OWN(config, NULL);
		git_config_free(config);
	}

	git_repository__configmap_lookup_cache_clear(repo);
}