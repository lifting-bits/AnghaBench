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
typedef  int /*<<< orphan*/ * acl_flagset_t ;
typedef  int /*<<< orphan*/  acl_flag_t ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 scalar_t__ _flag_is_invalid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errno ; 

int
acl_delete_flag_np(acl_flagset_t flagset_d, acl_flag_t flag)
{

	if (flagset_d == NULL) {
		errno = EINVAL;
		return (-1);
	}

	if (_flag_is_invalid(flag))
		return (-1);

	*flagset_d &= ~flag;

	return (0);
}