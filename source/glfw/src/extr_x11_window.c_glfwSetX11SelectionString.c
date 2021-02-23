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
struct TYPE_3__ {scalar_t__ helperWindowHandle; int /*<<< orphan*/  PRIMARY; int /*<<< orphan*/  display; int /*<<< orphan*/  primarySelectionString; } ;
struct TYPE_4__ {TYPE_1__ x11; } ;

/* Variables and functions */
 int /*<<< orphan*/  CurrentTime ; 
 int /*<<< orphan*/  GLFW_PLATFORM_ERROR ; 
 scalar_t__ XGetSelectionOwner (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XSetSelectionOwner (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _GLFW_REQUIRE_INIT () ; 
 TYPE_2__ _glfw ; 
 int /*<<< orphan*/  _glfwInputError (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  _glfw_strdup (char const*) ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ ) ; 

void glfwSetX11SelectionString(const char* string)
{
    _GLFW_REQUIRE_INIT();

    free(_glfw.x11.primarySelectionString);
    _glfw.x11.primarySelectionString = _glfw_strdup(string);

    XSetSelectionOwner(_glfw.x11.display,
                       _glfw.x11.PRIMARY,
                       _glfw.x11.helperWindowHandle,
                       CurrentTime);

    if (XGetSelectionOwner(_glfw.x11.display, _glfw.x11.PRIMARY) !=
        _glfw.x11.helperWindowHandle)
    {
        _glfwInputError(GLFW_PLATFORM_ERROR,
                        "X11: Failed to become owner of primary selection");
    }
}