#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  section; scalar_t__ allocated; } ;
struct TYPE_6__ {TYPE_1__ win32; } ;
typedef  TYPE_2__ _GLFWmutex ;

/* Variables and functions */
 int /*<<< orphan*/  DeleteCriticalSection (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (TYPE_2__*,int /*<<< orphan*/ ,int) ; 

void _glfwPlatformDestroyMutex(_GLFWmutex* mutex)
{
    if (mutex->win32.allocated)
        DeleteCriticalSection(&mutex->win32.section);
    memset(mutex, 0, sizeof(_GLFWmutex));
}