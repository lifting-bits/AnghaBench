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
 unsigned char* BREAKPOINT_FROM_PC (int /*<<< orphan*/ *,int*) ; 
 int /*<<< orphan*/  error (char*) ; 
 int target_read_memory (int /*<<< orphan*/ ,char*,int) ; 
 int target_write_memory (int /*<<< orphan*/ ,char*,int) ; 

int
default_memory_insert_breakpoint (CORE_ADDR addr, char *contents_cache)
{
  int val;
  const unsigned char *bp;
  int bplen;

  /* Determine appropriate breakpoint contents and size for this address.  */
  bp = BREAKPOINT_FROM_PC (&addr, &bplen);
  if (bp == NULL)
    error ("Software breakpoints not implemented for this target.");

  /* Save the memory contents.  */
  val = target_read_memory (addr, contents_cache, bplen);

  /* Write the breakpoint.  */
  if (val == 0)
    val = target_write_memory (addr, (char *) bp, bplen);

  return val;
}