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
struct arg {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  TLS ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  print_string_gw ; 
 int /*<<< orphan*/  tgl_do_get_terms_of_service (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct in_ev*) ; 

void do_get_terms_of_service (struct command *command, int arg_num, struct arg args[], struct in_ev *ev) {
  assert (!arg_num);
  if (ev) { ev->refcnt ++; }
  tgl_do_get_terms_of_service (TLS, print_string_gw, ev);
}