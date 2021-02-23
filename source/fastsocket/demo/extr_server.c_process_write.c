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
struct TYPE_3__ {struct conn_context* ptr; } ;
struct epoll_event {int events; TYPE_1__ data; } ;
struct conn_context {int events; int cpu_id; int ep_fd; int fd; int /*<<< orphan*/  handler; } ;
struct TYPE_4__ {int /*<<< orphan*/  trancnt; int /*<<< orphan*/  write_cnt; } ;

/* Variables and functions */
 int EPOLLERR ; 
 int EPOLLHUP ; 
 int EPOLLIN ; 
 int /*<<< orphan*/  EPOLL_CTL_MOD ; 
 int /*<<< orphan*/  enable_keepalive ; 
 int epoll_ctl (int,int /*<<< orphan*/ ,int,struct epoll_event*) ; 
 int /*<<< orphan*/  free_context (struct conn_context*) ; 
 int /*<<< orphan*/  http_response ; 
 int /*<<< orphan*/  http_response_len ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  print_d (char*,int,...) ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  process_close (struct conn_context*) ; 
 int /*<<< orphan*/  process_read ; 
 TYPE_2__* wdata ; 
 int write (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void process_write(struct conn_context *client_ctx)
{
	int ep_fd, fd;
	int events = client_ctx->events;
	int cpu_id = client_ctx->cpu_id;
	int ret;
	struct epoll_event evt;

	ep_fd = client_ctx->ep_fd;
	fd = client_ctx->fd;

	print_d("Process write event[%02x]\n", events);

	if (events & (EPOLLHUP | EPOLLERR)) {
		printf("process_write() with events HUP or ERR\n");
		goto free_back;
	}

	ret = write(fd, http_response, http_response_len);
	if (ret < 0) {
		wdata[cpu_id].write_cnt++;
		perror("process_write() can't write client socket");
		goto free_back;
	}

	print_d("Write %d to socket %d\n", ret, fd);

	wdata[cpu_id].trancnt++;

	if (!enable_keepalive)
		goto free_back;

	client_ctx->handler = process_read;

	evt.events = EPOLLIN | EPOLLHUP | EPOLLERR;
	evt.data.ptr = client_ctx;

	ret = epoll_ctl(ep_fd, EPOLL_CTL_MOD, fd, &evt);
	if (ret < 0) {
		perror("Unable to add client socket read event to epoll");
		goto free_back;
	}

	goto back;

free_back:

	process_close(client_ctx);
	free_context(client_ctx);
back:

	return;
}