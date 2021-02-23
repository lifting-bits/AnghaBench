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
struct TYPE_3__ {scalar_t__ monitor; } ;
typedef  TYPE_1__ _GLFWwindow ;
typedef  int /*<<< orphan*/  GLFWwindow ;

/* Variables and functions */
 int /*<<< orphan*/  _GLFW_REQUIRE_INIT () ; 
 int /*<<< orphan*/  _glfwPlatformMaximizeWindow (TYPE_1__*) ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 

void glfwMaximizeWindow(GLFWwindow* handle)
{
    _GLFWwindow* window = (_GLFWwindow*) handle;
    assert(window != NULL);

    _GLFW_REQUIRE_INIT();

    if (window->monitor)
        return;

    _glfwPlatformMaximizeWindow(window);
}