#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  sun_path; } ;
struct uds_ctx {int /*<<< orphan*/  uc_fd; int /*<<< orphan*/  uc_owner; TYPE_1__ uc_sun; } ;
struct sockaddr {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  UDS_SIDE_SERVER_LISTEN ; 
 int bind (int /*<<< orphan*/ ,struct sockaddr*,int) ; 
 int errno ; 
 int /*<<< orphan*/  getpid () ; 
 int listen (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  uds_close (struct uds_ctx*) ; 
 int uds_common_setup (char const*,void**,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  unlink (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
uds_server(const char *addr, void **ctxp)
{
	struct uds_ctx *uctx;
	int ret;

	ret = uds_common_setup(addr, ctxp, UDS_SIDE_SERVER_LISTEN);
	if (ret != 0)
		return (ret);

	uctx = *ctxp;

	(void)unlink(uctx->uc_sun.sun_path);
	if (bind(uctx->uc_fd, (struct sockaddr *)&uctx->uc_sun,
	    sizeof(uctx->uc_sun)) == -1) {
		ret = errno;
		uds_close(uctx);
		return (ret);
	}
	uctx->uc_owner = getpid();
	if (listen(uctx->uc_fd, 8) == -1) {
		ret = errno;
		uds_close(uctx);
		return (ret);
	}

	return (0);
}