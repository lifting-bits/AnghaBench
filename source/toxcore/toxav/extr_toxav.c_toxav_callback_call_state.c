#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  toxav_call_state_cb ;
struct TYPE_4__ {void* second; int /*<<< orphan*/ * first; } ;
struct TYPE_5__ {int /*<<< orphan*/  mutex; TYPE_1__ scb; } ;
typedef  TYPE_2__ ToxAV ;

/* Variables and functions */
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ ) ; 

void toxav_callback_call_state(ToxAV *av, toxav_call_state_cb *function, void *user_data)
{
    pthread_mutex_lock(av->mutex);
    av->scb.first = function;
    av->scb.second = user_data;
    pthread_mutex_unlock(av->mutex);
}