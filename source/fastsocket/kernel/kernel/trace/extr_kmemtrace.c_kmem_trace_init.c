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
struct trace_array {int dummy; } ;

/* Variables and functions */
 struct trace_array* kmemtrace_array ; 
 int /*<<< orphan*/  kmemtrace_start_probes () ; 
 int /*<<< orphan*/  tracing_reset_online_cpus (struct trace_array*) ; 

__attribute__((used)) static int kmem_trace_init(struct trace_array *tr)
{
	kmemtrace_array = tr;

	tracing_reset_online_cpus(tr);

	kmemtrace_start_probes();

	return 0;
}