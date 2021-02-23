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
struct TYPE_3__ {int /*<<< orphan*/  connection; int /*<<< orphan*/  event_mutex; int /*<<< orphan*/  event_queue; } ;
struct TYPE_4__ {TYPE_1__ mir; } ;

/* Variables and functions */
 TYPE_2__ _glfw ; 
 int /*<<< orphan*/  _glfwDeleteEventQueueMir (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _glfwTerminateEGL () ; 
 int /*<<< orphan*/  _glfwTerminateJoysticksLinux () ; 
 int /*<<< orphan*/  _glfwTerminateThreadLocalStoragePOSIX () ; 
 int /*<<< orphan*/  mir_connection_release (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pthread_mutex_destroy (int /*<<< orphan*/ *) ; 

void _glfwPlatformTerminate(void)
{
    _glfwTerminateEGL();
    _glfwTerminateJoysticksLinux();
    _glfwTerminateThreadLocalStoragePOSIX();

    _glfwDeleteEventQueueMir(_glfw.mir.event_queue);

    pthread_mutex_destroy(&_glfw.mir.event_mutex);

    mir_connection_release(_glfw.mir.connection);
}