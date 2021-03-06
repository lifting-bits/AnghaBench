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
 int strcmp (char const*,char const*) ; 

__attribute__((used)) static int
cmp_string (const void *pstr1, const void *pstr2)
{
  const char *str1 = *(const char **)pstr1;
  const char *str2 = *(const char **)pstr2;

  return strcmp (str1, str2);
}