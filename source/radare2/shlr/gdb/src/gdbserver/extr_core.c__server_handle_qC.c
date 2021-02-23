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
typedef  int /*<<< orphan*/  libgdbr_t ;
typedef  int (* gdbr_server_cmd_cb ) (int /*<<< orphan*/ *,void*,char*,char*,size_t) ;

/* Variables and functions */
 int /*<<< orphan*/  free (char*) ; 
 char* malloc (size_t) ; 
 int send_ack (int /*<<< orphan*/ *) ; 
 int send_msg (int /*<<< orphan*/ *,char*) ; 

__attribute__((used)) static int _server_handle_qC(libgdbr_t *g, gdbr_server_cmd_cb cmd_cb, void *core_ptr) {
	char *buf;
	int ret;
	size_t buf_len = 80;
	if ((ret = send_ack (g)) < 0) {
		return -1;
	}
	if (!(buf = malloc (buf_len))) {
		return -1;
	}
	if ((ret = cmd_cb (g, core_ptr, "dp", buf, buf_len)) < 0) {
		free (buf);
		return -1;
	}
	ret = send_msg (g, buf);
	free (buf);
	return ret;
}