#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  cmd ;
struct TYPE_6__ {int /*<<< orphan*/  type; int /*<<< orphan*/  repo_id; } ;
typedef  TYPE_1__ WatchCommand ;
struct TYPE_7__ {int /*<<< orphan*/ * res_pipe; int /*<<< orphan*/ * cmd_pipe; } ;
typedef  TYPE_2__ SeafWTMonitor ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_REFRESH_WATCH ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,char const*,int) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  seaf_debug (char*,char const*) ; 
 int seaf_pipe_readn (int /*<<< orphan*/ ,int*,int) ; 
 int seaf_pipe_writen (int /*<<< orphan*/ ,TYPE_1__*,int) ; 
 int /*<<< orphan*/  seaf_warning (char*) ; 

int
seaf_wt_monitor_refresh_repo (SeafWTMonitor *monitor, const char *repo_id)
{
    WatchCommand cmd;
    int res;

    memset (&cmd, 0, sizeof(cmd));
    memcpy (cmd.repo_id, repo_id, 37);
    cmd.type = CMD_REFRESH_WATCH;

    int n = seaf_pipe_writen (monitor->cmd_pipe[1], &cmd, sizeof(cmd));

    if (n != sizeof(cmd)) {
        seaf_warning ("[wt mon] fail to write command pipe.\n");
        return -1;
    }

    seaf_debug ("send a refresh command, repo %s\n", repo_id);

    n = seaf_pipe_readn (monitor->res_pipe[0], &res, sizeof(int));
    if (n != sizeof(int)) {
        seaf_warning ("[wt mon] fail to read result pipe.\n");
        return -1;
    }

    return res;
}