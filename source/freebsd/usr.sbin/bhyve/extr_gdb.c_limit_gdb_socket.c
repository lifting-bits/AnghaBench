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
typedef  int /*<<< orphan*/  cap_rights_t ;

/* Variables and functions */
 int /*<<< orphan*/  CAP_ACCEPT ; 
 int /*<<< orphan*/  CAP_EVENT ; 
 int /*<<< orphan*/  CAP_IOCTL ; 
 int /*<<< orphan*/  CAP_READ ; 
 int /*<<< orphan*/  CAP_SETSOCKOPT ; 
 int /*<<< orphan*/  CAP_WRITE ; 
 int /*<<< orphan*/  EX_OSERR ; 
 unsigned long FIONREAD ; 
 int /*<<< orphan*/  cap_rights_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int caph_ioctls_limit (int,unsigned long*,int /*<<< orphan*/ ) ; 
 int caph_rights_limit (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  errx (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  nitems (unsigned long*) ; 

void
limit_gdb_socket(int s)
{
	cap_rights_t rights;
	unsigned long ioctls[] = { FIONREAD };

	cap_rights_init(&rights, CAP_ACCEPT, CAP_EVENT, CAP_READ, CAP_WRITE,
	    CAP_SETSOCKOPT, CAP_IOCTL);
	if (caph_rights_limit(s, &rights) == -1)
		errx(EX_OSERR, "Unable to apply rights for sandbox");
	if (caph_ioctls_limit(s, ioctls, nitems(ioctls)) == -1)
		errx(EX_OSERR, "Unable to apply rights for sandbox");
}