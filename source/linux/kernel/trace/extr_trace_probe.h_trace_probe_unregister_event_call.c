#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct trace_probe {TYPE_1__* event; } ;
struct TYPE_2__ {int /*<<< orphan*/  call; } ;

/* Variables and functions */
 int trace_remove_event_call (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int trace_probe_unregister_event_call(struct trace_probe *tp)
{
	/* tp->event is unregistered in trace_remove_event_call() */
	return trace_remove_event_call(&tp->event->call);
}