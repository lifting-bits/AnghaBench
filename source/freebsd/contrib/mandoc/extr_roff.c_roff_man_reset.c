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
struct roff_man {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  roff_man_alloc1 (struct roff_man*) ; 
 int /*<<< orphan*/  roff_man_free1 (struct roff_man*) ; 

void
roff_man_reset(struct roff_man *man)
{
	roff_man_free1(man);
	roff_man_alloc1(man);
}