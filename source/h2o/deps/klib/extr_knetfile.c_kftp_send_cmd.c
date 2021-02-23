#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  ctrl_fd; } ;
typedef  TYPE_1__ knetFile ;

/* Variables and functions */
 int kftp_get_response (TYPE_1__*) ; 
 int /*<<< orphan*/  netwrite (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 
 scalar_t__ socket_wait (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlen (char const*) ; 

__attribute__((used)) static int kftp_send_cmd(knetFile *ftp, const char *cmd, int is_get)
{
	if (socket_wait(ftp->ctrl_fd, 0) <= 0) return -1; // socket is not ready for writing
	netwrite(ftp->ctrl_fd, cmd, strlen(cmd));
	return is_get? kftp_get_response(ftp) : 0;
}