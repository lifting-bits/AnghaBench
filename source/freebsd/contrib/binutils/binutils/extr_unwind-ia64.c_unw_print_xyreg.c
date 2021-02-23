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

/* Variables and functions */
 int /*<<< orphan*/  sprintf (char*,char*,unsigned int) ; 

__attribute__((used)) static void
unw_print_xyreg (char *cp, unsigned int x, unsigned int ytreg)
{
  switch ((x << 1) | ((ytreg >> 7) & 1))
    {
    case 0: /* gr */
      sprintf (cp, "r%u", (ytreg & 0x1f));
      break;

    case 1: /* fr */
      sprintf (cp, "f%u", (ytreg & 0x1f));
      break;

    case 2: /* br */
      sprintf (cp, "b%u", (ytreg & 0x1f));
      break;
    }
}