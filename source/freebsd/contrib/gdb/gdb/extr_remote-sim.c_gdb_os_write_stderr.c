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
typedef  int /*<<< orphan*/  host_callback ;

/* Variables and functions */
 int /*<<< orphan*/  fputs_unfiltered (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gdb_stdtargerr ; 

__attribute__((used)) static int
gdb_os_write_stderr (host_callback *p, const char *buf, int len)
{
  int i;
  char b[2];

  for (i = 0; i < len; i++)
    {
      b[0] = buf[i];
      b[1] = 0;
      fputs_unfiltered (b, gdb_stdtargerr);
    }
  return len;
}