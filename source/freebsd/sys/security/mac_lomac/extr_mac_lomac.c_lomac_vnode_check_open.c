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
struct vnode {int dummy; } ;
struct ucred {struct label* cr_label; } ;
struct mac_lomac {int dummy; } ;
struct label {int dummy; } ;
typedef  int accmode_t ;

/* Variables and functions */
 int EACCES ; 
 struct mac_lomac* SLOT (struct label*) ; 
 int VMODIFY_PERMS ; 
 int /*<<< orphan*/  lomac_enabled ; 
 int /*<<< orphan*/  lomac_subject_dominate (struct mac_lomac*,struct mac_lomac*) ; 

__attribute__((used)) static int
lomac_vnode_check_open(struct ucred *cred, struct vnode *vp,
    struct label *vplabel, accmode_t accmode)
{
	struct mac_lomac *subj, *obj;

	if (!lomac_enabled)
		return (0);

	subj = SLOT(cred->cr_label);
	obj = SLOT(vplabel);

	/* XXX privilege override for admin? */
	if (accmode & VMODIFY_PERMS) {
		if (!lomac_subject_dominate(subj, obj))
			return (EACCES);
	}

	return (0);
}