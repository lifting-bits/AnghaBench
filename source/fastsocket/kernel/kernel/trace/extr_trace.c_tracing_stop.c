#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct ring_buffer {int dummy; } ;
struct TYPE_4__ {struct ring_buffer* buffer; } ;
struct TYPE_3__ {struct ring_buffer* buffer; } ;

/* Variables and functions */
 int /*<<< orphan*/  __raw_spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  __raw_spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ftrace_max_lock ; 
 int /*<<< orphan*/  ftrace_stop () ; 
 TYPE_2__ global_trace ; 
 TYPE_1__ max_tr ; 
 int /*<<< orphan*/  ring_buffer_record_disable (struct ring_buffer*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  trace_stop_count ; 
 int /*<<< orphan*/  tracing_start_lock ; 

void tracing_stop(void)
{
	struct ring_buffer *buffer;
	unsigned long flags;

	ftrace_stop();
	spin_lock_irqsave(&tracing_start_lock, flags);
	if (trace_stop_count++)
		goto out;

	/* Prevent the buffers from switching */
	__raw_spin_lock(&ftrace_max_lock);

	buffer = global_trace.buffer;
	if (buffer)
		ring_buffer_record_disable(buffer);

	buffer = max_tr.buffer;
	if (buffer)
		ring_buffer_record_disable(buffer);

	__raw_spin_unlock(&ftrace_max_lock);

 out:
	spin_unlock_irqrestore(&tracing_start_lock, flags);
}