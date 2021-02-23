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
 int /*<<< orphan*/  TOUPPER (char const) ; 
 int /*<<< orphan*/  putchar (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
write_upcase (const char *str)
{
  while (*str)
    {
      /* The argument of TOUPPER should not have side effects.  */
      putchar (TOUPPER(*str));
      str++;
    }
}