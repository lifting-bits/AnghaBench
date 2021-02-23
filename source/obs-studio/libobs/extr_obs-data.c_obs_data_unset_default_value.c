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
typedef  int /*<<< orphan*/  obs_data_t ;

/* Variables and functions */
 int /*<<< orphan*/  get_item (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  obs_data_item_unset_default_value (int /*<<< orphan*/ ) ; 

void obs_data_unset_default_value(obs_data_t *data, const char *name)
{
	obs_data_item_unset_default_value(get_item(data, name));
}