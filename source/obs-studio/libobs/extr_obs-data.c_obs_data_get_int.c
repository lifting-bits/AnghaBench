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
 long long obs_data_item_get_int (int /*<<< orphan*/ ) ; 

long long obs_data_get_int(obs_data_t *data, const char *name)
{
	return obs_data_item_get_int(get_item(data, name));
}