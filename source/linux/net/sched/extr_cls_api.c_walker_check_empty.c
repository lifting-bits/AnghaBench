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
struct tcf_walker {int nonempty; } ;
struct tcf_proto {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static int walker_check_empty(struct tcf_proto *tp, void *fh,
			      struct tcf_walker *arg)
{
	if (fh) {
		arg->nonempty = true;
		return -1;
	}
	return 0;
}