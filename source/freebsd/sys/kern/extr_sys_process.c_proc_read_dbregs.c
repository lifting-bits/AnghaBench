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
struct thread {int dummy; } ;
struct dbreg {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PROC_ACTION (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fill_dbregs (struct thread*,struct dbreg*) ; 

int
proc_read_dbregs(struct thread *td, struct dbreg *dbregs)
{

	PROC_ACTION(fill_dbregs(td, dbregs));
}