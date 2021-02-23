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
struct nn_worker_task {int /*<<< orphan*/  item; } ;
struct nn_worker {int /*<<< orphan*/  sync; int /*<<< orphan*/  tasks; } ;

/* Variables and functions */
 int /*<<< orphan*/  nn_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nn_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nn_queue_remove (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

void nn_worker_cancel (struct nn_worker *self, struct nn_worker_task *task)
{
    nn_mutex_lock (&self->sync);
    nn_queue_remove (&self->tasks, &task->item);
    nn_mutex_unlock (&self->sync);
}