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
struct xt_mtchk_param {struct ip6t_frag* matchinfo; } ;
struct ip6t_frag {int invflags; } ;

/* Variables and functions */
 int EINVAL ; 
 int IP6T_FRAG_INV_MASK ; 
 int /*<<< orphan*/  pr_debug (char*,int) ; 

__attribute__((used)) static int frag_mt6_check(const struct xt_mtchk_param *par)
{
	const struct ip6t_frag *fraginfo = par->matchinfo;

	if (fraginfo->invflags & ~IP6T_FRAG_INV_MASK) {
		pr_debug("unknown flags %X\n", fraginfo->invflags);
		return -EINVAL;
	}
	return 0;
}