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

/* Variables and functions */
 int /*<<< orphan*/  AST_TELEMETRY_IO ; 
 int /*<<< orphan*/  act_set_ast (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
act_set_io_telemetry_ast(thread_t thread)
{
	act_set_ast(thread, AST_TELEMETRY_IO);
}