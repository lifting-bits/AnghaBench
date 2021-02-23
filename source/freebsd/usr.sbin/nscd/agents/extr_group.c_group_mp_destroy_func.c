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
 int /*<<< orphan*/  TRACE_IN (void (*) (void*)) ; 
 int /*<<< orphan*/  TRACE_OUT (void (*) (void*)) ; 

__attribute__((used)) static void
group_mp_destroy_func(void *mdata)
{
	TRACE_IN(group_mp_destroy_func);
	TRACE_OUT(group_mp_destroy_func);
}