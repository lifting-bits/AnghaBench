#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {void* task_threads_args; int arg_size; } ;
typedef  TYPE_1__ taskset_t ;

/* Variables and functions */

__attribute__((used)) static inline void *
taskset_thread_args( taskset_t *ts, int thr_idx )
{
    return( ts->task_threads_args + ( ts->arg_size * thr_idx ) );
}