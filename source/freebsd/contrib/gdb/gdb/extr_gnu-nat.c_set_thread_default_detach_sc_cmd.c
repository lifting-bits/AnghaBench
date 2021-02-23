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
struct TYPE_2__ {int /*<<< orphan*/  default_thread_detach_sc; } ;

/* Variables and functions */
 TYPE_1__* cur_inf () ; 
 int /*<<< orphan*/  parse_int_arg (char*,char*) ; 

__attribute__((used)) static void
set_thread_default_detach_sc_cmd (char *args, int from_tty)
{
  cur_inf ()->default_thread_detach_sc =
    parse_int_arg (args, "set thread default detach-suspend-count");
}