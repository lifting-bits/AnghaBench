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
struct in_ev {int /*<<< orphan*/  refcnt; } ;
struct command {int dummy; } ;
struct arg {int /*<<< orphan*/  dval; int /*<<< orphan*/  msg_id; } ;

/* Variables and functions */
 int /*<<< orphan*/  TLS ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  print_msg_success_gw ; 
 int /*<<< orphan*/  tgl_do_reply_location (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct in_ev*) ; 

void do_reply_location (struct command *command, int arg_num, struct arg args[], struct in_ev *ev) {
  assert (arg_num == 3);
  if (ev) { ev->refcnt ++; }
  tgl_do_reply_location (TLS, &args[0].msg_id, args[1].dval, args[2].dval, 0, print_msg_success_gw, ev);
}