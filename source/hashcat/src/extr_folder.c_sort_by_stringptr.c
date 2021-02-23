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
 int strcmp (char const* const,char const* const) ; 

int sort_by_stringptr (const void *p1, const void *p2)
{
  const char* const *s1 = (const char* const *) p1;
  const char* const *s2 = (const char* const *) p2;

  return strcmp (*s1, *s2);
}