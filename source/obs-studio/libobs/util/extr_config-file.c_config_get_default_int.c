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
typedef  int /*<<< orphan*/  int64_t ;
typedef  int /*<<< orphan*/  config_t ;

/* Variables and functions */
 char* config_get_default_string (int /*<<< orphan*/ *,char const*,char const*) ; 
 int /*<<< orphan*/  str_to_int64 (char const*) ; 

int64_t config_get_default_int(config_t *config, const char *section,
			       const char *name)
{
	const char *value = config_get_default_string(config, section, name);
	if (value)
		return str_to_int64(value);

	return 0;
}