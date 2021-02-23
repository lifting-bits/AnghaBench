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
struct gdbarch {struct floatformat const* long_double_format; } ;
struct floatformat {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  fprintf_unfiltered (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gdb_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gdb_stdlog ; 
 int gdbarch_debug ; 

const struct floatformat *
gdbarch_long_double_format (struct gdbarch *gdbarch)
{
  gdb_assert (gdbarch != NULL);
  if (gdbarch_debug >= 2)
    fprintf_unfiltered (gdb_stdlog, "gdbarch_long_double_format called\n");
  return gdbarch->long_double_format;
}