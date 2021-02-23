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
struct rev_info {int total; } ;
struct option {scalar_t__ value; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON_OPT_ARG (char const*) ; 
 int /*<<< orphan*/  BUG_ON_OPT_NEG (int) ; 
 int keep_subject ; 

__attribute__((used)) static int keep_callback(const struct option *opt, const char *arg, int unset)
{
	BUG_ON_OPT_NEG(unset);
	BUG_ON_OPT_ARG(arg);
	((struct rev_info *)opt->value)->total = -1;
	keep_subject = 1;
	return 0;
}