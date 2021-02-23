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
 scalar_t__ isspace (int const) ; 
 int /*<<< orphan*/  memmove (char*,char*,int const) ; 
 scalar_t__ strlen (char*) ; 

void hc_string_trim_leading (char *s)
{
  int skip = 0;

  const int len = (int) strlen (s);

  for (int i = 0; i < len; i++)
  {
    const int c = (const int) s[i];

    if (isspace (c) == 0) break;

    skip++;
  }

  if (skip == 0) return;

  const int new_len = len - skip;

  memmove (s, s + skip, new_len);

  s[new_len] = 0;
}