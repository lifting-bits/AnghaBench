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
struct thread {int /*<<< orphan*/  td_frame; } ;
struct reg {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (struct reg*,int /*<<< orphan*/ ,int) ; 

int
fill_regs(struct thread *td, struct reg *regs)
{
	memcpy(regs, td->td_frame, sizeof(struct reg));
	return (0);
}