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
struct ucred {int dummy; } ;
struct semid_kernel {int /*<<< orphan*/  label; } ;

/* Variables and functions */
 int /*<<< orphan*/  MAC_POLICY_CHECK_NOSLEEP (int /*<<< orphan*/ ,struct ucred*,struct semid_kernel*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sysvsem_check_semget ; 

int
mac_sysvsem_check_semget(struct ucred *cred, struct semid_kernel *semakptr)
{
	int error;

	MAC_POLICY_CHECK_NOSLEEP(sysvsem_check_semget, cred, semakptr,
	    semakptr->label);

	return (error);
}