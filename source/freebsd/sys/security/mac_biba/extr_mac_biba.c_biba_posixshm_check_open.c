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
struct shmfd {int dummy; } ;
struct mac_biba {int dummy; } ;
struct label {int dummy; } ;
typedef  int accmode_t ;

/* Variables and functions */
 int EACCES ; 
 struct mac_biba* SLOT (struct label*) ; 
 int VEXEC ; 
 int VMODIFY_PERMS ; 
 int VREAD ; 
 int VSTAT_PERMS ; 
 int /*<<< orphan*/  biba_dominate_effective (struct mac_biba*,struct mac_biba*) ; 
 int /*<<< orphan*/  biba_enabled ; 

__attribute__((used)) static int
biba_posixshm_check_open(struct ucred *cred, struct shmfd *shmfd,
    struct label *shmlabel, accmode_t accmode)
{
	struct mac_biba *subj, *obj;

	if (!biba_enabled)
		return (0);

	subj = SLOT(cred->cr_label);
	obj = SLOT(shmlabel);

	if (accmode & (VREAD | VEXEC | VSTAT_PERMS)) {
		if (!biba_dominate_effective(obj, subj))
			return (EACCES);
	}
	if (accmode & VMODIFY_PERMS) {
		if (!biba_dominate_effective(subj, obj))
			return (EACCES);
	}

	return (0);
}