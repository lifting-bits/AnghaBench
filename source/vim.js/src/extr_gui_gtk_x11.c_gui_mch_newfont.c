#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  mainwin; } ;

/* Variables and functions */
 int /*<<< orphan*/  GTK_WINDOW (int /*<<< orphan*/ ) ; 
 scalar_t__ get_menu_tool_height () ; 
 scalar_t__ get_menu_tool_width () ; 
 int /*<<< orphan*/  gtk_window_get_size (int /*<<< orphan*/ ,int*,int*) ; 
 TYPE_1__ gui ; 
 int /*<<< orphan*/  gui_resize_shell (int,int) ; 

void
gui_mch_newfont()
{
    int w, h;

    gtk_window_get_size(GTK_WINDOW(gui.mainwin), &w, &h);
    w -= get_menu_tool_width();
    h -= get_menu_tool_height();
    gui_resize_shell(w, h);
}