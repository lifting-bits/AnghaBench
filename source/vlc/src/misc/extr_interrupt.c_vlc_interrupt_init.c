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
struct TYPE_3__ {int interrupted; int /*<<< orphan*/ * callback; int /*<<< orphan*/  killed; int /*<<< orphan*/  lock; } ;
typedef  TYPE_1__ vlc_interrupt_t ;

/* Variables and functions */
 int /*<<< orphan*/  atomic_init (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  vlc_mutex_init (int /*<<< orphan*/ *) ; 

void vlc_interrupt_init(vlc_interrupt_t *ctx)
{
    vlc_mutex_init(&ctx->lock);
    ctx->interrupted = false;
    atomic_init(&ctx->killed, false);
    ctx->callback = NULL;
}