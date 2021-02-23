#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct timespec {int dummy; } ;
struct task_struct {int /*<<< orphan*/  tgid; int /*<<< orphan*/  pid; } ;
struct TYPE_3__ {int /*<<< orphan*/  process_tgid; int /*<<< orphan*/  process_pid; } ;
struct TYPE_4__ {TYPE_1__ exec; } ;
struct proc_event {TYPE_2__ event_data; int /*<<< orphan*/  what; int /*<<< orphan*/  timestamp_ns; int /*<<< orphan*/  cpu; } ;
struct cn_msg {int len; scalar_t__ ack; int /*<<< orphan*/  id; int /*<<< orphan*/  seq; scalar_t__ data; } ;
typedef  int /*<<< orphan*/  __u8 ;
typedef  int /*<<< orphan*/  __u64 ;

/* Variables and functions */
 int /*<<< orphan*/  CN_IDX_PROC ; 
 int CN_PROC_MSG_SIZE ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  PROC_EVENT_EXEC ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cn_netlink_send (struct cn_msg*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cn_proc_event_id ; 
 int /*<<< orphan*/  get_seq (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ktime_get_ts (struct timespec*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  proc_event_num_listeners ; 
 int /*<<< orphan*/  put_unaligned (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  timespec_to_ns (struct timespec*) ; 

void proc_exec_connector(struct task_struct *task)
{
	struct cn_msg *msg;
	struct proc_event *ev;
	struct timespec ts;
	__u8 buffer[CN_PROC_MSG_SIZE];

	if (atomic_read(&proc_event_num_listeners) < 1)
		return;

	msg = (struct cn_msg*)buffer;
	ev = (struct proc_event*)msg->data;
	get_seq(&msg->seq, &ev->cpu);
	ktime_get_ts(&ts); /* get high res monotonic timestamp */
	put_unaligned(timespec_to_ns(&ts), (__u64 *)&ev->timestamp_ns);
	ev->what = PROC_EVENT_EXEC;
	ev->event_data.exec.process_pid = task->pid;
	ev->event_data.exec.process_tgid = task->tgid;

	memcpy(&msg->id, &cn_proc_event_id, sizeof(msg->id));
	msg->ack = 0; /* not used */
	msg->len = sizeof(*ev);
	cn_netlink_send(msg, CN_IDX_PROC, GFP_KERNEL);
}