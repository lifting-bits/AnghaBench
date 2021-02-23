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
 int /*<<< orphan*/  PAM_SYSTEM_ERR ; 
 int /*<<< orphan*/  RETURNC (int /*<<< orphan*/ ) ; 

int
pam_sm_set_mapped_authtok(pam_handle_t *pamh,
	char *target_module_username,
	size_t target_authtok_len,
	unsigned char *target_module_authtok,
	char *target_module_type,
	char *target_authn_domain,
	int argc,
	const char *argv)
{

	ENTER();
	RETURNC(PAM_SYSTEM_ERR);
}