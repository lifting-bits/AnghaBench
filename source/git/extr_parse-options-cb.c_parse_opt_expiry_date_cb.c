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
typedef  int /*<<< orphan*/  timestamp_t ;
struct option {scalar_t__ value; } ;

/* Variables and functions */
 int /*<<< orphan*/  _ (char*) ; 
 int /*<<< orphan*/  die (int /*<<< orphan*/ ,char const*) ; 
 scalar_t__ parse_expiry_date (char const*,int /*<<< orphan*/ *) ; 

int parse_opt_expiry_date_cb(const struct option *opt, const char *arg,
			     int unset)
{
	if (unset)
		arg = "never";
	if (parse_expiry_date(arg, (timestamp_t *)opt->value))
		die(_("malformed expiration date '%s'"), arg);
	return 0;
}