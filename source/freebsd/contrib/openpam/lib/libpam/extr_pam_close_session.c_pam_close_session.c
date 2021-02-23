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
typedef  int /*<<< orphan*/  pam_handle_t ;

/* Variables and functions */
 int /*<<< orphan*/  ENTER () ; 
 int PAM_BAD_CONSTANT ; 
 int PAM_SILENT ; 
 int /*<<< orphan*/  PAM_SM_CLOSE_SESSION ; 
 int /*<<< orphan*/  RETURNC (int) ; 
 int openpam_dispatch (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 

int
pam_close_session(pam_handle_t *pamh,
	int flags)
{
	int r;

	ENTER();
	if (flags & ~(PAM_SILENT))
		RETURNC(PAM_BAD_CONSTANT);
	r = openpam_dispatch(pamh, PAM_SM_CLOSE_SESSION, flags);
	RETURNC(r);
}