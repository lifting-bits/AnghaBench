#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* vnode_t ;
struct TYPE_5__ {int v_lflag; } ;

/* Variables and functions */
 int VNAMED_FSHASH ; 
 int /*<<< orphan*/  panic (char*) ; 
 int /*<<< orphan*/  vnode_lock_spin (TYPE_1__*) ; 
 int /*<<< orphan*/  vnode_unlock (TYPE_1__*) ; 

int
vnode_removefsref(vnode_t vp)
{
	vnode_lock_spin(vp);
	if ((vp->v_lflag & VNAMED_FSHASH) == 0)
		panic("remove_fsref: no named reference");
	vp->v_lflag &= ~VNAMED_FSHASH;
	vnode_unlock(vp);
	return(0);

}