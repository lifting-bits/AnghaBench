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
 int fz_tolower (char const) ; 

int
fz_strncasecmp(const char *a, const char *b, int n)
{
	if (!n--)
		return 0;
	for (; *a && *b && n && (*a == *b || fz_tolower(*a) == fz_tolower(*b)); a++, b++, n--)
		;
	return fz_tolower(*a) - fz_tolower(*b);
}