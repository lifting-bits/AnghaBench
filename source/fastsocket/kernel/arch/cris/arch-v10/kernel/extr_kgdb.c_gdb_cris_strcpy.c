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

__attribute__((used)) static char*
gdb_cris_strcpy (char *s1, const char *s2)
{
	char *s = s1;
	
	for (s = s1; (*s++ = *s2++) != '\0'; )
		;
	return (s1);
}