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
typedef  int /*<<< orphan*/  GLFWwindow ;

/* Variables and functions */
 double cursor_x ; 
 double cursor_y ; 
 double glfwGetTime () ; 
 int /*<<< orphan*/  printf (char*,double,double,double,double,double) ; 

__attribute__((used)) static void cursor_position_callback(GLFWwindow* window, double x, double y)
{
    printf("%0.3f: Cursor position: %f %f (%+f %+f)\n",
           glfwGetTime(),
           x, y, x - cursor_x, y - cursor_y);

    cursor_x = x;
    cursor_y = y;
}