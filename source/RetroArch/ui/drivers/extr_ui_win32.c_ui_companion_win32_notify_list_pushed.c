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
typedef  int /*<<< orphan*/  file_list_t ;

/* Variables and functions */

__attribute__((used)) static void ui_companion_win32_notify_list_pushed(void *data,
        file_list_t *list, file_list_t *menu_list)
{
    (void)data;
    (void)list;
    (void)menu_list;
}