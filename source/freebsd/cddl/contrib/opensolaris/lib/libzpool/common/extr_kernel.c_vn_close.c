#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int v_fd; int v_dump_fd; int /*<<< orphan*/  v_path; } ;
typedef  TYPE_1__ vnode_t ;
typedef  int /*<<< orphan*/  kthread_t ;
typedef  int /*<<< orphan*/  cred_t ;

/* Variables and functions */
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  spa_strfree (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  umem_free (TYPE_1__*,int) ; 

void
vn_close(vnode_t *vp, int openflag, cred_t *cr, kthread_t *td)
{
	close(vp->v_fd);
	if (vp->v_dump_fd != -1)
		close(vp->v_dump_fd);
	spa_strfree(vp->v_path);
	umem_free(vp, sizeof (vnode_t));
}