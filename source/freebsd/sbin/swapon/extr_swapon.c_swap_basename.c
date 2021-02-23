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
 char* strdup (char const*) ; 
 char* strrchr (char*,char) ; 

__attribute__((used)) static char *
swap_basename(const char *name)
{
	char *dname, *p;

	dname = strdup(name);
	p = strrchr(dname, '.');
	/* assert(p != NULL); */
	*p = '\0';

	return (dname);
}