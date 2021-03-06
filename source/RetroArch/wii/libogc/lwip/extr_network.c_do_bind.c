#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_8__ {int /*<<< orphan*/  port; int /*<<< orphan*/  ipaddr; } ;
struct TYPE_9__ {TYPE_2__ bc; } ;
struct apimsg_msg {TYPE_4__* conn; TYPE_3__ msg; } ;
struct TYPE_7__ {int /*<<< orphan*/ * tcp; void* udp; int /*<<< orphan*/  raw; } ;
struct TYPE_10__ {int type; int /*<<< orphan*/  mbox; TYPE_1__ pcb; int /*<<< orphan*/  err; } ;

/* Variables and functions */
 int /*<<< orphan*/  MQ_MSG_BLOCK ; 
 int /*<<< orphan*/  MQ_Send (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
#define  NETCONN_RAW 132 
#define  NETCONN_TCP 131 
#define  NETCONN_UDP 130 
#define  NETCONN_UDPLITE 129 
#define  NETCONN_UDPNOCHKSUM 128 
 int /*<<< orphan*/  UDP_FLAGS_NOCHKSUM ; 
 int /*<<< orphan*/  UDP_FLAGS_UDPLITE ; 
 int /*<<< orphan*/  raw_bind (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  raw_new (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  raw_recv (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_4__*) ; 
 int /*<<< orphan*/  recv_raw ; 
 int /*<<< orphan*/  recv_udp ; 
 int /*<<< orphan*/  setuptcp (TYPE_4__*) ; 
 int /*<<< orphan*/  tcp_bind (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * tcp_new () ; 
 int /*<<< orphan*/  udp_bind (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* udp_new () ; 
 int /*<<< orphan*/  udp_recv (void*,int /*<<< orphan*/ ,TYPE_4__*) ; 
 int /*<<< orphan*/  udp_setflags (void*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void do_bind(struct apimsg_msg *msg)
{
	u32 dummy = 0;

	if(msg->conn->pcb.tcp==NULL) {
		switch(msg->conn->type) {
			case NETCONN_RAW:
				msg->conn->pcb.raw = raw_new(msg->msg.bc.port);
				raw_recv(msg->conn->pcb.raw,recv_raw,msg->conn);
				break;
			case NETCONN_UDPLITE:
				msg->conn->pcb.udp = udp_new();
				udp_setflags(msg->conn->pcb.udp,UDP_FLAGS_UDPLITE);
				udp_recv(msg->conn->pcb.udp,recv_udp,msg->conn);
				break;
			case NETCONN_UDPNOCHKSUM:
				msg->conn->pcb.udp = udp_new();
				udp_setflags(msg->conn->pcb.udp,UDP_FLAGS_NOCHKSUM);
				udp_recv(msg->conn->pcb.udp,recv_udp,msg->conn);
				break;
			case NETCONN_UDP:
				msg->conn->pcb.udp = udp_new();
				udp_recv(msg->conn->pcb.udp,recv_udp,msg->conn);
				break;
			case NETCONN_TCP:
				msg->conn->pcb.tcp = tcp_new();
				setuptcp(msg->conn);
				break;
			default:
				break;
		}
	}
	switch(msg->conn->type) {
		case NETCONN_RAW:
			msg->conn->err = raw_bind(msg->conn->pcb.raw,msg->msg.bc.ipaddr);
			break;
		case NETCONN_UDPLITE:
		case NETCONN_UDPNOCHKSUM:
		case NETCONN_UDP:
			msg->conn->err = udp_bind(msg->conn->pcb.udp,msg->msg.bc.ipaddr,msg->msg.bc.port);
			break;
		case NETCONN_TCP:
			msg->conn->err = tcp_bind(msg->conn->pcb.tcp,msg->msg.bc.ipaddr,msg->msg.bc.port);
			break;
		default:
			break;
	}
	MQ_Send(msg->conn->mbox,&dummy,MQ_MSG_BLOCK);
}