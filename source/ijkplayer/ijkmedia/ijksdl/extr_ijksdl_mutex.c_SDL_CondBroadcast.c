#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  id; } ;
typedef  TYPE_1__ SDL_cond ;

/* Variables and functions */
 int /*<<< orphan*/  assert (TYPE_1__*) ; 
 int pthread_cond_broadcast (int /*<<< orphan*/ *) ; 

int SDL_CondBroadcast(SDL_cond *cond)
{
    assert(cond);
    if (!cond)
        return -1;

    return pthread_cond_broadcast(&cond->id);
}