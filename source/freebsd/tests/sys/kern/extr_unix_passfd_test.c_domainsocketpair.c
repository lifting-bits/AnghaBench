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
 int /*<<< orphan*/  ATF_REQUIRE_MSG (int,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PF_UNIX ; 
 int /*<<< orphan*/  SOCK_STREAM ; 
 int /*<<< orphan*/  errno ; 
 int socketpair (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  strerror (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
domainsocketpair(int *fdp)
{

	ATF_REQUIRE_MSG(socketpair(PF_UNIX, SOCK_STREAM, 0, fdp) != -1,
	    "socketpair(PF_UNIX, SOCK_STREAM) failed: %s", strerror(errno));
}