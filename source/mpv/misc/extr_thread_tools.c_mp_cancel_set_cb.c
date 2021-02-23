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
struct mp_cancel {void (* cb ) (void*) ;int /*<<< orphan*/  lock; void* cb_ctx; } ;

/* Variables and functions */
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  retrigger_locked (struct mp_cancel*) ; 

void mp_cancel_set_cb(struct mp_cancel *c, void (*cb)(void *ctx), void *ctx)
{
    pthread_mutex_lock(&c->lock);
    c->cb = cb;
    c->cb_ctx = ctx;
    retrigger_locked(c);
    pthread_mutex_unlock(&c->lock);
}