#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct sockaddr_storage {int dummy; } ;
struct outside_network {int /*<<< orphan*/  base; int /*<<< orphan*/  tcp_mss; } ;
struct TYPE_2__ {int /*<<< orphan*/  addr; int /*<<< orphan*/  addrlen; } ;
struct comm_point {int /*<<< orphan*/  buffer; TYPE_1__ repinfo; } ;
typedef  int /*<<< orphan*/  socklen_t ;
typedef  int /*<<< orphan*/  sldns_buffer ;
typedef  int /*<<< orphan*/  comm_point_callback_type ;

/* Variables and functions */
 int /*<<< orphan*/  close (int) ; 
 struct comm_point* comm_point_create_tcp_out (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,void*) ; 
 int /*<<< orphan*/  comm_point_delete (struct comm_point*) ; 
 int /*<<< orphan*/  comm_point_start_listening (struct comm_point*,int,int) ; 
 int /*<<< orphan*/  fd_set_nonblock (int) ; 
 int /*<<< orphan*/  log_err (char*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,struct sockaddr_storage*,int /*<<< orphan*/ ) ; 
 int outnet_get_tcp_fd (struct sockaddr_storage*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outnet_tcp_connect (int,struct sockaddr_storage*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  setup_comm_ssl (struct comm_point*,struct outside_network*,int,char*) ; 
 int /*<<< orphan*/  sldns_buffer_copy (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

struct comm_point*
outnet_comm_point_for_tcp(struct outside_network* outnet,
	comm_point_callback_type* cb, void* cb_arg,
	struct sockaddr_storage* to_addr, socklen_t to_addrlen,
	sldns_buffer* query, int timeout, int ssl, char* host)
{
	struct comm_point* cp;
	int fd = outnet_get_tcp_fd(to_addr, to_addrlen, outnet->tcp_mss);
	if(fd == -1) {
		return 0;
	}
	fd_set_nonblock(fd);
	if(!outnet_tcp_connect(fd, to_addr, to_addrlen)) {
		/* outnet_tcp_connect has closed fd on error for us */
		return 0;
	}
	cp = comm_point_create_tcp_out(outnet->base, 65552, cb, cb_arg);
	if(!cp) {
		log_err("malloc failure");
		close(fd);
		return 0;
	}
	cp->repinfo.addrlen = to_addrlen;
	memcpy(&cp->repinfo.addr, to_addr, to_addrlen);

	/* setup for SSL (if needed) */
	if(ssl) {
		if(!setup_comm_ssl(cp, outnet, fd, host)) {
			log_err("cannot setup XoT");
			comm_point_delete(cp);
			return NULL;
		}
	}

	/* set timeout on TCP connection */
	comm_point_start_listening(cp, fd, timeout);
	/* copy scratch buffer to cp->buffer */
	sldns_buffer_copy(cp->buffer, query);
	return cp;
}