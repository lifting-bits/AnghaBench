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
struct ipmi_smi_msg {int rsp_size; int* rsp; int* data; int data_size; } ;
struct ipmi_smi_handlers {int /*<<< orphan*/  (* sender ) (int /*<<< orphan*/ ,struct ipmi_smi_msg*,int /*<<< orphan*/ ) ;} ;
struct TYPE_9__ {int netfn; int cmd; int data_len; int /*<<< orphan*/  data; } ;
struct ipmi_recv_msg {int msgid; int /*<<< orphan*/  msg_data; TYPE_2__ msg; int /*<<< orphan*/  recv_type; TYPE_3__* user; int /*<<< orphan*/  addr; } ;
struct ipmi_ipmb_addr {int slave_addr; int lun; int channel; int /*<<< orphan*/  addr_type; } ;
struct cmd_rcvr {TYPE_3__* user; } ;
typedef  TYPE_3__* ipmi_user_t ;
typedef  TYPE_4__* ipmi_smi_t ;
struct TYPE_11__ {int /*<<< orphan*/  send_info; struct ipmi_smi_handlers* handlers; TYPE_1__* channels; } ;
struct TYPE_10__ {int /*<<< orphan*/  refcount; } ;
struct TYPE_8__ {unsigned char address; } ;

/* Variables and functions */
 int /*<<< orphan*/  IPMI_CMD_RECV_TYPE ; 
 int IPMI_INVALID_CMD_COMPLETION_CODE ; 
 int /*<<< orphan*/  IPMI_IPMB_ADDR_TYPE ; 
 int IPMI_NETFN_APP_REQUEST ; 
 int IPMI_SEND_MSG_CMD ; 
 int /*<<< orphan*/  deliver_response (struct ipmi_recv_msg*) ; 
 struct cmd_rcvr* find_cmd_rcvr (TYPE_4__*,unsigned char,unsigned char,unsigned char) ; 
 int /*<<< orphan*/  free_user ; 
 int /*<<< orphan*/  handled_commands ; 
 int /*<<< orphan*/  invalid_commands ; 
 void* ipmb_checksum (unsigned char*,int) ; 
 struct ipmi_recv_msg* ipmi_alloc_recv_msg () ; 
 int /*<<< orphan*/  ipmi_inc_stat (TYPE_4__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int*,int) ; 
 int /*<<< orphan*/  printk (char*,...) ; 
 int /*<<< orphan*/  rcu_read_lock () ; 
 int /*<<< orphan*/  rcu_read_unlock () ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,struct ipmi_smi_msg*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  unhandled_commands ; 

__attribute__((used)) static int handle_ipmb_get_msg_cmd(ipmi_smi_t          intf,
				   struct ipmi_smi_msg *msg)
{
	struct cmd_rcvr          *rcvr;
	int                      rv = 0;
	unsigned char            netfn;
	unsigned char            cmd;
	unsigned char            chan;
	ipmi_user_t              user = NULL;
	struct ipmi_ipmb_addr    *ipmb_addr;
	struct ipmi_recv_msg     *recv_msg;
	struct ipmi_smi_handlers *handlers;

	if (msg->rsp_size < 10) {
		/* Message not big enough, just ignore it. */
		ipmi_inc_stat(intf, invalid_commands);
		return 0;
	}

	if (msg->rsp[2] != 0) {
		/* An error getting the response, just ignore it. */
		return 0;
	}

	netfn = msg->rsp[4] >> 2;
	cmd = msg->rsp[8];
	chan = msg->rsp[3] & 0xf;

	rcu_read_lock();
	rcvr = find_cmd_rcvr(intf, netfn, cmd, chan);
	if (rcvr) {
		user = rcvr->user;
		kref_get(&user->refcount);
	} else
		user = NULL;
	rcu_read_unlock();

	if (user == NULL) {
		/* We didn't find a user, deliver an error response. */
		ipmi_inc_stat(intf, unhandled_commands);

		msg->data[0] = (IPMI_NETFN_APP_REQUEST << 2);
		msg->data[1] = IPMI_SEND_MSG_CMD;
		msg->data[2] = msg->rsp[3];
		msg->data[3] = msg->rsp[6];
		msg->data[4] = ((netfn + 1) << 2) | (msg->rsp[7] & 0x3);
		msg->data[5] = ipmb_checksum(&(msg->data[3]), 2);
		msg->data[6] = intf->channels[msg->rsp[3] & 0xf].address;
		/* rqseq/lun */
		msg->data[7] = (msg->rsp[7] & 0xfc) | (msg->rsp[4] & 0x3);
		msg->data[8] = msg->rsp[8]; /* cmd */
		msg->data[9] = IPMI_INVALID_CMD_COMPLETION_CODE;
		msg->data[10] = ipmb_checksum(&(msg->data[6]), 4);
		msg->data_size = 11;

#ifdef DEBUG_MSGING
	{
		int m;
		printk("Invalid command:");
		for (m = 0; m < msg->data_size; m++)
			printk(" %2.2x", msg->data[m]);
		printk("\n");
	}
#endif
		rcu_read_lock();
		handlers = intf->handlers;
		if (handlers) {
			handlers->sender(intf->send_info, msg, 0);
			/*
			 * We used the message, so return the value
			 * that causes it to not be freed or
			 * queued.
			 */
			rv = -1;
		}
		rcu_read_unlock();
	} else {
		/* Deliver the message to the user. */
		ipmi_inc_stat(intf, handled_commands);

		recv_msg = ipmi_alloc_recv_msg();
		if (!recv_msg) {
			/*
			 * We couldn't allocate memory for the
			 * message, so requeue it for handling
			 * later.
			 */
			rv = 1;
			kref_put(&user->refcount, free_user);
		} else {
			/* Extract the source address from the data. */
			ipmb_addr = (struct ipmi_ipmb_addr *) &recv_msg->addr;
			ipmb_addr->addr_type = IPMI_IPMB_ADDR_TYPE;
			ipmb_addr->slave_addr = msg->rsp[6];
			ipmb_addr->lun = msg->rsp[7] & 3;
			ipmb_addr->channel = msg->rsp[3] & 0xf;

			/*
			 * Extract the rest of the message information
			 * from the IPMB header.
			 */
			recv_msg->user = user;
			recv_msg->recv_type = IPMI_CMD_RECV_TYPE;
			recv_msg->msgid = msg->rsp[7] >> 2;
			recv_msg->msg.netfn = msg->rsp[4] >> 2;
			recv_msg->msg.cmd = msg->rsp[8];
			recv_msg->msg.data = recv_msg->msg_data;

			/*
			 * We chop off 10, not 9 bytes because the checksum
			 * at the end also needs to be removed.
			 */
			recv_msg->msg.data_len = msg->rsp_size - 10;
			memcpy(recv_msg->msg_data,
			       &(msg->rsp[9]),
			       msg->rsp_size - 10);
			deliver_response(recv_msg);
		}
	}

	return rv;
}