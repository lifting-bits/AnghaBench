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
struct wpa_ctrl {int dummy; } ;
typedef  int /*<<< orphan*/  cmd ;
typedef  int /*<<< orphan*/  addr ;

/* Variables and functions */
 int /*<<< orphan*/  cli_txt_list_add (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  cli_txt_list_flush (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  interactive ; 
 int /*<<< orphan*/  os_snprintf (char*,int,char*,char*) ; 
 scalar_t__ os_strcmp (char*,char*) ; 
 int /*<<< orphan*/  stations ; 
 scalar_t__ wpa_ctrl_command_sta (struct wpa_ctrl*,char*,char*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void update_stations(struct wpa_ctrl *ctrl)
{
	char addr[32], cmd[64];

	if (!ctrl || !interactive)
		return;

	cli_txt_list_flush(&stations);

	if (wpa_ctrl_command_sta(ctrl, "STA-FIRST", addr, sizeof(addr), 0))
		return;
	do {
		if (os_strcmp(addr, "") != 0)
			cli_txt_list_add(&stations, addr);
		os_snprintf(cmd, sizeof(cmd), "STA-NEXT %s", addr);
	} while (wpa_ctrl_command_sta(ctrl, cmd, addr, sizeof(addr), 0) == 0);
}