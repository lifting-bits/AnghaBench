#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {scalar_t__ io_timestamp; } ;
typedef  TYPE_2__ zio_t ;
struct TYPE_11__ {int /*<<< orphan*/  vq_lock; int /*<<< orphan*/  vq_io_complete_ts; int /*<<< orphan*/  vq_active_tree; } ;
struct TYPE_10__ {int vdev_children; int /*<<< orphan*/  vdev_path; scalar_t__ vdev_guid; int /*<<< orphan*/ * vdev_spa; TYPE_4__ vdev_queue; TYPE_1__* vdev_ops; struct TYPE_10__** vdev_child; } ;
typedef  TYPE_3__ vdev_t ;
typedef  TYPE_4__ vdev_queue_t ;
typedef  scalar_t__ uint64_t ;
typedef  int /*<<< orphan*/  u_longlong_t ;
typedef  int /*<<< orphan*/  spa_t ;
struct TYPE_8__ {scalar_t__ vdev_op_leaf; } ;

/* Variables and functions */
 TYPE_2__* avl_first (int /*<<< orphan*/ *) ; 
 scalar_t__ avl_numnodes (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fm_panic (char*,int /*<<< orphan*/ ,unsigned long long,int /*<<< orphan*/ ) ; 
 scalar_t__ gethrtime () ; 
 int /*<<< orphan*/  mutex_enter (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_exit (int /*<<< orphan*/ *) ; 
 scalar_t__ spa_deadman_synctime (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spa_name (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vdev_dbgmsg (TYPE_3__*,char*,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
vdev_deadman(vdev_t *vd)
{
	for (int c = 0; c < vd->vdev_children; c++) {
		vdev_t *cvd = vd->vdev_child[c];

		vdev_deadman(cvd);
	}

	if (vd->vdev_ops->vdev_op_leaf) {
		vdev_queue_t *vq = &vd->vdev_queue;

		mutex_enter(&vq->vq_lock);
		if (avl_numnodes(&vq->vq_active_tree) > 0) {
			spa_t *spa = vd->vdev_spa;
			zio_t *fio;
			uint64_t delta;

			/*
			 * Look at the head of all the pending queues,
			 * if any I/O has been outstanding for longer than
			 * the spa_deadman_synctime we panic the system.
			 */
			fio = avl_first(&vq->vq_active_tree);
			delta = gethrtime() - fio->io_timestamp;
			if (delta > spa_deadman_synctime(spa)) {
				vdev_dbgmsg(vd, "SLOW IO: zio timestamp "
				    "%lluns, delta %lluns, last io %lluns",
				    fio->io_timestamp, (u_longlong_t)delta,
				    vq->vq_io_complete_ts);
				fm_panic("I/O to pool '%s' appears to be "
				    "hung on vdev guid %llu at '%s'.",
				    spa_name(spa),
				    (long long unsigned int) vd->vdev_guid,
				    vd->vdev_path);
			}
		}
		mutex_exit(&vq->vq_lock);
	}
}