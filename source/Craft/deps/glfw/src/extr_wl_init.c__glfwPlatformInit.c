#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  _GLFWmonitor ;
struct TYPE_4__ {int /*<<< orphan*/  context; } ;
struct TYPE_5__ {int monitorsSize; int /*<<< orphan*/  compositor; int /*<<< orphan*/  cursorSurface; int /*<<< orphan*/  defaultCursor; int /*<<< orphan*/  cursorTheme; scalar_t__ shm; scalar_t__ pointer; int /*<<< orphan*/  display; TYPE_1__ xkb; int /*<<< orphan*/  monitors; int /*<<< orphan*/  registry; } ;
struct TYPE_6__ {TYPE_2__ wl; } ;

/* Variables and functions */
 int /*<<< orphan*/  GLFW_PLATFORM_ERROR ; 
 int GL_FALSE ; 
 int GL_TRUE ; 
 TYPE_3__ _glfw ; 
 int /*<<< orphan*/  _glfwInitContextAPI () ; 
 int /*<<< orphan*/  _glfwInitJoysticks () ; 
 int /*<<< orphan*/  _glfwInitTimer () ; 
 int /*<<< orphan*/  _glfwInputError (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  calloc (int,int) ; 
 int /*<<< orphan*/  registryListener ; 
 int /*<<< orphan*/  wl_compositor_create_surface (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wl_cursor_theme_get_cursor (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  wl_cursor_theme_load (int /*<<< orphan*/ *,int,scalar_t__) ; 
 int /*<<< orphan*/  wl_display_connect (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wl_display_get_registry (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wl_display_roundtrip (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wl_registry_add_listener (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xkb_context_new (int /*<<< orphan*/ ) ; 

int _glfwPlatformInit(void)
{
    _glfw.wl.display = wl_display_connect(NULL);
    if (!_glfw.wl.display)
    {
        _glfwInputError(GLFW_PLATFORM_ERROR,
                        "Wayland: Failed to connect to display");
        return GL_FALSE;
    }

    _glfw.wl.registry = wl_display_get_registry(_glfw.wl.display);
    wl_registry_add_listener(_glfw.wl.registry, &registryListener, NULL);

    _glfw.wl.monitors = calloc(4, sizeof(_GLFWmonitor*));
    _glfw.wl.monitorsSize = 4;

    _glfw.wl.xkb.context = xkb_context_new(0);
    if (!_glfw.wl.xkb.context)
    {
        _glfwInputError(GLFW_PLATFORM_ERROR,
                        "Wayland: Failed to initialize xkb context");
        return GL_FALSE;
    }

    // Sync so we got all registry objects
    wl_display_roundtrip(_glfw.wl.display);

    // Sync so we got all initial output events
    wl_display_roundtrip(_glfw.wl.display);

    if (!_glfwInitContextAPI())
        return GL_FALSE;

    _glfwInitTimer();
    _glfwInitJoysticks();

    if (_glfw.wl.pointer && _glfw.wl.shm)
    {
        _glfw.wl.cursorTheme = wl_cursor_theme_load(NULL, 32, _glfw.wl.shm);
        if (!_glfw.wl.cursorTheme)
        {
            _glfwInputError(GLFW_PLATFORM_ERROR,
                            "Wayland: Unable to load default cursor theme\n");
            return GL_FALSE;
        }
        _glfw.wl.defaultCursor =
            wl_cursor_theme_get_cursor(_glfw.wl.cursorTheme, "left_ptr");
        if (!_glfw.wl.defaultCursor)
        {
            _glfwInputError(GLFW_PLATFORM_ERROR,
                            "Wayland: Unable to load default left pointer\n");
            return GL_FALSE;
        }
        _glfw.wl.cursorSurface =
            wl_compositor_create_surface(_glfw.wl.compositor);
    }

    return GL_TRUE;
}