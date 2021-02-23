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
typedef  int /*<<< orphan*/  thread_t ;
typedef  int /*<<< orphan*/  thread_state_t ;
struct arm_act_context {int /*<<< orphan*/  ns; int /*<<< orphan*/  ss; } ;
typedef  scalar_t__ kern_return_t ;

/* Variables and functions */
 int /*<<< orphan*/  ARM_NEON_STATE ; 
 int /*<<< orphan*/  ARM_NEON_STATE64 ; 
 int /*<<< orphan*/  ARM_NEON_STATE64_COUNT ; 
 int /*<<< orphan*/  ARM_NEON_STATE_COUNT ; 
 int /*<<< orphan*/  ARM_THREAD_STATE ; 
 int /*<<< orphan*/  ARM_UNIFIED_THREAD_STATE_COUNT ; 
 scalar_t__ KERN_SUCCESS ; 
 int /*<<< orphan*/  current_thread () ; 
 int /*<<< orphan*/  kfree (struct arm_act_context*,int) ; 
 scalar_t__ machine_thread_set_state (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ thread_is_64bit_data (int /*<<< orphan*/ ) ; 

void
act_thread_catt(void *ctx)
{
	struct arm_act_context *ic;
	kern_return_t   kret;
	thread_t thread = current_thread();

	ic = (struct arm_act_context *) ctx;
	if (ic == (struct arm_act_context *) NULL)
		return;

	kret = machine_thread_set_state(thread, ARM_THREAD_STATE, (thread_state_t)&ic->ss, ARM_UNIFIED_THREAD_STATE_COUNT);
	if (kret != KERN_SUCCESS)
		goto out;

#if __ARM_VFP__
	if (thread_is_64bit_data(thread)) {
		kret = machine_thread_set_state(thread,
				ARM_NEON_STATE64,
				(thread_state_t) & ic->ns,
				ARM_NEON_STATE64_COUNT);
	} else {
		kret = machine_thread_set_state(thread,
				ARM_NEON_STATE,
				(thread_state_t) & ic->ns,
				ARM_NEON_STATE_COUNT);
	}
	if (kret != KERN_SUCCESS)
		goto out;
#endif
out:
	kfree(ic, sizeof(struct arm_act_context));
}