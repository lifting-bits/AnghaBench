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
typedef  int /*<<< orphan*/  mrb_value ;
typedef  int /*<<< orphan*/  mrb_state ;
typedef  scalar_t__ mrb_int ;

/* Variables and functions */
 int /*<<< orphan*/  mrb_fixnum_value (int) ; 
 int /*<<< orphan*/  mrb_get_args (int /*<<< orphan*/ *,char*,scalar_t__*,scalar_t__*,scalar_t__*) ; 
 int /*<<< orphan*/  mrb_sys_fail (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ socket (int,int,int) ; 

__attribute__((used)) static mrb_value
mrb_socket_socket(mrb_state *mrb, mrb_value klass)
{
  mrb_int domain, type, protocol;
  int s;

  mrb_get_args(mrb, "iii", &domain, &type, &protocol);
  s = (int)socket((int)domain, (int)type, (int)protocol);
  if (s == -1)
    mrb_sys_fail(mrb, "socket");
  return mrb_fixnum_value(s);
}