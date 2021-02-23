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
typedef  int /*<<< orphan*/  hb_filter_param_t ;

/* Variables and functions */
 int /*<<< orphan*/ * filter_param_get_presets_internal (int,int /*<<< orphan*/ *) ; 

hb_filter_param_t* hb_filter_param_get_presets(int filter_id)
{
    return filter_param_get_presets_internal(filter_id, NULL);
}