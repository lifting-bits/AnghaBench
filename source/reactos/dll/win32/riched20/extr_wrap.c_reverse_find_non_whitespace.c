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
typedef  int /*<<< orphan*/  WCHAR ;

/* Variables and functions */
 scalar_t__ ME_IsWSpace (int /*<<< orphan*/  const) ; 

__attribute__((used)) static int reverse_find_non_whitespace(const WCHAR *s, int start)
{
  int i;
  for (i = start; i > 0 && ME_IsWSpace( s[i - 1] ); i--)
    ;

  return i;
}