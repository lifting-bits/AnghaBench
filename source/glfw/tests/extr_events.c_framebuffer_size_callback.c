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
struct TYPE_3__ {int number; } ;
typedef  TYPE_1__ Slot ;
typedef  int /*<<< orphan*/  GLFWwindow ;

/* Variables and functions */
 int /*<<< orphan*/  counter ; 
 double glfwGetTime () ; 
 TYPE_1__* glfwGetWindowUserPointer (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  printf (char*,int /*<<< orphan*/ ,int,double,int,int) ; 

__attribute__((used)) static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    Slot* slot = glfwGetWindowUserPointer(window);
    printf("%08x to %i at %0.3f: Framebuffer size: %i %i\n",
           counter++, slot->number, glfwGetTime(), width, height);
}