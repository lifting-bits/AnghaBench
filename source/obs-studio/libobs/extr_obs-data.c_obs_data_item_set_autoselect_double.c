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
typedef  int /*<<< orphan*/  obs_data_item_t ;

/* Variables and functions */
 int /*<<< orphan*/  obs_set_double (int /*<<< orphan*/ *,int /*<<< orphan*/ **,int /*<<< orphan*/ *,double,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_item_auto ; 

void obs_data_item_set_autoselect_double(obs_data_item_t **item, double val)
{
	obs_set_double(NULL, item, NULL, val, set_item_auto);
}