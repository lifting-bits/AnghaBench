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
typedef  scalar_t__ HANDLE ;

/* Variables and functions */
 int /*<<< orphan*/  CloseHandle (scalar_t__) ; 
 int /*<<< orphan*/  WaitForSingleObject (scalar_t__,int) ; 

__attribute__((used)) static inline void wait_for_dll_main_finish(HANDLE thread_handle)
{
	if (thread_handle) {
		WaitForSingleObject(thread_handle, 100);
		CloseHandle(thread_handle);
	}
}