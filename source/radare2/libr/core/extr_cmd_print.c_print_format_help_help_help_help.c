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
typedef  int /*<<< orphan*/  RCore ;

/* Variables and functions */
 int /*<<< orphan*/  r_core_cmd_help (int /*<<< orphan*/ *,char const**) ; 

__attribute__((used)) static void print_format_help_help_help_help(RCore *core) {
	const char *help_msg[] = {
		"    STAHP IT!!!", "", "",
		NULL
	};
	r_core_cmd_help (core, help_msg);
}