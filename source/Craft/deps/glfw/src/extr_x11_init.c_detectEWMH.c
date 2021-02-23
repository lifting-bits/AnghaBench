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
typedef  scalar_t__ Window ;
struct TYPE_3__ {scalar_t__ root; void* NET_WM_BYPASS_COMPOSITOR; void* NET_REQUEST_FRAME_EXTENTS; void* NET_FRAME_EXTENTS; void* NET_ACTIVE_WINDOW; void* NET_WM_PING; void* NET_WM_PID; void* NET_WM_ICON_NAME; void* NET_WM_NAME; void* NET_WM_FULLSCREEN_MONITORS; void* NET_WM_STATE_FULLSCREEN; void* NET_WM_STATE_ABOVE; void* NET_WM_STATE; int /*<<< orphan*/  display; } ;
struct TYPE_4__ {TYPE_1__ x11; } ;
typedef  scalar_t__ Atom ;

/* Variables and functions */
 scalar_t__ None ; 
 int /*<<< orphan*/  True ; 
 int /*<<< orphan*/  XA_ATOM ; 
 int /*<<< orphan*/  XA_WINDOW ; 
 int /*<<< orphan*/  XFree (scalar_t__*) ; 
 scalar_t__ XInternAtom (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 TYPE_2__ _glfw ; 
 int _glfwGetWindowProperty (scalar_t__,scalar_t__,int /*<<< orphan*/ ,unsigned char**) ; 
 int /*<<< orphan*/  _glfwGrabXErrorHandler () ; 
 int /*<<< orphan*/  _glfwReleaseXErrorHandler () ; 
 void* getSupportedAtom (scalar_t__*,unsigned long,char*) ; 

__attribute__((used)) static void detectEWMH(void)
{
    Window* windowFromRoot = NULL;
    Window* windowFromChild = NULL;

    // First we need a couple of atoms, which should already be there
    Atom supportingWmCheck =
        XInternAtom(_glfw.x11.display, "_NET_SUPPORTING_WM_CHECK", True);
    Atom wmSupported =
        XInternAtom(_glfw.x11.display, "_NET_SUPPORTED", True);
    if (supportingWmCheck == None || wmSupported == None)
        return;

    // Then we look for the _NET_SUPPORTING_WM_CHECK property of the root window
    if (_glfwGetWindowProperty(_glfw.x11.root,
                               supportingWmCheck,
                               XA_WINDOW,
                               (unsigned char**) &windowFromRoot) != 1)
    {
        if (windowFromRoot)
            XFree(windowFromRoot);
        return;
    }

    _glfwGrabXErrorHandler();

    // It should be the ID of a child window (of the root)
    // Then we look for the same property on the child window
    if (_glfwGetWindowProperty(*windowFromRoot,
                               supportingWmCheck,
                               XA_WINDOW,
                               (unsigned char**) &windowFromChild) != 1)
    {
        XFree(windowFromRoot);
        if (windowFromChild)
            XFree(windowFromChild);
        return;
    }

    _glfwReleaseXErrorHandler();

    // It should be the ID of that same child window
    if (*windowFromRoot != *windowFromChild)
    {
        XFree(windowFromRoot);
        XFree(windowFromChild);
        return;
    }

    XFree(windowFromRoot);
    XFree(windowFromChild);

    // We are now fairly sure that an EWMH-compliant window manager is running

    Atom* supportedAtoms;
    unsigned long atomCount;

    // Now we need to check the _NET_SUPPORTED property of the root window
    // It should be a list of supported WM protocol and state atoms
    atomCount = _glfwGetWindowProperty(_glfw.x11.root,
                                       wmSupported,
                                       XA_ATOM,
                                       (unsigned char**) &supportedAtoms);

    // See which of the atoms we support that are supported by the WM
    _glfw.x11.NET_WM_STATE =
        getSupportedAtom(supportedAtoms, atomCount, "_NET_WM_STATE");
    _glfw.x11.NET_WM_STATE_ABOVE =
        getSupportedAtom(supportedAtoms, atomCount, "_NET_WM_STATE_ABOVE");
    _glfw.x11.NET_WM_STATE_FULLSCREEN =
        getSupportedAtom(supportedAtoms, atomCount, "_NET_WM_STATE_FULLSCREEN");
    _glfw.x11.NET_WM_FULLSCREEN_MONITORS =
        getSupportedAtom(supportedAtoms, atomCount, "_NET_WM_FULLSCREEN_MONITORS");
    _glfw.x11.NET_WM_NAME =
        getSupportedAtom(supportedAtoms, atomCount, "_NET_WM_NAME");
    _glfw.x11.NET_WM_ICON_NAME =
        getSupportedAtom(supportedAtoms, atomCount, "_NET_WM_ICON_NAME");
    _glfw.x11.NET_WM_PID =
        getSupportedAtom(supportedAtoms, atomCount, "_NET_WM_PID");
    _glfw.x11.NET_WM_PING =
        getSupportedAtom(supportedAtoms, atomCount, "_NET_WM_PING");
    _glfw.x11.NET_ACTIVE_WINDOW =
        getSupportedAtom(supportedAtoms, atomCount, "_NET_ACTIVE_WINDOW");
    _glfw.x11.NET_FRAME_EXTENTS =
        getSupportedAtom(supportedAtoms, atomCount, "_NET_FRAME_EXTENTS");
    _glfw.x11.NET_REQUEST_FRAME_EXTENTS =
        getSupportedAtom(supportedAtoms, atomCount, "_NET_REQUEST_FRAME_EXTENTS");
    _glfw.x11.NET_WM_BYPASS_COMPOSITOR =
        getSupportedAtom(supportedAtoms, atomCount, "_NET_WM_BYPASS_COMPOSITOR");

    XFree(supportedAtoms);
}