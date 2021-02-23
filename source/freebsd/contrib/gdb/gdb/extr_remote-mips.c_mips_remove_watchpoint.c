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
typedef  int /*<<< orphan*/  CORE_ADDR ;

/* Variables and functions */
 scalar_t__ clear_breakpoint (int /*<<< orphan*/ ,int,int) ; 

int
mips_remove_watchpoint (CORE_ADDR addr, int len, int type)
{
  if (clear_breakpoint (addr, len, type))
    return -1;

  return 0;
}