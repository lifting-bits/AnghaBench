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
 int /*<<< orphan*/  FLAG_SET ; 
 int /*<<< orphan*/  PR_SYSEXIT ; 
 int /*<<< orphan*/  proc_trace_syscalls (char*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
proc_trace_sysexit_cmd (char *args, int from_tty)
{
  proc_trace_syscalls (args, from_tty, PR_SYSEXIT, FLAG_SET);
}