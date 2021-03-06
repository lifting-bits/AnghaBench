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
struct TYPE_3__ {int priority; } ;
struct TYPE_4__ {TYPE_1__ attr; } ;
struct i915_request {TYPE_2__ sched; } ;

/* Variables and functions */
 int __NO_PREEMPTION ; 

__attribute__((used)) static inline int rq_prio(const struct i915_request *rq)
{
	return rq->sched.attr.priority | __NO_PREEMPTION;
}