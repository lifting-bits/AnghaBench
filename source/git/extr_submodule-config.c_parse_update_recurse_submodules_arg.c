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
 int parse_update_recurse (char const*,char const*,int) ; 

int parse_update_recurse_submodules_arg(const char *opt, const char *arg)
{
	return parse_update_recurse(opt, arg, 1);
}