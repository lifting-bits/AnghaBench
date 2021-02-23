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
struct option {int* value; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON_OPT_ARG (char const*) ; 

int parse_opt_tertiary(const struct option *opt, const char *arg, int unset)
{
	int *target = opt->value;

	BUG_ON_OPT_ARG(arg);

	*target = unset ? 2 : 1;
	return 0;
}