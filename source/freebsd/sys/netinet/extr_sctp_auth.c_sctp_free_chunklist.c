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
typedef  int /*<<< orphan*/  sctp_auth_chklist_t ;

/* Variables and functions */
 int /*<<< orphan*/  SCTP_FREE (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SCTP_M_AUTH_CL ; 

void
sctp_free_chunklist(sctp_auth_chklist_t *list)
{
	if (list != NULL)
		SCTP_FREE(list, SCTP_M_AUTH_CL);
}