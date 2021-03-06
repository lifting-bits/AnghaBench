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
struct TYPE_5__ {int /*<<< orphan*/  adapterName; int /*<<< orphan*/  displayName; } ;
struct TYPE_6__ {TYPE_1__ win32; } ;
typedef  TYPE_2__ _GLFWmonitor ;
typedef  int GLFWbool ;

/* Variables and functions */
 scalar_t__ wcscmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ wcslen (int /*<<< orphan*/ ) ; 

GLFWbool _glfwPlatformIsSameMonitor(_GLFWmonitor* first, _GLFWmonitor* second)
{
    if (wcslen(first->win32.displayName))
        return wcscmp(first->win32.displayName, second->win32.displayName) == 0;
    else
        return wcscmp(first->win32.adapterName, second->win32.adapterName) == 0;
}