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
 int /*<<< orphan*/  hook_call (int /*<<< orphan*/ ,int,unsigned int) ; 
 int /*<<< orphan*/  hook_dog_timeout ; 

void CPU_WATCHDOG_TIMEOUT(unsigned t)
{
	(void)hook_call(hook_dog_timeout, 1, t);
}