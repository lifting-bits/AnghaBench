#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  GLFWvidmode ;

/* Variables and functions */
 int compareVideoModes (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 

int _glfwCompareVideoModes(const GLFWvidmode* first, const GLFWvidmode* second)
{
    return compareVideoModes(first, second);
}