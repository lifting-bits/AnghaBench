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
 long strtol (char const*,char**,int) ; 

int
ddi_strtol(const char *str, char **nptr, int base, long *result)
{

	*result = strtol(str, nptr, base);
	return (0);
}