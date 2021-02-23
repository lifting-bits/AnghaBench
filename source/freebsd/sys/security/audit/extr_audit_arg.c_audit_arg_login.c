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
struct TYPE_2__ {int /*<<< orphan*/  ar_arg_login; } ;
struct kaudit_record {TYPE_1__ k_ar; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARG_LOGIN ; 
 int /*<<< orphan*/  ARG_SET_VALID (struct kaudit_record*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAXLOGNAME ; 
 struct kaudit_record* currecord () ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 

void
audit_arg_login(char *login)
{
	struct kaudit_record *ar;

	ar = currecord();
	if (ar == NULL)
		return;

	strlcpy(ar->k_ar.ar_arg_login, login, MAXLOGNAME);
	ARG_SET_VALID(ar, ARG_LOGIN);
}