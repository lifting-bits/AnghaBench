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
 int git_config_copy_or_rename_section_in_file (char const*,char const*,char const*,int /*<<< orphan*/ ) ; 

int git_config_rename_section_in_file(const char *config_filename,
				      const char *old_name, const char *new_name)
{
	return git_config_copy_or_rename_section_in_file(config_filename,
					 old_name, new_name, 0);
}