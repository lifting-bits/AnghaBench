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
 int /*<<< orphan*/  memcpy (char*,char*,int) ; 
 char* xmalloc (int) ; 

__attribute__((used)) static char *
next (char **ptr)
{
  char *p = *ptr;
  char *s;
  char *r;
  int l = 0;

  while (*p && *p == ' ')
    p++;
  s = p;
  while (*p && (*p != ' ' && *p != '\t'))
    {
      l++;
      p++;
    }
  r = xmalloc (l + 1);
  memcpy (r, s, l);
  r[l] = 0;
  *ptr = p;
  return r;
}