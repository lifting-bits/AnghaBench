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
struct gdbarch {int /*<<< orphan*/ * unwind_sp; } ;

/* Variables and functions */
 int /*<<< orphan*/  gdb_assert (int /*<<< orphan*/ ) ; 

int
gdbarch_unwind_sp_p (struct gdbarch *gdbarch)
{
  gdb_assert (gdbarch != NULL);
  return gdbarch->unwind_sp != NULL;
}