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
 int /*<<< orphan*/  strcmp (char const* const,char const* const) ; 

__attribute__((used)) static int
def_name_eq_p (const void *def1, const void *def2)
{
  return ! strcmp (*(const char *const *) def1,
		   *(const char *const *) def2);
}