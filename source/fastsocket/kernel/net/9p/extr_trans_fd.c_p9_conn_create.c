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
struct p9_conn {int /*<<< orphan*/  wsched; int /*<<< orphan*/  pt; int /*<<< orphan*/  poll_pending_link; int /*<<< orphan*/  wq; int /*<<< orphan*/  rq; int /*<<< orphan*/  unsent_req_list; int /*<<< orphan*/  req_list; struct p9_client* client; int /*<<< orphan*/  mux_list; } ;
struct p9_client {int /*<<< orphan*/  msize; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENOMEM ; 
 struct p9_conn* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  INIT_WORK (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  P9_DEBUG_TRANS ; 
 int /*<<< orphan*/  P9_DPRINTK (int /*<<< orphan*/ ,char*,...) ; 
 int POLLIN ; 
 int POLLOUT ; 
 int /*<<< orphan*/  Rpending ; 
 int /*<<< orphan*/  Wpending ; 
 int /*<<< orphan*/  init_poll_funcptr (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct p9_conn* kzalloc (int,int /*<<< orphan*/ ) ; 
 int p9_fd_poll (struct p9_client*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  p9_pollwait ; 
 int /*<<< orphan*/  p9_read_work ; 
 int /*<<< orphan*/  p9_write_work ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static struct p9_conn *p9_conn_create(struct p9_client *client)
{
	int n;
	struct p9_conn *m;

	P9_DPRINTK(P9_DEBUG_TRANS, "client %p msize %d\n", client,
								client->msize);
	m = kzalloc(sizeof(struct p9_conn), GFP_KERNEL);
	if (!m)
		return ERR_PTR(-ENOMEM);

	INIT_LIST_HEAD(&m->mux_list);
	m->client = client;

	INIT_LIST_HEAD(&m->req_list);
	INIT_LIST_HEAD(&m->unsent_req_list);
	INIT_WORK(&m->rq, p9_read_work);
	INIT_WORK(&m->wq, p9_write_work);
	INIT_LIST_HEAD(&m->poll_pending_link);
	init_poll_funcptr(&m->pt, p9_pollwait);

	n = p9_fd_poll(client, &m->pt);
	if (n & POLLIN) {
		P9_DPRINTK(P9_DEBUG_TRANS, "mux %p can read\n", m);
		set_bit(Rpending, &m->wsched);
	}

	if (n & POLLOUT) {
		P9_DPRINTK(P9_DEBUG_TRANS, "mux %p can write\n", m);
		set_bit(Wpending, &m->wsched);
	}

	return m;
}