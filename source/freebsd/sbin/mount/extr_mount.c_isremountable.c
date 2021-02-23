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
 char** remountable_fs_names ; 
 scalar_t__ strcmp (char const*,char const*) ; 

int
isremountable(const char *vfsname)
{
	const char **cp;

	for (cp = remountable_fs_names; *cp; cp++)
		if (strcmp(*cp, vfsname) == 0)
			return (1);
	return (0);
}