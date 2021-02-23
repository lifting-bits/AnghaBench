#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int loaded; } ;
typedef  TYPE_1__ obs_script_t ;

/* Variables and functions */
 scalar_t__ ptr_valid (TYPE_1__ const*) ; 

bool obs_script_loaded(const obs_script_t *script)
{
	return ptr_valid(script) ? script->loaded : false;
}