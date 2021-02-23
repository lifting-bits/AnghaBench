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
struct rpc_handshake_reject {int /*<<< orphan*/  local_id; } ;
struct relative {int dummy; } ;
struct connection {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  handshake_reject_received; } ;
struct TYPE_4__ {TYPE_1__ structured; } ;

/* Variables and functions */
 TYPE_2__* STATS ; 
 int /*<<< orphan*/  delete_relative (struct relative*,int) ; 
 struct relative* get_relative_by_connection (struct connection*) ; 
 int /*<<< orphan*/  get_relative_by_id (int /*<<< orphan*/ ) ; 
 int rpc_send_handshake (struct connection*) ; 
 int /*<<< orphan*/  vkprintf (int,char*,int /*<<< orphan*/ ,int) ; 

int rpc_execute_handshake_reject (struct connection *c, struct rpc_handshake_reject *P, int len) {
  vkprintf (2, "rpc_execute_handshake_reject: remote_id = %lld, len = %d\n", P->local_id, len);
  if (len != sizeof (struct rpc_handshake_reject)) {
    return 0;
  }
  STATS->structured.handshake_reject_received ++;
  if (!get_relative_by_id (P->local_id)) {
    struct relative *x = get_relative_by_connection (c);
    if (x) {
      delete_relative (x, 1);
    }
    return 0;
  }
  return rpc_send_handshake (c);
}