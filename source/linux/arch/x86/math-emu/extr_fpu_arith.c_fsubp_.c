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

/* Variables and functions */
 int DEST_RM ; 
 int /*<<< orphan*/  FPU_pop () ; 
 int /*<<< orphan*/  FPU_rm ; 
 scalar_t__ FPU_sub (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int REV ; 
 int /*<<< orphan*/  clear_C1 () ; 
 int /*<<< orphan*/  control_word ; 

void fsubp_(void)
{
	/* fsubp st(i),st */
	clear_C1();
	if (FPU_sub(REV | DEST_RM, FPU_rm, control_word) >= 0)
		FPU_pop();
}