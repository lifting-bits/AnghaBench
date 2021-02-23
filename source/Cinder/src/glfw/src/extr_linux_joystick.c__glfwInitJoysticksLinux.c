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
struct dirent {char* d_name; } ;
typedef  int /*<<< orphan*/  regmatch_t ;
typedef  int /*<<< orphan*/  path ;
typedef  int /*<<< orphan*/  _GLFWjoystickLinux ;
struct TYPE_3__ {int inotify; int watch; int /*<<< orphan*/  js; int /*<<< orphan*/  regex; } ;
struct TYPE_4__ {TYPE_1__ linux_js; } ;
typedef  int /*<<< orphan*/  GLFWbool ;
typedef  int /*<<< orphan*/  DIR ;

/* Variables and functions */
 int /*<<< orphan*/  GLFW_FALSE ; 
 int /*<<< orphan*/  GLFW_PLATFORM_ERROR ; 
 int /*<<< orphan*/  GLFW_TRUE ; 
 int IN_ATTRIB ; 
 int IN_CLOEXEC ; 
 int IN_CREATE ; 
 int IN_NONBLOCK ; 
 TYPE_2__ _glfw ; 
 int /*<<< orphan*/  _glfwInputError (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  closedir (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  compareJoysticks ; 
 int /*<<< orphan*/  errno ; 
 int inotify_add_watch (int,char const*,int) ; 
 int inotify_init1 (int) ; 
 scalar_t__ openJoystickDevice (char*) ; 
 int /*<<< orphan*/ * opendir (char const*) ; 
 int /*<<< orphan*/  qsort (int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ) ; 
 struct dirent* readdir (int /*<<< orphan*/ *) ; 
 scalar_t__ regcomp (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ regexec (int /*<<< orphan*/ *,char*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char const*,char*) ; 
 int /*<<< orphan*/  strerror (int /*<<< orphan*/ ) ; 

GLFWbool _glfwInitJoysticksLinux(void)
{
#if defined(__linux__)
    DIR* dir;
    int count = 0;
    const char* dirname = "/dev/input";

    _glfw.linux_js.inotify = inotify_init1(IN_NONBLOCK | IN_CLOEXEC);
    if (_glfw.linux_js.inotify == -1)
    {
        _glfwInputError(GLFW_PLATFORM_ERROR,
                        "Linux: Failed to initialize inotify: %s",
                        strerror(errno));
        return GLFW_FALSE;
    }

    // HACK: Register for IN_ATTRIB as well to get notified when udev is done
    //       This works well in practice but the true way is libudev

    _glfw.linux_js.watch = inotify_add_watch(_glfw.linux_js.inotify,
                                             dirname,
                                             IN_CREATE | IN_ATTRIB);
    if (_glfw.linux_js.watch == -1)
    {
        _glfwInputError(GLFW_PLATFORM_ERROR,
                        "Linux: Failed to watch for joystick connections in %s: %s",
                        dirname,
                        strerror(errno));
        // Continue without device connection notifications
    }

    if (regcomp(&_glfw.linux_js.regex, "^js[0-9]\\+$", 0) != 0)
    {
        _glfwInputError(GLFW_PLATFORM_ERROR, "Linux: Failed to compile regex");
        return GLFW_FALSE;
    }

    dir = opendir(dirname);
    if (dir)
    {
        struct dirent* entry;

        while ((entry = readdir(dir)))
        {
            char path[20];
            regmatch_t match;

            if (regexec(&_glfw.linux_js.regex, entry->d_name, 1, &match, 0) != 0)
                continue;

            snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);
            if (openJoystickDevice(path))
                count++;
        }

        closedir(dir);
    }
    else
    {
        _glfwInputError(GLFW_PLATFORM_ERROR,
                        "Linux: Failed to open joystick device directory %s: %s",
                        dirname,
                        strerror(errno));
        // Continue with no joysticks detected
    }

    qsort(_glfw.linux_js.js, count, sizeof(_GLFWjoystickLinux), compareJoysticks);
#endif // __linux__

    return GLFW_TRUE;
}