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
struct clock_getcpuclockid2_args {int /*<<< orphan*/  clock_id; int /*<<< orphan*/  which; int /*<<< orphan*/  id; } ;
typedef  int /*<<< orphan*/  clockid_t ;

/* Variables and functions */
 int copyout (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int kern_clock_getcpuclockid2 (struct thread*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

int
sys_clock_getcpuclockid2(struct thread *td, struct clock_getcpuclockid2_args *uap)
{
	clockid_t clk_id;
	int error;

	error = kern_clock_getcpuclockid2(td, uap->id, uap->which, &clk_id);
	if (error == 0)
		error = copyout(&clk_id, uap->clock_id, sizeof(clockid_t));
	return (error);
}