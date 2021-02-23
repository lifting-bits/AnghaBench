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
struct ng_btsocket_l2cap_raw_auto_discon_timo {int /*<<< orphan*/  timeout; } ;
typedef  int /*<<< orphan*/  r ;

/* Variables and functions */
 int ERROR ; 
 int OK ; 
 int /*<<< orphan*/  SIOC_L2CAP_NODE_SET_AUTO_DISCON_TIMO ; 
 int USAGE ; 
 int /*<<< orphan*/  atoi (char*) ; 
 scalar_t__ ioctl (int,int /*<<< orphan*/ ,struct ng_btsocket_l2cap_raw_auto_discon_timo*,int) ; 
 int /*<<< orphan*/  memset (struct ng_btsocket_l2cap_raw_auto_discon_timo*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int
l2cap_write_auto_disconnect_timeout(int s, int argc, char **argv)
{
	struct ng_btsocket_l2cap_raw_auto_discon_timo	r;

	memset(&r, 0, sizeof(r));
	switch (argc) {
	case 1:
		r.timeout = atoi(argv[0]);
		break;

	default:
		return (USAGE);
	}

	if (ioctl(s, SIOC_L2CAP_NODE_SET_AUTO_DISCON_TIMO, &r, sizeof(r)) < 0)
		return (ERROR);

	return (OK);
}