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
struct ucred {struct label* cr_label; } ;
struct msqid_kernel {int dummy; } ;
struct mac_mls {int dummy; } ;
struct label {int dummy; } ;

/* Variables and functions */
 int EACCES ; 
#define  IPC_RMID 130 
#define  IPC_SET 129 
#define  IPC_STAT 128 
 struct mac_mls* SLOT (struct label*) ; 
 int /*<<< orphan*/  mls_dominate_effective (struct mac_mls*,struct mac_mls*) ; 
 int /*<<< orphan*/  mls_enabled ; 

__attribute__((used)) static int
mls_sysvmsq_check_msqctl(struct ucred *cred, struct msqid_kernel *msqkptr,
    struct label *msqklabel, int cmd)
{
	struct mac_mls *subj, *obj;

	if (!mls_enabled)
		return (0);

	subj = SLOT(cred->cr_label);
	obj = SLOT(msqklabel);

	switch(cmd) {
	case IPC_RMID:
	case IPC_SET:
		if (!mls_dominate_effective(obj, subj))
			return (EACCES);
		break;

	case IPC_STAT:
		if (!mls_dominate_effective(subj, obj))
			return (EACCES);
		break;

	default:
		return (EACCES);
	}

	return (0);
}