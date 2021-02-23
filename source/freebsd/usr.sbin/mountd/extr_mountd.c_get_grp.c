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
struct grouplist {int dummy; } ;

/* Variables and functions */
 scalar_t__ calloc (int,int) ; 
 int /*<<< orphan*/  out_of_mem () ; 

__attribute__((used)) static struct grouplist *
get_grp(void)
{
	struct grouplist *gp;

	gp = (struct grouplist *)calloc(1, sizeof (struct grouplist));
	if (gp == (struct grouplist *)NULL)
		out_of_mem();
	return (gp);
}