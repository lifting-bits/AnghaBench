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
struct window_pane {int dummy; } ;
struct cmd_find_state {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  cmd_find_from_pane (struct cmd_find_state*,struct window_pane*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  notify_add (char const*,struct cmd_find_state*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct window_pane*) ; 

void
notify_pane(const char *name, struct window_pane *wp)
{
	struct cmd_find_state	fs;

	cmd_find_from_pane(&fs, wp, 0);
	notify_add(name, &fs, NULL, NULL, NULL, wp);
}