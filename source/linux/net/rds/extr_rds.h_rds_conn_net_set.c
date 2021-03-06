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
struct rds_connection {int /*<<< orphan*/  c_net; } ;
struct net {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  write_pnet (int /*<<< orphan*/ *,struct net*) ; 

__attribute__((used)) static inline
void rds_conn_net_set(struct rds_connection *conn, struct net *net)
{
	write_pnet(&conn->c_net, net);
}