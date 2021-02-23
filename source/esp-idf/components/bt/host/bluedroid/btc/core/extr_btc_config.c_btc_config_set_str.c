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
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * config ; 
 int /*<<< orphan*/  config_set_string (int /*<<< orphan*/ *,char const*,char const*,char const*,int) ; 

bool btc_config_set_str(const char *section, const char *key, const char *value)
{
    assert(config != NULL);
    assert(section != NULL);
    assert(key != NULL);
    assert(value != NULL);

    config_set_string(config, section, key, value, false);

    return true;
}