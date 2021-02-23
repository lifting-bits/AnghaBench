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
 int /*<<< orphan*/  DLOG (char*) ; 
 int /*<<< orphan*/  draw_bars (int) ; 
 int /*<<< orphan*/  parse_workspaces_json (char*) ; 

__attribute__((used)) static void got_workspace_reply(char *reply) {
    DLOG("Got workspace data!\n");
    parse_workspaces_json(reply);
    draw_bars(false);
}