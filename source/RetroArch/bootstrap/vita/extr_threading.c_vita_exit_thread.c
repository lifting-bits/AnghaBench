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
 int _exit_thread_common (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sceKernelExitThread ; 

int vita_exit_thread(int exit_status) {
	return _exit_thread_common(exit_status, sceKernelExitThread);
}