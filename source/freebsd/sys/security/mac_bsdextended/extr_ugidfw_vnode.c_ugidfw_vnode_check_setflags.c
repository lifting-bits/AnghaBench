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
typedef  int /*<<< orphan*/  u_long ;
struct vnode {int dummy; } ;
struct ucred {int dummy; } ;
struct label {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MBI_ADMIN ; 
 int ugidfw_check_vp (struct ucred*,struct vnode*,int /*<<< orphan*/ ) ; 

int
ugidfw_vnode_check_setflags(struct ucred *cred, struct vnode *vp,
    struct label *vplabel, u_long flags)
{

	return (ugidfw_check_vp(cred, vp, MBI_ADMIN));
}