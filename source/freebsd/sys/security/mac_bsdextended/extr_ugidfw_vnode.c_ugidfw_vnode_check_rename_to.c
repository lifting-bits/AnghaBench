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
struct ucred {int dummy; } ;
struct label {int dummy; } ;
struct componentname {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MBI_WRITE ; 
 int ugidfw_check_vp (struct ucred*,struct vnode*,int /*<<< orphan*/ ) ; 

int
ugidfw_vnode_check_rename_to(struct ucred *cred, struct vnode *dvp,
    struct label *dvplabel, struct vnode *vp, struct label *vplabel,
    int samedir, struct componentname *cnp)
{
	int error;

	error = ugidfw_check_vp(cred, dvp, MBI_WRITE);
	if (error)
		return (error);
	if (vp != NULL)
		error = ugidfw_check_vp(cred, vp, MBI_WRITE);
	return (error);
}