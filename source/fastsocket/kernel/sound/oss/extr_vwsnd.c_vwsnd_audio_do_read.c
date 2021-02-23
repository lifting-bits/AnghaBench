#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {int flags; int swb_u_idx; int /*<<< orphan*/ * swbuf; int /*<<< orphan*/  queue; } ;
typedef  TYPE_1__ vwsnd_port_t ;
struct TYPE_12__ {TYPE_1__ wport; TYPE_1__ rport; } ;
typedef  TYPE_2__ vwsnd_dev_t ;
struct file {int f_mode; int f_flags; TYPE_2__* private_data; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  loff_t ;
struct TYPE_13__ {void* state; } ;

/* Variables and functions */
 int /*<<< orphan*/  DBGEV (char*,struct file*,char*,size_t,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DBGPV (char*,...) ; 
 int /*<<< orphan*/  DECLARE_WAITQUEUE (int /*<<< orphan*/ ,TYPE_4__*) ; 
 int DISABLED ; 
 int EAGAIN ; 
 int EFAULT ; 
 int EINVAL ; 
 int ERESTARTSYS ; 
 int FMODE_READ ; 
 int FMODE_WRITE ; 
 int O_NONBLOCK ; 
 int /*<<< orphan*/  TASK_INTERRUPTIBLE ; 
 void* TASK_RUNNING ; 
 int /*<<< orphan*/  VERIFY_READ ; 
 int /*<<< orphan*/  access_ok (int /*<<< orphan*/ ,char*,size_t) ; 
 int /*<<< orphan*/  add_wait_queue (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ copy_to_user (char*,int /*<<< orphan*/ *,int) ; 
 TYPE_4__* current ; 
 int /*<<< orphan*/  pcm_input (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int pcm_setup (TYPE_2__*,TYPE_1__*,TYPE_1__*) ; 
 int /*<<< orphan*/  remove_wait_queue (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  schedule () ; 
 int /*<<< orphan*/  set_current_state (int /*<<< orphan*/ ) ; 
 scalar_t__ signal_pending (TYPE_4__*) ; 
 int swb_inc_u (TYPE_1__*,int) ; 
 int /*<<< orphan*/  wait ; 

__attribute__((used)) static ssize_t vwsnd_audio_do_read(struct file *file,
				   char *buffer,
				   size_t count,
				   loff_t *ppos)
{
	vwsnd_dev_t *devc = file->private_data;
	vwsnd_port_t *rport = ((file->f_mode & FMODE_READ) ?
			       &devc->rport : NULL);
	int ret, nb;

	DBGEV("(file=0x%p, buffer=0x%p, count=%d, ppos=0x%p)\n",
	     file, buffer, count, ppos);

	if (!rport)
		return -EINVAL;

	if (rport->swbuf == NULL) {
		vwsnd_port_t *wport = (file->f_mode & FMODE_WRITE) ?
			&devc->wport : NULL;
		ret = pcm_setup(devc, rport, wport);
		if (ret < 0)
			return ret;
	}

	if (!access_ok(VERIFY_READ, buffer, count))
		return -EFAULT;
	ret = 0;
	while (count) {
		DECLARE_WAITQUEUE(wait, current);
		add_wait_queue(&rport->queue, &wait);
		while ((nb = swb_inc_u(rport, 0)) == 0) {
			DBGPV("blocking\n");
			set_current_state(TASK_INTERRUPTIBLE);
			if (rport->flags & DISABLED ||
			    file->f_flags & O_NONBLOCK) {
				current->state = TASK_RUNNING;
				remove_wait_queue(&rport->queue, &wait);
				return ret ? ret : -EAGAIN;
			}
			schedule();
			if (signal_pending(current)) {
				current->state = TASK_RUNNING;
				remove_wait_queue(&rport->queue, &wait);
				return ret ? ret : -ERESTARTSYS;
			}
		}
		current->state = TASK_RUNNING;
		remove_wait_queue(&rport->queue, &wait);
		pcm_input(devc, 0, 0);
		/* nb bytes are available in userbuf. */
		if (nb > count)
			nb = count;
		DBGPV("nb = %d\n", nb);
		if (copy_to_user(buffer, rport->swbuf + rport->swb_u_idx, nb))
			return -EFAULT;
		(void) swb_inc_u(rport, nb);
		buffer += nb;
		count -= nb;
		ret += nb;
	}
	DBGPV("returning %d\n", ret);
	return ret;
}