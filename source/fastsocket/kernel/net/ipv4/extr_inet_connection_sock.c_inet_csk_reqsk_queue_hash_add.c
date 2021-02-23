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
typedef  int /*<<< orphan*/  u32 ;
struct sock {int dummy; } ;
struct request_sock {int dummy; } ;
struct listen_sock {int /*<<< orphan*/  nr_table_entries; int /*<<< orphan*/  hash_rnd; } ;
struct TYPE_3__ {struct listen_sock* listen_opt; } ;
struct inet_connection_sock {TYPE_1__ icsk_accept_queue; } ;
struct TYPE_4__ {int /*<<< orphan*/  rmt_port; int /*<<< orphan*/  rmt_addr; } ;

/* Variables and functions */
 struct inet_connection_sock* inet_csk (struct sock*) ; 
 int /*<<< orphan*/  inet_csk_reqsk_queue_added (struct sock*,unsigned long) ; 
 TYPE_2__* inet_rsk (struct request_sock*) ; 
 int /*<<< orphan*/  inet_synq_hash (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  reqsk_queue_hash_req (TYPE_1__*,int /*<<< orphan*/  const,struct request_sock*,unsigned long) ; 

void inet_csk_reqsk_queue_hash_add(struct sock *sk, struct request_sock *req,
				   unsigned long timeout)
{
	struct inet_connection_sock *icsk = inet_csk(sk);
	struct listen_sock *lopt = icsk->icsk_accept_queue.listen_opt;
	const u32 h = inet_synq_hash(inet_rsk(req)->rmt_addr, inet_rsk(req)->rmt_port,
				     lopt->hash_rnd, lopt->nr_table_entries);

	reqsk_queue_hash_req(&icsk->icsk_accept_queue, h, req, timeout);
	inet_csk_reqsk_queue_added(sk, timeout);
}