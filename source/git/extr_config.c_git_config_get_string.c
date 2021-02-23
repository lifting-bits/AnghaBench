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
 int repo_config_get_string (int /*<<< orphan*/ ,char const*,char**) ; 
 int /*<<< orphan*/  the_repository ; 

int git_config_get_string(const char *key, char **dest)
{
	return repo_config_get_string(the_repository, key, dest);
}