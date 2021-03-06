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

/* Variables and functions */
 int /*<<< orphan*/  class_info ; 
 int /*<<< orphan*/  gdb_stdout ; 
 int /*<<< orphan*/  help_list (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  info_w32_cmdlist ; 

__attribute__((used)) static void
info_w32_command (char *args, int from_tty)
{
  help_list (info_w32_cmdlist, "info w32 ", class_info, gdb_stdout);
}