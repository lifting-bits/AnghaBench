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
 double glfwGetTime () ; 
 int /*<<< orphan*/  printf (char*,double,char*) ; 

__attribute__((used)) static void window_maximize_callback(GLFWwindow* window, int maximized)
{
    printf("%0.2f Window %s\n",
           glfwGetTime(),
           maximized ? "maximized" : "unmaximized");
}