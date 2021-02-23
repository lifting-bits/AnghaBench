#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int ip; scalar_t__ port; } ;
struct rpcc_data {TYPE_1__ remote_pid; } ;
struct rpc_handshake_packet {int len; int seq_num; int /*<<< orphan*/  crc32; int /*<<< orphan*/  peer_pid; int /*<<< orphan*/  sender_pid; scalar_t__ flags; int /*<<< orphan*/  type; } ;
struct process_id {int dummy; } ;
struct connection {int remote_ip; int /*<<< orphan*/  Out; scalar_t__ remote_port; int /*<<< orphan*/  our_ip; } ;
struct TYPE_5__ {int /*<<< orphan*/  (* flush_packet ) (struct connection*) ;} ;
typedef  int /*<<< orphan*/  P ;

/* Variables and functions */
 TYPE_1__ PID ; 
 struct rpcc_data* RPCC_DATA (struct connection*) ; 
 TYPE_2__* RPCC_FUNC (struct connection*) ; 
 int /*<<< orphan*/  RPC_HANDSHAKE ; 
 int /*<<< orphan*/  compute_crc32 (struct rpc_handshake_packet*,int) ; 
 int get_my_ipv4 () ; 
 int /*<<< orphan*/  init_client_PID (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,TYPE_1__*,int) ; 
 int /*<<< orphan*/  memset (struct rpc_handshake_packet*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub1 (struct connection*) ; 
 int /*<<< orphan*/  write_out (int /*<<< orphan*/ *,struct rpc_handshake_packet*,int) ; 

__attribute__((used)) static int rpcc_send_handshake_packet (struct connection *c) {
  struct rpcc_data *D = RPCC_DATA (c);
  static struct rpc_handshake_packet P;
  if (!PID.ip) {
    init_client_PID (c->our_ip);
    if (!PID.ip) {
      PID.ip = get_my_ipv4 ();
    }
  }
  memset (&P, 0, sizeof (P));
  P.len = sizeof (P);
  P.seq_num = -1;
  P.type = RPC_HANDSHAKE;
  P.flags = 0;
  if (!D->remote_pid.port) {
    D->remote_pid.ip = (c->remote_ip == 0x7f000001 ? 0 : c->remote_ip);
    D->remote_pid.port = c->remote_port;
  }
  memcpy (&P.sender_pid, &PID, sizeof (struct process_id));
  memcpy (&P.peer_pid, &D->remote_pid, sizeof (struct process_id));
  P.crc32 = compute_crc32 (&P, sizeof (P) - 4);
  write_out (&c->Out, &P, sizeof (P));
  RPCC_FUNC(c)->flush_packet (c);

  return 0;
}