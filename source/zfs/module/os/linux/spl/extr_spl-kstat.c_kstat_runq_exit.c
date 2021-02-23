#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int ulong_t ;
struct TYPE_3__ {int rlastupdate; int rlentime; int rtime; int /*<<< orphan*/  rcnt; } ;
typedef  TYPE_1__ kstat_io_t ;
typedef  int hrtime_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int gethrtime () ; 

void
kstat_runq_exit(kstat_io_t *kiop)
{
	hrtime_t new, delta;
	ulong_t rcnt;

	new = gethrtime();
	delta = new - kiop->rlastupdate;
	kiop->rlastupdate = new;
	rcnt = kiop->rcnt--;
	ASSERT((int)rcnt > 0);
	kiop->rlentime += delta * rcnt;
	kiop->rtime += delta;
}