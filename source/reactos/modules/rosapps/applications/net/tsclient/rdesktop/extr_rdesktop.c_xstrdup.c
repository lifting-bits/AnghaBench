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
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  perror (char*) ; 
 char* strdup (char const*) ; 

char *
xstrdup(const char *s)
{
	char *mem = strdup(s);
	if (mem == NULL)
	{
		perror("strdup");
		exit(1);
	}
	return mem;
}