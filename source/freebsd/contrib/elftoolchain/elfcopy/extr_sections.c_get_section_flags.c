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
struct sec_action {int flags; } ;
struct elfcopy {int dummy; } ;

/* Variables and functions */
 struct sec_action* lookup_sec_act (struct elfcopy*,char const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
get_section_flags(struct elfcopy *ecp, const char *name)
{
	struct sec_action *sac;

	sac = lookup_sec_act(ecp, name, 0);
	if (sac != NULL && sac->flags)
		return sac->flags;

	return (0);
}