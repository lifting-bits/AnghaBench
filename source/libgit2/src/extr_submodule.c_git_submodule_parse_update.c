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
typedef  scalar_t__ git_submodule_update_t ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 scalar_t__ GIT_SUBMODULE_UPDATE_CHECKOUT ; 
 int /*<<< orphan*/  _sm_update_map ; 
 scalar_t__ git_config_lookup_map_value (int*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*) ; 
 int submodule_config_error (char*,char const*) ; 

int git_submodule_parse_update(git_submodule_update_t *out, const char *value)
{
	int val;

	if (git_config_lookup_map_value(
			&val, _sm_update_map, ARRAY_SIZE(_sm_update_map), value) < 0) {
		*out = GIT_SUBMODULE_UPDATE_CHECKOUT;
		return submodule_config_error("update", value);
	}

	*out = (git_submodule_update_t)val;
	return 0;
}