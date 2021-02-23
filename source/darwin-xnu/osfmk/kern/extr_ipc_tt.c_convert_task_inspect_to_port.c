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
typedef  int /*<<< orphan*/  task_inspect_t ;
typedef  int /*<<< orphan*/  ipc_port_t ;

/* Variables and functions */
 int /*<<< orphan*/  IP_NULL ; 
 int /*<<< orphan*/  task_deallocate (int /*<<< orphan*/ ) ; 

ipc_port_t
convert_task_inspect_to_port(
	task_inspect_t		task)
{
	task_deallocate(task);

	return IP_NULL;
}